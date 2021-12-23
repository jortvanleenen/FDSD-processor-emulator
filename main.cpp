#include "processor.h"
#include <iostream>

/**
 * Tries all possible 4-bit input combinations to test the processor.
 *
 * @return EXIT_SUCCESS on success
 */
int main() {
  for (int x = 0; x < 16; x++) {
    for (int y = 0; y < 16; y++) {
      Processor processor{x, y};
      // 'starts the clock'
      processor.start();
    }
  }
  return EXIT_SUCCESS;
}
