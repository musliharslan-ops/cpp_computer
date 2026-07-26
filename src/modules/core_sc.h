#ifndef CORE_SC_H
#define CORE_SC_H

#include <string>
#include "fetch.h"
#include "decode.h"

class Core_sc{
public:
	fetch fet;
    decode dec;
	uint64_t r [32];
  	Core_sc(){

	}

	void ff(){
fet.comb();
fet.ff();
dec.comb(fet.comd);
	}

	void comb(){
 		
	}

	void reset(){
		
	}

protected:
private:

};


#endif