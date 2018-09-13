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
// ch07.h -- Functions from Chapter 7 of fM2GP.
// -------------------------------------------------------------------

#include <functional>

#define NoncommutativeAdditiveMonoid typename
#define NoncommutativeAdditiveGroup typename
#define MultiplicativeSemigroup typename
#define MultiplicativeMonoid typename
#define Regular typename
#define SemigroupOperation typename
#define MonoidOperation typename
#define GroupOperation typename
#define AdditiveGroup typename
#define MultiplicativeGroup typename
#define Integer typename

// Section 7.1

template <Integer N>
bool odd(N n) { return bool(n & 0x1); }

template <Integer N>
N half(N n) { return n >> 1; }

int mult_acc4(int r, int n, int a) {
    while (true) {
        if (odd(n)) {
            r = r + a;
            if (n == 1) return r;
        }
        n = half(n);
        a = a + a;
    }
}

template <typename A, typename N>
A multiply_accumulate0(A r, N n, A a) {
    while (true) {
        if (odd(n)) {
            r = r + a;
            if (n == 1) return r;
        }
        n = half(n);
        a = a + a;
    }
}

// Section 7.3

#define NoncommutativeAdditiveSemigroup typename


template <NoncommutativeAdditiveSemigroup A, typename N>
A multiply_accumulate(A r, N n, A a) {
    while (true) {
        if (odd(n)) {
            r = r + a;
            if (n == 1) return r;
        }
        n = half(n);
        a = a + a;
    }
}


template <NoncommutativeAdditiveSemigroup A, Integer N>
A multiply_accumulate_semigroup(A r, N n, A a) {
    // precondition(n >= 0);
    if (n == 0) return r;
    while (true) {
        if (odd(n)) {
            r = r + a;
            if (n == 1) return r;
        }
        n = half(n);
        a = a + a;
    }
}

template <NoncommutativeAdditiveSemigroup A, Integer N>
A multiply_semigroup(N n, A a) {
    // precondition(n > 0);
    while (!odd(n)) {
        a = a + a;
        n = half(n);
    }
    if (n == 1) return a;
    return multiply_accumulate_semigroup(a, half(n - 1), a + a);
}


// Section 7.4

template <NoncommutativeAdditiveMonoid A, Integer N>
A multiply_monoid(N n, A a) {
    // precondition(n >= 0);
    if (n == 0) return A(0);
    return multiply_semigroup(n, a);
}

template <NoncommutativeAdditiveGroup A, Integer N>
A multiply_group(N n, A a) {
    if (n < 0) {
        n = -n;
        a = -a;
    }
    return multiply_monoid(n, a);
}

// Section 7.5

template <MultiplicativeSemigroup A, Integer N>
A power_accumulate_semigroup(A r, A a, N n) {
    // precondition(n >= 0);
    if (n == 0) return r;
    while (true) {
        if (odd(n)) {
            r = r * a;
            if (n == 1) return r;
        }
        n = half(n);
        a = a * a;
    }
}

template <MultiplicativeSemigroup A, Integer N>
A power_semigroup(A a, N n) {
    // precondition(n > 0);
    while (!odd(n)) {
        a = a * a;
        n = half(n);
    }
    if (n == 1) return a;
    return power_accumulate_semigroup(a, a * a, half(n - 1));
}

template <MultiplicativeMonoid A, Integer N>
A power_monoid(A a, N n) {
    // precondition(n >= 0);
    if (n == 0) return A(1);
    return power_semigroup(a, n);
}

template <MultiplicativeGroup A>
A multiplicative_inverse(A a) {
    return A(1) / a;
}

template <MultiplicativeGroup A, Integer N>
A power_group(A a, N n) {
    if (n < 0) {
        n = -n;
        a = multiplicative_inverse(a);
    }
    return power_monoid(a, n);
}

// Section 7.6

template <Regular A, Integer N, SemigroupOperation Op>
// requires (Domain<Op, A>)
A power_accumulate_semigroup(A r, A a, N n, Op op) {
    // precondition(n >= 0);
    if (n == 0) return r;
    while (true) {
        if (odd(n)) {
            r = op(r, a);
            if (n == 1) return r;
        }
        n = half(n);
        a = op(a, a);
    }
}

template <Regular A, Integer N, SemigroupOperation Op>
// requires (Domain<Op, A>)
A power_semigroup(A a, N n, Op op) {
    // precondition(n > 0);
    while (!odd(n)) {
        a = op(a, a);
        n = half(n);
    }
    if (n == 1) return a;
    return power_accumulate_semigroup(a, op(a, a), half(n - 1), op);
}

template <NoncommutativeAdditiveMonoid T>
T identity_element(std::plus<T>) {
    return T(0);
}

template <MultiplicativeMonoid T>
T identity_element(std::multiplies<T>) {
    return T(1);
}

template <Regular A, Integer N, MonoidOperation Op>
// requires(Domain<Op, A>)
A power_monoid(A a, N n, Op op) {
    // precondition(n >= 0);
    if (n == 0) return identity_element(op);
    return power_semigroup(a, n, op);
}

template <AdditiveGroup T>
std::negate<T> inverse_operation(std::plus<T>) {
    return std::negate<T>();
}

template <MultiplicativeGroup T>
struct reciprocal {
    T operator()(const T& x) const {
        return T(1) / x;
    }
};

template <MultiplicativeGroup T>
reciprocal<T> inverse_operation(std::multiplies<T>) {
    return reciprocal<T>();
}

template <Regular A, Integer N, GroupOperation Op>
// requires(Domain<Op, A>)
A power_group(A a, N n, Op op) {
    if (n < 0) {
        n = -n;
        a = inverse_operation(op)(a); 
    }
    return power_monoid(a, n, op);
}


// Section 7.7

int fib0(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib0(n - 1) + fib0(n - 2);
}

int fibonacci_iterative(int n) {
    if (n == 0) return 0;
    std::pair<int, int> v = {0, 1};
    for (int i = 1; i < n; ++i) {
        v = {v.second, v.first + v.second};
    }
    return v.second;
}
