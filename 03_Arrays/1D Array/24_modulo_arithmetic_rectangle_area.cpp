#include <bits/stdc++.h>
using namespace std;

/*
 * File: 24_modulo_arithmetic_rectangle_area.cpp
 * Description:
 *   Demonstrates how to compute the union area of multiple axis-aligned rectangles
 *   under a given modulus (10^7 + 9). We use line sweeping in the x-dimension
 *   plus coordinate compression in the y-dimension, then apply modulo arithmetic
 *   for the final result.
 *
 * Modulo Arithmetic Formulas:
 *   (x + y) % m = ((x % m) + (y % m)) % m
 *   (x - y) % m = ((x % m) - (y % m) + m) % m  // to avoid negatives
 *   (x * y) % m = ((x % m) * (y % m)) % m
 *
 * For this problem:
 *   M = 10^7 + 9
 *   We'll accumulate the area mod M to handle potentially large sums.
 *
 * Rectangle Union Approach (Line Sweep + Coordinate Compression):
 *   1) Each rectangle is [x1, y1, x2, y2].
 *   2) Collect vertical edges: (x, y1, y2, type) where type is +1 for start, -1 for end.
 *   3) Sort edges by x. Sweep from left to right. Maintain a coverage array for y-segments.
 *   4) The covered length in y multiplied by (currentX - previousX) is the area of that vertical strip.
 *   5) Sum everything mod M.
 *
 * Steps to Compile and Run:
 *   Linux/Mac:
 *     g++ 24_modulo_arithmetic_rectangle_area.cpp -o rectangle_area
 *     ./rectangle_area
 *
 *   Windows:
 *     g++ 24_modulo_arithmetic_rectangle_area.cpp -o rectangle_area.exe
 *     rectangle_area
 */

static const long long M = 10000009; // 10^7 + 9

// Helper functions for modulo arithmetic
inline long long modAdd(long long a, long long b) {
    return ((a % M) + (b % M)) % M;
}
inline long long modSub(long long a, long long b) {
    return ((a % M) - (b % M) + M) % M; // +M to avoid negative
}
inline long long modMul(long long a, long long b) {
    return ((a % M) * (b % M)) % M;
}

// Struct for vertical edges
struct Edge {
    long long x;
    long long y1, y2;
    int type;  // +1 for start of rect, -1 for end
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter number of rectangles: ";
    int n;
    cin >> n;

    vector<Edge> edges;
    edges.reserve(n * 2);

    vector<long long> allY;
    allY.reserve(n * 2);

    // Read rectangles
    for (int i = 0; i < n; i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // We assume x1 < x2 and y1 < y2
        edges.push_back({x1, y1, y2, +1});
        edges.push_back({x2, y1, y2, -1});
        allY.push_back(y1);
        allY.push_back(y2);
    }

    // Sort edges by x
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        return a.x < b.x;
    });

    // Coordinate compression for y
    sort(allY.begin(), allY.end());
    allY.erase(unique(allY.begin(), allY.end()), allY.end());

    // We'll have coverCount for each segment in y
    vector<int> coverCount(allY.size() - 1, 0);

    // Helper to get compressed index
    auto getIndex = [&](long long val) {
        return int(lower_bound(allY.begin(), allY.end(), val) - allY.begin());
    };

    // Function to compute covered length in y dimension
    auto getCoveredLength = [&]() {
        long long total = 0;
        for (int i = 0; i < (int)coverCount.size(); i++) {
            if (coverCount[i] > 0) {
                long long segLen = allY[i+1] - allY[i];
                total = modAdd(total, segLen);
            }
        }
        return total;
    };

    // Sweep line
    long long area = 0;
    long long prevX = edges[0].x;

    // Apply the first edge coverage
    {
        Edge &e = edges[0];
        int start = getIndex(e.y1);
        int end = getIndex(e.y2);
        for (int i = start; i < end; i++) {
            coverCount[i] += e.type;
        }
    }

    for (int i = 1; i < (int)edges.size(); i++) {
        long long currX = edges[i].x;

        // Covered length in y
        long long coveredY = getCoveredLength();
        // Width in x
        long long width = currX - prevX;

        // Add area for this strip
        long long stripArea = modMul(coveredY, width);
        area = modAdd(area, stripArea);

        // Update coverage for new edge
        Edge &e = edges[i];
        int start = getIndex(e.y1);
        int end = getIndex(e.y2);
        for (int j = start; j < end; j++) {
            coverCount[j] += e.type;
        }

        prevX = currX;
    }

    cout << "Total union area mod (10^7+9) = " << area << endl;

    // Demonstrate the modulo formulas
    cout << "\nModulo formulas demonstration with x=15, y=27:" << endl;
    long long x = 15, y = 27;
    cout << "(x + y) % M = " << modAdd(x, y) << endl;
    cout << "(x - y) % M = " << modSub(x, y) << endl;
    cout << "(x * y) % M = " << modMul(x, y) << endl;

    return 0;
}
