#ifndef FETCH_H
#define FETCH_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include "execute.h"
using namespace std;
bool jmpcon=false;
extern bool jmpcon;
extern uint64_t pcc;
class fetch{
public:
    uint32_t comd;
    uint64_t pcplus4F;
    ifstream ins_mem;

    fetch() : ins_mem("imem.mem") 
    {}

    void ff() {
        if(jmpcon==0){
        pc+=4;
        }
        else pc=pcc;    
    }
	void comb(){
 		for(int i=0;i<=pc;i+=4){
            ins_mem>>hex>>comd;
        }
        pcplus4F=pc+4;
	}

	void reset(){
		
	}

protected:
private:

};



#endif