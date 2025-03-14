#include <iostream>
#include <vector>
#include <bit>       // For std::popcount in C++20 (if available)
using namespace std;

/*
 * File: 09_count_set_bits.cpp
 * Description:
 *   Demonstrates how to count the number of set bits (1-bits) in an integer.
 *   We'll show:
 *     1) GCC/Clang built-ins (__builtin_popcount, __builtin_popcountll).
 *     2) C++20 std::popcount (if your compiler supports <bit> header).
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ -std=c++20 09_count_set_bits.cpp -o 09_count_set_bits
 *     ./09_count_set_bits
 *
 *   Windows:
 *     g++ -std=c++20 09_count_set_bits.cpp -o 09_count_set_bits.exe
 *     09_count_set_bits
 *
 * Note: If your compiler doesn't support C++20 <bit>, you can still use the
 * built-in functions in GCC/Clang or your own bit-count function.
 */

int main() {
    unsigned int x = 13; // binary 1101, so 3 set bits

    // 1) Using GCC/Clang built-ins:
    // __builtin_popcount() for 32-bit int
    // __builtin_popcountll() for 64-bit long long
    cout << "Using GCC/Clang built-in popcount:\n";
    cout << "x = 13, __builtin_popcount(x) = " << __builtin_popcount(x) << endl;

    unsigned long long bigVal = 1ULL << 40; // 2^40 => 1 set bit
    cout << "bigVal = 2^40, __builtin_popcountll(bigVal) = "
         << __builtin_popcountll(bigVal) << endl;

#ifdef __cpp_lib_bit // If C++20 <bit> is available
    // 2) Using std::popcount (C++20)
    cout << "\nUsing C++20 std::popcount:\n";
    cout << "std::popcount(13) = " << std::popcount(13U) << endl;
    // For 64-bit, static_cast or pass an unsigned long long
    cout << "std::popcount(1ULL << 40) = " << std::popcount(1ULL << 40) << endl;
#else
    cout << "\nstd::popcount not available, use built-ins or custom function.\n";
#endif

    return 0;
}
