#ifndef PRIMELIB_HPP
#define PRIMELIB_HPP

#include <inttypes.h>
namespace primelib
{
    void generatePrimeLUT(uint_fast64_t n, uint_fast32_t* &primeArray);

    uint_fast64_t retrievePrime(uint_fast64_t n, uint_fast32_t* primeArray);
}


#endif