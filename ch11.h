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
// ch11.h -- Functions from Chapter 11 of fM2GP.
// -------------------------------------------------------------------

#include <algorithm>
#include <iterator>

#define InputIterator typename
#define ForwardIterator typename
#define BidirectionalIterator typename
#define RandomAccessIterator typename
#define OutputIterator typename
#define Predicate typename
#define Integer typename
#define BinaryInteger typename
#define EuclideanDomain typename
#define Semiregular typename
#define Transformation typename

template <Integer N>
bool odd(N n) { return bool(n & 0x1); }

template <Integer N>
N half(N n) { return n >> 1; }

template <InputIterator I>
using ValueType = typename std::iterator_traits<I>::value_type;

template <InputIterator I>
using DifferenceType =
        typename std::iterator_traits<I>::difference_type;

template <InputIterator I>
using IteratorCategory =
        typename std::iterator_traits<I>::iterator_category;

using namespace std;

namespace fmgp {

// Section 11.1

template <Semiregular T>
void swap(T& x, T& y) {
    T tmp(x);
    x = y;
    y = tmp;
}

// Section 11.2

template <ForwardIterator I0, ForwardIterator I1>
// ValueType<I0> == ValueType<I1>
I1 swap_ranges(I0 first0, I0 last0, I1 first1) {
    while (first0 != last0) fmgp::swap(*first0++, *first1++);
    return first1;
}

template <ForwardIterator I0, ForwardIterator I1>
std::pair<I0, I1> swap_ranges(I0 first0, I0 last0, I1 first1, I1 last1) {
    while (first0 != last0 && first1 != last1) {
      fmgp::swap(*first0++, *first1++);
    }
    return {first0, first1};
}

template <ForwardIterator I0, ForwardIterator I1, Integer N>
std::pair<I0, I1> swap_ranges_n(I0 first0, I1 first1, N n) {
    while (n != N(0)) {
      fmgp::swap(*first0++, *first1++);
        --n;
    }
    return {first0, first1};
}

// Section 11.3

template <ForwardIterator I>
void gries_mills_rotate(I f, I m, I l) {
    // u = distance(f, m) && v = distance(m, l)
    if (f == m || m == l) return;             // u == 0 || v == 0
    pair<I, I> p = swap_ranges(f, m, m, l);
    while(p.first != m || p.second != l) {
        if (p.first == m) {                   // u < v
            f = m; m = p.second;              // v = v - u
        } else {                              // v < u
            f = p.first;                      // u = u - v
        }
        p = swap_ranges(f, m, m, l);
    }
    return;                                   // u == v
}

template <ForwardIterator I>
void rotate_unguarded(I f, I m, I l) {
    // assert(f != m && m != l)
    pair<I, I> p = swap_ranges(f, m, m, l);
    while (p.first != m || p.second != l) {
        f = p.first;
        if (m == f) m = p.second;
        p = swap_ranges(f, m, m, l);
    }
}

template <ForwardIterator I>
I rotate(I f, I m, I l, std::forward_iterator_tag) {
    if (f == m) return l;
    if (m == l) return f;
    pair<I, I> p = swap_ranges(f, m, m, l);
    while (p.first != m || p.second != l) {
        if (p.second == l) {
            rotate_unguarded(p.first, m, l);
            return p.first;
        }
        f = m;
        m = p.second;
        p = swap_ranges(f, m, m, l);
    }
    return m;
}

// Section 11.4

template <ForwardIterator I, Transformation F>
void rotate_cycle_from(I i, F from) {
    ValueType<I> tmp = *i;
    I start = i;
    for (I j = from(i); j != start; j = from(j)) {
        *i = *j;
        i = j;
    }
    *i = tmp;
}

template <RandomAccessIterator I>
struct rotate_transform {
    DifferenceType<I> plus;
    DifferenceType<I> minus;
    I m1;

    rotate_transform(I f, I m, I l) :
        plus(m - f), minus(m - l), m1(f + (l - m)) {}
        // m1 is dividing point between items moving forward and backward

    I operator()(I i) const {
        return i + ((i < m1) ?  plus : minus);
    }
};


template <EuclideanDomain E>
E gcd(E a, E b) {
    while (b != E(0)) {
        a = a % b;
        fmgp::swap(a, b);
    }
    return a;
}

template <RandomAccessIterator I>
I rotate(I f, I m, I l, std::random_access_iterator_tag) {
    if (f == m) return l;
    if (m == l) return f;
    DifferenceType<I> cycles = gcd(m - f, l - m);
    rotate_transform<I> rotator(f, m, l);
    while (cycles-- > 0) rotate_cycle_from(f + cycles, rotator);
    return rotator.m1;
}

// Section 11.5

template <BidirectionalIterator I>
void reverse(I f, I l, std::bidirectional_iterator_tag) {
    while (f != l && f != --l) fmgp::swap(*f++, *l);
}

template <BidirectionalIterator I, Integer N>
void reverse_n(I f, I l, N n) {
    n >>= 1;
    while (n-- > N(0)) {
      fmgp::swap(*f++, *--l);
    }
}

template <RandomAccessIterator I>
void reverse(I f, I l, std::random_access_iterator_tag) {
    reverse_n(f, l, l - f);
}

template <BidirectionalIterator I>
void three_reverse_rotate(I f, I m, I l) {
  std::reverse(f, m);
  std::reverse(m, l);
  std::reverse(f, l);
}

template <BidirectionalIterator I>
pair<I, I> reverse_until(I f, I m, I l) {
    while (f != m && m != l) std::swap(*f++, *--l);
    return {f, l};
}

template <BidirectionalIterator I>
I rotate(I f, I m, I l, bidirectional_iterator_tag) {
  std::reverse(f, m);
  std::reverse(m, l);
     pair<I, I> p = reverse_until(f, m, l);
     std::reverse(p.first, p.second);
     if (m == p.first) return p.second;
     return p.first;
}

template <ForwardIterator I>
I rotate(I f, I m, I l) {
    return rotate(f, m, l, IteratorCategory<I>());
}

template <ForwardIterator I, BinaryInteger N>
I reverse_recursive(I f, N n) {
    if (n == 0) return f;
    if (n == 1) return ++f;
    N h = n >> 1;
    I m = reverse_recursive(f, h);
    if (odd(n)) ++m;
    I l = reverse_recursive(m, h);
    swap_ranges_n(f, m, h);
    return l;
}

template <ForwardIterator I>
void reverse(I f, I l, std::forward_iterator_tag) {
    reverse_recursive(f, distance(f, l));
}

template <ForwardIterator I>
void reverse(I f, I l) {
    reverse(f, l, IteratorCategory<I>());
}

// Section 11.6

template <BidirectionalIterator I, OutputIterator O>
O reverse_copy(I f, I l, O result) {
    while (f != l) *result++ = *--l;
    return result;
}

template <ForwardIterator I, Integer N, BidirectionalIterator B>
I reverse_n_with_buffer(I f, N n, B buffer) {
    B buffer_end = copy_n(f, n, buffer);
    return fmgp::reverse_copy(buffer, buffer_end, f);
}

// Section 11.7

template <ForwardIterator I, Integer N, BidirectionalIterator B>
I reverse_n_adaptive(I f, N n, B buffer, N bufsize) {
    if (n == N(0)) return f;
    if (n == N(1)) return ++f;
    if (n <= bufsize) return reverse_n_with_buffer(f, n, buffer);
    N h = n >> 1;
    I m = reverse_n_adaptive(f, h, buffer, bufsize);
    advance(m, n & 1);
    I l = reverse_n_adaptive(m, h, buffer, bufsize);
    swap_ranges_n(f, m, h);
    return l;
}

} // namespace
