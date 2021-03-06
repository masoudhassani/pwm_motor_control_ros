#ifndef JOYSTICK_AXIS_TRANSFORMER_H
#define JOYSTICK_AXIS_TRANSFORMER_H

#include <algorithm>
#include <cstddef>

namespace joystick_interpreter {

constexpr float THESHOLD_PRESSED = 0.01F;

struct Range
{
    float min;
    float max;
};

class JoystickAxisTransformer
{
public:
    JoystickAxisTransformer();
    JoystickAxisTransformer(const Range input_range, const Range ouput_range);

    float TransformInput(const float input_value) const;
    bool IsPressed(const float input_value) const;

    void SetAxisOutputRange(const float min_value, const float max_value);
    void SetAxisInputRange(const float min_value, const float max_value);

    const Range GetAxisOutputRange() const;
    const Range GetAxisInputRange() const;
 
private:
    void CalculateSlopeParamter();

    Range output_range_{0.0F, 1.0F};
    Range input_range_{0.0F, 1.0F};

    float param_slope_;
};

}

#endif
