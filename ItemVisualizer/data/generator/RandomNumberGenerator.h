#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H

#include <random>

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int min, int max) : distribution(min, max) {
        random_number = distribution(generator);
    }

    int getRandomNumber() const {
        return random_number;
    }

private:
    static std::mt19937 generator; // Static member to ensure it's shared across instances
    std::uniform_int_distribution<int> distribution;
    int random_number;
};

using RNG = RandomNumberGenerator;

#endif // RANDOMNUMBERGENERATOR_H
