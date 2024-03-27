#include "Robot/Robot.h"

using namespace Robot;

std::map<std::string, std::function<void()>> Robot::checkpoint4 = {
    {
        "(a) wait for CdS Cell",
        []() {
            while (CdS_cell.Value() > 2.5);
        },
    },
    {
        "(b) nav to ramp",
        []() {
            driveInches(4.5);
            turnDegrees(-30);
            driveInches(5.0);
            turnDegrees(-10);

            driveInches(8);
        },
    },
    {
        "(c) drive up ramp",
        []() {
            driveInches(16, 6.5, 0.7, 0.06, 0.06);
        },
    },
    {
        "(d) nav to stamp",
        []() {
            turnDegrees(-45);
            driveInches(9.5);
            turnDegrees(45);
            driveInches(8);
            driveInches(-8);
        },
    },
};

std::map<std::string, std::function<void()>> Robot::checkpoint5 = {
    {
        "(a) wait for CdS Cell",
        []() {
            while (CdS_cell.Value() > 2.5);
        },
    },
    {
        "(b) nav to ramp",
        []() {
            driveInches(4.5);
            turnDegrees(-30);
            driveInches(5.0);
            turnDegrees(-10);  // was 10

            driveInches(8);
        },
    },
    {
        "(c) drive up ramp",
        []() {
            driveInches(16, 6.5, 0.7, 0.06, 0.06);
        },
    },
    {
        "(d) nav to luggage",
        []() {
            turnDegrees(-45);
            driveInches(22);
            turnDegrees(-45);
            turnDegrees(-45);
            turnDegrees(-45);
            driveInches(20, 7.5);
        },

    },
};
