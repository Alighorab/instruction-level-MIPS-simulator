#ifndef SIM_h
#define SIM_h

#include <stdint.h>

void rtype(uint8_t rs, uint8_t rt, uint8_t rd, uint8_t shamt, uint8_t funct);
void itype(uint8_t op, uint8_t rs, uint8_t rt, int16_t imm);
void jtype(uint8_t op, uint32_t target);

/* R-Type arithmetical and logical categories */
void shifts(uint8_t rt, uint8_t rd, uint8_t shamt, uint8_t funct);
void arithmetic(uint8_t rs, uint8_t rt, uint8_t rd, uint8_t funct);
void logical(uint8_t rs, uint8_t rt, uint8_t rd, uint8_t funct);
void conditional(uint8_t rs, uint8_t rt, uint8_t rd, uint8_t funct);

void rtype_jump(uint8_t rs, uint8_t rd, uint8_t funct);
void rtype_lo_hi(uint8_t rs, uint8_t rd, uint8_t funct);

void itype_sbranches(uint8_t rs, uint8_t rt, int16_t imm);
void itype_arithmetic(uint8_t op, uint8_t rs, uint8_t rt, int16_t imm);
void itype_branches(uint8_t op, uint8_t rs, uint8_t rt, int16_t imm);

void mem_load_store(uint8_t op, uint8_t base, uint8_t rt, int16_t imm);

#endif
