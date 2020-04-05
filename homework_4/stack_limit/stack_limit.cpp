#include <iostream>
#include <numeric>

using namespace std;

int main(){
    int step = (1024 * 100) / 8;
    // double sum = 0.0;
    int size = step * 1;
    for(unsigned int i = 0 ; ; ++i){
        size += step * i;
        double arr[size];
        std::fill(arr,arr + size,1.5);

        // JUST TO ASSURE COMPILER CANT OPTIMIZE
        double sum = std::accumulate(arr, arr + size,0);

        std::cerr << size <<endl;
    }
}