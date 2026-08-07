#ifndef DECODE_H
#define DECODE_H

#include <iostream>
#include <cstdint>
#include "fetch.h"
#include "defines.h"
using namespace std;
extern uint8_t rd;
extern uint32_t imm;
extern uint8_t fun;
extern uint8_t rs1;
extern uint8_t rs2;
class decode{
public:
    uint32_t comd;
    uint8_t opcode;
    uint8_t funct3;
    uint8_t funct7;
	void ff(){
 		
	}
    void comb(uint32_t a) {
    comd=a;
    opcode=comd & 0x7F;
    rd=(comd>>7)& 0x1F;
    funct3=(comd>>12)& 0x7;
    rs1=(comd>>15)& 0x1F;
    rs2=(comd>>20)& 0x1F;
    funct7=(comd>>25)& 0x07F;
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
        fun=LUI;
        break;
        case 0x17:
        fun=AUIPC;
        break;
        case 0x6F:
        fun=JAL;
        break;
        case 0x67:
        if(funct3==0){
        fun=JALR;}
        break;
        case 0x63:
        switch(funct3){
            case 0:
            fun=BEQ;
            break;
            case 1:
            fun=BNE;
            break;
            case 4:
            fun=BLT;
            break;
            case 5:
            fun=BGE;
            break;
            case 6:
            fun=BLTU;
            break;
            case 7:
            fun=BGEU;
            break;
        }
        break;
        case 0x3:
        switch(funct3){
            case 0:
            fun=LB;
            break;
            case 1:
            fun=LH;
            break;
            case 2:
            fun=LW;
            break;
            case 4:
            fun=LBU;
            break;
            case 5:
            fun=LHU;
            break;
        }
        break;
        case 0x23:
        switch(funct3){
            case 0:
            fun=SB;
            break;
            case 1:
            fun=SH;
            break;
            case 2:
            fun=SW;
            break;
        }
        break;
        case 0x13:
        switch(funct3){
            case 0:
            fun=ADDI;
            break;
            case 2:
            fun=SLTI;
            break;
            case 3:
            fun=SLTIU;
            break;
            case 4:
            fun=XORI;
            break;
            case 6:
            fun=ORI;
            break;
            case 7:
            fun=ANDI;
            break;
            case 1:
            if(funct7==0x0){
                fun=SLLI;
            }
            break;
            case 5:
            switch(funct7){
                case 0:
                fun=SRLI;
                break;
                case 0x20:
                fun=SRAI;
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
                fun=ADD;
                break;
                case 0x20:
                fun=SUB;
                break;
            }
            break;
            case 1:
            if(funct7==0){
            fun=SLL;}
            break;
            case 2:
            if(funct7==0){
            fun=SLT;}
            break;
            case 3:
            if(funct7==0){
            fun=SLTU;}
            break;
            case 4:
            if(funct7==0){
            fun=XOR;}
            break;
            case 5:
            switch(funct7){
                case 0x0:
                fun=SRL;
                break;
                case 0x20:
                fun=SRA;
                break;
            }
            case 6:
            if(funct7==0){
            fun=OR;}
            break;
            case 7:
            if(funct7==0){
            fun=AND;}
            break;
        } 
        break;
        default:
        if(comd==0x00000000){
            fun=HALT;
        }
        break;
    }
    }
    
	void reset(){
		
	}

protected:
private:

};



#endif