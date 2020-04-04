#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "ppm_strategy.h"

using std::cout;
using std::string;
using std::endl;
using std::vector;


bool igg::PpmIoStrategy::Write(const string& file_name, const igg::ImageData& image_data) const {
    int rows = image_data.rows;
    int cols = image_data.cols;
    int max_val = image_data.max_val;

    std::ofstream out(file_name,std::ios_base::out);

    // CHECK IF FILE WAS OPEN CORRECTLY
    if(out.is_open()){
        // CHECK FOR DIMENSION OF IMAGE
        // IF 2D GO INTO IF BLOCK
        if(true){
            vector< vector<int> > data = image_data.data;
            out << "P3" << "\n";
            out << "# " << "Some Text" << "\n";
            out << rows <<" " <<cols <<"\n";
            out << max_val << "\n";

            int sizeOfInnerVec = data[0].size();
            for(int i = 0 ; i < sizeOfInnerVec ; ++i){
                int red = data[0][i];
                int green = data[1][i];
                int blue = data[2][i];
                out << red << " " << green <<" " << blue << " ";
                if(i != 0 && i % 4 == 0){
                    out << "\n"; 
                }
            }

        // IF 1D GO INTO ELSE BLOCK
        }else{
            // NOT DONE YET
        }

    // IF FILE DID NOT OPEN FOR SOME REASON 
    // GO INTO ELSE BLOCK
    }else{
        cout<< "SOMETHING WENT WRONG"<< endl;
        return EXIT_FAILURE;
    }
}

igg::ImageData igg::PpmIoStrategy::Read(const string& file_name) const {
    int rows,cols,max_value;

    std::ifstream in(file_name,std::ios_base::in);

    if(in.is_open()){
        string format, diagonal_line, hash;

        // READING THE FORMAT OF IMAGE
        in >> format;

        // SKIPPING THE COMMENT LINE    
        in >> hash;
        getline(in, diagonal_line);

        // READING SHAPE AND MAX_VALUE
        in >> rows >> cols;
        in >> max_value;


        vector< vector<int> > data(3, vector<int>(rows * cols));
        //  FORMAT IS RGB WHICH IS REPRESENTED BY 'P3'
        if(format == "P3"){
            unsigned short int red, green, blue; 
            for(int i = 0 ; ; ++i){
                if(in.eof()){
                    break;
                }
                in >> red >> green >> blue;
                data[0][i] = red;
                data[1][i] = green;
                data[2][i] = blue;
            }
            igg::ImageData image_data{rows,cols,max_value,data};
            return image_data;
        }
     }else{
         vector< vector <int> > data;
         igg::ImageData image_data{0,0,255, data};
         return image_data;
     }
}

