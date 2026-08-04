#include <iostream>
#include "core_sc.h"
#include "fetch.h"


using namespace std;
extern bool run;
int main(){
    Core_sc sc;
    while(run){
    sc.comb();
    sc.ff();
    }
    

    return 0;
}