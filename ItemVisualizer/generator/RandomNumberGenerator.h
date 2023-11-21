#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <random>
#include <chrono>

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int min, int max);

    int get() const;


    static void initialize();

private:
    static std::mt19937 generator; // Static member to ensure it's shared across instances
    std::uniform_int_distribution<int> distribution;
    int random_number;
};

using RNG = RandomNumberGenerator;

#endif // RANDOMNUMBERGENERATOR_H
