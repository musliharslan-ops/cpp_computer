#ifndef CORE_MC_H
#define CORE_MC_H

#include <string>
#include <cstdint>
#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "memory.h"
#include "defines.h"
uint64_t pc=0;
uint8_t rd;
uint32_t imm;
uint8_t rs1;
uint8_t rs2;
uint64_t RD1;
uint64_t RD2;
memory memor;
uint64_t rdc;
uint64_t memc;
bool run=true;
class Core_mc{
public:
	fetch fet;
    decode dec;
	execute exec;
	
  	Core_mc(){

	}

	void ff(){
		memor.ff();
		dec.ff();
		fet.ff();
	}

 	void comb(){
		memor.comb(exec.rdE,exec.pcplus4E,exec.RD1E,exec.memcE,exec.funE);
		exec.comb(dec.rdD,dec.pcplus4D,dec.RD1D,dec.funD);
		dec.comb(fet.comd,fet.pcplus4F);
        fet.comb();
    }

protected:
private:

};


#endif
