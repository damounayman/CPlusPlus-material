
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
# long vs long long
long is equivalent to long int, just as short is equivalent to short int. A long int is a signed integral type that is at least 32 bits, while a long long or long long int is a signed integral type is at least 64 bits.

# Vector 

- Declaration:

```cpp
    vector<int>v; (creates an empty vector of integers)
```

- Size:

```cpp
    int size=v.size();
```

- Pushing an integer into a vector:

```cpp
    v.push_back(x);(where x is an integer.The size increases by 1 after this.)
```

- Popping the last element from the vector:

```cpp
    v.pop_back(); (After this the size decreases by 1)
```

- Sorting a vector:

```cpp
    sort(v.begin(),v.end()); (Will sort all the elements in the vector)
```

- erase(int position):

```cpp
Removes the element present at position.  
Ex: v.erase(v.begin()+4); (erases the fifth element of the vector v)
```

- erase(int start,int end):

```cpp
Removes the elements in the range from start to end inclusive of the start and exclusive of the end.
Ex:v.erase(v.begin()+2,v.begin()+5);(erases all the elements from the third element to the fifth 
```

# Strings

C++ provides a nice alternative data type to manipulate strings, and the data type is conveniently called string. Some of its widely used features are the following:

- Declaration:

```cpp
    string a = "abc";
```

- Size:

```cpp
    int len = a.size();
```

- Concatenate two strings:

```cpp
    string a = "abc";
    string b = "def";
    string c = a + b; // c = "abcdef".
```

- Accessing $i^{th}$ element:

```cpp
string s = "abc";
char   c0 = s[0];   // c0 = 'a'
char   c1 = s[1];   // c1 = 'b'
char   c2 = s[2];   // c2 = 'c'

s[0] = 'z';         // s = "zbc"
```
# StringStream
stringstream is a stream class to operate on strings. It implements input/output operations on memory (string) based streams. stringstream can be helpful in different type of parsing. The following operators/functions are commonly used here:

- Operator >> Extracts formatted data.
- Operator << Inserts formatted data.
- Method str() Gets the contents of underlying string device object.
- Method str(string) Sets the contents of underlying string device object.

Its header file is sstream.

One common use of this class is to parse comma-separated integers from a string (e.g., "23,4,56").

```cpp
stringstream ss("23,4,56");
char ch;
int a, b, c;
ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56
```

# Sets-STL

Sets are a part of the C++ STL. Sets are containers that store unique elements following a specific order. Here are some of the frequently used member functions of sets:

- Declaration:

```cpp
set<int>s; //Creates a set of integers.
```

- Size:

```cpp
int length=s.size(); //Gives the size of the set.
```

- Insert:

```cpp
s.insert(x); //Inserts an integer x into the set s.
```

- Erasing an element:

```cpp
s.erase(val); //Erases an integer val from the set s.
```

- Finding an element:

```cpp
set<int>::iterator itr=s.find(val); //Gives the iterator to the element val if it is found otherwise returns s.end() .
Ex: set<int>::iterator itr=s.find(100); //If 100 is not present then it==s.end().
```

# lower_bound in C++
The lower_bound() method in C++ is used to return an iterator pointing to the first element in the range [first, last) which has a value not less than val. This means that the function returns the index of the next smallest number just greater than or equal to that number. If there are multiple values that are equal to val, lower_bound() returns the index of the first such value.
The elements in the range shall already be sorted or at least partitioned with respect to val. 

```cpp
// std :: lower_bound
#include <bits/stdc++.h>
 
// Driver code
int main()
{
    // Input vector
    std::vector<int> v{ 10, 20, 30, 30, 30, 40, 50 };
 
    // Print vector
    std::cout << "Vector contains :";
    for (unsigned int i = 0; i < v.size(); i++)
        std::cout << " " << v[i];
    std::cout << "\n";
 
    std::vector<int>::iterator low1, low2, low3;
     
    // std :: lower_bound
    low1 = std::lower_bound(v.begin(), v.end(), 30);
    low2 = std::lower_bound(v.begin(), v.end(), 35);
    low3 = std::lower_bound(v.begin(), v.end(), 55);
 
    // Printing the lower bounds
    std::cout
        << "\nlower_bound for element 30 at position : "
        << (low1 - v.begin());
    std::cout
        << "\nlower_bound for element 35 at position : "
        << (low2 - v.begin());
    std::cout
        << "\nlower_bound for element 55 at position : "
        << (low3 - v.begin());
 
    return 0;
}
```
Output
```
Vector contains : 10 20 30 30 30 40 50

lower_bound for element 30 at position : 2
lower_bound for element 35 at position : 5
lower_bound for element 55 at position : 7
```
# Sets-STL

Sets are a part of the C++ STL. Sets are containers that store unique elements following a specific order. Here are some of the frequently used member functions of sets:

- Declaration:

```cpp
set<int>s; //Creates a set of integers.
```

- Size:

```cpp
int length=s.size(); //Gives the size of the set.
```

- Insert:

```cpp
s.insert(x); //Inserts an integer x into the set s.
```

- Erasing an element:

```cpp
s.erase(val); //Erases an integer val from the set s.
```

- Finding an element:

```cpp
set<int>::iterator itr=s.find(val); //Gives the iterator to the element val if it is found otherwise returns s.end() .
Ex: set<int>::iterator itr=s.find(100); //If 100 is not present then it==s.end().
```

# Maps-STL

Maps are a part of the C++ STL.Maps are associative containers that store elements formed by a combination of a key value and a mapped value, following a specific order.The mainly used member functions of maps are:

- Map Template:

```cpp
std::map <key_type, data_type>
```

- Declaration:

``` cpp
map<string,int>m; //Creates a map m where key_type is of type string and data_type is of type int.
```

- Size:

```cpp
int length=m.size(); //Gives the size of the map.
```

- Insert:

```cpp
m.insert(make_pair("hello",9)); //Here the pair is inserted into the map where the key is "hello" and the value associated with it is 9.
```

- Erasing an element:

```cpp
m.erase(val); //Erases the pair from the map where the key_type is val.
```

- Finding an element:

```cpp
map<string,int>::iterator itr=m.find(val); //Gives the iterator to the element val if it is found otherwise returns m.end() .
Ex: map<string,int>::iterator itr=m.find("Maps"); //If Maps is not present as the key value then itr==m.end().
```

- Accessing the value stored in the key:

```cpp
To get the value stored of the key "MAPS" we can do m["MAPS"] or we can get the iterator using the find function and then by itr->second we can access the value.
```
