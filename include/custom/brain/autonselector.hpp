#pragma once
#include <vector>
#include "custom/brain/auton.hpp"

class AutonSelector {
public:
  std::vector<Auton> Autons;
  int currentAutonPage;
  int autonCount;
  AutonSelector();
  void callSelectedAuton();
  void printSelectedAuton();
  void addAutons(std::vector<Auton> autons);
  void AutonSelector::cycleAutons();
};