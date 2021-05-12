#ifndef INSTR_h
#define INSTR_h

#include <stdint.h>

/* op = 0x1. special funct. */
// shifts.
#define SLL 	0x0
#define SRL 	0x2
#define SRA 	0x3
#define SLLV 	0x4
#define SRLV 	0x6
#define SRAV 	0x7
// jumps.
#define JR 	0x8
#define JALR	0x9
// syscall.
#define SYSCALL 0xC
// move to-from lo-hi
#define MFHI	0x10
#define MTHI	0x11
#define MFLO	0x12
#define MTLO	0x13
// arithmetic & logic.
#define MULT	0x18
#define MULTU	0x19
#define DIV	0x1A
#define DIVU	0x1B
#define ADD	0x20
#define ADDU 	0x21
#define SUB	0x22
#define SUBU	0x23
#define AND	0x24
#define OR 	0x25
#define XOR	0x26
#define NOR	0x27
#define SLT	0x2A
#define SLTU	0x2B

/* op = 0x1. special rt. */
// special branches.
#define BLTZ	0x0
#define BGEZ	0x1
#define BLTZAL	0x10
#define BGEZAL	0x11

/* special op. */
// jumps.
#define J	0x2
#define JAL	0x3
// branches.
#define BEQ	0x4
#define BNE	0x5
#define BLEZ	0x6
#define BGTZ	0x7
// arithmetic & logic.
#define ADDI	0x8
#define ADDIU	0x9
#define SLTI	0xA
#define SLTIU	0xB
#define ANDI	0xC
#define ORI	0xD
#define XORI	0xE
#define LUI	0xF
// memory load-store.
#define LB	0x20
#define LH	0x21
#define LW	0x23
#define LBU	0x24
#define LHU	0x25
#define SB	0x28
#define SH 	0x29
#define SW	0x2B

void nop();
/* R-Type arithmetical and logical */
// logical
void sll(uint8_t rt, uint8_t rd, uint8_t shamt);
void srl(uint8_t rt, uint8_t rd, uint8_t shamt);
void sra(uint8_t rt, uint8_t rd, uint8_t shamt);
void sllv(uint8_t rs, uint8_t rt, uint8_t rd);
void srlv(uint8_t rs, uint8_t rt, uint8_t rd);
void srav(uint8_t rs, uint8_t rt, uint8_t rd);

void and(uint8_t rs, uint8_t rt, uint8_t rd);
void or(uint8_t rs, uint8_t rt, uint8_t rd);
void xor(uint8_t rs, uint8_t rt, uint8_t rd); 
void nor(uint8_t rs, uint8_t rt, uint8_t rd);
// arithmetic
void add(uint8_t rs, uint8_t rt, uint8_t rd);
void addu(uint8_t rs, uint8_t rt, uint8_t rd);
void sub(uint8_t rs, uint8_t rt, uint8_t rd);
void subu(uint8_t rs, uint8_t rt, uint8_t rd);
void mult(uint8_t rs, uint8_t rt);
void multu(uint8_t rs, uint8_t rt);
void div(uint8_t rs, uint8_t rt);
void divu(uint8_t rs, uint8_t rt);
// conditional
void slt(uint8_t rs, uint8_t rt, uint8_t rd);
void sltu(uint8_t rs, uint8_t rt, uint8_t rd);

/* R-Type jumps */
void jr(uint8_t rs);
void jalr(uint8_t rs, uint8_t rd);

/* R-Type lo-hi */
void mfhi(uint8_t rd);
void mflo(uint8_t rd);
void mthi(uint8_t rs);
void mtlo(uint8_t rs);

void syscall();

/* I-Type special branches */
void bltz(uint8_t rs, int16_t offset);
void bgez(uint8_t rs, int16_t offset);
void bltzal(uint8_t rs, int16_t offset);
void bgezal(uint8_t rs, int16_t offset);

/* I-Type arithmetic */
void addi(uint8_t rs, uint8_t rt, int16_t imm); 
void addiu(uint8_t rs, uint8_t rt, int16_t imm);
void slti(uint8_t rs, uint8_t rt, int16_t imm);
void sltiu(uint8_t rs, uint8_t rt, int16_t imm);
void andi(uint8_t rs, uint8_t rt, int16_t imm);
void ori(uint8_t rs, uint8_t rt, int16_t imm);
void xori(uint8_t rs, uint8_t rt, int16_t imm);
void lui(uint8_t rt, int16_t imm);

/* I-Type branches */
void beq(uint8_t rs, uint8_t rt, int16_t imm);
void bne(uint8_t rs, uint8_t rt, int16_t imm);
void blez(uint8_t rs, int16_t imm);
void bgtz(uint8_t rs, int16_t imm);


/* J-Type jumps */
void j(uint32_t target);
void jal(uint32_t target);


/* Memory load-store */ 
void lb(uint8_t base, uint8_t rt, int16_t imm);
void lh(uint8_t base, uint8_t rt, int16_t imm);
void lw(uint8_t base, uint8_t rt, int16_t imm);
void lbu(uint8_t base, uint8_t rt, int16_t imm);
void lhu(uint8_t base, uint8_t rt, int16_t imm);
void sb(uint8_t base, uint8_t rt, int16_t imm);
void sh(uint8_t base, uint8_t rt, int16_t imm);
void sw(uint8_t base, uint8_t rt, int16_t imm);

#endif
