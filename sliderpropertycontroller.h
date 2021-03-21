#ifndef SLIDERPROPERTYCONTROLLER_H
#define SLIDERPROPERTYCONTROLLER_H

#include "abstractpropertycontroller.h"
#include "fractal-model/labeledslider.h"


class SliderPropertyController :
    public AbstractPropertyController,
    public LabeledSlider
{
public:
  explicit SliderPropertyController(QWidget* parent = nullptr);
};

#endif // SLIDERPROPERTYCONTROLLER_H
