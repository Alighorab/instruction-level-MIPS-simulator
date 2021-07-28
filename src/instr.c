#include "instr.h"
#include "shell.h"
#include <stdio.h>

void nop() {
	return;
}

void sll(uint8_t rt, uint8_t rd, uint8_t shamt) {	
	if(rt != 0)
		NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] << shamt;
}

void srl(uint8_t rt, uint8_t rd, uint8_t shamt) {
	if(rt != 0)
		NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] >> shamt;
}

void sra(uint8_t rt, uint8_t rd, uint8_t shamt) {
	if(rt != 0)
		NEXT_STATE.REGS[rd] = (int32_t) CURRENT_STATE.REGS[rt] >> shamt;	
}

void sllv(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		uint8_t shamt = CURRENT_STATE.REGS[rs] & 0x1F;
		NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rt] << shamt;
	}
}

void srlv(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		uint8_t shamt = CURRENT_STATE.REGS[rs] & 0x1F;
		NEXT_STATE.REGS[rd] = (int8_t) CURRENT_STATE.REGS[rt] >> shamt;	
	}
}

void srav(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		uint8_t shamt = CURRENT_STATE.REGS[rs] & 0x1F;
		NEXT_STATE.REGS[rd] = (int8_t) CURRENT_STATE.REGS[rt] >> shamt;
	}
}

void and(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] & CURRENT_STATE.REGS[rt];
	}	
}

void or(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] | CURRENT_STATE.REGS[rt];
	}
}

void xor(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] ^ CURRENT_STATE.REGS[rt];
	}
}

void nor(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		NEXT_STATE.REGS[rd] = ~(CURRENT_STATE.REGS[rs] | CURRENT_STATE.REGS[rt]); 
	}
}

void add(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] + CURRENT_STATE.REGS[rt]; 
	}
}

void addu(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) 
		add(rs, rt, rd);
}

void sub(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) 
	NEXT_STATE.REGS[rd] = CURRENT_STATE.REGS[rs] - CURRENT_STATE.REGS[rt];
}

void subu(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) 
		sub(rs, rt, rd);
}

void mult(uint8_t rs, uint8_t rt) {
	int64_t temp = (int32_t) CURRENT_STATE.REGS[rs] * CURRENT_STATE.REGS[rt]; 
	NEXT_STATE.LO = temp;
	NEXT_STATE.HI = (int64_t) temp >> 32;
}

void multu(uint8_t rs, uint8_t rt) {
	uint32_t temp = CURRENT_STATE.REGS[rs] * CURRENT_STATE.REGS[rt];
	NEXT_STATE.LO = temp;
	NEXT_STATE.HI = (int64_t) temp >> 32;
}

void div(uint8_t rs, uint8_t rt) {
	NEXT_STATE.LO = (int32_t) CURRENT_STATE.REGS[rs] / CURRENT_STATE.REGS[rt];
	NEXT_STATE.HI = (int32_t) CURRENT_STATE.REGS[rs] % CURRENT_STATE.REGS[rt];
}

void divu(uint8_t rs, uint8_t rt) {
	NEXT_STATE.LO = CURRENT_STATE.REGS[rs] / CURRENT_STATE.REGS[rt];
	NEXT_STATE.HI = CURRENT_STATE.REGS[rs] % CURRENT_STATE.REGS[rt];
}

void slt(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		if((int32_t) CURRENT_STATE.REGS[rs] < CURRENT_STATE.REGS[rt])
			NEXT_STATE.REGS[rd] = 1;
		else 
			NEXT_STATE.REGS[rd] = 0;
	}
}

void sltu(uint8_t rs, uint8_t rt, uint8_t rd) {
	if(rd != 0) {
		if(CURRENT_STATE.REGS[rs] < CURRENT_STATE.REGS[rt])
			NEXT_STATE.REGS[rd] = 1;
		else 
			NEXT_STATE.REGS[rd] = 0;
	}
}

void jr(uint8_t rs) {
	NEXT_STATE.PC = CURRENT_STATE.REGS[rs] - 4;
}

void jalr(uint8_t rs, uint8_t rd) {
	uint8_t d = rd == 0? 31 : rd;
	NEXT_STATE.REGS[d] = CURRENT_STATE.PC + 4;
	NEXT_STATE.PC = CURRENT_STATE.REGS[rs] - 4;
}

void mfhi(uint8_t rd) {
	if(rd != 0) 
		NEXT_STATE.REGS[rd] = CURRENT_STATE.HI;
}

void mflo(uint8_t rd) {
	if(rd != 0)	
		NEXT_STATE.REGS[rd] = CURRENT_STATE.LO;
}

void mthi(uint8_t rs) {
	NEXT_STATE.HI = CURRENT_STATE.REGS[rs];
}

void mtlo(uint8_t rs) {
	NEXT_STATE.LO = CURRENT_STATE.REGS[rs];
}

void syscall() {
	int32_t buffer = 0;
	switch(CURRENT_STATE.REGS[2]) {
		case 0x1:
			printf("%d", CURRENT_STATE.REGS[4]);
			return;
		case 0x5:		
			scanf("%d", &buffer);
			NEXT_STATE.REGS[2] = buffer;
			return;
		case 0xA:
			RUN_BIT = 0;
			return;
		case 0xB:
			printf("%c", CURRENT_STATE.REGS[4] & 0xFF);
			return;
		case 0xC:
			scanf("%c", (int8_t*) &buffer);
			NEXT_STATE.REGS[2] = buffer;
			return;
	}
}


void bltz(uint8_t rs, int16_t offset) {
	if( (int32_t) CURRENT_STATE.REGS[rs] < 0) {
		NEXT_STATE.PC = CURRENT_STATE.PC + (offset<<2) - 4;	
	}
}

void bgez(uint8_t rs, int16_t offset) {
	if((int32_t) CURRENT_STATE.REGS[rs] >= 0) {
		NEXT_STATE.PC = CURRENT_STATE.PC + (offset<<2) - 4;	
	}
}

void bltzal(uint8_t rs, int16_t offset) {
	if( (int32_t) CURRENT_STATE.REGS[rs] < 0) {
		NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;
		NEXT_STATE.PC = CURRENT_STATE.PC + (offset<<2) - 4;	
	}
}

void bgezal(uint8_t rs, int16_t offset) {
	if(! (int32_t) CURRENT_STATE.REGS[rs] < 0) {
		NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;
		NEXT_STATE.PC = CURRENT_STATE.PC + (offset<<2) - 4;	
	}
}

void addi(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0)
		NEXT_STATE.REGS[rt] = (int32_t) CURRENT_STATE.REGS[rs] + imm;
}

void addiu(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0)
		addi(rs, rt, imm);
}

void slti(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0) {
		if( (int32_t) CURRENT_STATE.REGS[rs] < imm) {
			NEXT_STATE.REGS[rt] = 1;
			return;
		}
		NEXT_STATE.REGS[rt] = 0;
	}
}

void sltiu(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0)
		slti(rs, rt, imm);
}

void andi(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0)
		NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] & (uint32_t) imm;	
}

void ori(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0)
		NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] | (uint32_t) imm;
}

void xori(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0)
		NEXT_STATE.REGS[rt] = CURRENT_STATE.REGS[rs] ^ (uint32_t) imm;
}

void lui(uint8_t rt, int16_t imm) {
	if(rt != 0)
		NEXT_STATE.REGS[rt] = imm << 16;
}

void beq(uint8_t rs, uint8_t rt, int16_t imm) {
	if(CURRENT_STATE.REGS[rs] == CURRENT_STATE.REGS[rt])
		NEXT_STATE.PC = CURRENT_STATE.PC + (imm<<2) - 4;
}

void bne(uint8_t rs, uint8_t rt, int16_t imm) {
	if(rt != 0)
	if(CURRENT_STATE.REGS[rs] != CURRENT_STATE.REGS[rt])
		NEXT_STATE.PC = CURRENT_STATE.PC + (imm<<2) - 4;
}

void blez(uint8_t rs, int16_t imm) {
	if((int32_t) CURRENT_STATE.REGS[rs] <= 0)
		NEXT_STATE.PC = CURRENT_STATE.PC + (imm<<2) - 4;
}

void bgtz(uint8_t rs, int16_t imm) {
	if((int32_t) CURRENT_STATE.REGS[rs] > 0)
		NEXT_STATE.PC = CURRENT_STATE.PC + (imm<<2) - 4;
}

void j(uint32_t target) {
	NEXT_STATE.PC = (target<<2) - 4; // To maintain the PC+4 regular operation.
}

void jal(uint32_t target) {
	NEXT_STATE.REGS[31] = CURRENT_STATE.PC + 4;
	j(target);
}

void lb(uint8_t base, uint8_t rt, int16_t imm) {
	if(rt != 0) {
		uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
		NEXT_STATE.REGS[rt] = (int32_t) mem_read_32(address) & 0xFF;
	}
}

void lh(uint8_t base, uint8_t rt, int16_t imm) {
	if(rt != 0) {
		uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
		NEXT_STATE.REGS[rt] = (int32_t) mem_read_32(address) & 0xFFFF;
	}
}

void lw(uint8_t base, uint8_t rt, int16_t imm) {
	if(rt != 0) {
		uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
		NEXT_STATE.REGS[rt] = mem_read_32(address);
	}
}

void lbu(uint8_t base, uint8_t rt, int16_t imm) {
	if(rt != 0) {
		uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
		NEXT_STATE.REGS[rt] = mem_read_32(address) & 0xFF;
	}
}

void lhu(uint8_t base, uint8_t rt, int16_t imm) {
	if(rt != 0) {
		uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
		NEXT_STATE.REGS[rt] = mem_read_32(address) & 0xFFFF;
	}
}

void sb(uint8_t base, uint8_t rt, int16_t imm) {	
	uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
	uint32_t value = mem_read_32(address) & ~0xFF;
	value |= (CURRENT_STATE.REGS[rt] & 0xFF);
	mem_write_32(address, value);
}

void sh(uint8_t base, uint8_t rt, int16_t imm) {
	uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
	uint32_t value = mem_read_32(address) & ~0xFFFF;
	value |= (CURRENT_STATE.REGS[rt] & 0xFFFF);
	mem_write_32(address, value);
}

void sw(uint8_t base, uint8_t rt, int16_t imm) {
	uint32_t address = (int32_t) CURRENT_STATE.REGS[base] + imm;
	mem_write_32(address, CURRENT_STATE.REGS[rt]);	
}
