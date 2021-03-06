/*
    File:     FlashingCubes.cpp
    Purpose:  Flashing Cubes pattern for the Freetronics 4x4x4 Cube (non blocking)
    Author:   Adam Reed (adam@secretcode.ninja)
    Licence:  BSD 3-Clause Licence
*/

// Include for Arduino Library
#include <Arduino.h>

// Include for Cube Library
#include "Cube.h"

// Include the header file for this class
#include "FlashingCubes.h"

FlashingCubes::FlashingCubes(Cube cube, int theDelay)
{
  // Retain the reference to the cube
  _cube = cube;

  // Retain the delay we will use
  _theDelay = theDelay;

  // Set the default initial state for the animation
  _state = 1;

  // Set the time we last ran the code to zero as it hasn't run yet
  _previousMillis = 0;
}

void FlashingCubes::update(rgb_t theColour)
{
  // Handles drawing the FlashingCubes animation.

  /* This code is designed to be non blocking, so instead of using
     "delay()", it uses a state machine to track where it is upto in the
     animation. It then uses the time and the difference between this run
     and the last run to determine if it needs to change to a different
     state
  */

  // Get the current time
  unsigned long currentMillis = millis();

  if ((_state == 1) && (currentMillis - _previousMillis >= _theDelay))
  {
    _cube.all(BLACK);
    _cube.box(1, 1, 1, 2, 2, 2, theColour);

    // Remember the time for future reference, and move to the
    // next state
    _previousMillis = currentMillis;
    _state++;
  }
  else if ((_state == 2) && (currentMillis - _previousMillis >= _theDelay))
  {
    _cube.box(0, 0, 0, 3, 3, 3, theColour);

    // Remember the time for future reference, and move to the
    // next state
    _previousMillis = currentMillis;
    _state++;
  }
  else if ((_state == 3) && (currentMillis - _previousMillis >= _theDelay))
  {
    _cube.box(1, 1, 1, 2, 2, 2, BLACK);

    // Remember the time for future reference, and move to the
    // next state
    _previousMillis = currentMillis;
    _state++;
  }
  else if ((_state == 4) && (currentMillis - _previousMillis >= _theDelay))
  {
    _cube.box(0, 0, 0, 3, 3, 3, theColour);

    // Remember the time for future reference, and move to the
    // first state
    _previousMillis = currentMillis;
    _state = 1;
  }
}

