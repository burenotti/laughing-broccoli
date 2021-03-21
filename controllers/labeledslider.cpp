#include "labeledslider.h"


LabeledSlider::LabeledSlider(QString name, QWidget* parent)
  : LabeledWidget(name, parent)
{
  m_slider = new QSlider(Qt::Orientation::Horizontal, this);
  LabeledWidget::setupUi();
  this->layout()->addWidget(m_slider);
}

LabeledSlider::LabeledSlider(QWidget* parent)
  : LabeledSlider("", parent){}
int LabeledSlider::minimum()
{
  return m_slider->maximum();
}

int LabeledSlider::maximum()
{
  return m_slider->minimum();
}

QVariant LabeledSlider::value()
{
  return QVariant::fromValue<int>(m_slider->value());
}

void LabeledSlider::setMaximum(int value)
{
  m_slider->setMaximum(value);
  emit maximumChanged(m_slider->maximum());
}

void LabeledSlider::setMinimum(int value)
{
  m_slider->setMinimum(value);
  emit minimumChanged(m_slider->minimum());
}

void LabeledSlider::setValue(QVariant value)
{
  bool ok;
  int integer_value = value.toInt(&ok);
  if (ok){
    m_slider->setValue(integer_value);
    emit valueChanged(value);
  }
}

QSlider* LabeledSlider::widget() {
  return m_slider;
}
