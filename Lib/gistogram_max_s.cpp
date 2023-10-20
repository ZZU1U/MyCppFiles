#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<long long> min_rights(vector<long long> vec, long long n) {
    vector<long long> ans(n);
    vector<long long> stack;

    for (long long i = n-1; i >= 0; i--) {
        while (!stack.empty() && vec[stack.back()] >= vec[i]) {
            stack.pop_back();
        }

        if (stack.empty()) {
            ans[i] = n;
        } else {
            ans[i] = stack.back();
        }

        stack.push_back(i);
    }

    return ans;
}

vector<long long> min_lefts(vector<long long> vec, long long n) {
    vector<long long> ans(n);
    vector<long long> stack;

    for (long long i = 0; i < n; i++) {
        while (!stack.empty() && vec[stack.back()] >= vec[i]) {
            stack.pop_back();
        }

        if (stack.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = stack.back();
        }

        stack.push_back(i);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<long long> v(n);

    for (int i = 0; i < n; cin >> v[i++]) { }

    vector<long long> ans_rights = min_rights(v, n);

    vector<long long> ans_lefts = min_lefts(v, n);

    int bi = -1;

    for (int i = 0; i < n; i++) {
        if (bi == -1 || (ans_rights[i] - ans_lefts[i] - 1) * v[i] > v[bi] * (ans_rights[bi] - ans_lefts[bi] - 1)) {
            bi = i;
        }
    }

    cout << v[bi] * (ans_rights[bi] - ans_lefts[bi] - 1);
}
