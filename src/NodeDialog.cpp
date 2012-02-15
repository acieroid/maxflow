#include "NodeDialog.hpp"

NodeDialog::NodeDialog(Node *node) : QDialog(), node(node)
{
  layout = new QGridLayout();
  nameLabel = new QLabel("Name:");
  name = new QSpinBox();

  name->setMinimum(0);

  QObject::connect(name, SIGNAL(valueChanged(int)),
                   this, SLOT(setNodeName(int)));

  setModal(false); /* ne pas bloquer la fenêtre */

  layout->addWidget(nameLabel, 0, 0);
  layout->addWidget(name, 0, 1);

  setLayout(layout);
  show();
}

NodeDialog::~NodeDialog()
{
  delete layout;
  delete nameLabel;
  delete name;
}

void NodeDialog::setNodeName(int name)
{
  node->setName(name);
  node->update();
}
