/*
#include "custom/mechs/pid.hpp"

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}


void PID::resetVariables() {
  output = 0;
  target = 0;
  error = 0;
  prev_error = 0;
  integral = 0;
  time = 0;
  prev_time = 0;
}

PID::PID() {
  resetVariables();
  setConstants(0, 0, 0, 0);
}

PID::Constants PID::getConstants() { return constants; }

// PID constructor with constants
PID::PID(double p, double i, double d, double start_i, std::string name) {
  resetVariables();
  setConstants(p, i, d, start_i);
  setName(name);
}

// Set PID constants
void PID::setConstants(double p, double i, double d, double p_start_i) {
  constants.kp = p;
  constants.ki = i;
  constants.kd = d;
  constants.start_i = p_start_i;
}

// Set exit condition timeouts
void setExitCondition(double exitError, int timeout) {
    exit.exitError = exitError;
    exit.timeout = timeout;
}

void PID::setTarget(double input) { target = input; }

double PID::getTarget() { return target; }

double PID::compute(double current) {
  error = target - current;
  derivative = error - prev_error;

  if (constants.ki != 0) {
    if (fabs(error) < constants.start_i)
      integral += error;

    if (sgn(error) != sgn(prev_error))
      integral = 0;
  }

  output = (error * constants.kp) + (integral * constants.ki) + (derivative * constants.kd);

  prev_error = error;

  return output;
}

void PID::reset_timers() {
  i = 0;
  k = 0;
  j = 0;
  l = 0;
}

void PID::set_name(std::string p_name) {
  name = p_name;
}

exit_output PID::exit_condition(bool print) {

  // If the robot gets within the target, make sure it's there for small_timeout amount of time
  if (exit.small_error != 0) {
    if (abs(error) < exit.small_error) {
      j += util::DELAY_TIME;
      i = 0;  // While this is running, don't run big thresh
      if (j > exit.small_exit_time) {
        reset_timers();
        if (print) print_exit(SMALL_EXIT);
        return SMALL_EXIT;
      }
    } else {
      j = 0;
    }
  }

  // If the robot is close to the target, start a timer.  If the robot doesn't get closer within
  // a certain amount of time, exit and continue.  This does not run while small_timeout is running
  if (exit.big_error != 0 && exit.big_exit_time != 0) {  // Check if this condition is enabled
    if (abs(error) < exit.big_error) {
      i += util::DELAY_TIME;
      if (i > exit.big_exit_time) {
        reset_timers();
        if (print) print_exit(BIG_EXIT);
        return BIG_EXIT;
      }
    } else {
      i = 0;
    }
  }

  // If the motor velocity is 0,the code will timeout and set interfered to true.
  if (exit.velocity_exit_time != 0) {  // Check if this condition is enabled
    if (abs(derivative) <= 0.05) {
      k += util::DELAY_TIME;
      if (k > exit.velocity_exit_time) {
        reset_timers();
        if (print) print_exit(VELOCITY_EXIT);
        return VELOCITY_EXIT;
      }
    } else {
      k = 0;
    }
  }

  return RUNNING;
}

exit_output PID::exit_condition(pros::Motor sensor, bool print) {
  // If the motors are pulling too many mA, the code will timeout and set interfered to true.
  if (exit.mA_timeout != 0) {  // Check if this condition is enabled
    if (sensor.is_over_current()) {
      l += util::DELAY_TIME;
      if (l > exit.mA_timeout) {
        reset_timers();
        if (print) print_exit(mA_EXIT);
        return mA_EXIT;
      }
    } else {
      l = 0;
    }
  }

  return exit_condition(print);
}

exit_output PID::exit_condition(std::vector<pros::Motor> sensor, bool print) {
  // If the motors are pulling too many mA, the code will timeout and set interfered to true.
  if (exit.mA_timeout != 0) {  // Check if this condition is enabled
    for (auto i : sensor) {
      // Check if 1 motor is pulling too many mA
      if (i.is_over_current()) {
        is_mA = true;
        break;
      }
      // If all of the motors aren't drawing too many mA, keep bool false
      else {
        is_mA = false;
      }
    }
    if (is_mA) {
      l += util::DELAY_TIME;
      if (l > exit.mA_timeout) {
        reset_timers();
        if (print) print_exit(mA_EXIT);
        return mA_EXIT;
      }
    } else {
      l = 0;
    }
  }

  return exit_condition(print);
}


*/