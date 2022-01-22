#include <bits/stdc++.h>
#include "ChunkList.cpp"

using namespace std;
using namespace std::chrono;

#define ll long long
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll random(ll st, ll dr) {
    assert(st <= dr);
    return st + rng() % (dr - st + 1);
}

void testSearch() {
    ChunkList list = ChunkList(3);

    const int chunkSize = 1000;
    const int N = 1000;

    for (int i = 0; i < N; i++) {
        list.add(i);
    }

    for (int i = 0; i < 1e5; i++) {
        int idx = random(0, N);
        list.contains(idx);
    }
}

void benchmark(void (*fun)(), string fnName) {
    auto start = high_resolution_clock::now();

    fun();

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Running time for " << fnName << ": " << (double) duration.count() / 1e6 << " seconds" << endl;
}

int main() {
    benchmark(testSearch, "Search");

    return 0;
}