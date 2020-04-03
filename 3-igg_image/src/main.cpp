#include <iostream>
#include <igg_image/image.h>
#include <string>
#include <vector>
#include <igg_image/io_strategies/dummy_strategy.h>
#include <igg_image/io_strategies/png_strategy.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using igg::Image;
// using igg::IoStrategy;
using igg::DummyIoStrategy;
using igg::PngIoStrategy;
// using igg::Image::ReadFromDisk;

int main(){
    PngIoStrategy dum;
    Image img(dum);    

    const string file_name = "../data/joke.png";
    const string file_name1 = "../data/joke1.png";
    img.ReadFromDisk(std::move(file_name));
    img.WriteToDisk(std::move(file_name1));

    cout<<"("<<img.rows()<<","<<img.cols()<<")"<<endl;
    cout<<"Worked Fine"<<endl;
    return 0;   
}   