#ifndef EXECUTE_H
#define EXECUTE_H
#include <iostream>
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
            case JAL:
            case JALR:
            pc=pcc;
            case LUI:
            case LB:
            case LH:
            case LW:
            case LBU:
            case LHU:
            case ADDI:
            case SLTI:
            case SLTIU:
            case XORI:
            case ORI:
            case ANDI:
            case SLLI:
            case SRLI:
            case SRAI:
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
            reg[rd]=rdc;
            break;
            case AUIPC:
            case BEQ:
            case BNE:
            case BLT:
            case BGE:
            case BLTU:
            case BGEU:
            pc=pcc;
            break;
            case SB:
            case SH:
            case SW:
            mem[reg[rs1]+(simm12_64)]=memc;
            break;
            case HALT:
            run=false;
            cout<<"Halt"<<endl;
            break;
        }
        reg[0]=0;
    }
	void comb(){
    switch(fun){
        case LUI:
        rdc=simm32_64;
        cout<<"Register "<<rd<<" was set to: "<<simm32_64<<endl;
        break;
        case AUIPC:
        pcc=pc+simm32_64;
        cout<<"Added "<<simm32_64<<"to Program counter"<<endl;
        break;
        case JAL:
        pcc=pc+simm21_64;
        rdc=pc+4;
        cout<<"Register "<<rd<<" was set to line of the next command and Program Counter increased by "<<simm21_64<<endl;
        break;
        case JALR:
        pcc=pc+simm12_64+reg[rs1];
        rdc=pc+4;
        cout<<"Register "<<rd<<" was set to line of the next command and Program Counter increased by the sum of Register "<<rs1<<" and "<<simm21_64<<endl;
        break;
        case BEQ:
        if(reg[rs1]==reg[rs2]){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
        }
        else pcc=pc;
        break;
        case BNE:
        if(!(reg[rs1]==reg[rs2])){
            pcc=pc+simm13_64; 
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
        }
        else pcc=pc;
        break;
        case BLT:
        if(sregrs1_64<sregrs2_64){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
        }  
        else pcc=pc;
        break;
        case BGE:
        if(!(sregrs1_64<sregrs2_64)){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
        }  
        else pcc=pc;
        break;
        case BLTU:
        if(reg[rs1]<reg[rs2]){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
        }else pcc=pc;
        break;
        case BGEU:
        if(!(reg[rs1]<reg[rs2])){
            pcc=pc+simm13_64;
            cout<<"Added "<<simm13_64<<" to Program Counter"<<endl;
        }else pcc=pc;
        break;
        case LB:
        rdc=static_cast<int8_t>(mem[reg[rs1]+(simm12_64)]);
        cout<<"Register "<<rd<<" was set to first byte of memory"<<reg[rs1]+(simm12_64)<<"(signed)"<<endl;
        break;
        case LH:
        rdc=static_cast<int16_t>(mem[reg[rs1]+(simm12_64)]);
        cout<<"Register "<<rd<<" was set to first 2 bytes of memory"<<reg[rs1]+(simm12_64)<<"(signed)"<<endl;
        break;
        case LW:
        rdc=static_cast<int32_t>(mem[reg[rs1]+(simm12_64)]);
        cout<<"Register "<<rd<<" was set to first 4 bytes of memory"<<reg[rs1]+(simm12_64)<<"(signed)"<<endl;
        break;
        case LBU:
        rdc=static_cast<uint8_t>(mem[reg[rs1]+(simm12_64)]);
        cout<<"Register "<<rd<<" was set to first byte of memory"<<reg[rs1]+(simm12_64)<<" (unsigned)"<<endl;
        break;
        case LHU:
        rdc=static_cast<uint16_t>(mem[reg[rs1]+(simm12_64)]);
        cout<<"Register "<<rd<<" was set to first 2 bytes of memory"<<reg[rs1]+(simm12_64)<<" (unsigned)"<<endl;
        break;
        case SB:
        memc=sregrs2_8;
        cout<<"Memory "<<reg[rs1]+(simm12_64)<<" was set to first byte of register "<<rs2<<" (signed)"<<endl;
        break;
        case SH:
        memc=sregrs2_16;
        cout<<"Memory "<<reg[rs1]+(simm12_64)<<" was set to first 2 bytes of register "<<rs2<<" (signed)"<<endl;
        break;
        case SW:
        memc=sregrs2_32;
        cout<<"Memory "<<reg[rs1]+(simm12_64)<<" was set to first 4 bytes of register "<<rs2<<" (signed)"<<endl;
        break;
        case ADDI:
        rdc=reg[rs1]+simm12_64;
        cout<<"Register "<<rd<<" was set to the sum of Register "<<rs1<<" and "<<simm12_64<<endl;
        break;
        case SLTI:
        if(sregrs1_64<simm12_64){
            rdc=1;
            cout<<"Register "<<rd<<" was set to 1"<<endl;
        }  
        else{ 
        rdc=0;
        cout<<"Register "<<rd<<" was set to 0"<<endl;
        }
        break;
        case SLTIU:
        if(reg[rs1]<uimm32_64){
            rdc=1;
            cout<<"Register "<<rd<<" was set to 1"<<endl;
        }
        else{ 
        rdc=0;
        cout<<"Register "<<rd<<" was set to 0"<<endl;
        }
        break;
        case XORI:
        rdc=(simm12_64)^reg[rs1];
        cout<<"Register "<<rd<<" was set to the XOR of Register "<<rs1<<" and "<<simm12_64<<endl;
        break;   
        case ORI:
        rdc=(simm12_64)|reg[rs1];
        cout<<"Register "<<rd<<" was set to the OR of Register "<<rs1<<" and "<<simm12_64<<endl;
        break;                
        case ANDI:
        rdc=(simm12_64)&reg[rs1];
        cout<<"Register "<<rd<<" was set to the AND of Register "<<rs1<<" and "<<simm12_64<<endl;
        break; 
        case SLLI:
        rdc=reg[rs1]<<rs2;
        cout<<"Register "<<rd<<" was set to the Register "<<rs1<<" shifted left by "<<rs2<<endl;
        break;
        case SRLI:
        rdc=static_cast<uint64_t>(reg[rs1]>>rs2);
        cout<<"Register "<<rd<<" was set to the Register "<<rs1<<" shifted right by "<<rs2<<" (logical)"<<endl;
        break; 
        case SRAI:
        rdc=static_cast<int64_t>(reg[rs1]>>rs2);
        cout<<"Register "<<rd<<" was set to the Register "<<rs1<<" shifted right by "<<rs2<<" (arithmetic)"<<endl;
        break;
        case ADD:
        rdc=reg[rs1]+reg[rs2];
        cout<<"Register "<<rd<<" was set to the sum of Register "<<rs1<<" and Register "<<rs2<<endl;
        break;
        case SUB:
        rdc=reg[rs1]-reg[rs2];
        cout<<"Register "<<rd<<" was set to the difference of Register "<<rs1<<" and Register "<<rs2<<endl;
        break;
        case SLL:
        rdc=reg[rs1]<<reg[rs2];
        cout<<"Register "<<rd<<" was set to the Register "<<rs1<<" shifted left by Register "<<rs2<<endl;
        break;
        case SLT:
        if(sregrs1_64<sregrs2_64){
            rdc=1;
            cout<<"Register "<<rd<<" was set to 1"<<endl;
        }
        else{ 
        rdc=0;
        cout<<"Register "<<rd<<" was set to 0"<<endl;
        }
        break;
        case SLTU:
        if(reg[rs1]<reg[rs2]){
            rdc=1;
            cout<<"Register "<<rd<<" was set to 1"<<endl;
        }
        else{ 
        rdc=0;
        cout<<"Register "<<rd<<" was set to 0"<<endl;
        }
        break;
        case XOR:
        rdc=reg[rs1]^reg[rs2];
        cout<<"Register "<<rd<<" was set to the XOR of Register "<<rs1<<" and Register "<<rs2<<endl;
        break;
        case SRL:
        rdc=reg[rs1]>>reg[rs2];
        cout<<"Register "<<rd<<" was set to the Register "<<rs1<<" shifted right by Register "<<rs2<<" (logical)"<<endl;
        break;
        case SRA:
        rdc=sregrs1_64>>sregrs2_64;
        cout<<"Register "<<rd<<" was set to the Register "<<rs1<<" shifted right by Register "<<rs2<<" (arithmetic)"<<endl;
        break;
        case OR:
        rdc=reg[rs1]|reg[rs2];
        cout<<"Register "<<rd<<" was set to the OR of Register "<<rs1<<" and Register "<<rs2<<endl;
        break;
        case AND:
        rdc=reg[rs1]&reg[rs2];
        cout<<"Register "<<rd<<" was set to the AND of Register "<<rs1<<" and Register "<<rs2<<endl;
        break;
    }
    }

	void reset(){
		
	}

protected:
private:

};
#endif