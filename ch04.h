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
// ch04.h -- Functions from Chapter 4 of fM2GP.
// -------------------------------------------------------------------

#include <algorithm>

typedef unsigned line_segment;
typedef unsigned integer;

// Section 4.2

bool odd(unsigned n) { return n & 0x1; }
int half(unsigned n) { return n >> 1; }

line_segment gcm0(line_segment a, line_segment b) {
    while (a != b) {
        if (b < a) a = a - b;
        else b = b - a;
    }
    return a;
}

line_segment gcm1(line_segment a,  line_segment b) {
    while (a != b) {
        while (b < a) a = a - b;
    std::swap(a, b);
    }
    return a;
}

line_segment segment_remainder(line_segment a, line_segment b) {
    while (b < a) a = a - b;
    return a;
}

line_segment gcm(line_segment a, line_segment b) {
    while (a != b) {
        a = segment_remainder(a, b);
        std::swap(a, b);
    }
    return a;
}

line_segment fast_segment_remainder(line_segment a, line_segment b) {
    if (a <= b) return a;
    if (a - b <= b) return a - b;
    a = fast_segment_remainder(a, b + b);
    if (a <= b) return a;
    return a - b;
}

line_segment fast_segment_gcm(line_segment a, line_segment b) {
    while (a != b) {
        a = fast_segment_remainder(a, b);
        std::swap(a, b);
    }
    return a;
}

// Section 4.5

line_segment fast_segment_remainder1(line_segment a, line_segment b) {
    // precondition: b != 0
    if (a < b) return a;
    if (a - b < b) return a - b;
    a = fast_segment_remainder1(a, b + b);
    if (a < b) return a;
    return a - b;
}

line_segment largest_doubling(line_segment a, line_segment b) {
    // precondition: b != 0
    while (a - b >= b) b = b + b;
    return b;
}

line_segment remainder(line_segment a, line_segment b) {
    // precondition: b != 0
    if (a < b) return a;
    line_segment c = largest_doubling(a, b);
    a = a - c;
    while (c != b) {
        c = half(c);
        if (c <= a) a = a - c;
    }
    return a;
}

integer quotient(line_segment a, line_segment b) {
    // Precondition: b > 0
    if (a < b) return integer(0);
    line_segment c = largest_doubling(a, b);
    integer n(1);
    a = a - c;
    while (c != b) {
        c = half(c); n = n + n;
        if (c <= a) { a = a - c; n = n + 1; } 
    }
    return n;
}

std::pair<integer, line_segment>
quotient_remainder(line_segment a, line_segment b) {
    // Precondition: b > 0
    if (a < b) return {integer(0), a};
    line_segment c = largest_doubling(a, b);
    integer n(1);
    a = a - c;
    while (c != b) {
        c = half(c); n = n + n;
        if (c <= a) { a = a - c; n = n + 1; }
    }
    return {n, a};
}

line_segment remainder_fibonacci(line_segment a, line_segment b) {
    // Precondition: b > 0
    if (a < b) return a;
    line_segment c = b;
    do {
        line_segment tmp = c; c = b + c; b = tmp;
    } while (a >= c);
    do {
        if (a >= b) a = a - b;
        line_segment tmp = c - b; c = b; b = tmp;
    } while (b < c);
    return a;
}

line_segment gcm_remainder(line_segment a, line_segment b) {
    while (b != line_segment(0)) {
        a = remainder(a, b);
        std::swap(a, b);
    }
    return a;
}

integer gcd(integer a, integer b) {
    while (b != integer(0)) {
        a = a % b;
        std::swap(a, b);
    }
    return a;
}
