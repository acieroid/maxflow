#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <vector>

#include "Node.hpp"

class Graph
{
private:
  std::vector<Node*> _nodes;
public:
  Graph();
  ~Graph();
		
  void addNode(Node *node);
  std::vector<Node*> getNodes();
  std::vector<Node*> getSources();
  std::vector<Node*> getSinks();
};

#endif
