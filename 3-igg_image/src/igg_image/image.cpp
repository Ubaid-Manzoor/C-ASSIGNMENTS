#include <iostream>
#include <igg_image/image.h>
#include <string>
#include <vector>
#include <igg_image/io_strategies/strategy.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
// igg::Image::Image():io_strategy{NULL}{}

igg::Image::Image(const igg::IoStrategy& io_strategy):io_strategy{io_strategy}{}

igg::Image::Image(int rows, int cols, const igg::IoStrategy& io_strategy):rows_{rows},cols_{cols},io_strategy{io_strategy}{}

igg::Image::~Image(){
    // &io_strategy.
}

vector<igg::Image::Pixel> igg::Image::convertToVectorOfPixels(vector< vector<int> > vecsOfColors){
    // vecsOfColors == {red vec, green vec, blue vec}
    vector<igg::Image::Pixel> vecOfPixels;
    cout<<"Size of ColorVector : "<<vecsOfColors[0].size()<<endl;
    vecOfPixels.resize(vecsOfColors[0].size());

    for(int i=0 ; i < vecsOfColors[0].size() ; ++i){
        vecOfPixels[i].red = vecsOfColors[0][i];
        vecOfPixels[i].green = vecsOfColors[1][i];
        vecOfPixels[i].blue = vecsOfColors[2][i];
    }

    return vecOfPixels;
}

vector< vector<int> > igg::Image::convertToVectorsOfRGB(vector<igg::Image::Pixel> vecOfPixels){
    vector< vector<int> > vecsOfRGB(3, vector<int>(int(vecOfPixels.size())));
    cout<<"Size Of RGB : "<<vecsOfRGB[0].size()<<endl;
    for(int i = 0 ; i < vecOfPixels.size() ; ++i){
        vecsOfRGB[0][i] = vecOfPixels[i].red;
        vecsOfRGB[1][i] = vecOfPixels[i].green;
        vecsOfRGB[2][i] = vecOfPixels[i].blue;
    }

    return vecsOfRGB;
}

bool igg::Image::ReadFromDisk(const string& file_name){
    cout<<"In Read Function"<<endl;
    try{
        igg::ImageData image = io_strategy.Read(file_name);
        rows_ = image.rows;
        cols_ = image.cols;
        max_val_ = image.max_val;
        data_ = convertToVectorOfPixels(image.data);
        return true;
    }catch(...){
        cout<<"Something Went Wrong";
        return false;
    }
    
}


void igg::Image::WriteToDisk(const string& file_name){
    vector< vector<int> > vecsOfRGB = convertToVectorsOfRGB(data_);

    ImageData data{rows_,cols_,max_val_,vecsOfRGB};
    io_strategy.Write(file_name, data);
}


int igg::Image::rows() const{
    return rows_;
}

int igg::Image::cols() const{
    return cols_;
}