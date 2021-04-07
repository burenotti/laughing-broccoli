#include "pointwidget.h"
#include "ui_pointwidget.h"


PointWidget::PointWidget(QWidget* parent)
  : LabeledWidget(parent), ui(new Ui::PointWidget)
{
  PointWidget::setupUi();
  connect(this, &LabeledWidget::nameChanged, ui->nameLabel, &QLabel::setText);
}

QVariant PointWidget::value()
{
  return QVector2D(ui->xInput->value(),
                   ui->yInput->value());
}

void PointWidget::setProperty(Property* prop)
{
  auto point_prop = dynamic_cast<PointProperty*>(prop);
  if (point_prop)
  {
    if (m_property)
    {
      disconnect(this, &PointWidget::valueChanged, m_property, &Property::setValue);
      disconnect(m_property, &Property::valueChanged, this, &PointWidget::setValue);
    }
    setName(prop->name());
    setValue(prop->value());
    m_property = point_prop;
    connect(this, &PointWidget::valueChanged, m_property, &Property::setValue);
    connect(m_property, &Property::valueChanged, this, &PointWidget::setValue);
  }
}

const Property* PointWidget::property()
{
  return m_property;
}

void PointWidget::setValue(QVariant value)
{
  auto convertedValue = value.value<QVector2D>();
  ui->xInput->setValue(convertedValue.x());
  ui->yInput->setValue(convertedValue.y());
  emit valueChanged(convertedValue);
}

void PointWidget::setupUi()
{
  ui->setupUi(this);
}

QWidget* PointWidget::widget()
{
  return nullptr;
}
