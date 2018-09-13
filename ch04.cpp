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
// ch04.cpp -- For testing functions from Chapter 4 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include "ch04.h"

int main() {
  std::cout << "gcm0(121, 66) = " << gcm0(121, 66) << std::endl;
  std::cout << "gcm1(121, 66) = " << gcm1(121, 66) << std::endl;
  std::cout << "gcm(121, 66) = " << gcm(121, 66) << std::endl;
  std::cout << "fast_segment_gcm(121, 66) = " << fast_segment_gcm(121, 66) << std::endl;
  std::cout << "remainder(100, 7) = " << remainder(100, 7) << std::endl;
  std::cout << "quotient(100, 7) = " << quotient(100, 7) << std::endl;
  auto p = quotient_remainder(100, 7);
  std::cout << "quotient_remainder(100, 7) = pair<" << p.first << ", " << p.second << ">" << std::endl;
  std::cout << "remainder_fibonacci(100, 7) = " << remainder_fibonacci(100, 7) << std::endl;
  std::cout << "gcm_remainder(121, 66) = " << gcm_remainder(121, 66) << std::endl;
  std::cout << "gcd(121, 66) = " << gcd(121, 66) << std::endl;

}
