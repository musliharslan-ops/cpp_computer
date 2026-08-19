#ifndef CORE_SC_H
#define CORE_SC_H

#include <string>
#include <cstdint>
#include "fetch.h"
#include "decode.h"
#include "execute.h"
uint64_t pc=0;
uint64_t reg [32];
uint64_t mem [256];
uint8_t rd;
uint32_t imm;
uint8_t fun;
uint8_t rs1;
uint8_t rs2;
bool run=true;
class Core_sc{
public:
	fetch fet;
    decode dec;
	execute exec;
  	Core_sc(){

	}

	void ff(){
		fet.ff();
		exec.ff();
	}

	void comb(){
 		fet.comb();
		dec.comb(fet.comd);
		exec.comb();
	}

	void reset(){
		
	}

protected:
private:

};


#endif