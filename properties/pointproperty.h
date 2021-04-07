#ifndef POINTPROPERTY_H
#define POINTPROPERTY_H

#include "property.h"
#include <QVector2D>

class PointProperty : public Property
{
public:
  PointProperty(QObject* parent = nullptr);

  virtual float x();
  virtual float y();

public slots:

  virtual void setX(float x);
  virtual void setY(float y);

protected:
  QVector2D m_point;

  // Property interface
public slots:
  void setValue(QVariant value) override;
  QVariant value() override;

  // Property interface
public:
  const QString controllerType() const override;
};

#endif // POINTPROPERTY_H
