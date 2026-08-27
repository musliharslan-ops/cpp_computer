#ifndef FETCH_H
#define FETCH_H

#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
bool jmpcon=false;
extern uint64_t PCTARGETE;
class fetch{
public:
    uint32_t comd;
    uint64_t pcplus4F;
    uint64_t PCF;
    ifstream ins_mem;

    fetch() : ins_mem("imem.mem") 
    {}

    void ff() {
        if(jmpcon==0){
        PCF=pcplus4F;
        }
        else PCF=PCTARGETE;    
    }
	void comb(){
 		for(int i=0;i<PCF;i+=4){
            ins_mem>>hex>>comd;
        }
        pcplus4F=PCF+4;
	}

	void reset(){
		comd=0x00000013;
	}

protected:
private:

};



#endif