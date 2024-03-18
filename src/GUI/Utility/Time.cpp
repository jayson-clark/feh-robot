#include "GUI/Utility/Time.h"

DeltaTime DeltaTime::fromMinutes(float minutes) {
    DeltaTime dt;

    dt.minutes = minutes;
    dt.seconds = minutes * 60;
    dt.milliseconds = dt.seconds * 1000;

    return dt;
}

DeltaTime DeltaTime::fromSeconds(float seconds) {
    DeltaTime dt;

    dt.seconds = seconds;
    dt.minutes = seconds / 60.0;
    dt.milliseconds = dt.seconds * 1000;

    return dt;
}

DeltaTime DeltaTime::fromMilliseconds(float milliseconds) {
    DeltaTime dt;

    dt.milliseconds = milliseconds;
    dt.seconds = milliseconds / 1000.0;
    dt.minutes = dt.seconds / 60.0;

    return dt;
}
