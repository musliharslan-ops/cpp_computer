#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
class memory{
public:
    uint64_t* mem= new uint64_t[65536];
    uint64_t* reg= new uint64_t[32];
    uint64_t pcplus4M;
    uint64_t writedataM;
    uint64_t PCTARGETM;
    uint64_t readdataM;
    uint64_t ALURESULTM;

    bool memvalidM;
    uint8_t rdM;
    uint8_t funM;       
    void ff(uint64_t a, uint64_t b, uint64_t c, uint8_t d, uint8_t e,bool f) {
        if(memvalidM==true){
            mem[ALURESULTM]=writedataM;
        }
        pcplus4M=a;
        writedataM=b;
        ALURESULTM=c;
        rdM=d;
        funM=e;
        memvalidM=f;
    }
    
	void comb(){
        readdataM=mem[ALURESULTM];
	}

	void reset(){
		
	}

protected:
private:

};



#endif