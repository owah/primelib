#ifndef PRIMELIB_HPP
#define PRIMELIB_HPP

#include <inttypes.h>
namespace primelib
{
    bool check_prime_b(uint_fast64_t n_t);

    void generatePrimeLUT(uint_fast64_t n, uint_fast64_t* &primeArray);

    uint_fast64_t retrievePrime(uint_fast64_t n, uint_fast64_t* primeArray);
}


#endif