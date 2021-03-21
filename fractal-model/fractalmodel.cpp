#include "./fractal-model/fractalmodel.h"


FractalModel::FractalModel(const FractalModel& source) :
  QObject(source.parent())
{
  for (Property* prop: source.m_propertyList)
    m_propertyList.append(new Property(*prop));
}

FractalModel::~FractalModel()
{
  for (int i = 0; i < m_propertyList.size(); ++i)
    delete m_propertyList[i];
}

Property* FractalModel::at(int index)
{
  if (hasIndex(index))

    return m_propertyList[index];

  else

    return nullptr;
}

bool FractalModel::hasIndex(int index)
{
  return index >= 0 && index <= size();
}

void FractalModel::insertAt(int index, Property* prop)
{
  m_propertyList.insert(index, prop);
  emit itemAdded(index, prop);
}

void FractalModel::append(Property* prop)
{
  m_propertyList.append(prop);
  emit itemAdded(size(), prop);
}

int FractalModel::size()
{
  return m_propertyList.size();
}

void FractalModel::remove(int index)
{
  emit beforeItemRemoved(index);
  auto temp = at(index);
  m_propertyList.removeAt(index);
  emit afterItemRemoved(temp);
}

void FractalModel::clear()
{
  emit beforeContentCleared();
  m_propertyList.clear();
  emit contentCleared();
}
