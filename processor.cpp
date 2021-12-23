#include <iostream>
#include "processor.h"

Processor::Processor(int x, int y) {
  m_x = x;
  m_y = y;
  // Set this MANUALLY to the desired expression
  m_correct_result = abs(m_x / 2 - m_y);
}

/**
  * Overrides the content in register A with the value of 'i' between 0-15.
  *
  * @param i the new value register A should hold
  */
void Processor::LDA(int i) {
  m_register_A = abs(i % 16);
}

/**
  * Overrides the content in register B with the value of 'i' between 0-15.
  *
  * @param i the new value register B should hold
  */
void Processor::LDB(int i) {
  m_register_B = abs(i % 16);
}

/**
 * Shifts the content in register A bitwise one to the left.
 */
void Processor::SHLA() {
  m_register_A = (m_register_A << 1) % 16;
}

/**
 * Shifts the content in register A bitwise one to the right.
 */
void Processor::SHRA() {
  m_register_A = m_register_A >> 1;
}

/**
 * Overrides the content of register B with the content in register A.
 */
void Processor::MAB() {
  m_register_B = m_register_A;
}

/**
 * Adds the contents of register A and B and stores the result in register A.
 * A carry flag is set when a carry-out would occur.
 */
void Processor::ADDAB() {
  m_register_A += m_register_B;
  if (m_register_A > 15) {
    m_register_A -= 16;
    m_carry = true;
  } else {
    m_carry = false;
  }
}

/**
 * Complements the content in register A.
 */
void Processor::NOTA() {
  m_register_A = 15 - m_register_A;
}

/**
 * Sets the current instruction of the PC to 'i' when a carry has occurred.
 *
 * @param i the instruction that needs to be jumped to
 */
void Processor::JC(int i) {
  if (m_carry) {
    m_pc = abs(i % 16) - 1;
  }
}

/**
 * This function can be seen as the Program Counter (PC) iterating through the
 * the content/memory addresses of the ROM16X7. Each case represents a single
 * instruction, with a maximum of 16 instructions (0-15) stored.
 */
void Processor::start() {
  while (m_pc < 17) {
    switch (m_pc) {
      case 0:
        LDA(m_x);
        break;
      case 1:
        LDB(m_y);
        break;
      case 2:
        ADDAB();
        break;
      case 3:
        JC(5); // Jumps to case 5 in next iteration if carry flag is set
        break;
      case 4:
        SHRA();
        break;
      case 5:
        SHLA();
        break;
      case 6:
        NOTA();
        break;
      case 7:
        MAB();
        break;
      case 8:
        break;
      case 9:
        break;
      case 10:
        break;
      case 11:
        break;
      case 12:
        break;
      case 13:
        break;
      case 14:
        break;
      case 15:
        break;
      default:
        break;
    }

    m_pc++;
  }

  if (m_register_B != m_correct_result) {
    std::cout << "INCORRECT. ";
  }
  std::cout << "RegB: " << m_register_B << ", res: " << m_correct_result
            << ", X:" << m_x << ", Y:" << m_y << '\n';
}
