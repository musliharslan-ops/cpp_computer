#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include "execute.h"
using namespace std;
class memory{
public:
    uint64_t* memo= new uint64_t[65536];
    uint64_t* reg= new uint64_t[32];
    uint64_t resultW;
    uint8_t rdW;
    uint8_t wrback;
    uint64_t pcplus4W;
    uint64_t RD1W;
    uint64_t memcW;
    uint8_t funW;

    void ff() {  
        switch(funW){
            case BEQ:
            case BNE:
            case BLT:
            case BGE:
            case BLTU:
            case BGEU:
                break;
            case SB:
            case SH:
            case SW:
                memo[RD1W+simm12_64]=memcW;
                break;
            default:
            reg[rdW]=resultW;
            break;
        }
        reg[0]=0;
    }
	void comb(uint8_t a,uint64_t b,uint64_t c,uint64_t d,uint8_t e){
        rdW=a;
        pcplus4W=b;
        RD1W=c;
        memcW=d;
        funW=e;
        switch(funW){
            case JAL:
            case JALR:
            resultW=pcplus4W;
            break;
            case LB:
            resultW=static_cast<int8_t>(memo[RD1W+(simm12_64)]);
            break;
            case LH:
            resultW=static_cast<int16_t>(memo[RD1W+(simm12_64)]);
            break;
            case LW:
            resultW=static_cast<int32_t>(memo[RD1W+(simm12_64)]);
            break;
            case LBU:
            resultW=static_cast<uint8_t>(memo[RD1W+(simm12_64)]);
            break;
            case LHU:
            resultW=static_cast<uint16_t>(memo[RD1W+(simm12_64)]);
            break;
            default:
            resultW=rdc;
            break;
        }
	}

	void reset(){
		
	}

protected:
private:

};



#endif