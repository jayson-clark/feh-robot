#include "Robot/Robot.h"

using namespace Robot;

std::map<std::string, std::function<void()>> Robot::checkpoint5 = {
    {
        "(a) RCS",
        []() {
            RCS.InitializeTouchMenu("D62Op8WwL");
        },
    },
    {
        "(b) cds and btn",
        []() {
            while (CdS_cell.Value() > 2.5)
                ;

            driveInches(-3);
        },
    },
    {
        "(c) nav to ramp",
        []() {
            driveInches(3.0);
            turnCounts(DEG_60);

            driveInches(9.0);

            turnCounts(-DEG_15);
        },
    },
    {
        "(d) ramp n square",
        []() {
            driveRamp(20);

            driveInches(5);

            turnCounts(-DEG_90);

            driveInches(-12, 8.5);


            // nAV TO LIGHT
            driveInches(6.0);
            turnCounts(DEG_45);

            driveInches(21.0);
        },
    },
    {
        "(e) SHIMMY",
        []() {
            // If the light isnt found start shimmy
            bool backward = false;
            while (1) {
                bool found_light = false;
                found_light = driveInches(
                    3,
                    DEFAULT_LINEAR_VELOCITY,
                    dKp,
                    dKi,
                    dKd,
                    dSAMPLE_RATE,
                    true);

                if (found_light < 1.9) break;

                turnCounts(-DEG_15);

                found_light = driveInches(
                    -3,
                    DEFAULT_LINEAR_VELOCITY,
                    dKp,
                    dKi,
                    dKd,
                    dSAMPLE_RATE,
                    true);

                if (found_light < 1.9) {
                    backward = true;
                    turnCounts(DEG_15);
                    break;
                };

                turnCounts(DEG_15);
            }

            //
            // EXTRA SHIMMY
            //

            float min = 4;

            drive_L.SetPercent(backward ? -25 : 25);
            drive_R.SetPercent(backward ? -25 : 25);

            float startTime = TimeNow();
            while (TimeNow() - startTime < 0.25) {
                float a = CdS_cell.Value();
                if (a < min) min = a;
            }
            drive_R.Stop();
            drive_L.Stop();

            turnCounts(-DEG_15);

            drive_L.SetPercent(backward ? 25 : -25);
            drive_R.SetPercent(backward ? 25 : -25);

            startTime = TimeNow();
            while (TimeNow() - startTime < 0.35) {
                float a = CdS_cell.Value();
                if (a < min) min = a;
            }
            drive_R.Stop();
            drive_L.Stop();

            turnCounts(DEG_15);

            //
            // End EXTRA SHIMMY
            //

            // Square with corner wall
            float square_cds = driveInches(10);
            if(square_cds < min) min = square_cds;

            // Line up with luggage
            driveInches(-7.25);
            turnCounts(-DEG_90);
            turnCounts(-DEG_45);

            // Deposit
            driveInches(18, 16.0);

            // Face Button
            driveInches(-2);
            turnCounts(-DEG_90);
            turnCounts(-DEG_90);
            if (min < 1.2) {  // Red light
                LCD.WriteLine("red");
                turnCounts(DEG_45);
                driveInches(10.0);
                turnCounts(-DEG_45);
                driveInches(15, 13.0);
            } else {  // blue light
                LCD.WriteLine("blue");
                turnCounts(DEG_15);
                driveInches(11);
                turnCounts(-DEG_15);
                driveInches(15, 13.0);
            }
        },
    },
    {
        "(g) nav to passport",
        []() {
            driveInches(-15);
            turnCounts(DEG_90);
            driveInches(25);

            driveInches(-7.1);
            turnCounts(-DEG_90);
            driveInches(14);
        },
    },
    {
        "(h) lower stamp",
        []() {
            driveInches(-2);

            turnCounts(-DEG_15);
            driveInches(2);
            turnCounts(DEG_30);

            driveInches(-11, 10.0);
        },
    },
    {
        "(i) drive down ramp",
        []() {
            turnCounts(DEG_90);
            turnCounts(-DEG_15);
            driveInches(15.0);
            driveInches(-1);
            turnCounts(DEG_90);

            driveInches(27.25);

            // Square up
            turnCounts(DEG_90);
            driveInches(-6);
        },
    },
    {
        "(j) fueling",
        []() {
            int lever = RCS.GetCorrectLever();

            switch (lever) {
                case 0:
                    driveInches(22.75);
                    turnCounts(-DEG_90);

                    break;
                case 1:
                    driveInches(26);
                    turnCounts(-DEG_90);

                    break;
                case 2:
                    driveInches(50);

                    driveInches(-2);
                    turnCounts(-DEG_60);
                    driveInches(1.5);
                    turnCounts(-DEG_30);

                    break;
            }

            driveInches(7.0);

            float start = TimeNow();
            driveInches(-6.65);
            turnCounts(-DEG_60);
            driveInches(2.15);
            turnCounts(DEG_60);

            while (TimeNow() - start < 5.0)
                ;
            driveInches(6);
        },
    },
    {
        "(k) stop btn",
        []() {
            driveInches(-5);

            turnCounts(-DEG_90);
            driveInches(-30);
            driveInches(13);
            turnCounts(DEG_45);
            driveInches(20);
        },
    },
};
