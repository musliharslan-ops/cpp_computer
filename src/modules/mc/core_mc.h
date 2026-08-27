#ifndef CORE_MC_H
#define CORE_MC_H

#include <string>
#include <cstdint>
#include "fetch.h"
#include "decode.h"
#include "execute.h"
#include "memory.h"
#include "defines.h"
#include "writeback.h"
memory memo;
decode decod;
fetch fet;
bool run=true;
using namespace std;
extern uint8_t rdE;
class Core_mc{
public:
	
    
	execute exec;
	writeback writeb;
	
  	Core_mc(){

	}  

	void ff(){
		writeb.ff(memo.ALURESULTM, memo.readdataM, memo.pcplus4M, memo.rdM, memo.funM);
		memo.ff(exec.pcplus4E,exec.writedataE,exec.ALURESULTE,rdE,exec.funE,exec.memvalidE);
		exec.ff(decod.rdD, decod.RD1D, decod.RD2D, decod.pcplus4D, decod.PCD, decod.immextD, decod.rs2);
		decod.ff(fet.comd,fet.pcplus4F,fet.PCF);
		fet.ff();
	}

 	void comb(){
		writeb.comb();
		memo.comb();
		exec.comb();
		decod.comb();
        fet.comb();
    }

protected:
private:

};


#endif
