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
// ch10.cpp -- For testing functions from Chapter 10 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <list>
#include "ch10.h"

struct {
  bool operator()(int x) { return x == 3; }
} equal_3;

struct {
  bool operator()(int x) { return x < 3; }
} less_3;

int main() {
  std::vector<int> v { 1, 2, 3, 4, 5};
  std::list<int> l { 1, 2, 3, 4, 5};
  std::cout << "Initial sequence:  1 2 3 4 5" << std::endl;
  std::cout << "vector v and list l initialized to this sequence." << std::endl;

  auto x1 = begin(v);
  auto y1 = end(v);
  auto x2 = begin(l);
  auto y2 = end(l);
  std::cout << "Setting x1 = begin(v); y1 = end(v)" << std::endl;
  std::cout << "Setting x2 = begin(l); y2 = end(l)" << std::endl;

  std::cout << "fmgp::distance(x1, y1) is " << fmgp::distance(x1, y1) << std::endl;
  std::cout << "fmgp::distance(x2, y2) is " << fmgp::distance(x2, y2) << std::endl;
  fmgp::advance(x1, 3);
  std::cout << "After advance(x1, 3): ";
  std::cout << "(x1 == y1) is " << (x1 == y1) << std::endl;
  fmgp::advance(x2, 3);
  std::cout << "After advance(x2, 3): ";
  std::cout << "(x2 == y2) is " << (x2 == y2) << std::endl << std::endl;

  x1 = begin(v);
  y1 = end(v);
  x2 = begin(l);
  y2 = end(l);
  std::cout << "Setting x1 = begin(v); y1 = end(v)" << std::endl;
  std::cout << "Setting x2 = begin(l); y2 = end(l)" << std::endl;

  std::cout << "*fmgp::find_if(x1, y1, equal_3) is " << *fmgp::find_if(x1, y1, equal_3) << std::endl;
  std::cout << "*fmgp::find_if(x2, y2, equal_3) is " << *fmgp::find_if(x2, y2, equal_3) << std::endl;
  std::cout << "*fmgp::find_if_n(x1, 5, equal_3).first is " << *fmgp::find_if_n(x1, 3, equal_3).first << std::endl;
  std::cout << "*fmgp::find_if_n(x2, 5, equal_3).first is " << *fmgp::find_if_n(x2, 3, equal_3).first << std::endl;

  std::cout << "*fmgp::partition_point(x1, y1, less_3) is " << *fmgp::partition_point(x1, y1, less_3) << std::endl;
  std::cout << "*fmgp::partition_point(x2, y2, less_3) is " << *fmgp::partition_point(x2, y2, less_3) << std::endl;
  std::cout << "*fmgp::partition_point_n(x1, 5, less_3) is " << *fmgp::partition_point_n(x1, 3, less_3) << std::endl;
  std::cout << "*fmgp::partition_point_n(x2, 5, less_3) is " << *fmgp::partition_point_n(x2, 3, less_3) << std::endl;

  std::cout << "*fmgp::upper_bound(x1, y1, 2) is " << *fmgp::upper_bound(x1, y1, 2) << std::endl;
  std::cout << "*fmgp::upper_bound(x2, y2, 2) is " << *fmgp::upper_bound(x2, y2, 2) << std::endl;

  std::cout << "*fmgp::lower_bound(x1, y1, 2) is " << *fmgp::lower_bound(x1, y1, 2) << std::endl;
  std::cout << "*fmgp::lower_bound(x2, y2, 2) is " << *fmgp::lower_bound(x2, y2, 2) << std::endl;
}
