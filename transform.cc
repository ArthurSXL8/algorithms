/*
ID: johnhom2
PROG: transform
LANG: C++
 *
 */
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
void rotate(const std::vector<std::string>& matrix, int N,
            std::vector<std::string>* ptr_result) {
  *ptr_result = matrix;
  for (int i=0; i<N; ++i) {
    for (int j = 0; j<N; ++j) {
      (*ptr_result)[j][N-1-i] = matrix[i][j];
    }
  }

}
void reflect(const std::vector<std::string>& matrix, int N,
             std::vector<std::string>* ptr_result) {
  *ptr_result = matrix;  
  for (int i=0; i<N; ++i) {
    for (int j=0; j<N; ++j) {
      (*ptr_result)[i][N-1-j] = matrix[i][j]; 
    }

  }


}

bool Equal(const std::vector<std::string>& left,
           const std::vector<std::string>& right, int N) {
  for (int i=0; i<N; ++i) {
    if (left[i] != right[i]) {
      return false;
    }
  }
  return true;
}

void Print(const std::vector<std::string>& v) {
    std::cout << "Print: " << std::endl;
    for (int i=0; i<v.size(); ++i) {
      std::cout << v[i] << std::endl;
    }
    std::cout << "*******************" << std::endl;
}
int main(int argc, char** argv) {
  std::ifstream in("transform.in");
  std::string line;
  getline(in, line);
  std::stringstream ss;
  ss << line;
  int N;
  ss >> N;
  // std::cout << "N: " << N << std::endl;
  std::vector<std::string> before;
  for(int i=0; i<N; ++i) {
    getline(in, line);
    before.push_back(line);
    // std::cout << "line: " << line << std::endl;
  }
  // std::cout << "====================>" << std::endl;
  std::vector<std::string> after;
  for (int i=0; i<N; ++i) {
    getline(in, line);
    after.push_back(line);
    // std::cout << "-> " << line << std::endl;
  }
  std::ofstream os("transform.out");
  std::vector<std::string> result;
  rotate(before, N, &result);
  if (Equal(result, after, N)) {
    os << 1 << std::endl;  
    // std::cout << "the result: 1" << std::endl;
      return 0;
  }
  // std::cout << "1: " << std::endl;
  // Print(result);
  before = result;
  rotate(before, N, &result);
  if (Equal(result, after, N)) {
      os << 2 << std::endl;
    //  std::cout << "the result: 2" << std::endl;  
    return 0;
  }
  before = result;
  rotate(before, N, &result);
  if (Equal(after, result, N)) {
    os << 3 << std::endl;
  //  std::cout << "the result: 3" << std::endl;
    return 0;
  }
  // Print(result);
  before = result;
  rotate(before, N, &result);
  before = result;
  // Print(result);
  reflect(before, N, &result);
  if (Equal(after, result, N)) {
    os << 4 << std::endl;
    return 0;
    //std::cout << "the result: 4" << std::endl;
    //Print(result);
  }
  //std::cout << "4: " << std::endl;
  //Print(result);
  for (int i=0; i<3; ++i) {
    before = result;
    rotate(before, N, &result);
    //std::cout << "5: " << std::endl;
    //Print(result);
    if (Equal(result, after, N)) {
      os << 5 << std::endl;
      //std::cout << "the result: 5" << std::endl;
      //Print(result);
      return 0;
    }
  }
  
  before = result;
  rotate(before, N, &result);
  if (Equal(result, after, N)) {
    os << 6 << std::endl;
    //std::cout << "the result: 6" << std::endl;
    //Print(result);
    return 0;
  }
  os << 7 << std::endl;
  // std::cout << "the result: 7" << std::endl;
  return 0;




}
