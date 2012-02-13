#include "Graph.hpp"

Graph::Graph()
{
	_nodes = NULL;
}

void Graph::addNode(Node* node)
{
	_node.push_back(node);
}

Node* Graph::getSource()
{//la source sera le premier noeud
	_nodes.front();
}

Node* Graph::getSink()
{
	_node.back();
}
