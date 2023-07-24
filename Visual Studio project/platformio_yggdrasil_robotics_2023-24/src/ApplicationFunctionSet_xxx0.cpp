#include "DeviceDriverSet_xxx0.h"

extern DeviceDriverSet_Motor AppMotor;

/*Motion Direction Control Sequence*/
enum ConquerorCarMotionControl {
  Forward,       //(1)
  Backward,      //(2)
  Left,          //(3)
  Right,         //(4)
  LeftForward,   //(5)
  LeftBackward,  //(6)
  RightForward,  //(7)
  RightBackward, //(8)
  stop_it        //(9)
};

struct Application_xxx {
  ConquerorCarMotionControl Motion_Control;
};

extern Application_xxx Application_ConquerorCarxxx0;

static void ApplicationFunctionSet_ConquerorCarMotionControl(ConquerorCarMotionControl direction, uint8_t is_speed) {
  static uint8_t directionRecord = 0;
  uint8_t Kp, UpperLimit;
  uint8_t speed = is_speed;

  switch (direction) {
    case Forward:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_just, speed, direction_just, speed, control_enable);
      break;

    case Backward:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_back, speed, direction_back, speed, control_enable);
      break;

    case Left:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_just, speed, direction_back, speed, control_enable);
      break;

    case Right:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_back, speed, direction_just, speed, control_enable);
      break;

    case LeftForward:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_just, speed, direction_just, speed / 2, control_enable);
      break;

    case LeftBackward:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_back, speed, direction_back, speed / 2, control_enable);
      break;

    case RightForward:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_just, speed / 2, direction_just, speed, control_enable);
      break;

    case RightBackward:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_back, speed / 2, direction_back, speed, control_enable);
      break;

    case stop_it:
      //Code here...

      //Parameters: direction_A, speed_A, direction_B, speed_B, controlED
      AppMotor.DeviceDriverSet_Motor_control(direction_void, 0, direction_void, 0, control_enable);
      break;

    default:
      break;
  }
}
