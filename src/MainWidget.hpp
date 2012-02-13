#ifndef MAINWIDGET_HPP
#define MAINWIDGET_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
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

private:
  QVBoxLayout *mainLayout;
  QHBoxLayout *buttonsLayout;

  QPushButton *restart, *step;     /*< Boutons pour manipuler l'algorithme */
  QPushButton *newNode, *newEdge;  /*< Boutons pour manipuler le graphe */
  Context *context;                /*< Aire de dessin */
};

#endif /* MAINWIDGET_HPP */
