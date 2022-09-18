// created by ayman damoun on 24/07/2022

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

enum class State { k_empty, k_obstacle };

vector<vector<State>> readFile(string path) {

  ifstream file(path);
  vector<vector<State>> container_vec{};

  if (file) {
    string line;
    while (getline(file, line)) {
      istringstream string_line(line);
      int n;
      char c;
      vector<State> temp_vec;
      while (string_line >> n >> c && c == ',') {
        if (n == 0) {
          temp_vec.push_back(State::k_empty);
        }
        else{
          temp_vec.push_back(State::k_obstacle);
        }
      }
      container_vec.push_back(temp_vec);
    }
  }
  return container_vec;
}

void printFile(const vector<vector<State>> dd_vector) {
  // prints the 2D vector passed by iterating over each row
  // and then each column in the row
  for (vector<State> d_vector : dd_vector) {
    for (State col : d_vector) {
      if (col == State::k_empty)
        cout << "0";
      else
        cout << "⛰ ";
        cout<<",";
      }
      cout << "\n";
    }
  }

int main() {

  printFile(readFile("board.csv"));

  return 0;
}