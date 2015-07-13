/*
ID: johnhom2
PROG: barn1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
int main(int argc, char** argv) {
  std::ifstream in("barn1.in");
  int max_board, stalls, cows;
  std::string line;
  getline(in, line);
  std::stringstream t;
  t << line;
  t >> max_board >> stalls >> cows;
  std::ofstream out("barn1.out");
  if (cows <= max_board) {
    out << cows << std::endl;
    return 0;
  }
  int removed = max_board - 1;
  std::set<int> container;
  int index;
  while(cows-- > 0) {
    getline(in, line);
    std::stringstream ss;
    ss << line;
    ss >> index;
    container.insert(index);
  }
  std::multiset<int> s;
  int result = *container.rbegin() - *container.begin() + 1;
  std::set<int>::iterator prev = container.begin();
  for (std::set<int>::iterator it = container.begin();
       it != container.end(); ++it) {
//    if (it != container.begin()) {  
      //std::cout << "===> "
      s.insert(*it - *prev -1);
      prev = it;
//    }
  }
  for (std::set<int>::reverse_iterator rt = s.rbegin(); rt != s.rend() && removed--; ++rt) {
    //std::cout << "---> " << *rt << std::endl;
      result -= *rt;
  }
  out << result << std::endl;
}
