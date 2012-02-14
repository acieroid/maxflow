#include "Graph.hpp"

Graph::Graph()
{
}

Graph::~Graph()
{
  std::vector<Node *>::iterator it;
  Node *node;

  while (_nodes.begin() != _nodes.end()) {
    node = _nodes.pop_back();
    delete node;
  }
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
  std::vector<Node *> sources;
  std::vector<Node *>::iterator it;

  for (it = _nodes.begin(); it != _nodes.end(); it++) {
    if ((*it)->getType = SOURCE)
      sources.push_back(*it);
  }

  return sources;
}

std::vector<Node*> Graph::getSinks()
{
  std::vector<Node *> sinks;
  std::vector<Node *>::iterator it;

  for (it = _nodes.begin(); it != _nodes.end(); it++) {
    if ((*it)->getType = SINK)
      sinks.push_back(*it);
  }

  return sinks;
}
