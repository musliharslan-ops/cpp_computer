#ifndef WRAPPER_H
#define WRAPPER_H

#include "types.h"
#include "module.h"
#include "core.h"
#include "mem.h"


class Wrapper : public Module {
public:

	Mem(std::string name){
		this->core = new Core();
		this->imem = new Mem("imem", "imem.mem", 4096);
		this->dmem = new Mem("dmem", "dmem.mem", 4096);
		
		//get outputs
		this->imem_req = this->core.get_imem_req_o();
		this->imem_res = this->imem.get_mem_res_o();

		this->dmem_req = this->core.get_dmem_req_o();
		this->dmem_res = this->dmem.get_mem_res_o();
		
		//set inputs
		this->imem.set_mem_req_i(this->imem_req);
		this->core.set_imem_res_i(this->imem_res);

		this->dmem.set_mem_req_i(this->dmem_req);
		this->core.set_dmem_res_i(this->dmem_res);
	}

	void reset(){

	}

	void comb(){

	}

	void reset(){
		
	}

protected:
private:
	Core* core;
	
	Mem* imem;
	mem_req_t* imem_req;
	mem_res_t* imem_res;

	Mem* dmem;
	mem_req_t* dmem_req;
	mem_res_t* dmem_res;
};


#endif