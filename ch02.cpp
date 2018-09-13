// Copyright (c) 2014 Alexander A. Stepanov and Daniel E. Rose
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without
// fee, provided that the above copyright notice appear in all copies
// and that both that copyright notice and this permission notice
// appear in supporting documentation. The authors make no
// representations about the suitability of this software for any
// purpose. It is provided "as is" without express or implied
// warranty.
//
// This code accompanies the "fM2GP" book:
//
//	From Mathematics to Generic Programming
//	by Alexander Stepanov and Daniel E. Rose
//	Addison-Wesley Professional, 2015
//
// -------------------------------------------------------------------
// ch02.cpp -- For testing functions from Chapter 2 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include "ch02.h"

using namespace std;

int main() {
  cout << "multiply0(7, 8) = " << multiply0(7, 8) << endl;
  cout << "multiply1(7, 8) = " << multiply1(7, 8) << endl;
  cout << "multiply_by_15(15) = " << multiply_by_15(15) << endl;
  cout << "mult_acc0(0, 7, 8) = " << mult_acc0(0, 7, 8) << endl;
  cout << "mult_acc1(0, 7, 8) = " << mult_acc1(0, 7, 8) << endl;
  cout << "mult_acc2(0, 7, 8) = " << mult_acc2(0, 7, 8) << endl;
  cout << "mult_acc3(0, 7, 8) = " << mult_acc3(0, 7, 8) << endl;
  cout << "mult_acc4(0, 7, 8) = " << mult_acc4(0, 7, 8) << endl;
  cout << "multiply2(7, 8) = " << multiply2(7, 8) << endl;
  cout << "multiply3(7, 8) = " << multiply3(7, 8) << endl;
  cout << "multiply4(7, 8) = " << multiply4(7, 8) << endl;
}
