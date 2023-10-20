#include <fstream>
#include <iostream>

using namespace std;

int main() {
  // Reading
  ifstream fin;
  fin.open("divide.in");

  int a, b;
  fin >> a;
  fin >> b;

  fin.close(); // Don't forget
  
  // Writing
  ofstream fout;
  fout.open("divide.out");

  fout << a / b;

  fout.close(); // Dont't forget
}
