#include "Context.hpp"
#include <iostream>

Context::Context() :
  line(NULL)
{
  setBackgroundBrush(Qt::white);
  setMode(MOVE_ITEM);
  graph = new Graph();
}

Context::~Context()
{
  delete graph;
}

Graph *Context::getGraph()
{
  return graph;
}

void Context::setMode(Mode mode)
{
  this->mode = mode;
}

void Context::insertNode()
{
  setMode(INSERT_NODE);
}

void Context::insertSource()
{
  setMode(INSERT_SOURCE);
}

void Context::insertSink()
{
  setMode(INSERT_SINK);
}

void Context::insertEdge()
{
  setMode(INSERT_EDGE);
}

void Context::mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  if (mouseEvent->button() != Qt::LeftButton)
    return;

  QGraphicsRectItem *item;
  if (mode == INSERT_NODE || mode == INSERT_SOURCE || mode == INSERT_SINK) {
    item = new QGraphicsRectItem(0, 0, 100, 20);
    if (mode == INSERT_NODE)
      item->setBrush(NODE_COLOR);
    else if (mode == INSERT_SOURCE)
      item->setBrush(SOURCE_COLOR);
    else if (mode == INSERT_SINK)
      item->setBrush(SINK_COLOR);
    addItem(item);
    item->setPos(mouseEvent->scenePos());
  }
  else if (mode == INSERT_EDGE) {
    line = new QGraphicsLineItem(QLineF(mouseEvent->scenePos(),
                                        mouseEvent->scenePos()));
    addItem(line);
  }
  QGraphicsScene::mousePressEvent(mouseEvent);
}

void Context::mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  if (mode == INSERT_EDGE && line)
    line->setLine(QLineF(line->line().p1(), mouseEvent->scenePos()));
  if (mode == MOVE_ITEM)
    QGraphicsScene::mouseMoveEvent(mouseEvent);
}

void Context::mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
  if (line && mode == INSERT_EDGE) {
    QList<QGraphicsItem *> startItems = items(line->line().p1());
    if (startItems.count() > 0 && startItems.first() == line)
      startItems.removeFirst();
    QList<QGraphicsItem *> endItems = items(line->line().p2());
    if (endItems.count() > 0 && endItems.first() == line)
      endItems.removeFirst();

    removeItem(line);
    delete line;

    if (startItems.count() > 0 && endItems.count() > 0 &&
        startItems.first() != endItems.first()) {
      /* TODO: ajouter l'arc */
    }
  }
  setMode(MOVE_ITEM);
  QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
