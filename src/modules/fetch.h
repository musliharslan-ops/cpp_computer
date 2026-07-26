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

    fetch() : ins_mem("imem.mem") 
    {}

    void ff() {
         
    }
	void comb(){
 		if (ins_mem >> hex >> comd) {}
	}

	void reset(){
		
	}

protected:
private:

};



#endif