#include "Context.hpp"

Context::Context()
{
}

Context::~Context()
{
}

void Context::paintEvent(QPaintEvent * /* event */)
{
  QPainter *painter = new QPainter(this);

  /* fond blanc */
  painter->setPen(QColor(255, 255, 255));
  painter->setBrush(QColor(255, 255, 255));
  painter->drawRect(0, 0, width(), height());

  delete painter;
}
