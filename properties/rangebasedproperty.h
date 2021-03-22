#ifndef RANGEBASEDPROPERTY_H
#define RANGEBASEDPROPERTY_H

#include <QObject>
#include "./properties/property.h"

class RangeBasedProperty : public Property
{
  Q_OBJECT
public:
  RangeBasedProperty(QVariant min, QVariant max, QVariant value, QString name, QObject* parent = nullptr);
  RangeBasedProperty(QVariant min, QVariant max, QString name, QObject* parent = nullptr);
  RangeBasedProperty(QVariant min, QVariant max, QObject* parent = nullptr);


  Q_PROPERTY(QVariant maximum READ maximum WRITE setMaximum NOTIFY maximumChanged)
  Q_PROPERTY(QVariant minimum READ minimum WRITE setMinimum NOTIFY minimumChanged)

  QVariant maximum();
  QVariant minimum();

  virtual const QString controllerType() const override;

public slots:
  virtual void setMaximum(QVariant value);
  virtual void setMinimum(QVariant value);
  virtual void setValue(QVariant value) override;
  virtual void setRange(QVariant minimum, QVariant maximum);
signals:
  void minimumChanged(QVariant);
  void maximumChanged(QVariant);
private:
  QVariant m_maximum;
  QVariant m_minimum;
};

#endif // RANGEBASEDPROPERTY_H
