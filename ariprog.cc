/*
ID: johnhom2
PROG: ariprog
LANG: C++
*/
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
bool test(std::vector<int>::iterator begin_iter, std::vector<int>::iterator end_iter, int begin, int length, int div) {
  for (int i=length-1; i>=0; --i) {
    if (!binary_search(begin_iter, end_iter, begin + i*div)) {
      return false;
    }
    //begin_iter++;
  }
  return true;
}
int main(int argc, char** argv) {
  std::ifstream in("ariprog.in");
  std::string line;
  int length;
  int max;
  in >> length >> max;
  int limit = max*max*2;
  std::vector<int> container;
  container.reserve(62500);
  int div;
  for (int i=0; i<=max; ++i) {
    for (int j=0; j<=max; ++j) {
      container.push_back(i*i + j*j);
    }
  }
  sort(container.begin(), container.end());
  container.erase(unique(container.begin(), container.end()), container.end());
  std::multimap<int, int> result;
  vector<int>::iterator it_b = container.begin();
  vector<int>::iterator it_e = container.end();
  for (std::vector<int>::iterator iter_out = container.begin(); iter_out!=container.end(); ++iter_out) {
    if (iter_out + 1 == container.end()) break;
    for (std::vector<int>::iterator iter_inner = iter_out + 1; iter_inner != container.end();
         ++iter_inner) {
      if (container.end() - iter_inner < length-1) break;
      int div = *iter_inner - *iter_out;
      if (*iter_out + div*(length-1) > limit) break;
      if (test(iter_out, it_e, *iter_out, length, div)) {
        result.insert(make_pair(div, *iter_out));
      } else {
        continue;
      }
    }
  }

  ofstream out("ariprog.out");
  if (!result.empty()) {
    for (std::multimap<int, int>::iterator j = result.begin(); 
	     j != result.end(); ++j) {
      out << j->second << " " << j->first << "\n";
    }
  } else {
    out << "NONE" << "\n";
  }
  out << std::flush;
  return 0;
}
