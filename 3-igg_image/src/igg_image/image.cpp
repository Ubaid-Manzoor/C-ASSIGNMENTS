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

igg::Image::Image(int rows, int cols, const igg::IoStrategy& io_strategy):io_strategy{io_strategy}{
    rows_ = {rows};
    cols_ = {cols};
}

igg::Image::~Image(){
    // &io_strategy.
}

vector<igg::Image::Pixel> igg::Image::convertToVectorOfPixels(vector< vector<int> > vecsOfColors){
    // vecsOfColors == {red vec, green vec, blue vec}
    vector<igg::Image::Pixel> vecOfPixels;
    // cout<<"Size of ColorVector : "<<vecsOfColors[0].size()<<endl;
    vecOfPixels.resize(vecsOfColors[0].size());

    for(unsigned int i=0 ; i < vecsOfColors[0].size() ; ++i){
        vecOfPixels[i].red = vecsOfColors[0][i];
        vecOfPixels[i].green = vecsOfColors[1][i];
        vecOfPixels[i].blue = vecsOfColors[2][i];
    }

    return vecOfPixels;
}

vector< vector<int> > igg::Image::convertToVectorsOfRGB(vector<igg::Image::Pixel> vecOfPixels){
    vector< vector<int> > vecsOfRGB(3, vector<int>(int(vecOfPixels.size())));
    cout<<"Size Of RGB : "<<vecsOfRGB[0].size()<<endl;
    for(unsigned int i = 0 ; i < vecOfPixels.size() ; ++i){
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
        cout<<"CHECK VALUE :: "<<image.data[0].back()<<endl;
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


/////////////////////////////////   IMAGE RESIZING FUNCTIONS //////////////////////////////////

int igg::Image::positionFromCoordinates(int width,int row,int col) const{
    return row * width + col;
}

void igg::Image::UpScale(int scale){
    int rowsAfterScale = rows_ * scale;
    int colsAfterScale = cols_ * scale;

    vector<igg::Image::Pixel> scaledImage;
    scaledImage.resize( rowsAfterScale*colsAfterScale );

    // Fill the new Image with Original
    for(int row = 0 ; row < rows_ ; row++){
        for(int col = 0 ; col < cols_ ; col++){

            int scaledImageRowNo = row * scale;
            int scaledImageColNo = col * scale;

            int originalImagePosition = igg::Image::positionFromCoordinates(cols_,row,col);
            int newImagePosition = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo, scaledImageColNo);

            scaledImage[newImagePosition].red = data_[originalImagePosition].red;
            scaledImage[newImagePosition].green = data_[originalImagePosition].green;
            scaledImage[newImagePosition].blue = data_[originalImagePosition].blue;

            for(int j = 1; j < scale ; j++){
                int newPositionX = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo,scaledImageColNo+j);
                int newPositionY = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo+j,scaledImageColNo);
                
                scaledImage[newPositionX].red = scaledImage[newImagePosition].red;
                scaledImage[newPositionX].green = scaledImage[newImagePosition].green;
                scaledImage[newPositionX].blue = scaledImage[newImagePosition].blue;
                try{
                    scaledImage[newPositionY].red = scaledImage[newImagePosition].red;
                    scaledImage[newPositionY].green = scaledImage[newImagePosition].green;
                    scaledImage[newPositionY].blue = scaledImage[newImagePosition].blue;
                }catch(...){}

                for(int y = 1 ; y < scale ; ++y){
                    int newPositionXY = igg::Image::positionFromCoordinates(colsAfterScale, scaledImageRowNo+y,scaledImageColNo+j);
                    scaledImage[newPositionXY].red = scaledImage[newImagePosition].red;
                    scaledImage[newPositionXY].green = scaledImage[newImagePosition].green;
                    scaledImage[newPositionXY].blue = scaledImage[newImagePosition].blue;
                }

            }
        }
    }

    // cout<<"SCALEDIMAGE SIZE : "<<scaledImage.size()<<endl;
    data_ = scaledImage;
    rows_ = rowsAfterScale;
    cols_ = colsAfterScale;
}


void igg::Image::DownScale(int scale){
    int rowsAfterScale = int(rows_ / scale);
    int colsAfterScale = int(cols_ / scale);

    vector <igg::Image::Pixel> scaledImage;
    scaledImage.resize(rowsAfterScale * colsAfterScale);

    for(int row = 0 ; row < rowsAfterScale ; ++row ){
        for(int col = 0 ; col < colsAfterScale ; ++col){
            int originalImageRowNo = row * scale;
            int originalImageColNo = col * scale;

            int originalImagePosition = igg::Image::positionFromCoordinates(cols_,originalImageRowNo,originalImageColNo);
            int scaledImagePosition = igg::Image::positionFromCoordinates(colsAfterScale,row,col);

            scaledImage[scaledImagePosition].red = data_[originalImagePosition].red;
            scaledImage[scaledImagePosition].green = data_[originalImagePosition].green;
            scaledImage[scaledImagePosition].blue = data_[originalImagePosition].blue;
        }
    }

    data_ = scaledImage;
    rows_ = rowsAfterScale;
    cols_ = colsAfterScale;
    /// Temporary fix of error
    // data_.resize(512 * 512);
}
/////////////////////////////////  IMAGE RESIZING FUNCTIONS ENDS //////////////////////////////