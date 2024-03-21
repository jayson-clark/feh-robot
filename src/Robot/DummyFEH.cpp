#include "Robot/DummyFEH.h"

// FEHMotor method implementations

FEHMotor::FEHMotor(FEHMotorPort motorport, float max_voltage)
    : port(motorport) {
    std::cout << "Motor initialized on port: " << motorport
              << " with max voltage: " << max_voltage << std::endl;
}

void FEHMotor::Stop() {
    std::cout << "Motor stopped. (" << port << ")" << std::endl;
}

void FEHMotor::SetPercent(float perc) {
    percent = perc;
    std::cout << "Motor set to: " << percent << "% (" << port << ")"
              << std::endl;
}

// DigitalInputPin method implementations

DigitalInputPin::DigitalInputPin(FEHIO::FEHIOPin pin) {
    std::cout << "Digital input pin initialized: " << pin << std::endl;
}

bool DigitalInputPin::Value() {
    return true;  // Placeholder
}

// AnalogInputPin method function implementation

AnalogInputPin::AnalogInputPin(FEHIO::FEHIOPin pin) {
    std::cout << "Analog input pin initialized: " << pin << std::endl;
}

float AnalogInputPin::Value() { return 0.0; }

// DigitalEncoder method implementations

DigitalEncoder::DigitalEncoder(FEHIO::FEHIOPin pin, FEHMotor* motor)
    : motor(motor) {
    // Initialize a static random device and engine
    static std::random_device rd;
    static std::mt19937 rng(rd());

    // Setup the distribution to generate numbers between 200 and 240
    std::uniform_int_distribution<int> uni(200, 240);

    // Generate the random number and assign it to countsPerSecond
    countsPerSecond = uni(rng);

    // Initialize prevTime
    prevTime = std::chrono::high_resolution_clock::now();
}

void DigitalEncoder::UpdateCounts() {
    auto now = std::chrono::high_resolution_clock::now();
    auto deltaTime = std::chrono::duration<float>(now - prevTime).count();
    int deltaCounts = static_cast<int>(
        countsPerSecond * (motor ? motor->percent / 25.0f : 1.0f) * deltaTime);
    counts += deltaCounts;
    prevTime = now;
}

float DigitalEncoder::Counts() {
    UpdateCounts();
    return counts;
}

void DigitalEncoder::ResetCounts() { counts = 0; }

// FEHRCS method implementations

FEHRCS::FEHRCS() : _region(0) {}

void FEHRCS::InitializeTouchMenu(const char* team_key) {
    std::cout << "Initializing Touch Menu with team key: " << team_key
              << std::endl;
}

unsigned char FEHRCS::CurrentCourse() {
    std::cout << "Getting current course..." << std::endl;
    return 1;  // Simulate being in course A-D
}

char FEHRCS::CurrentRegionLetter() {
    std::cout << "Getting current region letter..." << std::endl;
    return 'A';  // Simulate initialization to region A
}

int FEHRCS::Time() {
    std::cout << "Getting time remaining for match..." << std::endl;
    return 90;  // Simulate 90 seconds left
}

int FEHRCS::GetCorrectLever() {
    std::cout << "Getting correct lever for task..." << std::endl;
    return 0;  // Simulate left lever
}

// Instantiate the RCS object
FEHRCS RCS;
