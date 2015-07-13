/*
ID: johnhom2
PROG: milk
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>
int main(int argc, char** argv) {
  std::ifstream in("milk.in");
  std::string line;
  int max, N;
  std::stringstream ss;
  getline(in, line);
  ss << line;
  ss >> max >> N;
  //std::cout << "max: " << max << ", N: " << N << std::endl;
  std::multimap<int, int> container;
  int av, mount;
  for (int i=0; i<N; ++i) {
    getline(in, line);
    std::stringstream st;
    st << line;
    st >> av >> mount;
    //std::cout << "av: " << av << " mount: " << mount << std::endl;
    container.insert(std::make_pair(av, mount));
  }
  int result = 0;
  for (std::map<int, int>::iterator it = container.begin();
       it != container.end(); ++it) {
    if (max > it->second) {
      result += it->first * it->second;
      max -= it->second;
    } else {
      result += max * it->first;
      break;
    }
  }
  std::ofstream out("milk.out");
  out << result << std::endl;

}
