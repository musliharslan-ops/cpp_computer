#ifndef FETCH_H
#define FETCH_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdint>
using namespace std;
class fetch{
public:
    uint32_t comd;
    ifstream ins_mem;

    fetch() : ins_mem("imem.mem") 
    {if (!ins_mem.is_open()) {
            cerr << "Error: Could not open imem.mem!" << endl;
        }
    }

    void ff() {
        // Double-check the stream is good before reading
        if (ins_mem >> hex >> comd) {
            cout << comd << endl; // This will now print 3430055955 (decimal representation of CC728013)
        } else {
            cerr << "Failed to read hex data from file." << endl;
        }
    }
	void comb(){
 		
	}

	void reset(){
		
	}

protected:
private:

};



#endif