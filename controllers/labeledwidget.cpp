#include "labeledwidget.h"

LabeledWidget::LabeledWidget(QWidget *parent)
  : LabeledWidget("", parent)
{
}

LabeledWidget::LabeledWidget(QString name, QWidget* parent)
  : AbstractPropertyController(parent)
{
  LabeledWidget::setName(name);
}

LabeledWidget::~LabeledWidget()
{
  delete m_label;
}

void LabeledWidget::setupUi()
{
  m_layout = new QVBoxLayout;
  m_label = new QLabel(this);
  m_layout->addWidget(m_label);
  m_layout->addWidget(widget());
  this->setLayout(m_layout);
  this->show();
  m_label->setText(name());
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
