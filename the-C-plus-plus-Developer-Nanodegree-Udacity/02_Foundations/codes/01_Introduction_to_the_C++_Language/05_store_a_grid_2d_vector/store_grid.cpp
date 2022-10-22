#include <iostream>
#include <vector>

using std::vector;

int main() {

  vector<vector<int>> board{

      {0, 1, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0},
      {0, 0, 0, 0, 1, 0}};
  std::cout << "board vector created" << std::endl;
  return 0;
}