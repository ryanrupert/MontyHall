/**
* Created by Ryan Rupert
* Date: 2018-03-10
* Source: None
* This a cpp implementation of the Monty hall problem
*/

#include <iostream>
#include <cstdint>
#include <chrono>
#include <random>
#include <time.h>

uint32_t seedseq_random_using_clock()
{
    uint64_t seed = std::chrono::high_resolution_clock::
                                        now().time_since_epoch().count();
    std::seed_seq seeder{uint32_t(seed),uint32_t(seed >> 32)};
    ++seed;
    int out;
    seeder.generate(&out,&out+1);
    return out;
}
