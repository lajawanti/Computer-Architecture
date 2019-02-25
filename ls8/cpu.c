
#include "cpu.h"

#define DATA_LEN 6
/*In `cpu.c`, add functions `cpu_ram_read()` and `cpu_ram_write()` that access the
RAM inside the `struct cpu`.*/
unsigned char cpu_ram_read(struct cpu *cpu, unsigned char index)
{
      //To READ RAM which is an array of memory addresses so to access memory we need index value
      return cpu->ram[index];
}

void cpu_ram_write(struct cpu *cpu, unsigned char index, unsigned char value) 
{
      //To WRITE IN RAM 
         /* - need to access ram of particular index where to write
            - and value -- data to be written */
      cpu->ram[index] = value;
}

/**
 * Load the binary bytes from a .ls8 source file into a RAM array
 */
void cpu_load(struct cpu *cpu)
{
  char data[DATA_LEN] = {
    // From print8.ls8
    0b10000010, // LDI R0,8
    0b00000000,
    0b00001000,
    0b01000111, // PRN R0
    0b00000000,
    0b00000001  // HLT
  };

  int address = 0;

  for (int i = 0; i < DATA_LEN; i++) {
    cpu->ram[address++] = data[i];
  }

  // TODO: Replace this with something less hard-coded
}

/**
 * ALU
 */
void alu(struct cpu *cpu, enum alu_op op, unsigned char regA, unsigned char regB)
{
  switch (op) {
    case ALU_MUL:
      // TODO
      break;

    // TODO: implement more ALU ops
  }
}

/**
 * Run the CPU
 */
void cpu_run(struct cpu *cpu)
{
    int running = 1; // True until we get a HLT instruction

    while (running) {
        // TODO
        // 1. Get the value of the current instruction (in address PC).
        unsigned char IR = cpu_ram_read(cpu, cpu->PC); //Instruction Register
        
        // 2. Figure out how many operands this next instruction requires
        // 3. Get the appropriate value(s) of the operands following this instruction
        unsigned char operandA = cpu_ram_read(cpu, (cpu->PC + 1));
        unsigned char operandB = cpu_ram_read(cpu, (cpu->PC + 2));
        
        // 4. switch() over it to decide on a course of action.
        switch (IR)
        {
            case 'ADD':
              break;
          
            default:
              break;
        }
        // 5. Do whatever the instruction should do according to the spec.
        // 6. Move the PC to the next instruction.
    }
}

/**
 * Initialize a CPU struct
 */
/*The `cpu_init()` function takes a pointer to a `struct cpu` and initializes it
as necessary. At first, the PC, registers, and RAM should be cleared to zero.
(`memset()` might help you clear registers and RAM.)

Later on, you might do further initialization here, e.g. setting the initial
value of the stack pointer.*/

void cpu_init(struct cpu *cpu)
{
      // TODO: Initialize the PC and other special registers
      cpu->PC = 0;
      //The C library function void *memset(void *str, int c, size_t n)
      memset(cpu->reg, 0, sizeof(cpu->reg));
      memset(cpu->ram, 0, sizeof(cpu->ram));
}
