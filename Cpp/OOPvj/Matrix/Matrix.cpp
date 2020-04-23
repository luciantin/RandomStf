#include "Matrix.h"
#include <iostream>

void Matrix::Reset(){
  for(int i=0;i<col;i++) delete [] data[i];
  delete [] data;
  col = 0;
  row = 0;
}

Matrix::~Matrix(){
  for(int i=0;i<col;i++) delete[] data[i];
  delete [] data;
}

void Matrix::SetMetaData(int x, int y){
  col = x;
  row = y;
}

void Matrix::InitMatrix(){
  data = new double* [col];  
  for(int i=0;i<col;i++) data[i] = new double[row];
}

Matrix::Matrix(int x,int y, double** i){
  SetMetaData(x,y);
  data = i;
}

Matrix::Matrix(int x,int y, double start){
  SetMetaData(x,y);  
  InitMatrix();
  for(int i=0;i<col;i++) for(int j=0;j<row;j++) data[i][j] = start;
}

Matrix::Matrix(int x,int y, double start, double offset){
  SetMetaData(x,y);  
  InitMatrix();
  for(int i=0;i<col;i++){
    for(int j=0;j<row;j++){
      data[i][j] = start;
      start += offset;
    }
  }
}

Matrix::Matrix(int x,int y){
  SetMetaData(x,y);  
  InitMatrix();
}

Matrix::Matrix(int x){
  SetMetaData(x,x);
  InitMatrix();
}

void Matrix::PrintMatrix(){
  std::cout<<std::endl;
  for(int i=0;i<row;i++) { 
    std::cout<<std::endl<<'|';       
      for(int j=0;j<col;j++) std::cout<<data[j][i]<<'|';
    }
  std::cout<<std::endl;
}

double Matrix::GetPoint(int x, int y){return data[x][y];}

void Matrix::SetPoint(int x, int y, double i){data[x][y]=i;}

// b_ij = a_ji
void Matrix::Translate(){
  int rw = row,cl = col;
  double **tmp_data = new double*[row];
  
  for(int i = 0; i<row;i++ ) tmp_data[i] = GetRow(i); 

  Reset();
  SetMetaData(rw,cl);
  data = tmp_data;  
}

double* Matrix::GetCol(int x){  
  double* tmp_col = new double[row];
  for(int i=0;i<row;i++) tmp_col[i] = data[x][i];
  return tmp_col;
}

double* Matrix::GetRow(int y){
  double* tmp_row = new double[col];
  for(int i = 0;i<col;i++) tmp_row[i] = data[i][y];
  return tmp_row;
}


void Matrix::add(const double b){
  std::cout<<'B';
  for(int i=0;i<col;i++) for(int j=0;j<row;j++) data[i][j] += b;
  //return *this;
}

void Matrix::operator!(){
  std::cout<<'A';
  // for(int i=0;i<col;i++) for(int j=0;j<row;j++) data[i][j] += b;
  // return *this;
}