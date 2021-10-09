
# How to find the maximum element of an Array using STL in C++?
Given an array arr[], find the maximum element of this array using STL in C++.

```cpp
#include <bits/stdc++.h>
*max_element (first_index, last_index);
```

# Pointer
A pointer in C++ is used to share a memory address among different contexts (primarily functions). They are used whenever a function needs to modify the content of a variable, but it does not have ownership. 

In order to access the memory address of a variable , val, prepend it with & sign. For example, &val returns the memory address of val.

This memory address is assigned to a pointer and can be shared among functions. For example, $i n t^{*} p=\& v a l$ assigns the memory address of val to pointer $p$. To access the content of the memory pointed to, prepend the variable name with a $\star$. For example, $\star p$ will return the value stored in $v a l$ and any modification to it will be performed on val.

```cpp
void increment(int *v) {
    (*v)++;
}

int main() {
    int a;
    scanf("%d", &a);
    increment(&a);
    printf("%d", a);
    return 0;
}  
```

# Arrays Introduction
An array is a series of elements of the same type placed in contiguous memory locations that can be individually referenced by adding an index to a unique identifier.

**Note**: Unlike $C, C++$ allows dynamic allocation of arrays at runtime without special calls like malloc(). If $n=10$, int arr $[n]$ will create an array with space for 10 integers.

# What is the use of cin.ignore() in C++?
 cin.ignore() will ignore what the cin buffer contains.

# Structs
struct is a way to combine multiple fields to represent a composite data structure, which further lays the foundation for Object Oriented Programming. For example, we can store details related to a student in a struct consisting of his age (int), first_name (string), last_name (string) and standard (int). 

```cpp
struct NewType {
    type1 value1;
    type2 value2;
    .
    .
    .
    typeN valueN;
};
```
# Classes
Classes in C++ are user defined types declared with keyword class that has data and functions . Although classes and structures have the same type of functionality, there are some basic differences. The data members of a class are private by default and the members of a structure are public by default. Along with storing multiple data in a common block, it also assigns some functions (known as methods) to manipulate/access them. It serves as the building block of Object Oriented Programming.

It also has access specifiers, which restrict the access of member elements. The primarily used ones are the following:

   - public: Public members (variables, methods) can be accessed from anywhere the code is visible.
   - private: Private members can be accessed only by other member functions, and it can not be accessed outside of class.

```cpp
   class ClassName {
    access_specifier1:
        type1 val1;
        type2 val2;
        ret_type1 method1(type_arg1 arg1, type_arg2 arg2,...)
        ...
    access_specifier2:
        type3 val3;
        type4 val4;
        ret_type2 method2(type_arg3 arg3, type_arg4 arg4,...)
        ...
};
```
It's a common practice to make all variables private, and set/get them using public methods. For example:

```cpp
class SampleClass {
    private:
        int val;
    public:
        void set(int a) {
            val = a;
        }
        int get() {
            return val;
        }
};
```