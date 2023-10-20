#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int obgoni = 0;

void merge_sort(vector<int> &vec, int start, int end) {
  if (end - start < 2) {
    return;
  }
  if (end - start == 2) {
    if (vec[start] > vec[start + 1]) {
      swap(vec[start], vec[start + 1]);
      obgoni++;
    }
    return;
  }

  merge_sort(vec, start, start + (end - start) / 2);
  merge_sort(vec, start + (end - start) / 2, end);

  vector<int> result;
  
  int bf = start;
  int bs, ef;
  bs = ef = start + (end - start) / 2;
  int es = end;

  while (bf < ef && bs < es) {
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

  for (int i = start; i < end; i++) {
    vec[i] = result[i - start];
  }
}

int main() {
  int n, l, t;

  cin >> n >> l;

  vector<int> end_time(n);

  for (int i = 0; i < n; i++) {
    cin >> t;
    end_time[i] = i + l * t;
  }

  merge_sort(end_time, 0, n);
  
  cout << obgoni;
}
