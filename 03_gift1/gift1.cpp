/*
ID: ace1o1o2
PROG: gift1
LANG: C++11
*/
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int search(string x[], string target, int n) {
  for (int i = 0; i < n; ++i) {
    if (x[i] == target) {
      return i;
    }
  }
}

int main() {
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  int np = 0;
  fin >> np;
  string names[np];
  int moneys[np];
  for (int i = 0; i < np; ++i) {
    moneys[i] = 0;
    fin >> names[i];
  }
  int money, count;
  string name;
  while (fin >> name) {
    fin >> money >> count;
    if (count == 0) {
      int index = search(names, name, np);
      moneys[index] += money;
    } else {
      int remain = money % count;
      int index = search(names, name, np);
      money -= remain;
      moneys[index] -= money;
      int give = money / count;
      string recipient;
      for (int i = 0; i < count; ++i) {
        fin >> recipient;
        int rec_index = search(names, recipient, np);
        moneys[rec_index] += give;
      }
    }
  }
  for (int i = 0; i < np; ++i) {
    fout << names[i] << " " << moneys[i] << endl;
  }
  return 0;
}
