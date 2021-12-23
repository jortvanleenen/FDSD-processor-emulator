# 4-bit processor emulation
## About
The primary goal of this repository is the emulation of a 4-bit processor built for the course 'Fundamentals of 
Digital Systems Design' of the LU. It aims to provide its users with an easy way of implementing a serie of 
instructions, which result can then be tested and verified.
## Get started
**Step 1.** Clone the repository to your machine and ensure its compilable and runnable.

**Step 2.** Open 'processor.cpp' and in the constructor, change the expression setting the 'm_correct_result' 
variable to the expression you wish to calculate and test for.
**Step 3.** Within 'processor.cpp' go to the implementation of start(). Each case of the switch-statement represents an 
instruction, with a maximum of 16 (0-15) instructions in total. Change each case to one of the existing instructions, 
or leave it blank to do nothing.
| Instruction name | Description |
|------------------|-------------|
| LDA #value       | Moves the value to register A |
| LDB #value       | Moves the value to register B |
| SHLA             | Shifts the content in register A bitwise one to the left |
| SHRA             | Shifts the content in register A bitwise one to the right |
| MAB              | Overrides the content of register B with the content in register A |
| ADDAB            | Adds the contents of register A and B and stores the result in register A.
A carry flag is set when a carry-out would occur |
| NOTA             | Complements the content in register A |
| JC #value        | Sets the current instruction of the PC to 'i' when a carry has occurred |