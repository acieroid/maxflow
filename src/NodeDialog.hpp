#ifndef NODE_DIALOG_HPP
#define NODE_DIALOG_HPP

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

#include "Node.hpp"
class Node;

/**
 * Dialogue créé lorsqu'on double clique sur un noeud. Permet de
 * modifier les paramètres de ce noeud
 */
class NodeDialog : public QDialog
{
  Q_OBJECT
public:
  NodeDialog(Node *node);
  ~NodeDialog();

public slots:
  void setNodeName(int name);
  void setNodeType(int type);

private:
  Node *node;

  QDialog *dialog;
  QGridLayout *layout;
  QLabel *nameLabel, *typeLabel;
  QSpinBox *name;
  QComboBox *typeBox;
};

#endif /* NODE_DIALOG_HPP */
