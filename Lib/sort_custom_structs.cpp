#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// First - create our sctruct
struct member {
    // Struct vars
    int id;
    int points;

    bool operator<(const member& mem) const { // Operator for less than
        if (points > mem.points) {
            return true;
        } else if (points == mem.points) {
            return id < mem.id;
        }
        return false;
    }
};

int main() {
    // Input
    int n, t1, t2;
    cin >> n;

    vector<member> mems(n);

    for (int i = 0; i < n; i++) {
        cin >> t1 >> t2;

        mems[i] = member{t1, t2};
    }

    // Sorting with algorithm's method
    sort(mems.begin(), mems.end());
    
    // Printing
    for (auto mem : mems) {
        cout << mem.id << ' ' << mem.points << '\n';
    }
}
