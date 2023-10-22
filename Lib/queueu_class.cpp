#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
 * This is simple realization of queue using two stacks
 * And also some king of cli...
 * Made as updated version for queue_from_stacks
 */

class Queue {
 public:
    stack<int> stpush;
    stack<int> stpop;

    void push(int elem) {
        stpush.push(elem);
        cout << "ok";
    }

    int pop() {
        int t;

        if (stpop.empty()) {
            while (!stpush.empty()) {
                t = stpush.top();
                stpush.pop();
                stpop.push(t);
            }
        }

        t = stpop.top();
        stpop.pop();
        return t;
    }

    int front() {
        int t;

        if (stpop.empty()) {
            while (!stpush.empty()) {
                t = stpush.top();
                stpush.pop();
                stpop.push(t);
            }
        }
        return stpop.top();
    }

    int size() {
        return stpop.size() + stpush.size();
    }

    void clear() {
        stpop = stack<int> ();
        stpush = stack<int> ();
        cout << "ok";
    }
};


int main() {
    int num;
    string comm;
    Queue q;

    while (true) { // Client
        cin >> comm;

        if (comm == "push") {
            cin >> num;
            q.push(num);
        } else if (comm == "pop") {
            num = q.pop();
            cout << num;
        } else if (comm == "front") {
            cout << q.front();
        } else if (comm == "size") {
            cout << q.size();
        } else if (comm == "clear") {
            q.clear();
        } else {
            cout << "bye";
            return 0;
        }
        cout << '\n';
    }
}
