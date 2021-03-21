#ifndef ABSTRACTPROPERTYCONTROLLER_H
#define ABSTRACTPROPERTYCONTROLLER_H

#include <QWidget>
#include "properties/property.h"

class AbstractPropertyController : public QWidget
{
  Q_OBJECT
public:
  explicit AbstractPropertyController(QWidget *parent = nullptr);

  virtual QVariant value() = 0;
  virtual void setProperty(Property* prop);
  virtual const Property* property();
signals:
  void valueChanged(QVariant value);
protected:
  Property* m_property;
};

#endif // ABSTRACTPROPERTYCONTROLLER_H
