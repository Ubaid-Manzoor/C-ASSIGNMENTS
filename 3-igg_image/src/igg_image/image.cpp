#include <iostream>
#include <igg_image/image.h>
#include <string>
#include <vector>
#include <igg_image/io_strategies/strategy.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;

// igg::Image::Image(){}

igg::Image::Image(const IoStrategy& io_strategy):io_strategy{io_strategy}{}

igg::Image::Image(int rows, int cols, const IoStrategy& io_strategy):rows_{rows},cols_{cols},io_strategy{io_strategy}{}

bool igg::Image::ReadFromDisk(const string& file_name){
    cout<<"In Read Function"<<endl;
    // io_strategy.Read(file_name);
}


// void igg::Image::WriteToDisk(const string& file_name){
//     // io_strategy.Write(file_name,data_);
// }


int igg::Image::rows() const{
    return rows_;
}

int igg::Image::cols() const{
    return cols_;
}