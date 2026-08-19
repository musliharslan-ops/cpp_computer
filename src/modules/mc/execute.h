#ifndef EXECUTE_H
#define EXECUTE_H
#include <iostream>
#include <cstdint>
#include "defines.h"
using namespace std;
extern uint64_t pc;
extern uint8_t rd;
extern uint32_t imm;
extern uint8_t rs1;
extern uint8_t rs2;
extern uint64_t rdc;
extern bool jmpcon;
extern bool run;
extern uint64_t RD2;
uint64_t pcc;
class execute{
    
public:
    uint8_t rdE;
    uint64_t pcplus4E;
    uint64_t RD1E;
    uint64_t memcE;
    uint8_t funE;
	void comb(uint8_t a,uint64_t b,uint64_t c,uint8_t d){
        rdE=a;
        pcplus4E=b;
        RD1E=c;
        funE=d;
    switch(funE){
        case LUI:
        rdc=simm32_64;
        jmpcon=false;
        cout<<"Register "<<erd<<" was set to: "<<simm32_64<<endl;
        break;
        case AUIPC:
        pcc=pc+simm32_64;
        jmpcon=true;
        cout<<"Added "<<simm32_64<<"to Program counter"<<endl;
        break;
        case JAL:
        pcc=pc+simm21_64;
        rdc=pc+4;
        jmpcon=true;
        cout<<"Register "<<erd<<" was set to line of the next command and Program Counter increased by "<<simm21_64<<endl;
        break;
        case JALR:
        pcc=pc+simm12_64+RD1E;
        rdc=pc+4;
        jmpcon=true;
        cout<<"Register "<<erd<<" was set to line of the next command and Program Counter increased by the sum of Register "<<ers1<<" and "<<simm21_64<<endl;
        break;
        case BEQ:
        if(RD1E==RD2){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
            jmpcon=true;
        }
        else jmpcon=false;
        break;
        case BNE:
        if(!(RD1E==RD2)){
            pcc=pc+simm13_64; 
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
            jmpcon=true;
        }
        else jmpcon=false;
        break;
        case BLT:
        if(sregrs1_64<sregrs2_64){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
            jmpcon=true;
        }  
        else jmpcon=false;
        break;
        case BGE:
        if(!(sregrs1_64<sregrs2_64)){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
            jmpcon=true;
        }  
        else false;
        break;
        case BLTU:
        if(RD1E<RD2){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
            jmpcon=true;
        }else jmpcon=false;
        break;
        case BGEU:
        if(!(RD1E<RD2)){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
            jmpcon=true;
        }else jmpcon=false;
        break;
        case LB:
        cout<<"Register "<<erd<<" was set to first byte of memory"<<RD1E+(simm12_64)<<"(signed)"<<endl;
        jmpcon=false;
        break;
        case LH:
        cout<<"Register "<<erd<<" was set to first 2 bytes of memory"<<RD1E+(simm12_64)<<"(signed)"<<endl;
        jmpcon=false;
        break;
        case LW:
        cout<<"Register "<<erd<<" was set to first 4 bytes of memory"<<RD1E+(simm12_64)<<"(signed)"<<endl;
        jmpcon=false;
        break;
        case LBU:
        cout<<"Register "<<erd<<" was set to first byte of memory"<<RD1E+(simm12_64)<<" (unsigned)"<<endl;
        jmpcon=false;
        break;
        case LHU:
        cout<<"Register "<<erd<<" was set to first 2 bytes of memory"<<RD1E+(simm12_64)<<" (unsigned)"<<endl;
        jmpcon=false;
        break;
        case SB:
        memcE=sregrs2_8;
        cout<<"Memory "<<RD1E+(simm12_64)<<" was set to first byte of register "<<ers2<<" (signed)"<<endl;
        jmpcon=false;
        break;
        case SH:
        memcE=sregrs2_16;
        cout<<"Memory "<<RD1E+(simm12_64)<<" was set to first 2 bytes of register "<<ers2<<" (signed)"<<endl;
        jmpcon=false;
        break;
        case SW:
        memcE=sregrs2_32;
        cout<<"Memory "<<RD1E+(simm12_64)<<" was set to first 4 bytes of register "<<ers2<<" (signed)"<<endl;
        jmpcon=false;
        break;
        case ADDI:
        rdc=RD1E+simm12_64;
        cout<<"Register "<<erd<<" was set to the sum of Register "<<ers1<<" and "<<simm12_64<<endl;
        jmpcon=false;
        break;
        case SLTI:
        if(sregrs1_64<simm12_64){
            rdc=1;
            cout<<"Register "<<erd<<" was set to 1"<<endl;
        }  
        else{ 
        rdc=0;
        cout<<"Register "<<erd<<" was set to 0"<<endl;
        
        }jmpcon=false;
        break;
        case SLTIU:
        if(RD1E<uimm32_64){
            rdc=1;
            cout<<"Register "<<erd<<" was set to 1"<<endl;
        }
        else{ 
        rdc=0;
        cout<<"Register "<<erd<<" was set to 0"<<endl;
        }
        jmpcon=false;
        break;
        case XORI:
        rdc=(simm12_64)^RD1E;
        cout<<"Register "<<erd<<" was set to the XOR of Register "<<ers1<<" and "<<simm12_64<<endl;
        jmpcon=false;
        break;   
        case ORI:
        rdc=(simm12_64)|RD1E;
        cout<<"Register "<<erd<<" was set to the OR of Register "<<ers1<<" and "<<simm12_64<<endl;
        jmpcon=false;
        break;                
        case ANDI:
        rdc=(simm12_64)&RD1E;
        cout<<"Register "<<erd<<" was set to the AND of Register "<<ers1<<" and "<<simm12_64<<endl;
        jmpcon=false;
        break; 
        case SLLI:
        rdc=RD1E<<rs2;
        cout<<"Register "<<erd<<" was set to the Register "<<ers1<<" shifted left by "<<ers2<<endl;
        jmpcon=false;
        break;
        case SRLI:
        rdc=static_cast<uint64_t>(RD1E>>rs2);
        cout<<"Register "<<erd<<" was set to the Register "<<ers1<<" shifted right by "<<ers2<<" (logical)"<<endl;
        jmpcon=false;
        break; 
        case SRAI:
        rdc=static_cast<int64_t>(RD1E>>rs2);
        cout<<"Register "<<erd<<" was set to the Register "<<ers1<<" shifted right by "<<ers2<<" (arithmetic)"<<endl;
        jmpcon=false;
        break;
        case ADD:
        rdc=RD1E+RD2;
        cout<<"Register "<<erd<<" was set to the sum of Register "<<ers1<<" and Register "<<ers2<<endl;
        jmpcon=false;
        break;
        case SUB:
        rdc=RD1E-RD2;
        cout<<"Register "<<erd<<" was set to the difference of Register "<<ers1<<" and Register "<<ers2<<endl;
        jmpcon=false;
        break;
        case SLL:
        rdc=RD1E<<RD2;
        cout<<"Register "<<erd<<" was set to the Register "<<ers1<<" shifted left by Register "<<ers2<<endl;
        jmpcon=false;
        break;
        case SLT:
        if(sregrs1_64<sregrs2_64){
            rdc=1;
            cout<<"Register "<<erd<<" was set to 1"<<endl;
        }
        else{ 
        rdc=0;
        cout<<"Register "<<erd<<" was set to 0"<<endl;
        }
        jmpcon=false;
        break;
        case SLTU:
        if(RD1E<RD2){
            rdc=1;
            cout<<"Register "<<erd<<" was set to 1"<<endl;
        }
        else{ 
        rdc=0;
        cout<<"Register "<<erd<<" was set to 0"<<endl;
        }
        jmpcon=false;
        break;
        case XOR:
        rdc=RD1E^RD2;
        cout<<"Register "<<erd<<" was set to the XOR of Register "<<ers1<<" and Register "<<ers2<<endl;
        jmpcon=false;
        break;
        case SRL:
        rdc=RD1E>>RD2;
        cout<<"Register "<<erd<<" was set to the Register "<<ers1<<" shifted right by Register "<<ers2<<" (logical)"<<endl;
        jmpcon=false;
        break;
        case SRA:
        rdc=sregrs1_64>>sregrs2_64;
        cout<<"Register "<<erd<<" was set to the Register "<<ers1<<" shifted right by Register "<<ers2<<" (arithmetic)"<<endl;
        jmpcon=false;
        break;
        case OR:
        rdc=RD1E|RD2;
        cout<<"Register "<<erd<<" was set to the OR of Register "<<ers1<<" and Register "<<ers2<<endl;
        jmpcon=false;
        break;
        case AND:
        rdc=RD1E&RD2;
        cout<<"Register "<<erd<<" was set to the AND of Register "<<ers1<<" and Register "<<ers2<<endl;
        jmpcon=false;
        break;
        case HALT:
        run=false;
        jmpcon=false;
        break;
    }
    }

	void reset(){
		
	}

protected:
private:

};
#endif