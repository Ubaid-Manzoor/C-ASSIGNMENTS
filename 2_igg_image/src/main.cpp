#include <iostream>
#include <image.h>
#include <io_tools.h>
#include <stdio.h>
#include <string>
#include <vector>

using igg::Image;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using igg::io_tools::ImageData;
using igg::io_tools::WriteToPgm;
using igg::io_tools::ReadFromPgm;


int main(){
    Image img(4,5);

    string filename{"/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/data/lena.ascii.pgm"};
    img.FillFromPgm(filename);

    // cout<<img.at(0,1)<<endl;
    img.UpScale(2);
    img.DisplayDetails();
    string filename1{"/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/data/lena1.ascii.pgm"};
    img.WriteToPgm(filename1);
    // vector< vector<float> > Hist = img.ComputeHistogram(10);
    return 0;
}