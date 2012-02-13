#ifndef _NODE_HPP
#define _NODE_HPP

#include <cstddef> /* NULL */
#include <vector>

#include "Edge.hpp"
class Edge;

class Node
{
private:
  unsigned int _name;
  unsigned int _potential;
  std::vector<Edge*> _next;
		
public:
  Node();
  Node(unsigned int name, unsigned int potential);
		
  unsigned int getName();
  void setName(unsigned int name);
  unsigned int getPotential();
  void setPotential(unsigned int potential);
		
  void addNext(Edge* edge);
  Edge* getEdge(unsigned int i);
  Edge* getEdgeFromNode(unsigned int name);
  int nextSize();
};

#endif
