#include "Edge.hpp"

Edge::Edge()
{
        setNode1(NULL);
	setNode2(NULL);
	setMaxCapacity(0);
	setCapacity(0);
	setCost(0);
}

Node* Edge::getNode1()
{
	return _node1;
}

Node* Edge::getNode2()
{
	return _node2;
}

int Edge::getMaxCapacity()
{
	return _maxCapacity;
}

int Edge::getCapacity()
{
	return _capacity;
}

int Edge::getCost()
{
	return _cost;
}

void Edge::setNode1(Node* node)
{
	_node1 = node;
}

void Edge::setNode2(Node* node)
{
	_node2 = node;
}

void Edge::setMaxCapacity(unsigned int maxCapacity)
{
	_maxCapacity = maxCapacity;
}

void Edge::setCapacity(unsigned int capacity)
{
	_capacity = capacity;
}

void Edge::setCost(unsigned int cost)
{
	_cost = cost;
}
