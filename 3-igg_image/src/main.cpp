#include <iostream>
#include <igg_image/image.h>
#include <string>
#include <vector>
#include <igg_image/io_strategies/dummy_strategy.h>
#include <igg_image/io_strategies/png_strategy.h>
#include <igg_image/io_strategies/ppm_strategy.h>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using igg::Image;
// using igg::IoStrategy;
using igg::DummyIoStrategy;
using igg::PngIoStrategy;
using igg::PpmIoStrategy;
// using igg::;
// using igg::Image::ReadFromDisk;

int main(){
    PpmIoStrategy dum;
    Image img(dum);    

    const string file_name = "../data/pbmlib.ascii.ppm";
    const string file_name1 = "../data/pbmlib1.ascii.ppm";
    const string file_name2 = "../data/pbmlib2.ascii.ppm";
    const string file_name3 = "../data/pbmlib3.ascii.ppm";
    igg::ImageData img1;
    img.ReadFromDisk(std::move(file_name1));
    // img.WriteToDisk(file_name2);
    // img.UpScale(2);
    img.DownScale(2);
    img.WriteToDisk(std::move(file_name3));

    // cout<<"("<<img.rows()<<","<<img.cols()<<")"<<endl;
    cout<<"Worked Fine"<<endl;
    return 0;   
}   