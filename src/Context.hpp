#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <QWidget>

/**
 * Le widget sur lequel on dessine
 */
class Context : public QWidget
{
  Q_OBJECT

public:
  Context();
  ~Context();
};

#endif /* CONTEXT_HPP */
