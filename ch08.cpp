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
// ch08.cpp -- For testing functions from Chapter 8 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include "ch08.h"

int main() {
  double poly[] = {1., 2., 1.};
  std::cout << "polynomial_value(...) = " << polynomial_value(poly, poly + 3, 1.) << std::endl;
}
