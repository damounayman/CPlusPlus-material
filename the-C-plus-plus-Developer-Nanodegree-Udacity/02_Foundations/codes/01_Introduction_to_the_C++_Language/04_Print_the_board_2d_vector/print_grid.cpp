#include <iostream>
#include <vector>

void PrintGrid(std::vector<std::vector<int>> board) {
  for (auto v1 : board) {
    for (int i : v1) {
      std::cout << i << " ";
    }
    std::cout << std::endl;
  }
}

void PrintBord(std::vector<std::vector<int>> board){
  for(size_t i = 0;i<board.size();i++){
    for(size_t j=0;j<board[0].size();j++){
      std::cout<<board[i][j]<<" ";
    }
    std::cout<< std::endl;
  }
}
int main() {
  std::vector<std::vector<int>> board{{0, 1, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0},
                                      {0, 1, 0, 0, 0, 0},
                                      {0, 0, 0, 0, 1, 0}};
  PrintBord(board);
}