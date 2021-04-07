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
  virtual void setProperty(Property* prop) = 0;
  virtual const Property* property() = 0;
signals:
  void valueChanged(QVariant value);
};

#endif // ABSTRACTPROPERTYCONTROLLER_H
