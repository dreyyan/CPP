#include <iostream>
#include <random>
using namespace std;
// RNG - Mersenne Twister Engine(Long period, faster PRNG | More memory, unsecure, slower)
void generate_random_numbers(int min_range, int max_range, int instances) {
    // Create Random Device
    random_device rd;

    // Create Mersenne Twister Engine Using Random Device(rd) Seed
    mt19937 mt(rd());

    // Generate Numbers in Given Range
    uniform_int_distribution<int> dist(min_range, max_range);

    // Generate & Display Random Numbers
    cout << "generating " << instances << " random numbers between " << min_range << " and " << max_range << "...\n";
    for (size_t i = 0; i < instances; ++i) {
        cout << "* " << dist(mt) <<'\n';
    }
}

int main() {
    generate_random_numbers(5, 10, 15);
    return 0;
}
/* Randomness Visualization
Range(Engine(Random Device)) */
