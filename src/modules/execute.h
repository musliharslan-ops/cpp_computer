#ifndef EXECUTE_H
#define EXECUTE_H
#include <iostream>
#include <fstream>
#include <cstdint>
using namespace std;
extern uint64_t pc;
extern uint64_t reg [32];
extern uint8_t rd;
extern uint32_t imm;
extern uint8_t fun;
extern uint8_t rs1;
extern uint8_t rs2;
extern uint64_t mem[256];
extern bool run;
class execute{
public:
    uint32_t pcc;
    uint64_t rdc;
    uint64_t memc;
    void ff() {
        switch(fun){
            case 2:
            case 3:
            pc=pcc;
            case 0:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
            case 18:
            case 19:
            case 20:
            case 21:
            case 22:
            case 23:
            case 24:
            case 25:
            case 26:
            case 27:
            case 28:
            case 29:
            case 30:
            case 31:
            case 32:
            case 33:
            case 34:
            case 35:
            case 36:
            reg[rd]=rdc;
            break;
            case 1:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            pc=pcc;
            break;
            case 15:
            case 16:
            case 17:
            mem[reg[rs1]+(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))]=memc;
            break;
        }
        reg[0]=0;
    }
	void comb(){
    switch(fun){
        case 0:
        rdc=static_cast<int64_t>(imm);
        break;
        case 1:
        pcc=pc+static_cast<int64_t>(imm);
        break;
        case 2:
        pcc=pc+static_cast<int64_t>((imm^(1u<<20))-(1u<<20));
        rdc=pc+4;
        break;
        case 3:
        pcc=pc+static_cast<int64_t>((imm^(1u<<11))-(1u<<11))+reg[rs1];
        rdc=pc+4;
        break;
        case 4:
        if(reg[rs1]==reg[rs2]){
            pcc=pc+static_cast<int64_t>((imm^(1u<<12))-(1u<<12));
        }
        else pcc=pc;
        break;
        case 5:
        if(!(reg[rs1]==reg[rs2])){
            pcc=pc+static_cast<int64_t>((imm^(1u<<12))-(1u<<12)); 
        }
        else pcc=pc;
        break;
        case 6:
        if(static_cast<int64_t>(reg[rs1])<static_cast<int64_t>(reg[rs2])){
            pcc=pc+static_cast<int64_t>((imm^(1u<<12))-(1u<<12));
        }  
        else pcc=pc;
        break;
        case 7:
        if(!(static_cast<int64_t>(reg[rs1])<static_cast<int64_t>(reg[rs2]))){
            pcc=pc+static_cast<int64_t>((imm^(1u<<12))-(1u<<12));
        }  
        else pcc=pc;
        break;
        case 8:
        if(reg[rs1]<reg[rs2]){
            pcc=pc+static_cast<int64_t>((imm^(1u<<12))-(1u<<12));
        }else pcc=pc;
        break;
        case 9:
        if(!(reg[rs1]<reg[rs2])){
            pcc=pc+static_cast<int64_t>((imm^(1u<<12))-(1u<<12));
        }else pcc=pc;
        break;
        case 10:
        rdc=static_cast<int8_t>(mem[rs1+(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))]);
        break;
        case 11:
        rdc=static_cast<int16_t>(mem[rs1+(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))]);
        break;
        case 12:
        rdc=static_cast<int32_t>(mem[rs1+(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))]);
        break;
        case 13:
        rdc=static_cast<uint8_t>(mem[rs1+(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))]);
        break;
        case 14:
        rdc=static_cast<uint16_t>(mem[rs1+(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))]);
        break;
        case 15:
        memc=static_cast<int8_t>(reg[rs2]);
        break;
        case 16:
        memc=static_cast<int16_t>(reg[rs2]);
        break;
        case 17:
        memc=static_cast<int32_t>(reg[rs2]);
        break;
        case 18:
        rdc=reg[rs1]+static_cast<int64_t>((imm^(1u<<11))-(1u<<11));
        break;
        case 19:
        if(static_cast<int64_t>(reg[rs1])<static_cast<int64_t>((imm^(1u<<11))-(1u<<11))){
            rdc=1;
        }  
        else 
        rdc=0;
        break;
        case 20:
        if(reg[rs1]<static_cast<uint64_t>(imm)){
            rdc=1;
        }
        else
        rdc=0;
        break;
        case 21:
        rdc=(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))^reg[rs1];
        break;   
        case 22:
        rdc=(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))|reg[rs1];
        break;                
        case 23:
        rdc=(static_cast<int64_t>((imm^(1u<<11))-(1u<<11)))&reg[rs1];
        break; 
        case 24:
        rdc=reg[rs1]<<rs2;
        break;
        case 25:
        rdc=static_cast<uint64_t>(reg[rs1]>>rs2);
        break; 
        case 26:
        rdc=static_cast<int64_t>(reg[rs1]>>rs2);
        break;
        case 27:
        rdc=reg[rs1]+reg[rs2];
        break;
        case 28:
        rdc=reg[rs1]-reg[rs2];
        break;
        case 29:
        rdc=reg[rs1]<<reg[rs2];
        break;
        case 30:
        if(static_cast<int64_t>(reg[rs1])<static_cast<int64_t>(reg[rs2])){
            rdc=1;
        }else rdc=0;
        break;
        case 31:
        if(static_cast<uint64_t>(reg[rs1])<static_cast<uint64_t>(reg[rs2])){
            rdc=1;
        }else rdc=0;
        break;
        case 32:
        rdc=reg[rs1]^reg[rs2];
        break;
        case 33:
        rdc=static_cast<uint64_t>(reg[rs1])>>static_cast<uint64_t>(reg[rs2]);
        break;
        case 34:
        rdc=static_cast<int64_t>(reg[rs1])>>static_cast<int64_t>(reg[rs2]);
        break;
        case 35:
        rdc=reg[rs1]|reg[rs2];
        break;
        case 36:
        rdc=reg[rs1]&reg[rs2];
        break;
        case 37:
        run=false;
        break;
    }
    }

	void reset(){
		
	}

protected:
private:

};
#endif