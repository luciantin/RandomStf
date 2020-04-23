#ifndef MATRIX_CLASS_H
#define MATRIX_CLASS_H


class Matrix{
  private:
  int row;
  int col;
  double** data;
  void SetMetaData(int x, int y);
  void InitMatrix();
  void Reset();

  public:
  Matrix(int x, int y, double start, double offset);
  Matrix(int x, int y, double start);
  Matrix(int x, int y, double** i);
  Matrix(int x, int y);
  explicit Matrix(int x);
  Matrix(const Matrix &x);
  ~Matrix();

  Matrix operator+(const double b);
  void operator!();

  double* GetCol(int x);
  double* GetRow(int y);
  int GetColCnt();
  int GetRowCnt();

  double GetPoint(int x, int y);
  void SetPoint(int x, int y, double i);
  void add(const double b);
  void Translate();  
  void PrintMatrix();
};


#endif


/*

matrix[stupac][red]

m/n
  ---------------
| a11 a12 ... a1n |
| a21 a22 ... a2n |
| ... ... ... ... |
| am1 am2 ... amn |
  ---------------

n je red
m je stupac

a_ij (i = 1,2,...,m; j = 1,2,...,n)

prvo stupac pa red

*/