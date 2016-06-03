/*
ID: ace1o1o2
PROG: ride
LANG: C++11
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int cal(string a) {
  long result = 1;
  for (int i = 0; i < a.length(); ++i) {
    int temp = int(a[i] - 'A') + 1;
    result *= temp;
  }
  return result;
}
int main() {
  ofstream fout("ride.out");
  ifstream fin("ride.in");
  string a;
  int n[3] = {0, 0, 0};
  int counter = 0;
  while (fin >> a) {
    n[counter] = cal(a);
    ++counter;
  }
  if (n[0] % 47 == n[1] % 47) {
    fout << "GO" << endl;
  } else {
    fout << "STAY" << endl;
  }
  return 0;
}
