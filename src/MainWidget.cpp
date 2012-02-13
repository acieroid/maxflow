#include "MainWidget.hpp"

MainWidget::MainWidget()
{
  mainLayout = new QVBoxLayout();
  buttonsLayout = new QHBoxLayout();
  restart = new QPushButton("Restart");
  step = new QPushButton("Step");
  newNode = new QPushButton("New node");
  newEdge = new QPushButton("New edge");
  context = new Context();
  view = new QGraphicsView(context);

  buttonsLayout->addWidget(restart);
  buttonsLayout->addWidget(step);
  buttonsLayout->addWidget(newNode);
  buttonsLayout->addWidget(newEdge);

  mainLayout->addLayout(buttonsLayout);
  mainLayout->addWidget(view);

  this->setLayout(mainLayout);
  this->show();
}

MainWidget::~MainWidget()
{
  delete context;
  delete newEdge;
  delete newNode;
  delete step;
  delete restart;
  delete buttonsLayout;
  delete mainLayout;
}
