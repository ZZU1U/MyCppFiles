#include <iostream>
#include <queue>

using namespace std;

/*
 * This is an example of using priority queue
 * It comes with queue package
 */


int main() {
    // Input
    int n;
    long long t;

    cin >> n;

    priority_queue<long long> docs;

    for (int i = 0; i < n; i++) {
        cin >> t;
        docs.push(-t);
    }

    /*
     * In this example we solve problem C from greedy algorithms
     * So we create a new country if we sum number of people in first and second 's
     * We need to sum minimal amount of people
     */

    // Solution

    long long counter = 0;

    while (docs.size() > 1) {
        t = docs.top();
        docs.pop();

        t += docs.top();
        docs.pop();

        counter -= t;

        docs.push(t);
    }

    cout << counter;
}
