#include "Edge.hpp"

Edge::Edge()
{
  Edge(NULL, NULL);
}

Edge::Edge(Node *src, Node *dest)
{
  setSource(src);
  setDestination(dest);
  setMaxCapacity(0);
  setCapacity(0);
  setCost(0);
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
}

void Edge::setDestination(Node* node)
{
  _dest = node;
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

int Edge::type()
{
  return Type;
}
