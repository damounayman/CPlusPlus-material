
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