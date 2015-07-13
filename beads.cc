/*
ID: johnhom2
PROG: beads
LANG: C++
*/
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
int GetLength(int start, std::string str) {
    int size = str.size();
    int pre_last = start + size -1;
    char pre_c = 'w';
    int post_first = start;
    char post_c = 'w';
    int count = 0;
    for (int i=0; i<size; ++i) {
      if (str[(pre_last-i)%size] != 'w') {
        pre_c = str[(pre_last-i)%size];
        break;
      }
    }
    for (int i = pre_last; i >start -1; --i) {
      if ((pre_c == str[i%size]) || (str[i%size] == 'w')) {
        ++count;
      } else {
        break;
      }
    }
    for (int i=post_first;i<size; ++i) {
      if (str[i] != 'w') {
        post_c = str[i];
        break;
      }
    }
    for (int i=post_first; i<size+post_first; ++i) {
      if ((str[i%size] == 'w') || (str[i%size]== post_c)) {
        ++count;
      } else {
        break;
      }
    }

    if (count >= size) return size;
    return count;
}


int main(int argc, char** argv) {
  std::ifstream in("beads.in");
  std::string line;
  getline(in, line);
  getline(in,line);
  int last = line.size() -1;
  int count = 2;
  for (int i=0;i<line.size();++i) {
      int j = GetLength(i, line);
      if (j > count) {
        count = j;
      }
  }
  ofstream out("beads.out");
  out << count << std::endl;
  return 0;
}
