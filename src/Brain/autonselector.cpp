#include "custom/brain/autonselector.hpp"

AutonSelector::AutonSelector() {
  autonCount = 0;
  currentAutonPage = 0;
  Autons = {};
}

void AutonSelector::callSelectedAuton() {
  if (autonCount == 0) return;
  void (*Autons[currentAutonPage])();
}

void AutonSelector::addAutons(std::vector<Auton> autons) {
  autonCount = autons.size();
  currentAutonPage = 0;
  Autons.assign(autons.begin(), autons.end());
}