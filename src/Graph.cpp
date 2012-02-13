#include "Graph.hpp"

Graph::Graph()
{
}

Graph::~Graph()
{
  /* TODO: supprimer tous les noeuds et arcs */
}

void Graph::addNode(Node* node)
{
  _nodes.push_back(node);
}

std::vector<Node*> Graph::getNodes()
{
  return _nodes;
}

std::vector<Node*> Graph::getSources()
{
  return _sources;
}

std::vector<Node*> Graph::getSinks()
{
  return _sinks;
}
