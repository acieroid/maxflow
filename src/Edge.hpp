#ifndef _EDGE_HPP
#define _EDGE_HPP

#include "Node.hpp"
class Node;

class Edge
{
	private:
		Node* _node1; //source de l'arc
		Node* _node2; //extremité de l'arc
		unsigned int _maxCapacity;
		unsigned int _capacity;
		unsigned int _cost;
	public:
		Edge();
		
		Node* getNode1();
		Node* getNode2();
		int getMaxCapacity();
		int getCapacity();
		int getCost();
		
		void setNode1(Node* node);
		void setNode2(Node* node);
		void setMaxCapacity(unsigned int maxCapacity);
		void setCapacity(unsigned int capacity);
		void setCost(unsigned int cost);
};

#endif

