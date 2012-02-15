#include "Edge.hpp"

Edge::Edge(Node *src, Node *dest) :
  _source(src), _dest(dest), _maxCapacity(0), _capacity(0), _cost(0)
{
  setLine(QLineF(src->pos(), dest->pos()));
  setZValue(-1000); /* évite de se dessiner devant les autres objets */
  setFlag(QGraphicsItem::ItemIsMovable, true);
}

Node* Edge::getSource()
{
  return _source;
}

Node* Edge::getDestination()
{
  return _dest;
}

int Edge::getMaxCapacity()
{
  return _maxCapacity;
}

int Edge::getCapacity()
{
  return _capacity;
}

int Edge::getCost()
{
  return _cost;
}

void Edge::setSource(Node* node)
{
  _source = node;
  update();
}

void Edge::setDestination(Node* node)
{
  _dest = node;
  update();
}

void Edge::setMaxCapacity(unsigned int maxCapacity)
{
  _maxCapacity = maxCapacity;
}

void Edge::setCapacity(unsigned int capacity)
{
  _capacity = capacity;
}

void Edge::setCost(unsigned int cost)
{
  _cost = cost;
}

void Edge::update()
{
  setLine(QLineF(_source->pos(), _dest->pos()));
}

QRectF Edge::boundingRect()
{
  /* TODO: quelques artéfact quand on déplace un arc */
  double extra = 10;
  return QRectF(line().p1(), QSizeF(line().p2().x() - line().p1().x(),
                                    line().p2().y() - line().p1().y()))
    .normalized().adjusted(-extra, -extra, extra, extra);
}

QPainterPath Edge::shape()
{
  /* TODO: ajouter la flèche au bout */
  return QGraphicsLineItem::shape();
}

void Edge::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
  QGraphicsLineItem::paint(painter, option, widget);
  QString infos = QString("%1/%2/%3")
    .arg(getCost()).arg(getCapacity()).arg(getMaxCapacity());
  painter->drawText((line().p2().x() + line().p1().x())/2,
                    (line().p2().y() + line().p1().y())/2, infos);
}

int Edge::type()
{
  return Type;
}
