/*
ID: johnhom2
PROG: friday
LANG: C++
 */
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
bool IsLeapYear(int year) {
  if (year%400 == 0) {
    return true;
  } else if ((year%100 != 0)&&(year%4 == 0)) {
    return true;
  } else {
    return false;
  }
}

int main(int argc, char** argv) {
  std::ifstream in("friday.in");
  string line;
  getline(in,line);
  stringstream ss;
  ss << line;
  int year;
  ss >> year;
  map<int, int> week_count;
  map<int, int> month_days;
  month_days.insert(make_pair<int, int>(1,31));
  month_days.insert(make_pair<int, int>(2, 28));
  month_days.insert(make_pair<int, int>(3,31));
  month_days.insert(make_pair<int, int>(4, 30));
  month_days.insert(make_pair<int, int>(5,31));
  month_days.insert(make_pair<int, int>(6, 30));
  month_days.insert(make_pair<int, int>(7,31));
  month_days.insert(make_pair<int, int>(8, 31));
  month_days.insert(make_pair<int, int>(9,30));
  month_days.insert(make_pair<int, int>(10,31));
  month_days.insert(make_pair<int, int>(11,30));
  month_days.insert(make_pair<int, int>(12, 31));
  int c = 0;
  for( int i=0; i<year; ++i) {
    if (IsLeapYear(1900 + i)) {
      month_days[2] = 29;
    } else {
      month_days[2] = 28;
    }
    for(std::map<int, int>::iterator it = month_days.begin();
        it != month_days.end(); ++it) {
      c += 13;
      week_count[(c%7)] += 1;
      c -= 13;
      c += it->second;
      
    }
  }
  ofstream out("friday.out");
  for(int i=0;i<7; ++i) {
    out << week_count[(i+13)%7] << std::flush;
    if (i != 6) {
      out << " ";
    }
  }
  out << std::endl;
  return 0;  
}
