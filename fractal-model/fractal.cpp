#include "./fractal-model/fractal.h"

Property* FractalModel::itemAt(int index)
{
  if (hasIndex(index))

    return m_propertyList[index];

  else

    return nullptr;
}
