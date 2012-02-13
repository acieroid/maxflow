#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QColor>

/**
 * Le widget sur lequel on dessine
 */
class Context : public QWidget
{
  Q_OBJECT

public:
  Context();
  ~Context();

private slots:
  void paintEvent(QPaintEvent *event);
};

#endif /* CONTEXT_HPP */
