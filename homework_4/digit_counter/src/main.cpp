#include <iostream>

#include <./digit_counting.h>
using namespace std;

int main(){
    // bool result = dc::ReturnTrue();
    // cout<<"RESULT : "<<result<<endl;

    double loss = dc::Warp(1000000000000,4.1);

    cout<<" LOSS : "<<loss<<endl;
    return 0;
}

