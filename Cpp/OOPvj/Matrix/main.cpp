#include "./Matrix.h"
#include <iostream>
#include <cmath>



int main() {

  Matrix a(6,1,1,1);
  Matrix b = a;

  a.add(2);


  a.PrintMatrix();
  b.PrintMatrix();


  std::cout<<'done';

  return 0;
}