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
// ch13.cpp -- For testing functions from Chapter 13 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include "ch07.h"
#include "ch12.h"
#include "ch13.h"

int main() {
  std::cout << "is_prime(101) = " << is_prime(101) << std::endl;
  std::cout << "is_prime(105) = " << is_prime(105) << std::endl;
  std::cout << "is_prime(10007) = " << is_prime(10007) << std::endl;
  std::cout << "(24 * multiplicative_inverse_fermat(24, 101)) % 101 = " << (24 * multiplicative_inverse_fermat(24, 101)) % 101 << std::endl;
  std::cout << "(24 * multiplicative_inverse_fermat(24, 10007)) % 10007 = " << (24 * multiplicative_inverse_fermat(24, 10007)) % 10007 << std::endl;
  std::cout << "(24 * multiplicative_inverse(24, 10007)) % 10007 = " << (24 * multiplicative_inverse(24, 10007)) % 10007 << std::endl;
  std::cout << "fermat_test(10001, 7) = " << fermat_test(10001, 7) << std::endl;
  std::cout << "fermat_test(10007, 7) = " << fermat_test(10007, 7) << std::endl;
  std::cout << "miller_rabin_test(10001, 625, 4, 7) = " << miller_rabin_test(10001, 625, 4, 7) << std::endl;
  std::cout << "miller_rabin_test(10007, 5003, 1, 7) = " << miller_rabin_test(10007, 5003, 1, 7) << std::endl;
  std::cout << "fermat_test(1729, 2) = " << fermat_test(1729, 2) << std::endl;
  std::cout << "miller_rabin_test(1729, 27, 6, 2) = " << miller_rabin_test(1729, 27, 6, 2) << std::endl;
}
