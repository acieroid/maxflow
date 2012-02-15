#include "NodeDialog.hpp"

NodeDialog::NodeDialog(Node *node) : QDialog(), node(node)
{
  layout = new QGridLayout();
  nameLabel = new QLabel("Name:");
  typeLabel = new QLabel("Type:");
  name = new QSpinBox();
  typeBox = new QComboBox();

  name->setMinimum(0);

  typeBox->addItem("Normal");
  typeBox->addItem("Source");
  typeBox->addItem("Sink");


  QObject::connect(name, SIGNAL(valueChanged(int)),
                   this, SLOT(setNodeName(int)));
  QObject::connect(typeBox, SIGNAL(activated(int)),
                   this, SLOT(setNodeType(int)));

  setModal(false); /* ne pas bloquer la fenêtre */

  layout->addWidget(nameLabel, 0, 0);
  layout->addWidget(name, 0, 1);
  layout->addWidget(typeLabel, 1, 0);
  layout->addWidget(typeBox, 1, 1);

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

void NodeDialog::setNodeType(int value)
{
  node->setType((Node::NodeType) value);
  node->update();
}
