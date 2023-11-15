#include "RandomNumberGenerator.h"

// Definition of the static member outside the class
std::mt19937 RandomNumberGenerator::generator{std::random_device{}()};

void RandomNumberGenerator::initialize()
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    auto seed = static_cast<unsigned>(currentTime.time_since_epoch().count());
    generator.seed(seed);
}

RandomNumberGenerator::RandomNumberGenerator(int min, int max)
    : distribution(min, max), random_number(distribution(generator)) {}

int RandomNumberGenerator::get() const {
    return random_number;
}
