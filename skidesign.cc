/*
ID: johnhom2
PROG: skidesign
LANG: C++
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int left(std::vector<int>& v) {
  int min = 2100000000;
  for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
//    std::cout << "=================================> " << std::endl;
    int cost = 0;
    std::vector<int>::iterator left_it = v.begin();
    while(*left_it != *it) {
//      std::cout << "left_it: " << *left_it << ", *it: " << *it << std::endl;
      cost += (*it - *left_it) * (*it - *left_it);
      ++left_it;
    }
//    std::cout << "->" << std::endl;
    vector<int>::iterator i = std::upper_bound(it, v.end(), *it + 17);
    int value = *it + 17;
    while(i != v.end()) {
//      std::cout << "right: " << *i << ", value: " << value << std::endl;
      int e = (*i - value)*(*i - value);
      cost += e;
      ++i;
    }
//    std::cout << "cost: " << cost << std::endl;
    if ((min > cost)) {
      min = cost;
    }
  }
  return min;

}

int right(std::vector<int>& v) {
  int min = 2100000000;
//  std::cout << "right: " << std::endl;
  for (vector<int>::iterator iter = v.begin(); iter != v.end(); ++iter) {
    int cost = 0;
//    std::cout << "->" << std::endl;
    vector<int>::iterator ite = v.begin();
    while((*ite < *iter) || (*ite > *iter + 17)) {
      if (*ite < *iter) {
        cost += (*iter - *ite)*(*iter - *ite);
      } else {
        cost += (*ite - *iter - 17) * (*ite - *iter - 17);
      }
      ++ite;
    }
//    std::cout << "-->" << std::endl;
//    vector<int>::reverse_iterator it = std::lower_bound(iter, v.rend(), *iter -17);
//    int value = *iter - 17;
//    vector<int>::iterator it = v.begin();
//    while(*it < value) {
//      int e = (*it - value)*(*it - value);
//      cost += e;
//      ++it;
//    }
//    std::cout << "cost: " << cost << std::endl;
    if ((min > cost)) {
      min = cost;
    }

  }
  return min;
}


int main(int argc, char** argv) {
  std::ifstream in("skidesign.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  ss << line;
  int N;
  ss >> N;
  std::vector<int> container;
  for (int i=0; i<N; ++i) {
    getline(in, line);
    ss.clear();
    ss.str("");
    ss << line;
    int number;
    ss >> number;
    container.push_back(number);
  }
  sort(container.begin(), container.end());
  int min = 2100000000;
  for (int i=0; i<101; ++i) {
    int cost = 0;
    for (int j=0; j<container.size(); ++j) {
      if (container[j] < i) {
        cost += (container[j] - i) * (container[j] - i);
      }
      if (container[j] > i+17) {
        cost += (container[j] - i -17)*(container[j]-i-17);
      }
    }
    if (cost < min) {
      min = cost;
    }
 
  }
   std::ofstream out("skidesign.out");
   out << min << std::endl;

}
