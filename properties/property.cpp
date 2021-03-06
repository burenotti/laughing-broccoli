#include "./properties/property.h"

Property::Property(QObject *parent) : QObject(parent) {}

Property::Property(QString name, QObject *parent) : QObject(parent)
{
  Property::setName(name);
}

Property::Property(QString name, QVariant value, QObject *parent) : QObject(parent)
{
  Property::setName(name);
  Property::setValue(value);
}

Property::Property(const Property& source)
  : QObject(source.parent())
{
  m_name = source.m_name;
  m_value = source.m_value;
}

QString Property::name()
{
  return m_name;
}

QVariant Property::value()
{
  return m_value;
}

const QString Property::controllerType() const {
  return "default";
}

void Property::setValue(QVariant value)
{
  if (value != m_value)
  {
    m_value = value;
    emit valueChanged(value);
  }
}

void Property::setName(QString name)
{
  if (m_name != name)
  {
    m_name = name;
   emit nameChanged(name);
  }
}
