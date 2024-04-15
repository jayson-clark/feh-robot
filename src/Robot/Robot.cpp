#include "Robot/Robot.h"

using namespace Robot;

//
// Electronic references
//

FEHMotor Robot::drive_L(FEHMotor::Motor0, 9.0);
FEHMotor Robot::drive_R(FEHMotor::Motor2, 9.0);

DigitalInputPin Robot::bump_L(FEHIO::P0_1);
DigitalInputPin Robot::bump_R(FEHIO::P1_1);

AnalogInputPin Robot::CdS_cell(FEHIO::P1_7);

#ifdef SIMULATOR
// Simulated encoders get a reference to motors for variable count speed
DigitalEncoder Robot::encoder_R(FEHIO::P1_0, &drive_R);
DigitalEncoder Robot::encoder_L(FEHIO::P0_0, &drive_L);
#else
DigitalEncoder Robot::encoder_R(FEHIO::P1_0);
DigitalEncoder Robot::encoder_L(FEHIO::P0_0);
#endif

//
// Control methods
//

void Robot::driveRamp(
    float inches,
    float velocity,
    float Kp,
    float Ki,
    float Kd,
    int sample_rate) {
    // Multiplier to control direction of drive
    int mult = (inches < 0) ? -1 : 1;

    // Calculate desired number of counts for each encoder
    float desiredCounts =
        (mult * inches * COUNTS_PER_REV) / (2.0 * M_PI * WHEEL_RADIUS);

    // Ensure motors are stopped
    drive_L.Stop();
    drive_R.Stop();
    Sleep(250);

    // Initialize controllers
    PIDController left_controller(Kp, Ki, Kd, velocity, drive_L, encoder_L);
    PIDController right_controller(Kp, Ki, Kd, velocity, drive_R, encoder_R);

    left_controller.ResetPIDVariables();
    right_controller.ResetPIDVariables();

    // Variables to hold the previous counts for checking stall condition
    int lastLeftCounts = encoder_L.Counts();
    int lastRightCounts = encoder_R.Counts();

    // Start the motors
    drive_L.SetPercent(mult * DEFAULT_MOTOR_PERCENT);
    drive_R.SetPercent(mult * DEFAULT_MOTOR_PERCENT);

    Sleep(200);

    float prevUpdateTime = TimeNow();

    // Control loop
    while ((encoder_L.Counts() + encoder_R.Counts()) / 2.0 < desiredCounts) {
        if (TimeNow() - prevUpdateTime > sample_rate / 1000.0) {
            // Check for stalled wheel (encoder not counting)
            // if ((encoder_L.Counts() - lastLeftCounts < 5) ||
            //     (encoder_R.Counts() - lastRightCounts < 5)) {
            //     LCD.WriteLine("Stalled wheel detected.");
            //     break;  // Exit the loop if a wheel is stalled
            // // }

            // lastLeftCounts = encoder_L.Counts();
            // lastRightCounts = encoder_R.Counts();

            // Apply PID adjustments to motor speed
            float perc = left_controller.PIDAdjustment();
            LCD.WriteLine(perc);
            drive_L.SetPercent(mult * perc);
            drive_R.SetPercent(mult * right_controller.PIDAdjustment());

            prevUpdateTime = TimeNow();
        }
    }

    // Stop the motors
    drive_L.Stop();
    drive_R.Stop();
    Sleep(250);
}

float Robot::driveInches(
    float inches,
    float velocity,
    float Kp,
    float Ki,
    float Kd,
    int sample_rate,
    bool light_break) {
    // Multiplier to control direction of drive
    int mult = (inches < 0) ? -1 : 1;

    // Calculate desired number of counts for each encoder
    float desiredCounts =
        (mult * inches * COUNTS_PER_REV) / (2.0 * M_PI * WHEEL_RADIUS);

    // Ensure motors are stopped
    drive_L.Stop();
    drive_R.Stop();
    Sleep(250);

    // Initialize controllers
    PIDController left_controller(Kp, Ki, Kd, velocity, drive_L, encoder_L);
    PIDController right_controller(Kp, Ki, Kd, velocity, drive_R, encoder_R);

    left_controller.ResetPIDVariables();
    right_controller.ResetPIDVariables();

    // Variables to hold the previous counts for checking stall condition
    int lastLeftCounts = encoder_L.Counts();
    int lastRightCounts = encoder_R.Counts();

    // Start the motors
    drive_L.SetPercent(mult * DEFAULT_MOTOR_PERCENT);
    drive_R.SetPercent(mult * DEFAULT_MOTOR_PERCENT);

    Sleep(200);

    float prevUpdateTime = TimeNow();

    float min = 4;

    // Control loop
    while ((encoder_L.Counts() + encoder_R.Counts()) / 2.0 < desiredCounts) {
        //   CDS CELL light break

        float cds_value = CdS_cell.Value();
        if (cds_value < min) min = cds_value;

        if (cds_value < 1.9 && light_break) return min;

        if (TimeNow() - prevUpdateTime > sample_rate / 1000.0) {
            // Check for stalled wheel (encoder not counting)
            if ((encoder_L.Counts() - lastLeftCounts < 3) ||
                (encoder_R.Counts() - lastRightCounts < 3)) {
                LCD.WriteLine("Stalled wheel detected.");
                break;  // Exit the loop if a wheel is stalled
            }

            if (!bump_L.Value() && !bump_R.Value()) {
                LCD.WriteLine("Bump switches activated.");
                break;
            }

            lastLeftCounts = encoder_L.Counts();
            lastRightCounts = encoder_R.Counts();

            // Apply PID adjustments to motor speed
            float perc = left_controller.PIDAdjustment();
            drive_L.SetPercent(mult * perc);
            drive_R.SetPercent(mult * right_controller.PIDAdjustment());

            prevUpdateTime = TimeNow();
        }
    }

    // Stop the motors
    drive_L.Stop();
    drive_R.Stop();
    Sleep(250);

    return min;
}

void Robot::turnCounts(
    float counts,
    float velocity,
    float Kp,
    float Ki,
    float Kd,
    int sample_rate) {
    // Multiplier to control direction of turn
    int mult = (counts < 0) ? -1 : 1;

    // Calculate desired number of counts for each encoder
    float desiredCounts = mult * counts;

    // Initialize controllers
    PIDController left_controller(Kp, Ki, Kd, velocity, drive_L, encoder_L);
    PIDController right_controller(Kp, Ki, Kd, velocity, drive_R, encoder_R);
    left_controller.ResetPIDVariables();
    right_controller.ResetPIDVariables();

    // Variables to hold the previous counts for checking stall condition
    int lastLeftCounts = encoder_L.Counts();
    int lastRightCounts = encoder_R.Counts();

    // Start the motors
    drive_L.SetPercent(mult * DEFAULT_MOTOR_PERCENT);
    drive_R.SetPercent(mult * -DEFAULT_MOTOR_PERCENT);

    float prevUpdateTime = TimeNow();
    // Control loop
    while ((encoder_L.Counts() + encoder_R.Counts()) / 2.0 < desiredCounts) {
        if (TimeNow() - prevUpdateTime > sample_rate / 1000.0) {
            // Apply PID adjustments to motor speed
            drive_L.SetPercent(mult * left_controller.PIDAdjustment());
            drive_R.SetPercent(mult * -right_controller.PIDAdjustment());

            prevUpdateTime = TimeNow();
        }
    }

    // Stop the motors
    drive_L.Stop();
    drive_R.Stop();
    Sleep(300);
}

void Robot::processSequence(
    std::map<std::string, std::function<void()>> sequence) {
    for (const auto &step : sequence) {
        std::cout << "Running step: " << step.first << std::endl;
        step.second();
    }
}
