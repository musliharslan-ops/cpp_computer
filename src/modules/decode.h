#ifndef DECODE_H
#define DECODE_H

#include <iostream>
#include <fstream>
#include <cstdint>
#include "fetch.h"
using namespace std;
class decode{
public:
    uint32_t comd;
    uint32_t imm;
    uint8_t opcode;
    uint8_t rd;
    uint8_t funct3;
    uint8_t rs1;
    uint8_t rs2;
    uint8_t funct7;
    uint8_t fun;
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
    case 0x73:
        imm=(comd>>20)&0xFFF;
        break;
    case 0x23:
        imm=(comd>>7)&0x1F|(comd>>20)&0xFE0;
        break;
    case 0x63:
        imm=((comd >> 19) & 0x1000) | ((comd << 4)  & 0x800) | ((comd >> 20) & 0x7E0) | ((comd >> 7)  & 0x1E);
        break;
    case 0x37:
    case 0x17:
        imm=(comd >> 12) & 0xFFFFF;
        break;
    case 0xF:
        imm=(comd >> 11) & 0x100000 | comd & 0xFF000 | (comd >> 9)  & 0x800 | (comd >> 20) & 0x7FE;   
        break;
    }
    switch(opcode){
        case 0x37:
        fun=0;
        break;
        case 0x17:
        fun=1;
        break;
        case 0x6F:
        fun=2;
        break;
        case 0x67:
        if(funct3==0){
        fun=3;}
        break;
        case 0x63:
        switch(funct3){
            case 0:
            fun=4;
            break;
            case 1:
            fun=5;
            break;
            case 4:
            fun=6;
            break;
            case 5:
            fun=7;
            break;
            case 6:
            fun=8;
            break;
            case 7:
            fun=9;
            break;
        }
        break;
        case 0x3:
        switch(funct3){
            case 0:
            fun=10;
            break;
            case 1:
            fun=11;
            break;
            case 2:
            fun=12;
            break;
            case 4:
            fun=13;
            break;
            case 5:
            fun=14;
            break;
        }
        break;
        case 0x23:
        switch(funct3){
            case 0:
            fun=15;
            break;
            case 1:
            fun=16;
            break;
            case 2:
            fun=17;
            break;
        }
        break;
        case 0x13:
        switch(funct3){
            case 0:
            fun=18;
            break;
            case 2:
            fun=19;
            break;
            case 3:
            fun=20;
            break;
            case 4:
            fun=21;
            break;
            case 6:
            fun=22;
            break;
            case 7:
            fun=23;
            break;
            case 1:
            if(funct7==0x0){
                fun=24;
            }
            break;
            case 5:
            switch(funct7){
                case 0:
                fun=25;
                break;
                case 0x20:
                fun=26;
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
                fun=27;
                break;
                case 0x20:
                fun=28;
                break;
            }
            break;
            case 1:
            if(funct7==0){
            fun=29;}
            break;
            case 2:
            if(funct7==0){
            fun=30;}
            break;
            case 3:
            if(funct7==0){
            fun=31;}
            break;
            case 4:
            if(funct7==0){
            fun=32;}
            break;
            case 5:
            switch(funct7){
                case 0x0:
                fun=33;
                break;
                case 0x20:
                fun=34;
                break;
            }
            case 6:
            if(funct7==0){
            fun=35;}
            break;
            case 7:
            if(funct7==0){
            fun=36;}
            break;
        } 
        break;
        case 0xF:
        if(comd!=0x8330000F||comd!=0x0100000F){
            fun=37;
        }
        break;
        default:
        switch(comd){
            case 0x1330000F:
            fun=38;
            break;
            case 0x0100000F:
            fun=39;
            break;
            case 0x00000073:
            fun=40;
            break;
            case 0x00100073:
            fun=41;
            break;
        }
    }
    }
    
	void reset(){
		
	}

protected:
private:

};



#endif