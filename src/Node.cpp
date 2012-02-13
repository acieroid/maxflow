#include "Node.hpp"

Node::Node()
{
  setName(-1);
  setPotential(0);
}

Node::Node(int name, int potential)
{
  setName(name);
  setPotential(potential);
}

int Node::getName()
{
  return _name;
}

int Node::getPotential()
{
  return _potential;
}

void Node::setName(int name)
{
  _name = name;
}

void Node::setPotential(int potential)
{
  _potential = potential;
}

void Node::addNext(Edge* edge)
{
  _follow.push_back(edge);
}

Edge* Node::getEdge(unsigned int i)
{//acces au noeud suivant i
	if(i < _next.size())
	{
		return _next[i];
	}
	else
	{
		return NULL;
	}
}

Edge* Node::getEdgeFromNode(unsigned int name)
{//sert à trouver le noeud suivant avec son nom
  int size = nextSize();
  int i = 0;
  while(_next[i] != name && i < size)
  {
      ++i;
  }
  if(i != size)
  {
    return _follow[i];
  }
  else
  {
    return NULL;
  }
}

int Node::followSize()
{
  return _follow.size();
}
