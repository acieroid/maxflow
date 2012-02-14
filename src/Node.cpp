#include "Node.hpp"

Node::Node(NodeType type) :
  QGraphicsRectItem(-NODE_WIDTH/2, -NODE_HEIGHT/2, NODE_WIDTH, NODE_HEIGHT)
{
  setName(-1);
  setType(type);
  setPotential(0);
  setFlag(QGraphicsItem::ItemIsMovable, true);
  setAcceptDrops(true);
}

unsigned int Node::getName()
{
  return _name;
}

unsigned int Node::getPotential()
{
  return _potential;
}

void Node::setName(unsigned int name)
{
  _name = name;
}

void Node::setPotential(unsigned int potential)
{
  _potential = potential;
}

void Node::addNext(Edge* edge)
{
  _next.push_back(edge);
}

void Node::addPrev(Edge *edge)
{
  _prev.push_back(edge);
}

Edge* Node::getEdge(unsigned int i)
{//acces au noeud suivant i
  if(i < _next.size())
    return _next[i];
  return NULL;
}

Edge* Node::getEdgeFromNode(unsigned int name)
{//sert à trouver le noeud suivant avec son nom
  std::vector<Edge *>::iterator it;
  for (it = _next.begin(); it != _next.end(); it++) {
    if ((*it)->getDestination()->getName() == name)
      return *(it++);
  }
  return NULL;
}

int Node::nextSize()
{
  return _next.size();
}

Node::NodeType Node::getType()
{
  return _type;
}

void Node::setType(NodeType type)
{
  _type = type;
  switch (type) {
  case NODE:
    setBrush(QBrush(NODE_COLOR));
    break;
  case SOURCE:
    setBrush(QBrush(SOURCE_COLOR));
    break;
  case SINK:
    setBrush(QBrush(SINK_COLOR));
    break;
  default:
    ;
  }
}

int Node::type()
{
  return Type;
}

void Node::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
  /* TODO: idéalement il faudrait utiliser le dragMoveEvent mais ça ne
     marche pas, même en utilisant setAcceptDrops(true) */
  std::vector<Edge *>::iterator it;

  /* Mets à jour les arcs */
  for (it = _next.begin(); it != _next.end(); it++)
    (*it)->update();

  for (it = _prev.begin(); it != _prev.end(); it++)
    (*it)->update();

  QGraphicsItem::mouseMoveEvent(event);
}

/**
 * TODO: la méthode n'a pas l'air d'être appelée...
 */
void Node::paint(QPainter *painter, QStyleOptionGraphicsItem *option,
                 QWidget *widget)
{
  /* Dessine le noeud */
  /* QGraphicsRectItem::paint(painter, option, widget); */
  painter->drawRect(rect());

  /* Ajoute le nom par dessus */
  QFontMetrics fontMetrics(painter->font());
  QString name = QString("%1").arg(getName());
  painter->drawText(NODE_WIDTH/2-fontMetrics.width(name),
                    NODE_HEIGHT/2-fontMetrics.width(name), name);
}
