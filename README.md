# Instruction-Level MIPS Simulator

## Description
- This project is the first lab of [18-447: Introduction to Computer Architecture - Spring 2015](https://course.ece.cmu.edu/~ece447/s15/doku.php?id=start).
- The task was to create a C program which is an instruction-level simulator for a limited subset of the MIPS instruction set. This instruction-level simulator models the behavior of each instruction, and allows the user to run MIPS programs and see their outputs.
- The simulator processes an input file that contains a MIPS program. Each line of the input file corresponds to a single MIPS instruction written as a hexadecimal string. For example, 2402000a is the hexadecimal representation of addiu $v0, $zero, 10.
- The simulator executes the input program one instruction at a time. After each instruction, the simulator will modify the MIPS architectural state: values stored in registers and memory. The simulator is partitioned into two main sections: the (1) **shell** and the (2) **simulation routine**. My job was to implement the routine.

## The Shell
- The purpose of the shell is to provide the user with commands to control the execution of the simulator. The shell accepts one or more program files as command line arguments and loads them into the memory image. In order to extract information from the simulator, a file named dumpsim will be created to hold information requested from the simulator. The shell supports the following commands:
  1. *go*: simulate the program until it indicates that the simulator should halt. (As we define below, this is when a SYSCALL instruction is executed when the value in $v0 (register 2) is equal to 0x0A.)
  2. *run <n>*: simulate the execution of the machine for n instructions.
  3. *mdump <low> <high>*: dump the contents of memory, from location low to location high to the screen and the dump file (dumpsim).
  4. *rdump*: dump the current instruction count, the contents of R0 – R31, and the PC to the screen and the dump file (dumpsim).
  5. *input reg num reg val*: set general purpose register reg num to value reg val.
  6. *high value*: set the HI register to value.
  7. *low value*: set the LO register to value.
  8. *?*: print out a list of all shell commands.
  9. *quit*: quit the shell.

## The Simulation Routine
- The simulation routine carries out the instruction-level simulation of the input MIPS program. During the execution of an instruction, the simulator should take the current architectural state and modify it according to the ISA description of the instruction in the [*MIPS R4000 User Manual*](https://github.com/Alighorab/instruction-level-MIPS-simulator/blob/main/MIPSISA.pdf) (32-bit mode only) that is provided on the course website. The architectural state includes the PC, the general purpose registers, and the memory image. The state is contained in the global variables apwcified in [*shell.h*](https://github.com/Alighorab/instruction-level-MIPS-simulator/blob/main/src/shell.h)

## My Work
- I've implemented the function *process_instruction()* in [*sim.c*](https://github.com/Alighorab/instruction-level-MIPS-simulator/blob/main/src/sim.c).
- [**Simulator design**](https://github.com/Alighorab/instruction-level-MIPS-simulator/blob/main/MIPS%20simulator.png).

## Lab Files
- In directory src/, there are the simulator files and Makefile to compile them. inputs/ directory contains input files for testing the simulator. I struggeled at first to convert them into hex code, but finally I used Qtspim simulator to convert them amd extracted the log file and modify it to get the hex code. I put these files alse, they're very helpful while debugging the code.
