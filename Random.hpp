#ifndef _RANDOM
#define _RANDOM

#include <random>
#include <cstdint>
#include <bsd/stdlib.h>

// g++ Random.cpp -lbsd

// Random number generator
class Random {
public:
    // Initializes with random seed
    Random() {
        uint32_t seed = arc4random();
        gen.seed(seed);    
    }
    void seed(uint32_t s) {
    	gen.seed(s);
    }
    // Returns a uniform real number in [a,b)
    template <class T=double>
    T real(const T& a = 0.0, const T& b = 1.0) {
        std::uniform_real_distribution<T> dist(a,b);
        return dist(gen);
    }
    // Returns a uniform integer in [a,b]
    template <class T=int>
    T integer(const T& a, const T& b) {
        std::uniform_int_distribution<T> dist(a,b);
        return dist(gen);
    }
    // Returns a normally distributed real number
    template <class T=double>
    T normal(const T& mean=0.0, const T& stddev=1.0) {
        std::normal_distribution<T> dist(mean, stddev);
        return dist(gen);
    }
private:
    std::mt19937_64 gen;
};

#endif