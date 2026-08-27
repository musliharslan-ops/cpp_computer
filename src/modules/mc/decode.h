#ifndef DECODE_H
#define DECODE_H

#include <iostream>
#include <cstdint>
#include "defines.h"
#include "memory.h"
#include "fetch.h"
using namespace std;
extern memory memo;
extern uint8_t rdW;
extern uint64_t resultW;
extern bool regvalid;
extern uint8_t rdE;
extern fetch fet;
class decode{
public:
    uint32_t comd;
    uint32_t imm;
    uint8_t opcode;
    uint8_t funct3;
    uint8_t funct7;
    uint8_t rdD;
    uint64_t pcplus4D;
    uint64_t PCD;
    uint64_t RD1D;
    uint64_t RD2D;
    uint8_t funD;
    uint8_t rs1;
    uint8_t rs2;
    int64_t immextD;
	void ff(uint64_t a,uint64_t b,uint64_t c){
 		comd=a;
        pcplus4D=b;
        PCD=c;
        if(regvalid==true){
            memo.reg[rdW]=resultW;
        }
        memo.reg[0]=0;
	}
    void comb() {
    opcode=comd & 0x7F;
    rdD=(comd>>7)& 0x1F;
    funct3=(comd>>12)& 0x7;
    rs1=(comd>>15)& 0x1F;
    rs2=(comd>>20)& 0x1F;
    funct7=(comd>>25)& 0x07F;
    RD1D=memo.reg[rs1];
    RD2D=memo.reg[rs2];
    switch (opcode)
    {
    case 0x33:
        imm=0;
        break;
    case 0x13:
    case 0x3:
    case 0x67:
        imm=(comd>>20)&0xFFF;
        break;
    case 0x23:
        imm=(comd>>7)&0x1F|(comd>>20)&0xFE0;
        break;
    case 0x63:
        imm=((comd>>19)&0x1000)|((comd<<3)&0x800)|((comd>>20)&0x7E0)| ((comd >> 7)  & 0x1E);
        break;
    case 0x37:
    case 0x17:
        imm=comd &0xFFFFF000;
        break;
    case 0x6F:
        imm=(comd >> 11) & 0x100000 | comd & 0xFF000 | (comd >> 9)  & 0x800 | (comd >> 20) & 0x7FE;   
        break;
    }
    switch(opcode){
        case 0x37:
        funD=LUI;
        break;
        case 0x17:
        funD=AUIPC;
        break;
        case 0x6F:
        funD=JAL;
        break;
        case 0x67:
        if(funct3==0){
        funD=JALR;}
        break;
        case 0x63:
        switch(funct3){
            case 0:
            funD=BEQ;
            break;
            case 1:
            funD=BNE;
            break;
            case 4:
            funD=BLT;
            break;
            case 5:
            funD=BGE;
            break;
            case 6:
            funD=BLTU;
            break;
            case 7:
            funD=BGEU;
            break;
        }
        break;
        case 0x3:
        switch(funct3){
            case 0:
            funD=LB;
            break;
            case 1:
            funD=LH;
            break;
            case 2:
            funD=LW;
            break;
            case 4:
            funD=LBU;
            break;
            case 5:
            funD=LHU;
            break;
        }
        break;
        case 0x23:
        switch(funct3){
            case 0:
            funD=SB;
            break;
            case 1:
            funD=SH;
            break;
            case 2:
            funD=SW;
            break;
        }
        break;
        case 0x13:
        switch(funct3){
            case 0:
            funD=ADDI;
            break;
            case 2:
            funD=SLTI;
            break;
            case 3:
            funD=SLTIU;
            break;
            case 4:
            funD=XORI;
            break;
            case 6:
            funD=ORI;
            break;
            case 7:
            funD=ANDI;
            break;
            case 1:
            if(funct7==0x0){
                funD=SLLI;
            }
            break;
            case 5:
            switch(funct7){
                case 0:
                funD=SRLI;
                break;
                case 0x20:
                funD=SRAI;
                break;
            }
            break;
        }
        break;
        case 0x33:
        switch(funct3){
            case 0:
            switch(funct7){
                case 0x0:
                funD=ADD;
                break;
                case 0x20:
                funD=SUB;
                break;
            }
            break;
            case 1:
            if(funct7==0){
            funD=SLL;}
            break;
            case 2:
            if(funct7==0){
            funD=SLT;}
            break;
            case 3:
            if(funct7==0){
            funD=SLTU;}
            break;
            case 4:
            if(funct7==0){
            funD=XOR;}
            break;
            case 5:
            switch(funct7){
                case 0x0:
                funD=SRL;
                break;
                case 0x20:
                funD=SRA;
                break;
            }
            case 6:
            if(funct7==0){
            funD=OR;}
            break;
            case 7:
            if(funct7==0){
            funD=AND;}
            break;
        } 
        break;
        default:
        if(comd==0x00000000){
            funD=HALT;
        }
        break;
    }
    switch(opcode){
        case 0x13:
        case 0x3:
        case 0x67:  
        case 0x23:
        immextD=simm12_64;
        if(funD==SLTIU){
            immextD=uimm32_64;
        }
        break;
        case 0x63:
        immextD=simm13_64;
        break;
        case 0x37:
        case 0x17:
        immextD=simm32_64;
        break;
        case 0x6F:
        immextD=simm21_64;
        break;
    }
    if((rdE!=0)&&(rdE==rs1||rdE==rs2)){
        
    }
}
	void reset(){
        comd=0x00000013;
        fet.reset();
	}

protected:
private:

};



#endif