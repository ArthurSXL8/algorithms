/*
ID: johnhom2
PROG: crypt1
LANG: C++
 */
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
bool Test(const std::string& container, const std::string& str) {
  for (std::string::const_iterator i = str.begin();i != str.end(); ++i ) {
    if (container.find(*i) == std::string::npos) {
      return false;
    }
  }
  return true;
}

std::string ToString(int i) {
  std::stringstream ss;
  ss << i;
  std::string str;
  ss >> str;
  return str;
}
int main(int argc, char** argv) {
  std::ifstream in("crypt1.in");
  std::string c;
  getline(in, c);
  std::stringstream ss;
  int count;
  ss << c;
  ss >> count;
  std::string numbers;
  std::string line;
  getline(in, line);
  std::stringstream st;
  st <<line << std::flush;
  int t;
  std::string str;
  for (int k = 0; k< count; ++k) {
    st >> t;
    std::stringstream sk;
    sk << t;
    sk >> str;
    numbers += str;
  }
  int total = 0;
  //std::cout << "numbers: " << numbers << std::endl;
  for (int i=100;i<1000;++i) {
      std::string stri = ToString(i);
      if (!Test(numbers, stri)) {
        continue;
      }
      for (int j=10; j<100; ++j) {
      std::string strj = ToString(j);
      if (!Test(numbers, strj)) {
        continue;
      }
      int z = i * j;
      if (z > 9999) continue;
      int j1 = j/10;
      int j2 = j%10;  
      int z1 = i*j1;
      int z2 = i*j2;
      if (z2 > 1000) continue;
      std::string strz = ToString(z);
      if (!Test(numbers, strz)) {
        continue;
      }
      std::string strz1 = ToString(z1);
      if (!Test(numbers, strz1)) {
        continue;
      }

      std::string strz2 = ToString(z2);
      if (!Test(numbers, strz2)) {
        continue;
      }
     // std::cout << "numbers: " << numbers << ", i: " << i << ", j: " << j << ", z: "
     //           << z << ", z1: " << z1 << ", z2: " << z2 << std::endl;
      ++total;
    }
  }
  std::ofstream out("crypt1.out");
  out << total << std::endl;
}
