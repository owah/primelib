#include "primelib.hpp"
#include <cmath>

void primelib::generatePrimeLUT(uint_fast64_t n, uint_fast32_t* &primeArray)
{
    uint_fast64_t primeArrayCounter = 0;
    uint_fast64_t lookupIndex = 0;
    uint_fast8_t lookupSlot = 0;
    uint_fast64_t upperBound = sqrt(n);

    if (n % 32 == 0)
    {
        primeArrayCounter = n / 32;
    }
    else
    {
        primeArrayCounter = n / 32 + 1;
    }

    primeArray = new uint_fast32_t[primeArrayCounter];

    for (uint_fast64_t i = 0; i < primeArrayCounter; i++)
    {
        primeArray[i] = 0xFFFF'FFFF;
    }

    primeArray[0] = 0xFFFF'FFFE;

    for (uint_fast64_t i = 2; i <= upperBound; i++)
    {
        if (i % 32 == 0)
        {
            lookupIndex = i / 32 - 1;
        }
        else
        {
            lookupIndex = i / 32;
        }

        lookupSlot = i - lookupIndex * 32;

        if (primeArray[lookupIndex] & 1 << (lookupSlot - 1))
        {
            uint_fast64_t j = 0;
            uint_fast64_t k = 0;

            while (i*i + k*i <= n)
            {
                j = i*i + k*i;
                if (j != 0 && j % 32 == 0)
                {
                    lookupIndex = j / 32 - 1;
                }
                else
                {
                    lookupIndex = j / 32;
                }

                lookupSlot = j - lookupIndex * 32;

                primeArray[lookupIndex] = primeArray[lookupIndex] & ~(1 << (lookupSlot - 1));

                k++;
            }
        }
    }
}

uint_fast64_t primelib::retrievePrime(uint_fast64_t n, uint_fast32_t * primeArray)
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