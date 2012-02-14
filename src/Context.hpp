#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QColor>
#include "Graph.hpp"

static const QColor NODE_COLOR = Qt::white;
static const QColor SOURCE_COLOR = Qt::green;
static const QColor SINK_COLOR = Qt::red;

/**
 * Le widget sur lequel on dessine
 */
class Context : public QGraphicsScene
{
  Q_OBJECT

public:
  enum Mode { INSERT_NODE, INSERT_SOURCE, INSERT_SINK, INSERT_EDGE, MOVE_ITEM };
  Context();
  ~Context();

  /**
   * Retourne le graphe actuellement affiché
   */
  Graph *getGraph();

  void setMode(Mode mode);

public slots:
  void insertNode();
  void insertSource();
  void insertSink();
  void insertEdge();
protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseMoveEvent(QGraphicsSceneMouseEvent *mouseEvent);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent *mouseEvent);

private:
  Graph *graph;                 /*< Le  graphe qu'on manipule */
  Mode mode;                    /*< Mode actuel quand on clique */
  QGraphicsLineItem *line;
};

#endif /* CONTEXT_HPP */
