#ifndef _NODE_HPP
#define _NODE_HPP

#include <vector>

#include "Edge.hpp"
class Edge;

class Node
{
	private:
		int _name;
		int _potential;
		std::vector<Edge*> _follow;
		
	public:
		Node();
		Node(int name, int potential);
		
		int getName();
		int getPotential();
		void setPotential(int potential);
		void setName(int name);
		
		void addFollow(Edge* edge);
		Edge* getEdge(unsigned int i);
		Edge* getEdgeFromNode(unsigned int name);
		int followSize();
};

#endif
