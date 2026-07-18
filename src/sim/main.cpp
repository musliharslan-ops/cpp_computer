#include <iostream>
#include "wrapper.h"

using namespace std;

int main(){

    Core my_core = new Core();
    while(true){
        my_core.ff();
        my_core.comb();
    }

    return 0;
}