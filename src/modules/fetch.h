#ifndef FETCH_H
#define FETCH_H

#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
class fetch{
public:
    uint32_t comd;
    ifstream ins_mem;
    uint32_t clock=0x00000000;

    fetch() : ins_mem("imem.mem") 
    {}

    void ff() {
        clock++;    
    }
	void comb(){
 		for(int i=0;i<=clock;i++){
            ins_mem>>hex>>comd;
        }
	}

	void reset(){
		
	}

protected:
private:

};



#endif