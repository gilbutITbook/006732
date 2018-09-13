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
// ch13.h -- Functions from Chapter 13 of fM2GP.
// -------------------------------------------------------------------

#include <functional>
#include <utility>

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

// Section 13.2

template <Integer I>
bool divides(const I& i, const I& n) {
    return n % i == I(0);
}

template <Integer I>
I smallest_divisor(I n) {
    // precondition: n > 0
    if (even(n)) return I(2); 
    for (I i(3); n >= i * i; i += I(2)) {
        if (divides(i, n)) return i;
    }
    return n;
}

template <Integer I>
I is_prime(const I& n) {
    return n > I(1) && smallest_divisor(n) == n;
}

template <Integer I>
struct modulo_multiply {
    I modulus;
    modulo_multiply(const I& i) : modulus(i) {}
      
    I operator() (const I& n, const I& m) const {
        return (n * m) % modulus;
    }
};

template <Integer I>
I identity_element(const modulo_multiply<I>&) {
    return I(1);
}

template <Integer I>
I multiplicative_inverse_fermat(I a, I p) {
    // precondition: p is prime & a > 0
    return power_monoid(a, p - 2, modulo_multiply<I>(p));
}

template <Integer I>
bool fermat_test(I n, I witness) {
    // precondition: 0 < witness < n
    I remainder(power_semigroup(witness,
                                n - I(1),
                                modulo_multiply<I>(n)));
    return remainder == I(1);
}

// Section 13.3

template <Integer I>
bool miller_rabin_test(I n, I q, I k, I w) {

    // precondition n > 1 && n - 1 = 2^kq && q is odd
    
    modulo_multiply<I> mmult(n);
    I x = power_semigroup(w, q, mmult);
    if (x == I(1) || x == n - I(1)) return true;
    for (I i(1); i < k; ++i) {
    
        // invariant x = w^{2^{i-1}q}
        
        x = mmult(x, x);
        if (x == n - I(1)) return true;
        if (x == I(1))     return false;
    }
    return false;
}

// Section 13.4

template <Integer I>
I multiplicative_inverse(I a, I n) {
    std::pair<I, I> p = extended_gcd(a, n);
    if (p.second != I(1)) return I(0);
    if (p.first < I(0)) return p.first + n;
    return p.first;
}
