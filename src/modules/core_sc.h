#ifndef CORE_SC_H
#define CORE_SC_H

#include <string>
#include "fetch.h"
#include "decode.h"

class Core_sc{
public:
	fetch fet;
    decode dec;
  	Core_sc(){

	}

	void ff(){
fet.comb();
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