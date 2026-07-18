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

typedef struct packed{
	bool valid;
	int32_t data;
	int idx;
} mem_res_t;

typedef struct packed{
	bool valid;
	int32_t addr;
	int32_t data;
	int idx;
	bool is_write;
} mem_req_t;

#endif