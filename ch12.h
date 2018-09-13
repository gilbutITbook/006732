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
// ch12.h -- Functions from Chapter 12 of fM2GP.
// -------------------------------------------------------------------

#include <algorithm>

#define Integer typename
#define BinaryInteger typename
#define EuclideanDomain typename

// Section 12.1

template <Integer N>
bool even(N n) { return !bool(n & 0x1); }

template <BinaryInteger N>
N stein_gcd(N m, N n) {
    if (m < N(0)) m = -m;
    if (n < N(0)) n = -n;
    if (m == N(0)) return n;
    if (n == N(0)) return m;

    // m > 0 && n > 0
  
    int d_m = 0; 
    while (even(m)) { m >>= 1; ++d_m;}

    int d_n = 0;
    while (even(n)) { n >>= 1; ++d_n;}

    // odd(m) && odd(n)
  
    while (m != n) {
      if (n > m) std::swap(n, m);
      m -= n;
      do m >>= 1; while (even(m));
    }
  
    // m == n
  
    return m << std::min(d_m, d_n);
}

// Section 12.4

template <EuclideanDomain E>
E gcd(E a, E b) {
    while (b != E(0)) {
        a = remainder(a, b);
        std::swap(a, b);
    }
    return a;
}

std::pair<int, int>
quotient_remainder(int a, int b) {
  return { a / b, a % b };
}

template <EuclideanDomain E> 
std::pair<E, E> extended_gcd(E a, E b) {
    E x0(1); 
    E x1(0); 
    while (b != E(0)) { 
        // compute new r and x
        std::pair<E, E> qr = quotient_remainder(a, b); 
        E x2 = x0 - qr.first * x1;
        // shift r and x
        x0 = x1;
        x1 = x2; 
        a = b;
        b = qr.second;
    } 
    return {x0, a}; 
} 
