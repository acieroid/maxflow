#ifndef _NODE_HPP
#define _NODE_HPP

#include <QGraphicsPolygonItem>
#include <QBrush>
#include <QColor>
#include <QPainter>
#include <vector>

#include "Edge.hpp"
class Edge;

static const QColor NODE_COLOR = Qt::white;
static const QColor SOURCE_COLOR = Qt::green;
static const QColor SINK_COLOR = Qt::red;
static const int NODE_WIDTH = 100;
static const int NODE_HEIGHT = 25;

class Node : public QGraphicsRectItem
{
public:
  enum { Type = UserType + 1 };
  enum NodeType { NODE, SOURCE, SINK };

  Node(NodeType type);
		
  unsigned int getName();
  void setName(unsigned int name);
  unsigned int getPotential();
  void setPotential(unsigned int potential);
		
  void addNext(Edge *edge);
  void addPrev(Edge *edge);
  Edge* getEdge(unsigned int i);
  Edge* getEdgeFromNode(unsigned int name);
  int nextSize();

  NodeType getType();
  void setType(NodeType type);

  int type();

protected:
  void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

private:
  unsigned int _name;
  unsigned int _potential;
  NodeType _type;
  std::vector<Edge *> _next;
  std::vector<Edge *> _prev;
};

#endif
