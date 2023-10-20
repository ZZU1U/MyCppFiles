#include <iostream>

using namespace std;

int main() {
  char n;
  int s = 0;

  cin >> n;
  
  s += (int) (n - '0');

  cin >> n;

  s -= (int) (n - '0');

  cin >> n;

  s += (int) (n - '0');

  if (s) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
