#ifndef CORE_H
#define CORE_H

#include "module.h"
#include "fetch.h"
#include "types.h"


class Core : public Module {
public:

	Core(std::string name){
		this->fetch = new Fetch();
		this->imem_req = this->fetch.get_mem_req();
		//this->dmem_req = this->fetch.get_mem_req();
	}

	void ff(){
/*



*/
	}

	void comb(){

	}

	void reset(){
		
	}

	mem_req_t get_imem_req_o(){
		return this->imem_req_o;
	}
	mem_req_t get_dmem_req_o(){
		return this->dmem_req;
	}
	void set_imem_res(mem_res_t* mem_res){
		this->imem_res = mem_res;
	}
	void set_dmem_res(mem_res_t* mem_res){
		this->dmem_res = mem_res;
	}

protected:
private:
	Fetch* fetch;
	
	mem_req_t* imem_req_o;
	mem_res_t* imem_res_i;

	mem_req_t* dmem_req_o;
	mem_res_t* dmem_res_i;

};


#endif