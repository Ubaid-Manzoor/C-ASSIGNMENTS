#pragma once

#include <vector>

namespace igg {

class Image {
 public:
  ///////////////////// Create the public interface here ///////////////////////
  /// Constructors
  Image();
  Image(int rows, int cols);

  // Getter Functions
  int rows() const;
  int cols() const;

  // Setter Functions
  int at(int,int) const;
  int& at(int, int);


  // Functions to read and write to file
  bool FillFromPgm(const std::string& file_name);
  void WriteToPgm(const std::string& file_name);

  std::vector< std::vector<float> > ComputeHistogram(int bins) const;

  //Helper Function
  void DisplayDetails() const;
  int positionFromCoordinates(int width,int row,int col) const;

  // Rescaling Functions
  void DownScale(int scale);
  void UpScale(int scale);
 
 private:
  int rows_ = 0;
  int cols_ = 0;
  int max_val_ = 255;
  std::vector<int> data_;
};

}  // namespace igg
