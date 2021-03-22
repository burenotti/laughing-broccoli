 #include "PropertyControllerContainer.h"


PropertyControllerContainer::PropertyControllerContainer(QWidget* parent) : QWidget(parent)
{
  connect(m_model, &FractalModel::contentCleared,
          this, &PropertyControllerContainer::deleteControllers);
  connect(m_model, &FractalModel::itemAdded,
          this, &PropertyControllerContainer::insertController);
  connect(m_model, &FractalModel::beforeItemRemoved,
          this, &PropertyControllerContainer::removeController);
  connect(m_model, &FractalModel::contentCleared,
          this, &PropertyControllerContainer::deleteControllers);
}

const FractalModel* PropertyControllerContainer::model()
{
  return m_model;
}

void PropertyControllerContainer::setModel(FractalModel* model)
{
  deleteControllers();
  m_model = model;
  for (int i = 0; i < model->size(); ++i)
  {
    Property* prop = model->at(i);
    auto* controller = createController(prop);
    m_controllerList.append(controller);
  }
}

void PropertyControllerContainer::setCreatorOfType(const QString& id, ControllerCreator creator)
{
  m_creatorMap[id] = creator;
}

AbstractPropertyController* PropertyControllerContainer::createController(Property* prop)
{
  AbstractPropertyController* controller = nullptr;
  auto controllerType = prop->controllerType();
  if (m_creatorMap.contains(controllerType))
  {
    controller = m_creatorMap[controllerType](prop);
  }
  return controller;
}

void PropertyControllerContainer::deleteControllers()
{
  for (auto controller: m_controllerList)
  {
    delete controller;
  }
  m_controllerList.clear();
}

void PropertyControllerContainer::insertController(int index, Property* prop)
{
  auto* controller = createController(prop);
  m_controllerList.insert(index, controller);
  controller->show();
}

void PropertyControllerContainer::removeController(int index)
{
  delete m_controllerList.at(index);
  m_controllerList.removeAt(index);
}
