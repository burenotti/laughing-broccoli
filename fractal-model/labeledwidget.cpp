#include "labeledwidget.h"

LabeledWidget::LabeledWidget(QWidget *parent)
  : LabeledWidget("", parent)
{

}

LabeledWidget::LabeledWidget(QString name, QWidget* parent)
  : QWidget(parent)
{
  LabeledWidget::setName(name);
  auto* layout = new QVBoxLayout();
  layout->addWidget(m_label);

}

LabeledWidget::~LabeledWidget()
{
  delete m_root;
}

void LabeledWidget::setupUi()
{
  m_root = new QWidget(this);
  auto* layout = new QVBoxLayout;
  m_label = new QLabel(m_root);
  layout->addWidget(m_label);
  layout->addWidget(widget());
  m_root->setLayout(layout);
  connect(this, &LabeledWidget::nameChanged, m_label, &QLabel::setText);
}

QString LabeledWidget::name()
{
  return m_name;
}

void LabeledWidget::setName(QString name)
{
  m_name = name;
  emit nameChanged(name);
}
