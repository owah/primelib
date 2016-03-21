#include "primelib.hpp"
#include <cmath>

bool primelib::check_prime_b(uint_fast64_t n_t)
{
    uint_fast64_t upper_t = std::sqrt(n_t);
    for (uint_fast64_t i_t = 3; i_t <= upper_t; i_t += 2)
    {
        if (n_t % i_t == 0)
            return false;
    }
    return true;
}

void primelib::generatePrimeLUT(uint_fast64_t n, uint_fast64_t* &primeArray)
{
    uint_fast64_t primeArrayCounter = 0;
    if (n % 32 == 0)
    {
        primeArrayCounter = n / 32;
    }
    else
    {
        primeArrayCounter = n / 32 + 1;
    }

    primeArray = new uint_fast64_t[primeArrayCounter];

    primeArray[0] = 1'346'704'470;

    for (uint_fast64_t i = 1; i < primeArrayCounter; i++)
    {
        primeArray[i] = 0;

        for (uint_fast8_t j = 1; j < 32; j += 2)
        {
            if (primelib::check_prime_b(i * 32 + j))
            {
                primeArray[i] = primeArray[i] | 1 << (j - 1);
            }
        }
    }
}

uint_fast64_t primelib::retrievePrime(uint_fast64_t n, uint_fast64_t * primeArray)
{
    uint_fast64_t lookupIndex = 0;
    uint_fast8_t lookupSlot = 0;

    if (n % 32 == 0)
    {
        lookupIndex = n / 32 - 1;
    }
    else
    {
        lookupIndex = n / 32;
    }

    lookupSlot = n - lookupIndex * 32;

    if (primeArray[lookupIndex] & 1 << (lookupSlot - 1))
    {
        return n;
    }
    else
    {
        return uint_fast64_t(0);
    }
}