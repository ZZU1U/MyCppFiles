#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;

    cin >> n;

    vector<int> provinces(n);

    for (int i = 0; i < n; i++) {
        cin >> provinces[i];
    }

    sort(provinces.begin(), provinces.end());
    reverse(provinces.begin(), provinces.end());

    int i = n - 1;
    int counter = 0;

    while (i) {
        n = provinces.back();
        provinces.pop_back();
        n += provinces.back();
        provinces.pop_back();
        provinces.push_back(n);
        counter += n;
        i -= 1;
    }

    cout << counter;
}
