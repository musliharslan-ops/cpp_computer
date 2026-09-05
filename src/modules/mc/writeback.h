#ifndef WRITEBACK_H
#define WRITEBACK_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include "defines.h"
using namespace std;
uint64_t resultW;
uint8_t rdW;
bool regvalid;
class writeback{
public:
    uint64_t ALURESULTW;
	uint64_t readdataW;
	uint64_t pcplus4W;
	uint8_t funW;
    void ff(uint64_t a, uint64_t b, uint64_t c, uint8_t d, uint8_t e) {  
        ALURESULTW=a;
		readdataW=b;
		pcplus4W=c;
		rdW=d;
		funW=e;
    }
	void comb(){
        switch(funW){
			case BEQ:
			case BNE:
			case BLT:
			case BGE:
			case BLTU:
			case BGEU:
				regvalid=false;
				break;
			case LB:
			case LH:
			case LW:
			case LBU:
			case LHU:
				resultW=readdataW;
				regvalid=true;
				break;
			case JAL:
			case JALR:
				resultW=pcplus4W;
				regvalid=true;
				break;
			default:
				resultW=ALURESULTW;
				regvalid=true;
				break;
		}
	}

	void reset(){
		
	}

protected:
private:

};



#endif