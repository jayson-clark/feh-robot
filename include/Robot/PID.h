#ifndef PID_H
#define PID_H

#ifdef SIMULATOR
#include "Robot/DummyFEH.h"
#else
#include <FEHIO.h>
#include <FEHMotor.h>
#endif

#include <FEHLCD.h>
#include <FEHUtility.h>

#include <algorithm>
#include <cmath>

// Definitions of constants
constexpr float INCHES_PER_COUNT = (2 * M_PI * 1.5f) / 318.0f;
constexpr float DEFAULT_MOTOR_POWER = 25.0f;
constexpr float MAX_MOTOR_POWER = 50.0f;

// PID Controller structure
struct PIDController {
    float Kp, Ki, Kd, setPoint;
    FEHMotor &motor;
    DigitalEncoder &encoder;

    float sumError, prevError;
    double prevTime;
    int prevCounts;
    float currentMotorPower;

    PIDController(
        float Kp,
        float Ki,
        float Kd,
        float setPoint,
        FEHMotor &motor,
        DigitalEncoder &encoder);

    void ResetPIDVariables();
    float PIDAdjustment();
};

#endif  // PID_H
