#include <iostream>
#include <vector>
#include <algorithm>

/*
 * The main idea is that
 * we should take as much good as possible
 * and than take as much not good as we can (bruh what)
 */

using namespace std;

struct sand {
    int qty;
    int price;

    bool operator<(const sand& l) const {
        return price < l.price;
    }
};

int main() {
    int n, m, c; // m - backpack capacity; c - counter
    cin >> m >> n;

    vector<sand> sands(n);

    for (int i = 0; i < n; i++) {
        cin >> sands[i].qty >> sands[i].price;
    }

    sort(sands.begin(), sands.end());

    int i;

    for (i = 0; sands[i].qty < m && i < n; i++) {
        c += sands[i].qty * sands[i].price;
        m -= sands[i].qty;
    }

    if (i != n) {
        c += sands[i].price * m;
    }

    cout << c;
}
