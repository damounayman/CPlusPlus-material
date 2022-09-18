// istringstream constructors.
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <string>       // std::string


/*
One way to stream a string is to use an input string
stream object std::istringstream from the header. 
Once a std::istringstream object has been created, 
then the string can be streamed and stored using the 
extraction operator(>>). The extraction operator will read
until whitespace is reached or until the stream fails.
Below is the illustration of the std::istringstream:
*/

int main () {
  // Input string
  std::string stringvalues = "125 320 512 750 333";
  // Object class of istringstream
  std::istringstream iss (stringvalues);

  for (int n=0; n<5; n++)
  {
    // Variable to store number n
    int val;
    // Stream a number till white space
    // is encountered
    iss >> val;
    std::cout << val*2 << '\n';
  }

  return 0;
}