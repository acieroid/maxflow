#include "Context.hpp"
#include <iostream>

Context::Context() :
  line(NULL)
{
  setBackgroundBrush(Qt::white);
  setMode(MOVE_NODE);
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

  Node *node;
  if (mode == INSERT_NODE || mode == INSERT_SOURCE || mode == INSERT_SINK) {
    /* mode correspond à un NodeType dans ce cas-ci */
    node = new Node((Node::NodeType) mode);
    graph->addNode(node);
    addItem(node);
    node->setPos(mouseEvent->scenePos());
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
  if (mode == MOVE_NODE)
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
      Node *start = (Node *)(startItems.first());
      Node *end = (Node *)(endItems.first());
      Edge *edge = new Edge(start, end);
      start->addNext(edge);
      end->addPrev(edge);
      addItem(edge);
    }
  }
  setMode(MOVE_NODE);
  QGraphicsScene::mouseReleaseEvent(mouseEvent);
}
