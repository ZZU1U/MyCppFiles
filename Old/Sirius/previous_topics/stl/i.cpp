#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;

map<char, int> counter;
set<string> known_words;

void increment_counter(char letter) {
  if (counter.find(letter) != counter.end()) {
    counter[letter]++;
  } else {
    counter[letter] = 1;
  }
}

void sub_solve(string country, map<char, int>& current_counter, set<string>& cur_known_words) {
  if (known_words.find(country) == known_words.end()) {
    increment_counter(char(tolower(country.at(0))));
    known_words.insert(country);
  } else {
    current_counter[char(tolower(country.at(0)))]--;
    cur_known_words.erase(country);
  }
}

void solve() {
  int m;
  cin >> m;

  string country;
  auto current_counter = counter;
  auto cur_known_words = known_words;
  for (int i = 0; i < m / 2; i++) {
    cin >> country;

    sub_solve(country, current_counter, cur_known_words);

    cin >> country;

    sub_solve(country, current_counter, cur_known_words);
  }

  char fnd = country.back();

  if (current_counter.find(fnd) != current_counter.end() && current_counter[fnd] > 0) {
    for (auto j = known_words.begin(); j != known_words.end(); j++) {
      if (tolower(j->at(0)) == fnd) {
        cout << *j;
      }
    }
  } else {
    cout << "unknown";
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  while (n--){
    solve();
  }
}
