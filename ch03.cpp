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
// ch03.cpp -- For testing functions from Chapter 3 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include <vector>
#include "ch03.h"

template <RandomAccessIterator I, Integer N>
void print_sieve(I first, N n) {
  N i {0};
  std::cout << 2;
  while (i < n) {
    if (*first) {
      std::cout << " " << 2 * i + 3;
    }
    ++first;
    ++i;
  }
  std::cout << std::endl;
}

int main() {
  std::vector<int> v(500);
  sift0(begin(v), 50);
  std::cout << "sift0(begin(v), 50):\n";
  print_sieve(begin(v), 50);
  sift1(begin(v), 50);
  std::cout << "sift1(begin(v), 50):\n";
  print_sieve(begin(v), 50);
  sift(begin(v), 500);
  std::cout << "sift(begin(v), 500):\n";
  print_sieve(begin(v), 500);
  std::cout << "gcm(15, 9) = " << gcm(15, 9) << std::endl;
}
