#include <iostream>
#include "digit_counting.h"

namespace dc {
    bool ReturnTrue(){
        return true;
    }

    double Warp(double number, double factor){
        double newFactor = factor;
        newFactor += number;
        newFactor -= number; // newFactor at this line give the amount of factor which was added to number
        return factor/* what was added*/ - newFactor /*what actually got added*/ ;    
    }
}