/*
ID: johnhom2
PROG: ariprog
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;
bool test(std::set<int> container, int begin, int length, int div) {
  for (int i=0; i<length; ++i) {
    if (container.find(begin + i* div) == container.end()) {
      return false;
    }
  }
  return true;
}
int main(int argc, char** argv) {
  std::ifstream in("ariprog.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  ss << line;
  int length;
  ss >> length;
  int max;
  ss.str("");
  ss.clear();
  getline(in, line);
  ss << line;
  ss >> max;
  int limit = max*max*2;
  std::set<int> container;
  int div = limit/(length-1);
  for (int i=0; i<=max; ++i) {
    for (int j=0; j<=max; ++j) {
      container.insert(i*i + j*j);
    }
  }
  std::multimap<int, int> result;
  for (int i=0; i<=limit; ++i) {
    for (int j=1; j<=div; ++j) {
      if (i + j* (length-1) > limit) {
        break;
      }
      if (test(container, i, length, j)) {
        result.insert(make_pair(j, i));
      }
    }
  }
  ofstream out("ariprog.out");
  if (!result.empty()) {
  for (std::multimap<int, int>::iterator j = result.begin(); j != result.end(); ++j) {
    out << j->second << " "<< j->first << std::endl;
  }
  } else {
    out << "NONE" << std::endl;
  }

  return 0;
  
}
