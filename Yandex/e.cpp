#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

typedef long long ll;

using namespace std;


/*
5
po
pod
sasha
shla
shosse
12
7 4 5 7 2 7 6 1 7 4 6 1
shla sasha po shosse |||

5
aa
b
bb
c
cda
7
2 2 1 2 3 2 1
aa cda b |||

4
ap
lap
op
vosem
11
1 6 2 4 1 1 8 5 9 1 1
op ap vosem lap |||

2
sem
vosem
6
7 8 9 7 8 1
sem vosem |||

2
a
z
2
5 1
Примечание:  в этом примере выходной файл должен быть создан, но должен быть пустым, в частности, в него не нужно выводить пробел.
 */

int cmp(const string& a, const string& b) {
  for (int i = 0; i < min(a.length(), b.length()); i++) {
    if (a[i] > b[i])
      return 0;

    if (a[i] < b[i])
      return 1;
  }

  return -1;
}

bool fcmp(const pair<string, string>& n, const pair<string, string>& m) {
  auto a = n.first;
  auto b = m.first;

  int ans = cmp(a, b);

  return (ans == -1 ? a.length() < b.length() : ans);
}

int lower_bound(const vector<pair<string, string>>& vec, int start, int end, const string& kv) {
  while (end - start > 1) {
    int mid = (end + start) / 2;

    int ans = cmp(vec[mid].first, kv);

    if (ans == -1 && kv.length() <= vec[ans+1].second.length()) {
      return lower_bound(vec, start, mid, kv);
    } else {
      if (ans == 1) {
        start = mid;
      } else {
        end = mid;
      }
    }
  }
  return start;
}

int upper_bound(const vector<pair<string, string>>& vec, int start, int end, const string& kv) {
  while (end - start > 1) {
    int mid = (end + start) / 2;

    int ans = cmp(vec[mid].first, kv);

    if (ans == -1) {
      return upper_bound(vec, mid, end, kv);
    } else {
      if (ans) {
        start = mid;
      } else {
        end = mid;
      }
    }
  }
  return end;
}

char ctoi(char c) {
  if (c <= 'c')
    return '2';

  if (c >= 'd' && c <= 'f')
    return '3';

  if (c >= 'g' && c <= 'i')
    return '4';

  if (c >= 'j' && c <= 'l')
    return '5';

  if (c >= 'm' && c <= 'o')
    return '6';

  if (c >= 'p' && c <= 's')
    return '7';

  if (c >= 't' && c <= 'v')
    return '8';

  return '9';
}

void solve() {
  int m;
  cin >> m;

  vector<pair<string, string>> tran = {{"/", ""}, {";", ""}};

  for (int i = 0; i < m; i++) {
    string wrd;

    string trns;

    cin >> wrd;

    for (auto j : wrd)
      trns.push_back(ctoi(j));

    tran.emplace_back(trns, wrd);
  }

  m += 2;

  sort(all(tran), fcmp);

  for (auto [a, b] : tran)
    cout << a << ':' << b << '\n';

  int n;
  cin >> n;

  string word;

  for (int i = 0; i < n; i++) {
    char elem;

    cin >> elem;

    if (elem == '1') {
      int b = lower_bound(tran, 0, m, word);

      if (!word.empty() && cmp(tran[b+1].first, word) == -1)
        cout << tran[b+1].second << ' ';

      word = "";
      continue;
    }

    word.push_back(elem);

    int lb = lower_bound(tran, 0, m, word);
    int rb = upper_bound(tran, 0, m, word);

    cout << word << ' ' << lb << ' ' << rb << '\n';

    if (rb - lb <= 2) {
      cout << tran[lb + 1].second << ' ';
      word = "";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed << setprecision(12);

  #ifdef DEBUG
  freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  #endif

  int t = 1;
  // cin >> t;

  while (t--)
    solve();
}
