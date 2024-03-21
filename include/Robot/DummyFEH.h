#ifndef DUMMY_FEH
#define DUMMY_FEH

#include <FEHUtility.h>

#include <chrono>
#include <cmath>
#include <iostream>
#include <random>

// Forward declaration for FEHMotor to be used in DigitalEncoder
class FEHMotor;

// FEHMotor class definition
class FEHMotor {
   public:
    enum FEHMotorPort { Motor0 = 0, Motor1, Motor2, Motor3 };

    FEHMotor(FEHMotorPort motorport, float max_voltage);
    void Stop();
    void SetPercent(float percent);

    float percent = 0.0f;

   private:
    FEHMotorPort port;
};

// FEHIO class definitionz
class FEHIO {
   public:
    enum FEHIOPin {
        P0_0 = 0,
        P0_1,
        P0_2,
        P0_3,
        P0_4,
        P0_5,
        P0_6,
        P0_7,
        P1_0,
        P1_1,
        P1_2,
        P1_3,
        P1_4,
        P1_5,
        P1_6,
        P1_7,
        P2_0,
        P2_1,
        P2_2,
        P2_3,
        P2_4,
        P2_5,
        P2_6,
        P2_7,
        P3_0,
        P3_1,
        P3_2,
        P3_3,
        P3_4,
        P3_5,
        P3_6,
        P3_7,
        BATTERY_VOLTAGE
    };
};

// DigitalInputPin class definition
class DigitalInputPin {
   public:
    explicit DigitalInputPin(FEHIO::FEHIOPin pin);
    bool Value();
};

// AnalogInputPin class definition
class AnalogInputPin {
   public:
    explicit AnalogInputPin(FEHIO::FEHIOPin pin);
    float Value();
};

// DigitalEncoder class definition
class DigitalEncoder {
   public:
    explicit DigitalEncoder(FEHIO::FEHIOPin pin, FEHMotor* motor);
    void UpdateCounts();
    float Counts();
    void ResetCounts();

   private:
    std::chrono::time_point<std::chrono::high_resolution_clock> prevTime;
    int counts = 0;
    float countsPerSecond;
    FEHMotor* motor;
};

// FEHRCS class definition
class FEHRCS {
   public:
    FEHRCS();
    void InitializeTouchMenu(const char* team_key);
    unsigned char CurrentCourse();
    char CurrentRegionLetter();
    int Time();
    int GetCorrectLever();

   private:
    int _region;
};

extern FEHRCS RCS;

#endif  // DUMMY_FEH
