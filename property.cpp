#include "property.h"

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

QString Property::name()
{
  return m_name;
}

QVariant Property::value()
{
  return m_value;
}

void Property::setValue(QVariant value)
{
  m_value = value;
  emit valueChanged(value);
}

void Property::setName(QString name)
{
  m_name = name;
  emit nameChanged(name);
}
