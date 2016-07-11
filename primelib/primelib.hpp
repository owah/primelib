#pragma once
#include <inttypes.h>

namespace primelib
{
    void generatePrimeLUT(uint64_t n, uint64_t* &primeArray);

    uint64_t retrievePrime(uint64_t n, uint64_t* primeArray);
}