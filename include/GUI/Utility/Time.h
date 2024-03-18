#ifndef TIME_H
#define TIME_H

struct DeltaTime {
  float minutes;
  float seconds;
  float milliseconds;

  static DeltaTime fromMinutes(float minutes);
  static DeltaTime fromSeconds(float seconds);
  static DeltaTime fromMilliseconds(float milliseconds);
};

#endif // TIME_H
