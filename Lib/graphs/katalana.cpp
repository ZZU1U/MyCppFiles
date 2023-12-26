#include <iostream>
#include <vector>

using namespace std;

/*
 * Simple realisation of katalana number counter
 * (it also recursive with caching and counts iterations)
 *
 */

int iters = 0;

unsigned long long katalana(unsigned int n, vector<unsigned long long> &cache) {
    iters++;

    if (n < cache.size()) {
        return cache[n];
    }

    unsigned long long katalana_number = 0;

    for (unsigned int i = 0; i < n; i++) {
        katalana_number += katalana(i, cache) * katalana(n - i - 1, cache);
    }

    cache.push_back(katalana_number);
    return katalana_number;
}

int main() {
    vector<unsigned long long> cache = {1, 1, 2, 5};

    unsigned int n;

    cin >> n;

    cout << katalana(n, cache) << '\n';

    for (auto i : cache) {
        cout << i << ' ';
    }

    cout << "\niter: " << iters;
}
