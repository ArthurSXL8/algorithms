/*
ID: johnhom2
PROG: namenum
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

    std::map<std::string, std::string> dict;
    std::string line;
    std::ifstream dict_file("dict.txt");
    while(getline(dict_file, line)) {
      dict[line] = "";
    }
    std::map<char, std::string> transformation_pair;
    transformation_pair.insert(std::make_pair('A', "2"));
    transformation_pair.insert(std::make_pair('B', "2"));
    transformation_pair.insert(std::make_pair('C', "2"));

    transformation_pair.insert(std::make_pair('D', "3"));
    transformation_pair.insert(std::make_pair('E', "3"));
    transformation_pair.insert(std::make_pair('F', "3"));

    transformation_pair.insert(std::make_pair('G', "4"));
    transformation_pair.insert(std::make_pair('H', "4"));
    transformation_pair.insert(std::make_pair('I', "4"));

    transformation_pair.insert(std::make_pair('J', "5"));
    transformation_pair.insert(std::make_pair('K', "5"));
    transformation_pair.insert(std::make_pair('L', "5"));

    transformation_pair.insert(std::make_pair('M', "6"));
    transformation_pair.insert(std::make_pair('N', "6"));
    transformation_pair.insert(std::make_pair('O', "6"));

    transformation_pair.insert(std::make_pair('P', "7"));
    transformation_pair.insert(std::make_pair('R', "7"));
    transformation_pair.insert(std::make_pair('S', "7"));

    transformation_pair.insert(std::make_pair('T', "8"));
    transformation_pair.insert(std::make_pair('U', "8"));
    transformation_pair.insert(std::make_pair('V', "8"));

    transformation_pair.insert(std::make_pair('W', "9"));
    transformation_pair.insert(std::make_pair('X', "9"));
    transformation_pair.insert(std::make_pair('Y', "9"));

    std::ifstream input("namenum.in");
    std::string number;
    getline(input, number);
    
    
    for (std::map<std::string, std::string>::iterator it = dict.begin(); 
         it != dict.end(); ++it) {
        std::string name = it->first;
        for (std::string::iterator i = name.begin(); i != name.end(); ++i) {
          it->second += transformation_pair[*i];
        }
    }

    std::vector<string> result;
    for (std::map<std::string, std::string>::iterator iter = dict.begin();
         iter != dict.end(); ++iter) {
      if (iter->second == number) {
        result.push_back(iter->first);
      }

    }

    ofstream output("namenum.out");
    if (result.empty()) {
      output << "NONE" << std::endl;
    } else {
      for (std::vector<std::string>::iterator iter = result.begin(); iter != result.end(); ++iter) {
        output << *iter << std::endl;
      }
 
    }


}
