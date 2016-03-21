# primelib
primelib is a static library which generates a prime lookup table from 1 to n, in which prime numbers have the value 1 whereas non-prime integers are marked as 0.

## Usage ##
The following usage example shows how to use the library:

Create a pointer to the array which will hold all the bits for all the integers.
Additionally a vector, if you want to, to later only store all the primes.

call *primelib::generatePrimeLUT(n, primeArray);* n stands for the upper bound.

The for-loop will then iterate through the generated LUT via:
*primelib::retrievePrime(i, primeArray)*

Whenever *retrievePrime* is not null, it will have returned a prime number.

```c++
uint_fast32_t* primeArray = nullptr;
std::vector<uint_fast32_t> primes;

primelib::generatePrimeLUT(100, primeArray);

std::cout << "PrimeLUT generated!" << std::endl;

for (uint_fast32_t i = 2; i <= 100; i++)
{
    if (primelib::retrievePrime(i, primeArray))
    {
        primes.push_back(i);
    }
}

for (auto p : primes)
{
    std::cout << p << " ";
}

std::cout << std::endl;

delete [] primeArray;
```

####Output:####

>PrimeLUT generated!

>2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97
