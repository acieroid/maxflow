#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QGraphicsView>
#include "Context.hpp"

/**
 * Le widget principal, qui contient tous les autres
 */
class MainWidget : public QWidget
{
  Q_OBJECT

public:
  MainWidget();
  ~MainWidget();

protected:
  void resizeEvent(QResizeEvent *event);

private:
  QVBoxLayout *mainLayout;
  QHBoxLayout *buttonsLayout;

  QPushButton *restart, *step;     /*< Boutons pour manipuler l'algorithme */
  QPushButton *newNode, *newEdge;  /*< Boutons pour manipuler le graphe */
  QGraphicsView *view;             /*< Vue de l'aire de dessin */
  Context *context;                /*< Aire de dessin */
};

#endif /* MAINWIDGET_HPP */
