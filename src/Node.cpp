#include "Node.hpp"

Node::Node()
{
  setName(-1);
  setPotential(0);
}

Node::Node(unsigned int name, unsigned int potential)
{
  setName(name);
  setPotential(potential);
}

unsigned int Node::getName()
{
  return _name;
}

unsigned int Node::getPotential()
{
  return _potential;
}

void Node::setName(unsigned int name)
{
  _name = name;
}

void Node::setPotential(unsigned int potential)
{
  _potential = potential;
}

void Node::addNext(Edge* edge)
{
  _next.push_back(edge);
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
  std::vector<Edge *>::iterator it;
  for (it = _next.begin(); it != _next.end(); it++) {
    if ((*it)->getDestination()->getName() == name)
      return *(it++);
  }
  return NULL;
}

int Node::nextSize()
{
  return _next.size();
}
