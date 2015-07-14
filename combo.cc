/*
ID: johnhom2
PROG: combo
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
int main(int argc, char** argv) {
  std::ifstream in("combo.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  ss << line;
  int N;
  ss >> N;
  getline(in, line);
  ss.clear();
  ss.str("");
  ss << line;
  int l1,l2,l3, r1,r2,r3;
  ss >> l1 >> l2 >> l3;
  getline(in, line);
  ss.clear();
  ss.str("");
  ss << line;
  ss >> r1 >> r2 >> r3;
//  std::cout << l1 << "," << l2 << "," << l3 << std::endl;
//  std::cout << r1 << "," << r2 << "," << r3 << std::endl;
  std::map<int, int> m;
  m.insert(std::make_pair(N-1, 4));
  m.insert(std::make_pair(N-2, 3));
  m.insert(std::make_pair(N-3, 2));
  m.insert(std::make_pair(N-4, 1));
  m[0] = 5;
  m[1] = 4;
  if (m[2] < 3) {
    m[2] = 3;
  }
  if (m[3] <2) {
    m[3] = 2;
  }
  if (m[4] < 1) {
    m[4] = 1;
  }
  int max1,min1,max2,min2,max3,min3;
  max1 = (l1>r1)?l1:r1;
  min1 = (l1>r1)?r1:l1;
  max2 = (l2>r2)?l2:r2;
  min2 = (l2>r2)?r2:l2;
  max3 = (l3>r3)?l3:r3;
  min3 = (l3>r3)?r3:l3;
//  std::cout << "max1: " << max1 << ", min1: " << min1 << std::endl;
//  std::cout << "max2: " << max2 << ", min2: " << min2 << std::endl;
//  std::cout << "max3: " << max3 << ", min3: " << min3 << std::endl;
  int result = m[max1 - min1]*m[max2-min2]*m[max3-min3];
  std::ofstream out("combo.out");
  if (N > 6) {
  out << 250-result << std::endl;
  } else {
    out << N*N*N << std::endl;
  }

}
