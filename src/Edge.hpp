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

#if 0
protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget = NULL);
#endif
private:
  Node* _source;
  Node* _dest;
  unsigned int _maxCapacity;
  unsigned int _capacity;
  unsigned int _cost;

#if 0
  QPolygonF headPolygon;
#endif
};

#endif

