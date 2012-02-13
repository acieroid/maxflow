#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <vector>

#include "Node.hpp"

class Graph
{
private:
  std::vector<Node*> _nodes;
  std::vector<Node*> _sources;
  std::vector<Node*> _sinks;
public:
  Graph();
  ~Graph();
		
  void addNode(Node* node);
  void addSource(Node *node);
  void addSink(Node *node);
  std::vector<Node*> getNodes();
  std::vector<Node*> getSources();
  std::vector<Node*> getSinks();
};

#endif
