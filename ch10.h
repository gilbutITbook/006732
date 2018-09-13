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
// ch10.h -- Functions from Chapter 10 of fM2GP.
// -------------------------------------------------------------------

#include <iterator>
#include <utility>

#define InputIterator typename
#define ForwardIterator typename
#define RandomAccessIterator typename
#define Predicate typename

namespace fmgp {

// Section 10.5

template <InputIterator I>
using ValueType = typename std::iterator_traits<I>::value_type;

template <InputIterator I>
using DifferenceType =
        typename std::iterator_traits<I>::difference_type;

template <InputIterator I>
using IteratorCategory =
        typename std::iterator_traits<I>::iterator_category;

template <InputIterator I>
DifferenceType<I> distance(I f, I l, std::input_iterator_tag) {
    // precondition: valid_range(f, l)
    DifferenceType<I> n(0);
    while (f != l) {
        ++f;
        ++n;
    }
    return n;
}

template <RandomAccessIterator I>
DifferenceType<I> distance(I f, I l, std::random_access_iterator_tag) {
    // precondition: valid_range(f, l)
    return l - f;
}

template <InputIterator I>
DifferenceType<I> distance(I f, I l) {
    return distance(f, l, IteratorCategory<I>());
}

// Section 10.6

template <InputIterator I>
void advance(I& x, DifferenceType<I> n, std::input_iterator_tag) {
    while (n) {
        --n;
        ++x;
    }
}
 
template <RandomAccessIterator I>
void advance(I& x, DifferenceType<I> n, std::random_access_iterator_tag) {
    x += n;
}

template <InputIterator I>
void advance(I& x, DifferenceType<I> n) {
    advance(x, n, IteratorCategory<I>());
}

// Section 10.7

template <InputIterator I, Predicate P>
I find_if(I f, I l, P p) {
    while (f != l && !p(*f)) ++f;
    return f;
}

template <InputIterator I, Predicate P>
std::pair<I, DifferenceType<I>>
find_if_n(I f, DifferenceType<I> n, P p) {
    while (n && !p(*f)) { ++f; --n; }
    return {f, n};
}

// Section 10.8

template <ForwardIterator I, Predicate P>
I partition_point_n(I f, DifferenceType<I> n, P p) {
    while (n) {
        I middle(f);
        DifferenceType<I> half(n >> 1);
        fmgp::advance(middle, half);
        if (!p(*middle)) {
            n = half;
        } else {
            f = ++middle;
            n = n - (half + 1);
        }
    }
    return f;
}

template <ForwardIterator I, Predicate P>
I partition_point(I f, I l, P p) {
  return partition_point_n(f, fmgp::distance(f, l), p);
}

template <ForwardIterator I>
I lower_bound(I f, I l, ValueType<I> a) {
  return fmgp::partition_point(f, l,
                                [=](ValueType<I> x) { return x < a; });
}

template <ForwardIterator I>
I upper_bound(I f, I l, ValueType<I> a) {
  return fmgp::partition_point(f, l,
                                [=](ValueType<I> x) { return x <= a; });
}

} // namespace fmgp
