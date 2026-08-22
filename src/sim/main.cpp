#include <iostream>
#include "../modules/mc/core_mc.h"

using namespace std;
extern bool run;
int main(){
    Core_mc mc;
    while(run){
        mc.comb();
        mc.ff();
    }
    

    return 0;
}