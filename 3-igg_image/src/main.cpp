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
// using igg::Image::ReadFromDisk;

int main(){
    // Image img();
    Image img(igg::DummyIoStrategy());
    // img.Read
    bool a = img.ReadFromDisk("asd");

    // img.Read
    cout<<"Worked Fine"<<endl;
    return 0;   
}   