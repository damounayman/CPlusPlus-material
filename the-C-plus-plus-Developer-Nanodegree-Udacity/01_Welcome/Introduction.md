# 1- The c++ creator:
**Bjarne Stroustrup** is the designer and original implementer of C++ as well as the author of The C++ Programming Language (Fourth Edition), A Tour of C++ (Second edition), Programming: Principles and Practice using C++ (Second Edition), and many popular and academic publications.

# 2- The C++ Core Guidelines:
The C++ Core Guidelines are a set of best practices, recommendations, and rules for coding in C++ which have been developed by Bjarne Stroustrup and hundreds of other experts in the field. These guidelines are an important part of the language, as they help users to write the best, most up-to-date C++ programs
``` http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#main ```

# 3 Standard Library

    "The C++ Standard Library is a collection of classes and functions, which are written in the core language and part of the C++ ISO Standard itself."

Learning how to use the Standard Library is an important part of becoming a proficient C++ software engineer. In almost all cases, it is preferable to utilize functionality that already exists in the Standard Library, instead of implementing functionality from scratch. This is both because using the Standard Library is faster (it is well-documented) and because many expert software engineers have worked on the Standard Library. The performance of Standard Library facilities is optimized, robust, and almost always as fast or faster than an initial re-implementation of the same functionality.

In fact, guideline SL.1 of the C++ Core Guidelines is:

    Use libraries wherever possible

And guideline SL.2 is:

    Prefer the standard library to other libraries

# 4 Namespace

Standard Library functions and classes exist in the std:: namespace. std::vector, for example, refers to the vector class within the Standard Library. Typically, in order to use a Standard Library feature we must both include the necessary header file (e.g. #include **\<vector\>**) and also namespace the class with std:: (e.g. std::vector).

# 5 Compilation

C++ is a compiled programming language, which means that programmers use a program to compile their human-readable source code into machine-readable object and executable files. The program that performs this task is called a compiler.

C++ does not have an "official" compiler. Instead, there are many different compilers that a programmer can use.

- **GNU Compiler Collection (GCC)**:  
The **GNU Compiler Collection**, is a popular, open-source, cross-platform compiler from the larger GNU Project. In particular, we use the g++ program, which is a command line executable that compiles C++ source code and automatically links the C++ Standard Library.

![C++ Compilation Process (Wikimedia)](../docs/c-compilation-process.svg)

In order to use classes and functions from the C++ Standard Library, the compiler must have access to a compiled version of the standard library, stored in object files. Most compiler implementations, including GCC, include those object files as part of the installation process. In order to use the Standard Library facilities, the compiler must "link" the standard library object files to the object files created from the programmer's source code.

Once the compiler links together the necessary object files, it is able to generate a standalone executable file that can run on the operating system.


# 6 Build Tools

**Make** and **CMake** are two separate and similar build tools that both serve to help simplify the process of building software.

In particular, build tools automate the process of compiling multiple source code files into object files, linking those object files together, and generating an executable. Build tools also often automate the process of determining which files have changed since the last build and thus need to be recompiled.

```https://cmake.org/cmake/help/latest/guide/tutorial/index.html```

# 7-Style:
There are many different C++ styles, none of which is authoritative.


    - C++ Core Guidlines: Naming and layout rules
    - Google C++ Style Guide
    - Mozilla Coding Style: C/C++ practices

**ClangFormat**

clang-format is a command line text formatter that automatically reformats source code according to configurable set of policies. The tool includes several pre-configured styles, or you can create your own.

# 8-Debuggers

Debuggers are tools that allow you to pause the execution of your code in various locations, inspect the state of the program, and step through your code line-by-line.

**GDB** and **LLDB** are two popular, open-source debuggers for C++. Integrating them into a code editor often makes debugging easier.
```https://www.sourceware.org/gdb/```

Why Is C++ the Choice for Industry?
- work well with hardware
- handel complexity through abstraction
