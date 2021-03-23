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

const Property* LabeledSlider::property()
{
  return m_property;
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

void LabeledSlider::setProperty(Property* prop)
{
  auto* range_prop = dynamic_cast<RangeBasedProperty*>(prop);
  if (range_prop)
  {
    disconnect(this, &LabeledSlider::valueChanged, m_property, &Property::setValue);
    disconnect(this, &LabeledSlider::minimumChanged, m_property, &RangeBasedProperty::setMinimum);
    disconnect(this, &LabeledSlider::maximumChanged, m_property, &RangeBasedProperty::setMaximum);

    m_property = range_prop;

    setMinimum(m_property->minimum().toInt());
    setMaximum(m_property->maximum().toInt());
    setName(m_property->name());
    setValue(m_property->value());

    connect(this, &LabeledSlider::valueChanged, m_property, &Property::setValue);
    connect(this, &LabeledSlider::minimumChanged, m_property, &RangeBasedProperty::setMinimum);
    connect(this, &LabeledSlider::maximumChanged, m_property, &RangeBasedProperty::setMaximum);

  }
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
