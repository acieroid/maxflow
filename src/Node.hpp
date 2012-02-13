#ifndef _NODE_HPP
#define _NODE_HPP

#include <cstddef> /* NULL */
#include <vector>

#include "Edge.hpp"
class Edge;

class Node
{
private:
  int _name;
  int _potential;
  std::vector<Edge*> _next;
		
public:
  Node();
  Node(int name, int potential);
		
  int getName();
  void setName(int name);
  int getPotential();
  void setPotential(int potential);
		
  void addNext(Edge* edge);
  Edge* getEdge(unsigned int i);
  Edge* getEdgeFromNode(unsigned int name);
  int nextSize();
};

#endif
