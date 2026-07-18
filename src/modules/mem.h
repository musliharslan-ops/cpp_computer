#ifndef MEM_H
#define MEM_H

#include "types.h"
#include "module.h"
#include <stdint.h>


class Mem : public Module {
public:

	Mem(std::string name, char* file_name, int size){
		int i=0;
		this->name=name;
		this->size = size;
		this->mem = new int32_t[size];
		std::ifstream f_in;
		f_in.open(file_name);
		while(f_in >> hex >> word){
			// std::cout << word << std::endl;
			mem[i] = word;
		}


		this->mem_res_o = new mem_res_t;

	} 

	void ff(){

	}

	void comb(){

	}

	void reset(){
		
	}

	void set_mem_req_i(mem_req_t* mem_req_i){
		this->mem_req_i = mem_req_i
	}

	mem_res_t get_mem_res_o(){
		return this->mem_res_o;
	}

protected:
private:
	std::string name;
	int32_t* mem;
	int size;

	mem_req_t* mem_req_i;
	mem_res_t* mem_res_o;
};


#endif