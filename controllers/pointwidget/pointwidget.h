#ifndef POINTWIDGET_H
#define POINTWIDGET_H

#include "../labeledwidget.h"
#include "QVector2D"
#include "properties/pointproperty.h"

namespace Ui{
  class PointWidget;
}

class PointWidget : public LabeledWidget
{
  Q_OBJECT
public:
  PointWidget(QWidget* parent = nullptr);

  // AbstractPropertyController interface
public:
  QVariant value() override;
  void setProperty(Property* prop) override;
  const Property* property() override;

  // LabeledWidget interface
public slots:
  void setValue(QVariant) override;


  // LabeledWidget interface
public:
  void setupUi() override;

protected:
  QWidget* widget() override;
private:
  Ui::PointWidget* ui;
  PointProperty* m_property = nullptr;
};

#endif // POINTWIDGET_H
