#ifndef FETCH_H
#define FETCH_H

#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
extern uint64_t pc;
class fetch{
public:
    uint32_t comd;
    ifstream ins_mem;

    fetch() : ins_mem("imem.mem") 
    {}

    void ff() {
        pc+=4;    
    }
	void comb(){
 		for(int i=0;i<=pc;i+=4){
            ins_mem>>hex>>comd;
        }
	}

	void reset(){
		
	}

protected:
private:

};



#endif