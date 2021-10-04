
The creator of C++ is  Bjarne Stroustrup.

Each C++ program consists of two parts: the preprocessor directives and the main function. 

# C++ Example

```cpp
#include <iostream>

  int main() 
 {
      std::cout << "Hello world, I am ready for C++";
      return 0;
  }
```

 Any line that has a hash sign at the start is a preprocessor directive. 

 The brackets say “Look for this file in the directory where all the standard libraries are stored”. C++ also allows us to specify the library name using double quotes. 

 The double quotes say “look in the current directory, if the file is not there, then look in the directory where the standard libraries are stored”. 

 # Adding Comments

 Comments can be added in two ways:

    As a comment block
    As a single line


## comment Example

```cpp
/*write a C++ program that get your favorite year:
"What year is your favorite?"
*/
int main()
{
    int year = 0;
    int age = 0;
    std::string name = " ";
    //print a message to the user <- this line is a comment
    std::cout<<"What year is your favorite? ";
    //get the user response and assign it to the year<- this line is a comment
    std::cin >> year;
```

The command to compile is : 

```sh
 g++  main.cpp -o main.out
 ```

 # Using Namespace
 Before the start of the main function, put in the command “using namespace std;”
```cpp
using namespace std;
 int main()
 {
 }
```
This tells the compiler to assume we are using the standard library, so we don’t have to write std::.

# Define Constants
In C++ we can define a variable as a constant. Meaning, its value does not change for the life of the program.

We use the keyword 'const' to define a constant.

For example: 
```cpp
const int weightGoal = 100;
 ```

# Format Output
The iomanip is a library in C++ which helps us in manipulating the output of any C++ program.

setw: It helps in changing the width of the next input or output field.

```cpp
std::cout<<"Ints"<<std::setw(15)<<"Floats"<<std::setw(15)<<"Doubles"<< "\n";
// Ints         Floats        Doubles
 ```

# FileI0 Steps:
 - Include the <fstream> library 
 - Create a stream (input, output, both)
      - ofstream myfile; (for writing to a file)
      - ifstream myfile; (for reading a file)
      - fstream myfile; (for reading and writing a file)
 - Open the file  myfile.open(“filename”);
 - Write or read the file
 - Close the file myfile.close();

# Header Files
As we have seen we can include additional libraries in C++, we can also include our own libraries.

Traditionally, these files are called header files and they have an .hpp extension. Although any extension will work.

Header files contain information about how to do a task.
The main program contains information about what to do.

To tell the compiler to include the header file.

```cpp
 #include "main.hpp"
 ```

# String Input

std::cin will not retrieve strings that have a space in them. It will see the space as the end of the input. We will obviously need a method to enter strings.
C++ has a function called getline.

The basic form of getline is:

getline: it will retrieve characters from the std::cin source and stores them in the variable called variableName. It will retrieve all characters until the newline or “\n” is detected.

The programmer can also specify a different delimiter if the newline character is not desired.