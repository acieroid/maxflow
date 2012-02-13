#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <QGraphicsScene>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>
#include "Graph.hpp"

/**
 * Le widget sur lequel on dessine
 */
class Context : public QGraphicsScene
{
  Q_OBJECT

public:
  Context();
  ~Context();

  /**
   * Retourne le graphe actuellement affiché
   */
  Graph *getGraph();

private:
  Graph *graph;                 /* Le  graphe qu'on manipule */
};

#endif /* CONTEXT_HPP */
