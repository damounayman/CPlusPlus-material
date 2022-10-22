# include <iostream>
# include <string>
# include <vector>


int main(int argc, char const *argv[]) {
  /* code */
  std::vector<std::string> todolist{"clean the house", "make the diner", "read the book"};
  for (std::string const& todo : todolist){
      std::cout<<todo<<"\n";
  }
  
  return 0;
}

