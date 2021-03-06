/*
    File:     DoubleCube_NoDelay.ino
    Purpose:  Double Cube pattern for the Freetronics 4x4x4 Cube (non blocking)

    Original Author:   ADA
    This example was contributed by sparky-nz on the Freetronics forums:
    http://forum.freetronics.com/viewtopic.php?f=32&t=5579.

    Modified by:       Adam Reed (adam@secretcode.ninja)
*/

// Include required libraries
#include "Cube.h"
#include "DoubleCube.h"

/*
   User editable variables
*/
// theDelay tracks how long to pause between colour changes
int theDelay = 800;

// Create an instance of the cube class
Cube cube;

// Create an instance of the DoubleCube class
DoubleCube doublecube(cube, theDelay);

void setup(void) {
  // Serial port options for control of the Cube using serial commands are:
  // 0: Control via the USB connector (most common).
  // 1: Control via the RXD and TXD pins on the main board.
  // -1: Don't attach any serial port to interact with the Cube.
  cube.begin(0, 115200); // Start on serial port 0 (USB) at 115200 baud

  // Wait for the serial interface, to be established, or for a maximum of
  // 3 seconds.
  byte waitCounter = 0;
  while (waitCounter < 30 && !Serial) {
    delay(100);
    waitCounter++;
  }

  // Print Debug Info if a serial interface is present
  if (Serial)
  {
    serial->println("DoubleCube v1.0 (non-blocking)");
  }
}

void loop(void) {
  doublecube.update();
}

