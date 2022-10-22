#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> myfullname{"ayman", "damoun"};
  for (std::string const &part : myfullname) {
    std::cout << part << std::endl;
  }
}
