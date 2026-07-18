#ifndef TYPES_H
#define TYPES_H
#include <stdint.h>

enum width
{
	BYTE,
	HALF,
	WORD,
	DOUBLE
};

typedef struct dinstr_t{
	int valid;
	//opcode;
	//rs1_valid;
	//rs1_idx;
	//rs2_valid;
	//rs2_idx;
	//rd_valid;
	//rd_idx;
	//imm;
};
#endif