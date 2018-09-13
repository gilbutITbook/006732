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
// ch07.cpp -- For testing functions from Chapter 7 of fM2GP.
// -------------------------------------------------------------------

#include <iostream>
#include "ch07.h"

int main() {
  std::cout << "mult_acc4(0, 7, 8) = " << mult_acc4(0, 7, 8) << std::endl;
  std::cout << "multiply_accumulate0(0, 7, 8) = " << multiply_accumulate0(0, 7, 8) << std::endl;
  std::cout << "multiply_accumulate(0, 7, 8) = " << multiply_accumulate(0, 7, 8) << std::endl;
  std::cout << "multiply_accumulate_semigroup(0, 7, 8) = " << multiply_accumulate_semigroup(0, 7, 8) << std::endl;
  std::cout << "multiply_semigroup(7, 8) = " << multiply_semigroup(7, 8) << std::endl;
  std::cout << "multiply_monoid(7, 8) = " << multiply_monoid(7, 8) << std::endl;
  std::cout << "multiply_group(7, 8) = " << multiply_group(7, 8) << std::endl;
  std::cout << "power_accumulate_semigroup(1, 2, 10) = " << power_accumulate_semigroup(1, 2, 10) << std::endl;
  std::cout << "power_semigroup(2, 10) = " << power_semigroup(2, 10) << std::endl;
  std::cout << "power_monoid(2, 10) = " << power_monoid(2, 10) << std::endl;
  std::cout << "power_monoid(2, 0) = " << power_monoid(2, 0) << std::endl;
  std::cout << "power_group(2., -10) = " << power_group(2., -10) << std::endl;
  std::plus<int> plus_int;
  std::cout << "power_accumulate_semigroup(0, 7, 8, plus_int) = " << power_accumulate_semigroup(0, 7, 8, plus_int) << std::endl;
  std::cout << "power_semigroup(7, 8, plus_int) = " << power_semigroup(7, 8, plus_int) << std::endl;
  std::cout << "power_monoid(0, 8, plus_int) = " << power_monoid(0, 8, plus_int) << std::endl;
  std::cout << "power_group(7, -8, plus_int) = " << power_group(7, -8, plus_int) << std::endl;
  std::cout << "fib0(5) = " << fib0(5) << std::endl;
  std::cout << "fibonacci_iterative(5) = " << fibonacci_iterative(5) << std::endl;
}
