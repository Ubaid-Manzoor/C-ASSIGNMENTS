// Copyright Igor Bogoslavskyi, year 2018.
// In case of any problems with the code please contact me.
// Email: igor.bogoslavskyi@uni-bonn.de.

#pragma once

#include <vector>
#include <igg_image/io_strategies/strategy.h>
#include <string>
#include <memory>

using std::string;

namespace igg {

class Image {
 public:
  /// A struct within class Image that defines a pixel.
  struct Pixel {
    int red;
    int green;
    int blue;
  };

  // TODO: fill public interface.
  // Image();
  Image(const std::shared_ptr<IoStrategy>&);
  Image(int rows, int cols, const std::shared_ptr<IoStrategy>&);
  // ~Image();


  // Getter Functions
  int rows() const;
  int cols() const;

  // Setter Functions
  Pixel at(int,int) const;
  Pixel& at(int, int);

  // Read and Write Functions
  bool ReadFromDisk(const string& file_name);
  void WriteToDisk(const string& file_name);

  // Data Conversion Functions
  std::vector<Pixel> convertToVectorOfPixels(std::vector< std::vector<int> >);
  std::vector< std::vector<int> >  convertToVectorsOfRGB(std::vector<Pixel>);

  //Image Resizing Fucntions
  void DownScale(int scale);
  void UpScale(int scale);

  // FUNDTIONS TO CHANGE STRATEGY
  // void changeStragy(const igg::IoStrategy& new_strategy){
  //   io_strategy = new_strategy;
  // }

  // Helper Functions
  int positionFromCoordinates(int, int, int) const;

  // Function to Set a Strategy
  void SetIoStrategy(const std::shared_ptr<IoStrategy>& strategy_ptr){
    this->strategy_ptr = strategy_ptr;
  }

 private:

  // TODO: add missing private members when needed.
  // const igg::IoStrategy& io_strategy;
  std::shared_ptr<igg::IoStrategy> strategy_ptr=nullptr;

  // Already Given
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<Pixel> data_;
};

}  // namespace igg
