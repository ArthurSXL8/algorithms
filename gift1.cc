/*
ID: johnhom2
PROG: gift1
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char** argv) {
    std::ifstream in("gift1.in");
    string line;
    getline(in, line);
    std::stringstream ss;
    ss << line;
    int friends_count;
    ss >> friends_count;
    std::string name;
    std::vector<string> names;
    std::map<string, int> names_money;
    for(int i=0; i<friends_count; ++i) {
      getline(in, name);
      names.push_back(name);
    }
    while(true) {
      bool status = getline(in, name);
      if (!status) break;
      std::string money_info;
      getline(in, money_info);
      ss.clear();
      ss << money_info;
      int total, count;
      ss >> total >> count;
      if(count == 0) continue;
      names_money[name] -= total;
      names_money[name] += total%count;
      for(int i=0; i<count; ++i) {
        getline(in, name);
        names_money[name] += total/count;
      }
    }

    ofstream output("gift1.out");
    for(std::vector<string>::iterator it = names.begin(); it != names.end(); ++it) {
      output << *it << " " << names_money[*it] << std::endl;
    }

  return 0;  
}
