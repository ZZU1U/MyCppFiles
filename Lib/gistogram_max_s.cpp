#include <iostream>
#include <vector>
#include <algorithm>

/*
 * The task is to find maximum area under a gistogram
 *
 * We have an array with heights of each column in gistogram
 *
 * Output is the maximum area
 *
 */

using namespace std;


vector<long long> min_rights(vector<long long> vec, long long n) {
    /*
     * This function finds nearest right value in array that is smaller than our
     * It uses stack and it's linear
     */

    vector<long long> ans(n);
    vector<long long> stack;

    for (long long i = n-1; i >= 0; i--) { // We go from the end of array
        while (!stack.empty() && vec[stack.back()] >= vec[i]) {
          /*
           * If values are bigger than our than they can't be min rights
           * cz there's another value righter than them and smaller than them
           */
          stack.pop_back(); 
        }

        if (stack.empty()) { // If there's no revelant value
            ans[i] = n; // We choose the most right value
        } else { 
            ans[i] = stack.back(); // Else we choose our answer
        }

        stack.push_back(i); // And add our new value in stack
    }

    return ans;
}

vector<long long> min_lefts(vector<long long> vec, long long n) {
    /*
     * This function is the same as the previous
     * But when i didn't wrote it, it didn't work
     * So... yeah...
     */
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

    vector<long long> ans_rights = min_rights(v, n); // We find each right min

    vector<long long> ans_lefts = min_lefts(v, n); // And each left min

    int bi = -1;

    for (int i = 0; i < n; i++) {
        /*
         * Let's choose as max height - height of our column
         * Than we
         */
        if (bi == -1 || (ans_rights[i] - ans_lefts[i] - 1) * v[i] > v[bi] * (ans_rights[bi] - ans_lefts[bi] - 1)) {
            bi = i;
        }
    }

    cout << v[bi] * (ans_rights[bi] - ans_lefts[bi] - 1);
}
