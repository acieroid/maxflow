#include "Edge.hpp"

Edge::Edge(Node *src, Node *dest) :
  _source(src), _dest(dest), _maxCapacity(0), _capacity(0), _cost(0)
{
  setLine(QLineF(src->pos(), dest->pos()));
  setZValue(-1000); /* évite de se dessiner devant les autres objets */
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

int Edge::type()
{
  return Type;
}
