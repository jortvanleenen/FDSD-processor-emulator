#ifndef FDSD_EMULATOR_PROCESSOR_H
#define FDSD_EMULATOR_PROCESSOR_H

#include <vector>

/**
 * A simple 4-bit processor that can simulate the one built in FDSD Task 5.
 */
class Processor {
public:
  /**
   * Construct a new Processor object.
   *
   * @param x input value X
   * @param y input value Y
   * @param correct_result the correct result of the operation(s) on X and Y
   */
  Processor(int x, int y, int correct_result);

 /**
  * This function can be seen as the Program Counter (PC) iterating through the
  * the content/memory addresses of the ROM16X7. Each case represents a single
  * instruction, with a maximum of 16 instructions (0-15) stored.
  * TODO: in processor.cpp, define the content of each case/memory address.
  */
  void start();

private:
  // Input values X and Y
  int m_x{0};
  int m_y{0};
  // The correct result of the wished operation(s) on X and Y, see main.cpp
  int m_correct_result{0};
  // The contents of 4-bit registers A and B (0-15)
  int m_register_A{0};
  int m_register_B{0};
  // The current memory address the Program Counter (PC) is pointing to (0-15)
  int m_pc{0};
  // Whether a carry has occurred during addition (ADDAB)
  bool m_carry{false};

  /**
   * Overrides the content in register A with the value of 'i' between 0-15.
   *
   * @param i the new value register A should hold
   */
  void LDA(int i);

  /**
   * Overrides the content in register B with the value of 'i' between 0-15.
   *
   * @param i the new value register B should hold
   */
  void LDB(int i);

 /**
  * Shifts the content in register A bitwise one to the left.
  */
  void SHLA();

 /**
  * Shifts the content in register A bitwise one to the right.
  */
  void SHRA();

 /**
  * Overrides the content of register B with the content in register A.
  */
  void MAB();

 /**
  * Adds the contents of register A and B and stores the result in register A.
  * A carry flag is set when a carry-out would occur.
  */
  void ADDAB();

 /**
  * Complements the content in register A.
  */
  void NOTA();

 /**
  * Sets the current instruction of the PC to 'i' when a carry has occurred.
  *
  * @param i the instruction address that needs to be jumped to
  */
  void JC(int i);
};

#endif
