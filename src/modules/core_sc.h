#ifndef DECODE_H
#define DECODE_H

#include "module.h"

#define op_BGEU 0x0000707f

class Core_sc{
public:
	
	Core_sc(std::string name){

	}

	void ff(){

	}

	void comb(){
		file instruction_memory = open("imem.mem");
		uint32_t instr;
		uint32_t opcode;
		while(!instruction_memory.feof){
			instr=instruction_memory.readline();
			opcode = instr & b00000000_00000000_00000000_0111_1111;
			opcode = instr & 0x0000007f;
			func3 = instr & 0x00007000;

			decode_value=opcode|func3;
			switch(decode_value){
			case 0x00007063:
				switch(funct3)
			}
		}
	}

	void reset(){
		
	}

protected:
private:

};


#endif