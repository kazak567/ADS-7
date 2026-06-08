// Copyright 2022 NNTU-CS
#include <iostream>
#include "train.h"

int main() {
  const int wagonCount = 6;

  Train circularTrain;

  // Construct a train with a fixed pattern
  bool pattern[] = {false, true, false, false, true, false};
  for (int i = 0; i < wagonCount; ++i) {
    circularTrain.attachWagon(pattern[i]);
  }

  int computedLength = circularTrain.determineSize();
  int totalMoves = circularTrain.getMoveCount();

  std::cout << "Train length: " << computedLength << std::endl;
  std::cout << "Number of steps: " << totalMoves << std::endl;

  return 0;
}
