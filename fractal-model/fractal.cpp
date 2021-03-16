#include "./fractal-model/fractal.h"

Property* FractalModel::itemAt(int index)
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
}

void FractalModel::append(Property* prop)
{
  m_propertyList.append(prop);
}

int FractalModel::size()
{
  return m_propertyList.size();
}

void FractalModel::remove(int index)
{
  m_propertyList.removeAt(index);
}

void FractalModel::clear()
{
  m_propertyList.clear();
}

