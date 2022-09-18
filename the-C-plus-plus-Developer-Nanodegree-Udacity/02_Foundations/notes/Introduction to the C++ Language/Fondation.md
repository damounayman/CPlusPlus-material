# Outline

- **Getting Started**:
    - Write and run your first C++ program
    - Send output to the console
- **Variables and Containers**:
    - Variable types
    - Vectors
    - Using auto
- **Functions and Control Structures**:
    - For loops
    - Functions
    - If statements and while loops
- **Data Input**
    - Read data from a file
    - Parse data and process strings
- **Defining your own types with Enums**


# **Getting Started**:
### C++ Main()

main() should return an integer (an int in C++), which indicates if the program exited successfully. 

```cpp
// `#include` is a preprocessor command that searches for the iostream header file and pastes its contents into the program.
# include <iostream>
int main() {
// The main function has the datatype of `integer`.
// That means, it should return a number. That's why we return 0.
  int x = 5 + 6;
  std::cout << "Hello World! " << x << "\n";
  return 0;
}
```

Compile the file

```sh
$ g++ -o hello_world hello_world.cpp
```
The flag -o creates an executable with the name hello_world instead of a.out by using the file hello_world.cpp

Compiled Languages vs Scripted Languages


# ** C++ Comments **


// You can use two forward slashes for single line comments.

/*
For longer comments, you can enclose the text with an opening
slash-star and closing star-slash.
*/ 
