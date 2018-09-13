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
// ch11.cpp -- For testing functions from Chapter 11 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include <vector>
#include "ch11.h"

template <InputIterator I>
void print_range(I f, I l) {
  while (f != l) std::cout << *f++ << " ";
  std::cout << std::endl;
}

int main() {
  std::vector<int> v {1, 2, 3, 4, 5, 6, 7};
  auto x = begin(v);
  auto y = end(v);
  std::cout << "Initial sequence:\t\t\t\t\t";
  print_range(x, y);
  std::cout << "Setting x = begin(v); y = end(v)" << std::endl;
  fmgp::swap_ranges(x, x + 3, x + 4);
  std::cout << "After swap_ranges(x, x+3, x+4):\t\t\t\t";
  print_range(x, y);
  fmgp::swap_ranges(x, x + 3, x + 4);
  std::cout << "After swap_ranges(x, x+3, x+4):\t\t\t\t";
  print_range(x, y);
  fmgp::swap_ranges(x, x + 4, x + 4, y);
  std::cout << "After swap_ranges(x, x+4, x+4, y):\t\t\t";
  print_range(x, y);
  fmgp::swap_ranges(x, x + 4, x + 4, y);
  std::cout << "After swap_ranges(x, x+4, x+4, y):\t\t\t";
  print_range(x, y);
  fmgp::swap_ranges_n(x, x + 4, 3);
  std::cout << "After swap_ranges(x, x+4, 3):\t\t\t\t";
  print_range(x, y);
  fmgp::swap_ranges_n(x, x + 4, 3);
  std::cout << "After swap_ranges(x, x+4, 3):\t\t\t\t";
  print_range(x, y);
  auto m = x + 4;
  fmgp::gries_mills_rotate(x, m, y);
  std::cout << "Setting m = x + 4" << std::endl;
  std::cout << "After gries_mills_rotate(x, m, y):\t\t\t";
  print_range(x, y);
  fmgp::gries_mills_rotate(x, x + 3, y);
  std::cout << "After gries_mills_rotate(x, x+3, y):\t\t\t";
  print_range(x, y);
  auto m1 = fmgp::rotate(x, m, y, std::forward_iterator_tag());
  std::cout << "Setting m1 = rotate(x, m, y, forward_iterator_tag())" << std::endl;
  std::cout << "After rotate(x, m, y, forward_iterator_tag()):\t\t";
  print_range(x, y);
  fmgp::rotate(x, m1, y, std::forward_iterator_tag());
  std::cout << "After rotate(x, m1, y, forward_iterator_tag()):\t\t";
  print_range(x, y);
  m1 = fmgp::rotate(x, m, y, std::random_access_iterator_tag());
  std::cout << "After rotate(x, m, y, random_access_iterator_tag()):\t";
  print_range(x, y);
  fmgp::rotate(x, m1, y, std::random_access_iterator_tag());
  std::cout << "After rotate(x, m1, y, random_access_iterator_tag()):\t";
  print_range(x, y);
  fmgp::three_reverse_rotate(x, m, y);
  std::cout << "After three_reverse_rotate(x, m, y)\t\t\t";
  print_range(x, y);
  fmgp::three_reverse_rotate(x, x + 3, y);
  std::cout << "After three_reverse_rotate(x, x+3, y)\t\t\t";
  print_range(x, y);
  m1 = fmgp::rotate(x, m, y, std::bidirectional_iterator_tag());
  std::cout << "After rotate(x, m, y, bidirectional_iterator_tag()):\t";
  print_range(x, y);
  fmgp::rotate(x, m1, y, std::bidirectional_iterator_tag());
  std::cout << "After rotate(x, m1, y, bidirectional_iterator_tag()):\t";
  print_range(x, y);
  fmgp::reverse_n(x, y, 7);
  std::cout << "After reverse_n(x, y, 7):\t\t\t\t";
  print_range(x, y);
  fmgp::reverse_n(x, y, 7);
  std::cout << "After reverse_n(x, y, 7):\t\t\t\t";
  print_range(x, y);
  fmgp::reverse_recursive(x, 7);
  std::cout << "After reverse_recursive(x, 7):\t\t\t\t";
  print_range(x, y);
  fmgp::reverse_recursive(x, 7);
  std::cout << "After reverse_recursive(x, 7):\t\t\t\t";
  print_range(x, y);
  vector<int> buffer(3);
  fmgp::reverse_n_adaptive(x, 7, begin(buffer), 3);
  std::cout << "After reverse_n_adaptive(x, 7, begin(buffer), 3):\t";
  print_range(x, y);
  fmgp::reverse_n_adaptive(x, 7, begin(buffer), 3);
  std::cout << "After reverse_n_adaptive(x, 7, begin(buffer), 3):\t";
  print_range(x, y);
  
}
