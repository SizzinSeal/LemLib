#include "lemlib/util.hpp"
#include <cmath>

namespace lemlib {
ExpoDriveCurve::ExpoDriveCurve(float upperLimit, float lowerLimit, float minOutput, float curve)
    : upperLimit(upperLimit),
      lowerLimit(lowerLimit),
      minOutput(minOutput),
      curveGain(curve) {}

float ExpoDriveCurve::curve(float input) {
    // return 0 if input is within deadzone
    if (input >= 0 && input <= upperLimit) return 0;
    if (input <= 0 && input >= -lowerLimit) return 0;
    // g is the output of g(x) as defined in the Desmos graph
    const float gu = fabs(input) - upperLimit;
    const float gl = fabs(input) - lowerLimit;
    // g127 is the output of g(127) as defined in the Desmos graph
    const float gu127 = 127 - upperLimit;
    const float gl127 = 127 - lowerLimit;
    // i is the output of i(x) as defined in the Desmos graph
    const float iu = pow(curveGain, gu - 127) * gu * sgn(input);
    const float il = pow(curveGain, gl - 127) * gl * sgn(input);
    // i127 is the output of i(127) as defined in the Desmos graph
    const float iu127 = pow(curveGain, gu127 - 127) * gu127;
    const float il127 = pow(curveGain, gl127 - 127) * gl127;
    if (input > 0) return (127.0 - minOutput) / (127) * iu * 127 / iu127 + minOutput * sgn(input);
    else return (127.0 - minOutput) / (127) * il * 127 / il127 + minOutput * sgn(input);
}
} // namespace lemlib