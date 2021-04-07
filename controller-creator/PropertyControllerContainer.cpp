 #include "PropertyControllerContainer.h"


PropertyControllerContainer::PropertyControllerContainer(QWidget* parent) : QGroupBox(parent)
{
  m_layout = new QVBoxLayout();
  m_layout->addStretch();
  this->setLayout(m_layout);
}

const FractalModel* PropertyControllerContainer::model()
{
  return m_model;
}

void PropertyControllerContainer::setModel(FractalModel* model)
{

  deleteControllers();

  if (m_model)
  {
    disconnect(m_model, &FractalModel::contentCleared,
            this, &PropertyControllerContainer::deleteControllers);
    disconnect(m_model, &FractalModel::itemAdded,
            this, &PropertyControllerContainer::insertController);
    disconnect(m_model, &FractalModel::beforeItemRemoved,
            this, &PropertyControllerContainer::removeController);
    disconnect(m_model, &FractalModel::contentCleared,
            this, &PropertyControllerContainer::deleteControllers);
  }

  m_model = model;
  this->setTitle(m_model->name());

  connect(m_model, &FractalModel::contentCleared,
          this, &PropertyControllerContainer::deleteControllers);
  connect(m_model, &FractalModel::itemAdded,
          this, &PropertyControllerContainer::insertController);
  connect(m_model, &FractalModel::beforeItemRemoved,
          this, &PropertyControllerContainer::removeController);
  connect(m_model, &FractalModel::contentCleared,
          this, &PropertyControllerContainer::deleteControllers);
  for (int i = 0; i < model->size(); ++i)
  {
    Property* prop = model->at(i);
    auto* controller = createController(prop);
    appendController(controller);
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
    controller = m_creatorMap[controllerType](prop, this);
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

void PropertyControllerContainer::appendController(AbstractPropertyController* controller)
{

  m_controllerList.append(controller);
  controller->show();
  m_layout->insertWidget(m_layout->count()-1, controller);
}

void PropertyControllerContainer::insertController(int index, Property* prop)
{
  auto* controller = createController(prop);
  m_controllerList.insert(index, controller);
  m_layout->insertWidget(index, controller);
  controller->show();
}

void PropertyControllerContainer::removeController(int index)
{
  delete m_controllerList.at(index);
  m_controllerList.removeAt(index);
}
