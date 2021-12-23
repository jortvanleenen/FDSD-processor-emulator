#ifndef FDSD_EMULATOR_PROCESSOR_H
#define FDSD_EMULATOR_PROCESSOR_H

/**
 * A simple 4-bit processor that can simulate the one built in FDSD Task 5.
 */
class Processor {
public:
  Processor(int x, int y);

  void start();

private:
  // Input values X and Y
  int m_x{0};
  int m_y{0};
  // The expression the processor should calculate, needs to be set MANUALLY
  // in the constructor
  int m_correct_result{0};
  // The contents of 4-bit registers A and B (0-15)
  int m_register_A{0};
  int m_register_B{0};
  // The current memory address the Program Counter (PC) is pointing to
  int m_pc{0};
  // Whether a carry has occurred during addition (ADDAB)
  bool m_carry{false};

  void LDA(int i);

  void LDB(int i);

  void SHLA();

  void SHRA();

  void MAB();

  void ADDAB();

  void NOTA();

  void JC(int i);
};

#endif
