#include "Context.hpp"

Context::Context()
{
  setBackgroundBrush(Qt::white);
  graph = new Graph();
}

Context::~Context()
{
  delete graph;
}

Graph *Context::getGraph()
{
  return graph;
}
