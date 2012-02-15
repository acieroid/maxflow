#ifndef _EDGE_HPP
#define _EDGE_HPP

#include <QGraphicsLineItem>

#include "Node.hpp"
class Node;

class Edge : public QGraphicsLineItem
{
public:
  enum { Type = UserType + 2 };

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

  /**
   * Permet de regénérer la flèche, si la source ou la destination a
   * été déplacée par exemple
   */
  void update();

  QRectF boundingRect() const;
  QPainterPath shape() const;

  int type();

protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
private:
  Node* _source;
  Node* _dest;
  unsigned int _maxCapacity;
  unsigned int _capacity;
  unsigned int _cost;
};

#endif

