#include <iostream>
#include <vector>
#include <algorithm>

/*
 * The task is to count how much times racers have switched places
 *
 * The input is velocities of each racer
 *
 * We solve it using the merge sort and counting swaps during sort
 *
 */

using namespace std;

int obgoni = 0; // Counter of switches

void merge_sort(vector<int> &vec, int start, int end) {
  if (end - start < 2) { // If size is small, we do nothing
    return;
  }
  if (end - start == 2) { // Or swap elements
    if (vec[start] > vec[start + 1]) {
      swap(vec[start], vec[start + 1]);
      obgoni++;
    }
    return;
  }

  merge_sort(vec, start, start + (end - start) / 2); // Than we sort each half of our array
  merge_sort(vec, start + (end - start) / 2, end);

  vector<int> result;
  
  int bf = start;
  int bs, ef;
  bs = ef = start + (end - start) / 2;
  int es = end;

  while (bf < ef && bs < es) { // Merge-sorting it
    if (vec[bf] <= vec[bs]) {
      result.push_back(vec[bf]);
      bf++;
    } else {
      result.push_back(vec[bs]);
      bs++;
      obgoni = obgoni + (ef - bf);
    }
  }

  for (; bf < ef; bf++) {
    result.push_back(vec[bf]);
  }

  for (; bs < es; bs++) {
    result.push_back(vec[bs]);
  }

  for (int i = start; i < end; i++) { // And writing in array
    vec[i] = result[i - start];
  }
}

int main() {
  int n, l, t;

  cin >> n >> l;

  vector<int> end_time(n); // Array

  for (int i = 0; i < n; i++) { // Input
    cin >> t;
    end_time[i] = i + l * t;
  }

  merge_sort(end_time, 0, n); // Sort
  
  cout << obgoni; // Print counter
}
