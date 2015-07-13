/*
ID: johnhom2
PROG: dualpal
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::string ToBase(int i, int base) {
  int i_copy = i;  
  int left;
  std::string str;
  std::string result;
  while(i) {
    left = i%base;
    std::stringstream ss;
    ss << left;
    ss >> str;
    result = str + result;
    //std::cout << "str: " << str << std::endl;
    i /= base;
  }
  //std::cout << "int: " << i_copy << " base: " << base <<  " str: " << result << std::endl;
  return result;
}

bool IsRight(int source) {
  int flag = 0;  
  for (int i=2; i<=10; ++i) {  
    std::string source_str = ToBase(source, i);
    //std::cout << "source: " <<source_str << std::endl;
    if (source_str.empty()) {
      continue;
    }
    std::string::iterator it_b = source_str.begin();
    std::string::iterator it_e = source_str.end() - 1;
    if ((*it_b == '0') || (*it_e == '0')) {
      continue;
    }
    for (; 
         it_b <= it_e; ++it_b, --it_e ) {
      if (*it_e != *it_b) {
        break;
      }
    }
    if (it_b >= it_e) {
      flag += 1;
    }
    if (flag >= 2) {
      //    std::cout << "IsRight: " << source_str <<  ", int: " << source <<std::endl;  
      return true;
    }
  }
  return false;
}

int main(int argc, char** argv) {
  std::ifstream in("dualpal.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  ss << line;
  int N, standard;
  ss >> N >> standard;
  //std::cout << "N: " << N << "standard: " << standard << std::endl;
  std::vector<int> container;
  while(N >0) {
    ++standard;
    //std::cout << "----->: " << standard << std::endl;
    if (IsRight(standard)) {
      //std::cout << "===> " << N << ": " << standard << std::endl;  
      container.push_back(standard);
      --N;
    }
  }
  std::ofstream os("dualpal.out");
  for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) {
    os << *it << std::endl;
  }
}
