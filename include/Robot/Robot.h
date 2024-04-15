#ifndef ROBOT_H
#define ROBOT_H

// Custom libraries
#include "Robot/PID.h"

// FEH libraries
#include <FEHLCD.h>
#include <FEHUtility.h>

#ifdef SIMULATOR
#include "Robot/DummyFEH.h"
#else
#include <FEHIO.h>
#include <FEHMotor.h>
#include <FEHRCS.h>
#endif

// std libraries
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <string>

constexpr float DEG_15 = 30;
constexpr float DEG_30 = 68;
constexpr float DEG_45 = 105;
constexpr float DEG_60 = 140;
constexpr float DEG_90 = 211;

constexpr float COUNTS_PER_REV = 318.0;
constexpr float WHEEL_RADIUS = 1.5;
constexpr int dSAMPLE_RATE = 50;  // Default sample rate

// Default PID constants
constexpr float dKp = 0.8;
constexpr float dKi = 0.02;
constexpr float dKd = 0.08;

// Default motor speeds
constexpr float DEFAULT_LINEAR_VELOCITY = 6.5;
constexpr float DEFAULT_TURN_VELOCITY = 4.0;
constexpr float DEFAULT_MOTOR_PERCENT = 25.0;

namespace Robot {

// Electronics references
extern FEHMotor drive_R;
extern FEHMotor drive_L;
extern DigitalEncoder encoder_R;
extern DigitalEncoder encoder_L;
extern AnalogInputPin CdS_cell;

extern DigitalInputPin bump_L;  // 0_1
extern DigitalInputPin bump_R;  // 1_1

// Control methods
void driveRamp(
    float inches,
    float velocity = 5.5,
    float Kp = dKp,
    float Ki = dKi,
    float Kd = dKd,
    int sample_rate = dSAMPLE_RATE);

float driveInches(
    float inches,
    float velocity = DEFAULT_LINEAR_VELOCITY,
    float Kp = dKp,
    float Ki = dKi,
    float Kd = dKd,
    int sample_rate = dSAMPLE_RATE,
    bool light_break = false);

void turnCounts(
    float counts,
    float velocity = DEFAULT_TURN_VELOCITY,
    float Kp = dKp,
    float Ki = dKi,
    float Kd = dKd,
    int sample_rate = dSAMPLE_RATE);

void processSequence(std::map<std::string, std::function<void()>> sequence);

// Control sequences
extern std::map<std::string, std::function<void()>> checkpoint4;
extern std::map<std::string, std::function<void()>> checkpoint5;
extern std::map<std::string, std::function<void()>> example;

};  // namespace Robot

#endif  // ROBOT_H
