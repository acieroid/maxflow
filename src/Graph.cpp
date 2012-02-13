#include "Graph.hpp"

Graph::Graph()
{
}

void Graph::addNode(Node* node)
{
	_nodes.push_back(node);
}

Node* Graph::getSource()
{//la source sera le premier noeud
	return _nodes.front();
}

Node* Graph::getSink()
{
	return _nodes.back();
}
