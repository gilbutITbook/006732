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
// ch03.h -- Functions from Chapter 3 of fM2GP.
// -------------------------------------------------------------------

#include <algorithm>

#define RandomAccessIterator typename
#define Integer typename

// Section 3.3

template <RandomAccessIterator I, Integer N>
void mark_sieve(I first, I last, N factor) {
    // assert(first != last)
    *first = false;
    while (last - first > factor) {
        first = first + factor;
        *first = false;
    }
}

template <RandomAccessIterator I, Integer N>
void sift0(I first, N n) {
    std::fill(first, first + n, true);
    N i(0);
    N index_square(3);
    while (index_square < n) {
        // invariant: index_square = 2i^2 + 6i + 3
        if (first[i]) {            // if current candidate is prime
            mark_sieve(first + index_square, 
                       first + n, // last
                       i + i + 3); // factor
        }
        ++i;
        index_square = 2*i*(i + 3) + 3;
    }
}

template <RandomAccessIterator I, Integer N>
void sift1(I first, N n) {
    I last = first + n;
    std::fill(first, last, true);
    N i(0);
    N index_square(3);
    N factor(3);
    while (index_square < n) {
        // invariant: index_square = 2i^2 + 6i + 3, factor = 2i + 3
        if (first[i]) mark_sieve(first + index_square, last, factor);
        ++i;
        factor = i + i + 3;
        index_square = 2*i*(i + 3) + 3;
    }
}

template <RandomAccessIterator I, Integer N>
void sift(I first, N n) {
    I last = first + n;
    std::fill(first, last, true);
    N i(0);
    N index_square(3);
    N factor(3);
    while (index_square < n) {
        // invariant: index_square = 2i^2 + 6i + 3, factor = 2i + 3
        if (first[i]) mark_sieve(first + index_square, last, factor);
        ++i;
        index_square += factor;
        factor += N(2);
        index_square += factor;
    }
}

// Section 3.5

typedef unsigned line_segment;

line_segment gcm(line_segment a, line_segment b) {
    if (a == b)     return a;
    if (b < a)      return gcm(a - b, b);
 /* if (a < b) */   return gcm(a, b - a);
}
