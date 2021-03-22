#ifndef PROPERTYCONTROLLERCONTAINER_H
#define PROPERTYCONTROLLERCONTAINER_H

#include <QWidget>
#include <QHash>
#include "properties/property.h"
#include "fractal-model/fractalmodel.h"
#include "controllers/abstractpropertycontroller.h"

using ControllerCreator = AbstractPropertyController* (*)(Property* property);

class PropertyControllerContainer : public QWidget {
  Q_OBJECT
public:


  explicit PropertyControllerContainer(QWidget* parent = nullptr);

  const FractalModel* model();

public slots:

  void setModel(FractalModel* model);

  void setCreatorOfType(const QString& id, ControllerCreator creator);

signals:

protected:
  AbstractPropertyController* createController(Property* prop);

protected slots:
  void deleteControllers();

  void insertController(int index, Property* prop);
  void removeController(int index);
private:
  QList<AbstractPropertyController*> m_controllerList;
  QHash<QString, ControllerCreator> m_creatorMap;
  FractalModel* m_model;
};

#endif // PROPERTYCONTROLLERCONTAINER_H
