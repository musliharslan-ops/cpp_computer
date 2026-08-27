#ifndef EXECUTE_H
#define EXECUTE_H
#include <iostream>
#include <cstdint>
#include "decode.h"
using namespace std;

uint8_t rdE;
uint64_t PCTARGETE;
extern bool jmpcon;
extern decode decod;
extern bool run;
class execute{
    
public:
    bool memvalidE;
    uint8_t shift_amount;
    uint64_t pcplus4E;
    int64_t immextE;
    uint64_t PCE;
    uint64_t RD1E;
    uint64_t RD2E;
    uint64_t writedataE;
    uint8_t funE;
    
    uint64_t ALUINPUT2;
    uint64_t ALURESULTE;
    void ff(uint8_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e,int64_t f,uint8_t g){
        rdE=a;
        RD1E=b;
        RD2E=c;
        pcplus4E=d;
        PCE=e;
        immextE=f;
        shift_amount=g;
    }
	void comb(){
        switch(funE){
            case ADD:
            case SUB:
            case SLL:
            case SLT:
            case SLTU:
            case XOR:
            case SRL:
            case SRA:
            case OR:
            case AND:
            case BNE:
            case BEQ:
            case BLT:
            case BGE:
            case BLTU:
            case BGEU:
            ALUINPUT2=RD2E;
            break;
            default:
            ALUINPUT2=immextE;
            break;
        }
    PCTARGETE=PCE+immextE;
    switch(funE){
        case LUI:
        ALURESULTE=immextE;
        jmpcon=false;
        memvalidE=false;
        break;
        case JAL:
        ALURESULTE=pcplus4E;
        case AUIPC:
        jmpcon=true;
        memvalidE=false;
        ::decod.reset();
        break;
        case JALR:
        PCTARGETE=immextE+RD1E;
        ALURESULTE=pcplus4E;
        jmpcon=true;
        memvalidE=false;
        ::decod.reset();
        break;
        case BEQ:
        if(RD1E==ALUINPUT2){
            jmpcon=true;
            ::decod.reset();
        }
        else jmpcon=false;
        memvalidE=false;
        break;
        case BNE:
        if(!(RD1E==ALUINPUT2)){ 
            jmpcon=true;
            ::decod.reset();
        }
        else jmpcon=false;
        memvalidE=false;
        break;
        case BLT:
        if(sregrs1_64<sregrs2_64){
            jmpcon=true;
            ::decod.reset();
        }  
        else jmpcon=false;
        memvalidE=false;
        break;
        case BGE:
        if(!(sregrs1_64<sregrs2_64)){ 
            jmpcon=true;
            ::decod.reset();
        }  
        else jmpcon=false;
        memvalidE=false;
        break;
        case BLTU:
        if(RD1E<ALUINPUT2){
            jmpcon=true;
            ::decod.reset();
        }else jmpcon=false;
        memvalidE=false;
        break;
        case BGEU:
        if(!(RD1E<ALUINPUT2)){
            jmpcon=true;
            ::decod.reset();
        }else jmpcon=false;
        memvalidE=false;
        break;
        case LB:
        case LH:
        case LW:
        case LBU:
        case LHU:
        jmpcon=false;
        memvalidE=false;
        break;
        case SB:
        writedataE=sregrs2_8;
        jmpcon=false;
        memvalidE=true;
        break;
        case SH:
        writedataE=sregrs2_16;
        jmpcon=false;
        memvalidE=true;
        break;
        case SW:
        writedataE=sregrs2_32;
        jmpcon=false;
        memvalidE=true;
        break;
        case ADDI:
        ALURESULTE=RD1E+immextE;
        jmpcon=false;
        memvalidE=false;
        break;
        case SLTI:
        if(sregrs1_64<immextE){
            ALURESULTE=1;
        }  
        else{ 
        ALURESULTE=0;
        }jmpcon=false;
        memvalidE=false;
        break;
        case SLTIU:
        if(RD1E<immextE){
            ALURESULTE=1;
        }
        else{ 
        ALURESULTE=0;
        }
        jmpcon=false;
        memvalidE=false;
        break;
        case XORI:
        ALURESULTE=(immextE)^RD1E;
        jmpcon=false;
        memvalidE=false;
        break;   
        case ORI:
        ALURESULTE=(immextE)|RD1E;
        jmpcon=false;
        memvalidE=false;
        break;                
        case ANDI:
        ALURESULTE=(immextE)&RD1E;
        jmpcon=false;
        memvalidE=false;
        break; 
        case SLLI:
        ALURESULTE=RD1E<<shift_amount;
        jmpcon=false;
        memvalidE=false;
        break;
        case SRLI:
        ALURESULTE=static_cast<uint64_t>(RD1E>>shift_amount);
        jmpcon=false;
        memvalidE=false;
        break; 
        case SRAI:
        ALURESULTE=static_cast<int64_t>(RD1E>>shift_amount);
        jmpcon=false;
        memvalidE=false;
        break;
        case ADD:
        ALURESULTE=RD1E+ALUINPUT2;
        jmpcon=false;
        memvalidE=false;
        break;
        case SUB:
        ALURESULTE=RD1E-ALUINPUT2;
        jmpcon=false;
        memvalidE=false;
        break;
        case SLL:
        ALURESULTE=RD1E<<ALUINPUT2;
        jmpcon=false;
        memvalidE=false;
        break;
        case SLT:
        if(sregrs1_64<sregrs2_64){
            ALURESULTE=1;
        }
        else{ 
        ALURESULTE=0;
        }
        jmpcon=false;
        memvalidE=false;
        break;
        case SLTU:
        if(RD1E<ALUINPUT2){
            ALURESULTE=1;
        }
        else{ 
        ALURESULTE=0;
        }
        jmpcon=false;
        memvalidE=false;
        break;
        case XOR:
        ALURESULTE=RD1E^ALUINPUT2;
        jmpcon=false;
        memvalidE=false;
        break;
        case SRL:
        ALURESULTE=RD1E>>ALUINPUT2;
        jmpcon=false;
        memvalidE=false;
        break;
        case SRA:
        ALURESULTE=static_cast<int64_t>(RD1E>>ALUINPUT2);
        jmpcon=false;
        memvalidE=false;
        break;
        case OR:
        ALURESULTE=RD1E|ALUINPUT2;
        jmpcon=false;
        memvalidE=false;
        break;
        case AND:
        ALURESULTE=RD1E&ALUINPUT2;
        jmpcon=false;
        memvalidE=false;
        break;
        case HALT:
        run=false;
        jmpcon=false;
        memvalidE=false;
        break;
    }
    }

	void reset(){
		
	}

protected:
private:

};
#endif