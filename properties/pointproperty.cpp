#include "pointproperty.h"

PointProperty::PointProperty(QObject* parent) : Property(parent)
{

}

float PointProperty::x()
{
  return m_point.x();
}

float PointProperty::y()
{
  return m_point.y();
}


void PointProperty::setX(float x)
{
  if (m_point.x() != x)
  {
    m_point.setX(x);
    emit valueChanged(m_point);
  }
}

void PointProperty::setY(float y)
{
  if (m_point.y() != y)
  {
    m_point.setX(y);
    emit valueChanged(m_point);
  }
}

void PointProperty::setValue(QVariant value)
{
  m_point = value.value<QVector2D>();
  emit valueChanged(m_point);
}

QVariant PointProperty::value()
{
  return m_point;
}

const QString PointProperty::controllerType() const
{
  return "point";
}
