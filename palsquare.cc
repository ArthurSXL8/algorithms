/*
ID: johnhom2
PROG: palsquare
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
bool IsPalindromic(std::string str) { 
  if (str.empty()) return true;  
  for (std::string::iterator it_begin = str.begin(), 
       it_last  = str.end()-1; 
       it_begin < it_last; ++it_begin, --it_last) {
    if (*it_begin != *it_last) {
      return false;
    }
  }
  return true;
}

template<typename T, typename U>
void TypeCast(const T& source, U* ptr_result) {
  std::stringstream ss;
  ss << source;
  ss >> (*ptr_result);
  return;
}

void Transform(int num, int base,std::map<int, std::string> pair,
               std::string* ptr_result) {
  int left;
  while(num) {
    left = num%base;
    *ptr_result = pair[left] + *ptr_result;
    num /= base;
  }
}

int main(int argc, char** argv) {
  




  std::map<int, std::string> transform_pair;
  transform_pair[0] = "0";
  transform_pair[1] = "1";
  transform_pair[2] = "2";
  transform_pair[3] = "3";
  transform_pair[4] = "4";
  transform_pair[5] = "5";
  transform_pair[6] = "6";
  transform_pair[7] = "7";
  transform_pair[8] = "8";
  transform_pair[9] = "9";
  transform_pair[10] = "A";
  transform_pair[11] = "B";
  transform_pair[12] = "C";
  transform_pair[13] = "D";
  transform_pair[14] = "E";
  transform_pair[15] = "F";
  transform_pair[16] = "G";
  transform_pair[17] = "H";
  transform_pair[18] = "I";
  transform_pair[19] = "J";
  std::ifstream in("palsquare.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  ss << line;
  int base;
  ss >> base;
  std::vector<std::string> result;
  int square;
  for (int i=1; i<=300; ++i) {
      square = i*i;
      std::string str;
      Transform(square, base, transform_pair,&str);
      if (IsPalindromic(str)) {
          std::string sqrt;
          Transform(i, base, transform_pair, &sqrt);
          std::string element = sqrt + " " + str;
          result.push_back(element);
      }
  }
  std::ofstream out("palsquare.out");
  for (std::vector<std::string>::iterator it = result.begin();
       it != result.end(); ++it) {
    out << *it << std::endl;
  }








}
