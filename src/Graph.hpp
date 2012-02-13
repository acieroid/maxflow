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
		
		void addNode(Node* node);
		Node* getSource();
		Node* getSink();
};

#endif
