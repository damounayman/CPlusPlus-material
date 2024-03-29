## 2.4 Writing Muitifile Programs

### Intro

#### Lesson Outline

- Header files
  - Using headers to break a single file into multiple files
- Build systems
  - CMake and Make
- Tools for writing larger programs:
  - References
  - Pointers
  - Maps
  - Classes and object-oriented programming in C++

### Header Files

Header files, or `.h ` files, allow related function, method, and class declarations to be collected in one place. The corresponding definitions can then be placed in `.cpp ` files. The compiler considers a header declaration a "promise" that the definition will be found later in the code, so if the compiler reaches a function that hasn't been defined yet, it can continue on compiling until the definition is found. This allows functions to be defined (and declared) in arbitrary order.

#### Function Order in a Single File

In the following code example, the functions are out of order, and the code will not compile. Try to fix this by rearranging the functions to be in the correct order.

```cpp
#include <iostream>
using std::cout;
void OuterFunction(int i)
{   
    //you have to define the InnerFunction befre call it.
    InnerFunction(i);
}
void InnerFunction(int i)
{
    cout << "The value of the integer is: " << i << "\n";
}
int main()
{
    int a = 5;
    OuterFunction(a);
}
```

Solution:

```cpp
#include <iostream>
using std::cout;
void InnerFunction(int i)
{
    cout << "The value of the integer is: " << i << "\n";
}
void OuterFunction(int i)
{   
    //you have to define the InnerFunction befre call it.
    InnerFunction(i);
}
int main()
{
    int a = 5;
    OuterFunction(a);
}
```



#### Using a Header

One other way to solve the code problem above (without rearranging the functions) would have been to declare each function at the top of the file.

A function declaration is much like the first line of a function definition - it contains the return type, function name, and input variable types. The details of the function definition are not needed for the declaration though.

To avoid a single file from becomming cluttered with declarations and definitions for every function, it is customary to declare the functions in another file, called the header file. In C++, the header file will have filetype .h, and the contents of the header file must be included at the top of the .cpp file.

See the following example for a refactoring of the code above into a header and a cpp file.

```cpp
// The contents of header_example.h are included in
// the corresponding .cpp file using quotes:
//find .h in the same directory as the .cpp file
#include "header_example.h"
#include <iostream>
using std::cout;
void OuterFunction(int i)
{
    InnerFunction(i);
}
void InnerFunction(int i)
{
    cout << "The value of the integer is: " << i << "\n";
}
int main()
{
    int a = 5;
    OuterFunction(a);
}
```

```h
// header_example.h
// The header file with just the function declarations.
// When you click the "Run Code" button, this file will
// be saved as header_example.h.
//include guard
#ifndef HEADER_EXAMPLE_H
#define HEADER_EXAMPLE_H
//don't need variable names, just variable types.
void OuterFunction(int);
void InnerFunction(int);
#endif
```

NOTE:
The function declarations in the header file don't need variable names, just variable types. You can put names in the declaration, however, and doing this often makes the code easier to read.
The `#include` statement for the header used quotes `" "` around the file name, and not angle brackets `<>`. We have stored the header in the same directory as the `.cpp` file, and the quotes tell the preprocessor to look for the file in the same directory as the current file - not in the usual set of directories where libraries are typically stored.

Finally, there is a preprocessor directive:

```h
#ifndef HEADER_EXAMPLE_H
#define HEADER_EXAMPLE_H
```

at the top of the header, along with an `#endif` at the end. This is called an **"include guard"**. Since the header will be included into another file, and `#include` just pastes contents into a file, **the include guard prevents the same file from being pasted multiple times into another file.**
This might happen if multiple files include the same header, and then are all included into the same main.cpp, for example. The ifndef checks if HEADER_EXAMPLE_H has not been defined in the file already. If it has not been defined yet, then it is defined with #define HEADER_EXAMPLE_H, and the rest of the header is used. If HEADER_EXAMPLE_H has already been defined, then the preprocessor does not enter the ifndef block. 

Note: There are other ways to do this.
Another common way is to use an #pragma oncepreprocessor directive, but we won't cover that in detail here. See this Wikipedia article for examples.

#### Using Header Practice

```cpp
// main.cpp
#include <iostream>
#include <vector>
#include "myhelper.h"
using std::vector;
using std::cout;
int IncrementAndComputeVectorSum(vector<int> v)
{
    int total = 0;
    AddOneToEach(v);
    for (auto i: v) {
        total += i;
    }
    return total;
}
void AddOneToEach(vector<int> &v)
{
    // Note that the function passes a reference to v
    // and the for loop below uses references to
    // each item in v. This means the actual
    // ints that v holds will be incremented.
    for (auto& i: v) {
        i++;
    }
}
int main()
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}
```

```h
// myhelper.h
#ifndef MYHELPER_H
#define MYHELPER_H
#include<vector>
using std::vector;
int IncrementAndComputeVectorSum(vector<int> );
void AddOneToEach(vector<int> &);
#endif
```



### Using Headers with Multiple Files

In the previous concept, you saw how header files could be useful for separating definitions from declarations, so that you don't need to be too careful about the order in which functions are defined. Using header files is typically the first step in creating a multi-file program. In this concept, you will learn about using multiple `.cpp ` and `.h ` files in a program - how to compile all the files together, and how to ensure the code from one file can be used in another.



#### Single File Code

In the previous concept, you saw some example code that wouldn't compile because the functions were out of order:

```cpp
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;
    //pass reference
    AddOneToEach(v);
    
    for (auto i: v) {
        total += i;
    }
    return total;
}
void AddOneToEach(vector<int> &v) {
    for (auto& i: v) {
        i++;
    }
}
int main() {
    vector<int> v{1, 2, 3, 4};
    //call by value
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}
```

In the last exercise of the notebook, you were to separate that code into a header .h file and a .cpp file. But what if you wanted to use completely separate files for each of the functions? For example, you might want to do this if the functions were going to belong to different classes or libraries.

#### Multi-file Code

In the next few cells these functions have been separated into several different files.


```cpp
// main.cpp
/*
The structure of the included files is as follows:
    vect_add_one --> increment_and_sum -->main
*/
#include <iostream>
#include <vector>
#include "increment_and_sum.h"
using std::vector;
using std::cout;
int main()
{
    vector<int> v{1, 2, 3, 4};
    int total = IncrementAndComputeVectorSum(v);
    cout << "The total is: " << total << "\n";
}
```

```h
// increment_and_sum.h
#ifndef INCREMENT_ADD_SUM_H
#define INCREMENT_ADD_SUM_H
#include<vector>
using std::vector;
int IncrementAndComputeVectorSum(vector<int> );
#endif
```

```cpp
// increment_and_sum.cpp
// include vect_add_one call  AddOneToEach function
#include "vect_add_one.h"
int IncrementAndComputeVectorSum(vector<int> v) {
    int total = 0;
    //pass reference
    AddOneToEach(v);
    for (auto i: v) {
        total += i;
    }
    return total;
}
```

```h
// vect_add_one.h
#ifndef VECT_ADD_ONE_H
#define VECT_ADD_ONE_H
#include<vector>
using std::vector;
void AddOneToEach(vector<int> &);
#endif
```

```cpp
// vect_add_one.cpp
#include<vector>
using std::vector;
void AddOneToEach(vector<int> &v) {
    for (auto& i: v) {
        i++;
    }
}
```



If you look carefully at the files above, you will see several things:

a. vect_add_one.h is included in increment_and_sum.cpp.

This is becuase `AddOneToEach` is used in `IncrementAndComputeVectorSum`. Including the `vect_add_one.h` header means that the `AddOneToEach` function declaration is pasted into  `increment_and_sum.cpp`, so no compiler error will occur when the `AddOneToEach` function is used.

b. Only the header file needs to be included in another file.

As long as the header file is included, the corresponding function declarations will be included. When the compiler finds an undefined function, it has already seen the function's declaration. This means the compiler can continue on without error until it finds the definition of the function, regardless of where that definition is.

c. Some libraries, like `<vector>` are included in mutliple files.

Each file is compiled alone and must have all the declarations and libraries necessary to compile, so the necessary libraries must be included. This is another reason why include guards are important. If multiple headers were included in main, each with the same `#include <vector>` statement, you wouldn't want the vector header pasted multiple times into the code.



Compile

```
g++ -std=c++17 ./main.cpp ./increment_and_sum.cpp ./vect_add_one.cpp
```

Output

```
The total is: 14
```
