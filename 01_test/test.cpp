/*
ID: ace1o1o2
PROG: test
LANG: C++11
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  ofstream fout("test.out");
  ifstream fin("test.in");
  int a, b;
  fin >> a >> b;
  fout << a + b << endl;
  return 0;
}
