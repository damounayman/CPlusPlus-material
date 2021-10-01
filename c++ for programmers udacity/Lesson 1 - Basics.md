
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
 