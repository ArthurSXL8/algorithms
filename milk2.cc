/*
ID: johnhom2
PROG: milk2
LANG: C++
*/
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
using namespace std;
int main(int argc, char** argv) {
  ifstream in("milk2.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  int count;
  ss << line;
  ss >> count;
  std::map<int, int> data;
  int start, end;
  for (int i=0;i<count;++i) {
    getline(in, line);
    ss.clear();
    ss << line;
    ss >> start >> end;
    if (data[start] < end) {
      data[start] = end;
    }
  }
  std::map<int, int> unique_data;
  std::map<int, int>::iterator it_inner;
  for (std::map<int, int>::iterator it = data.begin(); it != data.end(); ++it) {
    //std::cout << "data: " << it->first << ", " << it->second << std::endl;
  }
  int j=0;
  for (std::map<int,int>::iterator it_outer = data.begin();
       it_outer != data.end(); ++it_outer) {
    for (it_inner = unique_data.begin(); 
         it_inner != unique_data.end(); ++it_inner) {
      if (it_outer->first >= it_inner->first && it_outer->first <= it_inner->second) {
        if (it_outer->second > it_inner->second) {
          it_inner->second = it_outer->second;
          break;
        } else if (it_inner->second >= it_outer->second) {
          break;
        } else if (it_inner->second == it_outer->first) {
          it_inner->second = it_outer->second;
          break;
        } 
      } 
    }
    if (it_inner == unique_data.end()) {
      unique_data.insert(make_pair(it_outer->first, it_outer->second));
    }
  }

  for (std::map<int, int>::iterator it = unique_data.begin();
       it != unique_data.end(); ++it) {
    // std::cout << "unique: " << it->first << ", " << it->second << std::endl;
  }

  int max_persist = 0;
  int max_interval = 0;
  std::map<int, int>::iterator i;
  for (std::map<int, int>::iterator it = unique_data.begin(); it != unique_data.end();
       ++it) {
    if (it->second - it->first > max_persist) {
      max_persist = it->second - it->first;
    }
    i = it;

    if (++i != unique_data.end()) {
      if (max_interval < i->first - it->second) {
        max_interval = i->first - it->second;
      }
    }
  }

  ofstream output("milk2.out");
  output << max_persist  << " " << max_interval << std::endl;
}

