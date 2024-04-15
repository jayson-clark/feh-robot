#include "Robot/PID.h"

PIDController::PIDController(
    float Kp,
    float Ki,
    float Kd,
    float setPoint,
    FEHMotor &motor,
    DigitalEncoder &encoder)
    : Kp(Kp),
      Ki(Ki),
      Kd(Kd),
      setPoint(setPoint),
      motor(motor),
      encoder(encoder),
      sumError(0),
      prevError(0),
      prevTime(TimeNow()),
      prevCounts(encoder.Counts()),
      currentMotorPower(DEFAULT_MOTOR_POWER) {}

void PIDController::ResetPIDVariables() {
    encoder.ResetCounts();

    sumError = prevError = 0;
    prevCounts = encoder.Counts();
    prevTime = TimeNow();
    currentMotorPower = DEFAULT_MOTOR_POWER;
}

float PIDController::PIDAdjustment() {
    float currentCounts = encoder.Counts();
    float deltaCounts = currentCounts - prevCounts;

    float deltaTime = TimeNow() - prevTime;

    // Calculate error
    float linearVelocity = INCHES_PER_COUNT * (deltaCounts / deltaTime);
    float error = setPoint - linearVelocity;
    sumError += error * deltaTime;  // Accumulate error over time

    // Calculate PID terms
    float P = error * Kp;
    float I = sumError * Ki;
    float D = (error - prevError) / deltaTime * Kd;

    // Store values for the next adjustment
    prevError = error;
    prevTime = TimeNow();
    prevCounts = currentCounts;

    // Update the motor power
    currentMotorPower += P + I + D;

    // Ensure motor power is no greater than MAX_MOTOR_POWER
    currentMotorPower = std::max(
        -MAX_MOTOR_POWER, std::min(currentMotorPower, MAX_MOTOR_POWER));

    return currentMotorPower;
}
