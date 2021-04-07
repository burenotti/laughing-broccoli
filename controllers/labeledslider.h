#ifndef LABELEDSLIDER_H
#define LABELEDSLIDER_H

#include "labeledwidget.h"
#include "properties/rangebasedproperty.h"
#include <QVariant>
#include <QSlider>
#include <QSpacerItem>

class LabeledSlider : public LabeledWidget
{
  Q_OBJECT
public:
  LabeledSlider(QString name, QWidget* parent = nullptr);
  explicit LabeledSlider(QWidget* parent);

  int minimum();
  int maximum();
  QVariant value() override;

  virtual const Property* property() override;

signals:
  void minimumChanged(int minimum);
  void maximumChanged(int maximum);
public slots:
  virtual void setValue(QVariant value) override;
  void setMaximum(int value);
  void setMinimum(int value);
  virtual void setProperty(Property* prop) override;
protected:
  QSlider* widget() override;
protected:
  QSlider* m_slider = nullptr;
  RangeBasedProperty* m_property = nullptr;
};

#endif // LABELEDSLIDER_H
