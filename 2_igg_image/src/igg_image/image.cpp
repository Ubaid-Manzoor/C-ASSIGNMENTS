#include <iostream>
#include <image.h>
#include <io_tools.h>
#include <string>
#include <vector>

// #include <io_tools.h>

using std::cout;
using std::endl;
using std::string;
using igg::io_tools::ReadFromPgm;
using igg::io_tools::ImageData;
using std::vector;

igg::Image::Image():data_{}{}

igg::Image::Image(int rows, int cols):rows_{rows}, cols_{cols}{
    data_.resize(rows_*cols_,0);
}

int igg::Image::rows() const{
    return rows_;
}

int igg::Image::cols() const{
    return cols_;
}

int igg::Image::positionFromCoordinates(int width,int row,int col) const{
    return row * width + col;
}

int igg::Image::at(int rows, int cols) const{
    int position = igg::Image::positionFromCoordinates(cols_, rows,cols);
    return data_[position];
}

int& igg::Image::at(int rows, int cols){
    int position = igg::Image::positionFromCoordinates(cols_,rows,cols);
    return data_[position];
}

bool igg::Image::FillFromPgm(const std::string& file_name){
    // string path = "/home/ubaid/Desktop/MyDrive/Computer Science/Programming Languages/Modern C++ 2018/c++_projects/HomeWorks/igg_image_0/igg_image/data/lena.ascii.pgm";
    ImageData result_img = ReadFromPgm(file_name);

    if(result_img.rows == 0 ){
        return false;
    }else{
        rows_ = result_img.rows;
        cols_ = result_img.cols;
        max_val_ = result_img.max_val;
        data_ = result_img.data;
    }
}


void igg::Image::DisplayDetails() const{
    cout<<"( rows = "<<rows_<<" , cols = "<<cols_<<", "<<"max_val_ = "<<max_val_<<" )"<<endl;
}

void igg::Image::WriteToPgm(const std::string& file_name){
    ImageData img_data{rows_,cols_,max_val_,data_};
    bool result = igg::io_tools::WriteToPgm(img_data,file_name);
    if(result){
        cout<<"Worked Fine"<<endl;
    }else{
        cout<<"Something went wrong"<<endl;
    }
}


vector< std::vector<float> > igg::Image::ComputeHistogram(int bins) const {
    vector< vector<float> > Histogram;
    Histogram.resize( bins );

    for(int i = 0 ; i < bins ; i++){
        Histogram[i].reserve( int( ( rows_*cols_ )/( 2 * bins ) ) );
        int start = int( (i * max_val_)/bins);
        int end = int( ( ((i + 1) * max_val_)/bins) );

        for(int pixel:data_){
            if(start <= pixel && pixel < end){
                Histogram[i].emplace_back(pixel);
            }
        }
    }

    return Histogram;
}


void igg::Image::UpScale(int scale) {
    int rowsAfterScale = rows_ * scale;
    int colsAfterScale = cols_ * scale;

    vector<int> scaledImage;
    scaledImage.resize( rowsAfterScale*colsAfterScale );

    // Fill the new Image with Original
    for(int row = 0 ; row < rows_ ; row++){
        for(int col = 0 ; col < cols_ ; col++){

            int scaledImageRowNo = row * scale;
            int scaledImageColNo = col * scale;

            int originalImagePosition = igg::Image::positionFromCoordinates(cols_,row,col);
            int newImagePosition = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo, scaledImageColNo);

            scaledImage[newImagePosition] = data_[originalImagePosition];

            for(int j = 1; j < scale ; j++){
                int newPositionX = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo,scaledImageColNo+j);
                int newPositionY = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo+j,scaledImageColNo);
                
                scaledImage[newPositionX] = scaledImage[newImagePosition];
                try{
                    scaledImage[newPositionY] = scaledImage[newImagePosition];
                }catch(...){}

                for(int y = 1 ; y < scale ; ++y){
                    int newPositionXY = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo+y,scaledImageColNo+j);
                    scaledImage[newPositionXY] = scaledImage[newImagePosition];
                }

            }
        }
    }

    data_ = scaledImage;
}