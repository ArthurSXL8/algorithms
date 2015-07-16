/*
ID: johnhom2
PROG: airprog
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
using namespace std;
int main(int argc, char** argv) {
  std::ifstream in("airprog.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  ss << line;
  int length;
  ss >> length;
  std::cout << "length: " << length << std::endl;
  int max;
  ss.str("");
  ss.clear();
  getline(in, line);
  ss << line;
  ss >> max;
  std::cout << "max: " << max << std::endl;
  int limit = max*max*2;
  std::set<int> container;
  int div = limit/(length-1);
  for (int i=0; i<=max; ++i) {
    for (int j=0; j<=max; ++j) {
      container.insert(i*i + j*j);
    }
  }
  for (set<int>::iterator i = container.begin(); i != container.end(); ++i) {
    std::cout << "===> " << *i << std::endl;
  }
//  std::cout << "limit: " << limit << ", " << "div: " << div << std::endl;
  std::multimap<int, int> result;
  for (int i=0;i<=limit; ++i) {
    //std::cout << "i: " << i << std::endl;
    int step = 0;
    //std::cout << "div: " << div << std::endl;
    for (int j=1;j<=div; ++j) {
  //    std::cout << "j: " << j << std::endl;
      if (step == length) {
        result.insert(make_pair(j, i));
        step = 0;
        continue;
      }
      if (i == 1 && step == 4) {
      //  std::cout << "n: " << i + j*step << std::endl;
      } else {
        //std::cout << i << "," << step << std::endl;
      }
     
      if (container.find(i+ j*step) == container.end()) {
        step = 0;
        continue;
      } 
      step++;
    }

  }
 // std::cout << "size: " << result.size() << std::endl;
  for (std::multimap<int, int>::iterator it = result.begin();
       it != result.end(); ++it) {
      std::cout << "b: " << it->first << ", a:" << it->second << std::endl;
  }

  return 0;




  
}
