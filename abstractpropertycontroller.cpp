#include "abstractpropertycontroller.h"

AbstractPropertyController::AbstractPropertyController(QWidget *parent) : QWidget(parent)
{
}

void AbstractPropertyController::setProperty(Property* prop)
{
  m_property = prop;
}

const Property* AbstractPropertyController::property()
{
  return m_property;
}
