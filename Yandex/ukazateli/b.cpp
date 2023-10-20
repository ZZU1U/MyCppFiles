#include <iostream>
#include <vector>
#include <algorithm>

// ukazateli B

using namespace std;

int diff(vector<int> indexes, vector<vector<pair<int, int>>> matrix) {
    int ma = matrix[0][indexes[0]].first, mi = matrix[0][indexes[0]].first;

    for (int i = 0; i < (int)indexes.size(); i++) {
        ma = max(ma, matrix[i][indexes[i]].first);
        mi = min(mi, matrix[i][indexes[i]].first);
    }

    return ma - mi;
}

int main() {
    int n;
    vector<vector<pair<int, int>>> colors(4);

    for (int i = 0; i < 4; i++) {
        cin >> n;
        colors[i] = vector<pair<int, int>>(n);

        for (int j = 0; j < n; j++) {
            cin >> colors[i][j].first;
            colors[i][j].second = j;
        }

        sort(colors[i].begin(), colors[i].end());
    }

    vector<int> bindexes = {0, 0, 0, 0};
    int bdiff = diff(bindexes, colors);
    vector<int> indexes = {0, 0, 0, 0};


    for (int indmin = 0; indmin < (int) colors[0].size(); indmin++) {
        indexes[0] = indmin;
        n = colors[0][indmin].first;
        for (int i = 1; i < 4; i++) {
            while (colors[i][indexes[i]].first < n && indexes[i] < (int) colors[i].size()) {
                indexes[i]++;
            }
        }
        n = diff(indexes, colors);
        if (n < bdiff) {
            bdiff = n;
            bindexes = indexes;
        }
    }

    for (int i = 0; i < 4; i++) {
        cout << colors[i][bindexes[i]].first << ' ';
    }
}
