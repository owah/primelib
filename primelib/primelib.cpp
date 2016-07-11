#include "primelib.hpp"
#include <cmath>

void primelib::generatePrimeLUT(uint64_t n, uint64_t* &primeArray)
{
    uint64_t primeArrayCounter = 0;
    uint64_t lookupIndex = 0;
    uint64_t lookupSlot = 0;
    uint64_t upperBound = static_cast<uint64_t>(sqrt(n));

    if (n % 64 == 0)
    {
        primeArrayCounter = n / 64;
    }
    else
    {
        primeArrayCounter = n / 64 + 1;
    }

    primeArray = new uint64_t[primeArrayCounter];

    for (uint64_t i = 0; i < primeArrayCounter; i++)
    {
        primeArray[i] = 0xFFFF'FFFF'FFFF'FFFF;
    }

    primeArray[0] = 0xFFFF'FFFF'FFFF'FFFE;

    for (uint64_t i = 2; i <= upperBound; i++)
    {
        if (i % 64 == 0)
        {
            lookupIndex = i / 64 - 1;
        }
        else
        {
            lookupIndex = i / 64;
        }

        lookupSlot = i - lookupIndex * 64;

        if (primeArray[lookupIndex] & static_cast<uint64_t>(1) << (lookupSlot - 1))
        {
            uint64_t j = 0;
            uint64_t k = 0;

            while (i*i + k*i <= n)
            {
                j = i*i + k*i;
                if (j != 0 && j % 64 == 0)
                {
                    lookupIndex = j / 64 - 1;
                }
                else
                {
                    lookupIndex = j / 64;
                }

                lookupSlot = j - lookupIndex * 64;

                primeArray[lookupIndex] = primeArray[lookupIndex] & ~(static_cast<uint64_t>(1) << (lookupSlot - 1));

                k++;
            }
        }
    }
}

uint64_t primelib::retrievePrime(uint64_t n, uint64_t * primeArray)
{
    uint64_t lookupIndex = 0;
    uint64_t lookupSlot = 0;

    if (n % 64 == 0)
    {
        lookupIndex = n / 64 - 1;
    }
    else
    {
        lookupIndex = n / 64;
    }

    lookupSlot = n - lookupIndex * 64;

    if (primeArray[lookupIndex] & static_cast<uint64_t>(1) << (lookupSlot - 1))
    {
        return n;
    }
    else
    {
        return uint64_t(0);
    }
}