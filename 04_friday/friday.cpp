/*
ID: ace1o1o2
PROG: friday
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
  ofstream fout("friday.out");
  ifstream fin("friday.in");
  int answers[7] = {0};
  int year = 0;
  fin >> year;
  int days_before_this_year = 0;
  for (int i = 0; i < year; ++i) {
    int this_year = 1900 + i;
    int increment = 365;
    if (this_year % 100 == 0) {
      if (this_year % 400 == 0) {
        increment = 366;
      } else {
        increment = 365;
      }
    } else {
      if (this_year % 4 == 0) {
        increment = 366;
      } else {
        increment = 365;
      }
    }
    int tuesday = bool(increment % 365) ? 29 : 28;
    int months[12] = {31, tuesday, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int j = 0; j < 12; ++j) {
      int days_before_this_month = 0;
      for (int k = 1; k <= j; ++k) {
        days_before_this_month += months[k - 1];
      }
      int index = (days_before_this_year + days_before_this_month + 13) % 7;
      answers[index] += 1;
    }
    days_before_this_year += increment;
  }
  fout << answers[6] << " " << answers[0];
  for (int i = 1; i <= 5; ++i) {
    fout << " ";
    fout << answers[i];
  }
  fout << endl;
  return 0;
}
