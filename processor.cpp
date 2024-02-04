#include "processor.h"
#include <iostream>
#include <vector>

Processor::Processor(int x, int y, int correct_result) :
    m_x(x), m_y(y), m_correct_result(correct_result) {
}

void Processor::LDA(int i) {
  m_register_A = std::abs(i) % 16;
}

void Processor::LDB(int i) {
  m_register_B = std::abs(i) % 16;
}

void Processor::SHLA() {
  m_register_A = (m_register_A << 1) % 16;
}

void Processor::SHRA() {
  m_register_A = m_register_A >> 1;
}

void Processor::MAB() {
  m_register_B = m_register_A;
}

void Processor::ADDAB() {
  m_register_A += m_register_B;
  if (m_register_A > 15) {
    m_register_A -= 16;
    m_carry = true;
  } else {
    m_carry = false;
  }
}


void Processor::NOTA() {
  m_register_A = 15 - m_register_A;
}

void Processor::JC(int i) {
  if (m_carry) {
    m_pc = std::abs(i % 16);
  }
}

void Processor::start() {
  while (m_pc < 16) {
    // TODO: MODIFY BELOW SWITCH CASES, LEAVE UNUSED CASES AS IS
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
        JC(5); // Jump to case/'address' 5 in next iteration if carry is set
        break;
      case 4:
        SHLA();
        break;
      case 5:
        SHRA();
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
        throw std::runtime_error("Invalid memory address");
    }
    ++m_pc;
  }

  // Register B needs to contain the correct result per the specification
  if (m_register_B != m_correct_result) {
    std::cout << "INCORRECT. ";
  }
  std::cout << "RegB: " << m_register_B
            << ", res: " << m_correct_result
            << ", X:" << m_x
            << ", Y:" << m_y << '\n';
}
