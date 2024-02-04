#include "processor.h"
#include <cmath>
#include <vector>

/**
 * Try all possible 4-bit input combinations to test the processor.
 * Uses standard output for results.
 *
 * @return EXIT_SUCCESS on success
 */
int main() {
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {

      // TODO: DEFINE THE CORRECT CALCULATION HERE
      int correct_calculation{std::abs(x / 2 - y)};

      Processor processor{x, y, correct_calculation};
      processor.start(); // 'starts the clock'
    }
  }
  return EXIT_SUCCESS;
}
