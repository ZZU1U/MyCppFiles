#include <fstream>
#include <iostream>

/*
 * Example of reading and writing files in c++
 */

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

  fout.close(); // Don't forget!
}
