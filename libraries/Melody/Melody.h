#pragma once
#include <Arduino.h>

class Melody {
protected:
  int pin;
  int *notes;
  int *durations;
  int length;
  int cur_idx;
  long old_time;
  int note_duration;
  boolean b_play; 
public:
  Melody(int pin, int *notes, int *durations, int length);
  void play();
  void stop();
  int toggle(bool bpause = false);
  void replay();
  int getNote(); // 현재 재생중인 음
  void run(); 
};