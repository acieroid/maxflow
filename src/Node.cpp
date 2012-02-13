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

void Node::addFollow(Edge* edge)
{
	_follow.push_back(edge);
}

Edge* Node::getEdge(unsigned int i)
{//acces au noeud suivant i
	if(i < _follow.size())
	{
		return _follow[i];
	}
	else
	{
		return NULL;
	}
}

Edge* Node::getEdgeFromNode(unsigned int name)
{//sert à trouver le noeud suivant avec son nom
	int size = followSize();
	int i = 0;
#if 0 /* FIX */
	while(_follow[i] != name && i < size)
	{
		++i;
	}
	if(i != size)
	{
		return _follow[i];
	}
	else
#endif
	{
		return NULL;
	}
}

int Node::followSize()
{
	return _follow.size();
}
