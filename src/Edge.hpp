#ifndef _EDGE_HPP
#define _EDGE_HPP

#include <QGraphicsLineItem>

#include "Node.hpp"
class Node;

class Edge : public QGraphicsLineItem
{
public:
  enum { Type = UserType + 2 };

  Edge();
  Edge(Node *src, Node *dest);
		
  Node* getSource();
  Node* getDestination();
  int getMaxCapacity();
  int getCapacity();
  int getCost();
		
  void setSource(Node* node);
  void setDestination(Node* node);
  void setMaxCapacity(unsigned int maxCapacity);
  void setCapacity(unsigned int capacity);
  void setCost(unsigned int cost);

  int type();
private:
  Node* _source;
  Node* _dest;
  unsigned int _maxCapacity;
  unsigned int _capacity;
  unsigned int _cost;
};

#endif

