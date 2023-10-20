#include <iostream>
#include <vector>

using namespace std;

int main() {
  // Input
  int n; // length of input
  cin >> n; 
  vector<int> a(n); // input vector
  for (int i = 0; i < n; cin >> a[i++]) { }

  vector<int> st; // stack with minimals
  vector<int> ans(n); // answers
  
  // Main part

  for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && a[st.back()] >= a[i]) {
      st.pop_back(); // If next elem is less than our: delete our
    }

    if (st.empty()) {
      ans[i] = -1; // If we have no less items
    } else { 
      ans[i] = st.back(); // Else ans is the minimal elem index
    }

    st.push_back(i);
  }

  // Printing

  for (auto i : ans) {
    cout << i << ' ';
  }
}

