#ifndef _NODE_HPP
#define _NODE_HPP

#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QDialog>
#include <QGridLayout>
#include <QSpinBox>
#include <QLabel>
#include <vector>

#include "NodeDialog.hpp"
class NodeDialog;
#include "Edge.hpp"
class Edge;

static const QColor NODE_COLOR = Qt::white;
static const QColor SOURCE_COLOR = Qt::green;
static const QColor SINK_COLOR = Qt::red;
static const int NODE_WIDTH = 100;
static const int NODE_HEIGHT = 25;

class Node : public QGraphicsRectItem, public QObject
{
public:
  enum { Type = UserType + 1 };
  enum NodeType { NODE, SOURCE, SINK };

  Node(NodeType type);
		
  unsigned int getName();
  void setName(int name);
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
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
  QVariant itemChange(GraphicsItemChange change, const QVariant &value);
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);

private:
  unsigned int _name;
  unsigned int _potential;
  NodeType _type;
  std::vector<Edge *> _next;
  std::vector<Edge *> _prev;
};

#endif
