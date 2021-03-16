#include "./properties/rangebasedproperty.h"

RangeBasedProperty::RangeBasedProperty(QVariant min, QVariant max, QVariant value, QString name, QObject* parent)
  : Property(name, value, parent)
{
  RangeBasedProperty::setMinimum(min);
  RangeBasedProperty::setMaximum(max);
}

RangeBasedProperty::RangeBasedProperty(QVariant min, QVariant max, QString name, QObject* parent)
  : RangeBasedProperty(min, max, min, name, parent)
{

}

RangeBasedProperty::RangeBasedProperty(QVariant min, QVariant max, QObject *parent)
  : RangeBasedProperty(min, max, min, "", parent) {
}


void RangeBasedProperty::setValue(QVariant value)
{
  if (value.value<qreal>() <= minimum().value<qreal>())
  {
      Property::setValue(minimum());
  } else if (value.value<qreal>() >= maximum().value<qreal>())
  {
      Property::setValue(maximum());
  } else
  {
    Property::setValue(value);
  }
}

void RangeBasedProperty::setRange(QVariant minimum, QVariant maximum)
{
  setMinimum(minimum);
  setMaximum(maximum);
}

QVariant RangeBasedProperty::maximum()
{
  return m_maximum;
}

QVariant RangeBasedProperty::minimum()
{
  return m_minimum;
}

void RangeBasedProperty::setMaximum(QVariant value)
{
  if(minimum().value<qreal>() <= value.value<qreal>())
    m_maximum = value;
  else
    m_maximum = minimum();
}

void RangeBasedProperty::setMinimum(QVariant value)
{
  if (maximum().value<qreal>() >= value.value<qreal>())
    m_minimum = value;
  else
    m_minimum = maximum();
}
