
## Object Files

So far in this course, we have refered to running g++ as "compiling".

However, g++ performs several distinct tasks:

    1 - The preprocessor runs and executes any statement beginning with a hash symbol: #. This takes care of any #include statements, for example, so that all code is in place and ready to compile.
    2 - Each file in the source code is compiled into an "object file" (a .o file). Object files are platform-specific machine code that will be used to create an executable.
    3 - The object files are "linked" together to make a single executable. In the examples you have seen so far, this executable is a.out, but you can specify whatever name you want.

It is possible to have g++ perform each of the steps separately by using the -c flag. For example,
```bash
g++ -c main.cpp
```
will produce a main.o file, and that file can be converted to an executable with
```bash
g++ main.o
```

Your Turn!

Try these commands in the terminal below:

    Save the file. The button will save the file as main.cpp
    Compile to an object file using the -c flag. You can list the files in the directory with ls. After compiling, you should see a main.o somewhere in the directory (along with all the notebook files).
    Convert the file to an executable with g++.
    Run the executable with ./a.out.
```cpp
#include 
using std::cout;

int main() 
{
    cout << "Hello!" << "\n";
}
```
 
In the example above, you compiled a single source code file to an object file. That object file was then converted into an executable. If you wanted to do this with many source code files, and your directory only contained the files for your project, your bash commands might look like the following:
```bash
root@abc123defg:/home/workspace# g++ -c *.cpp
root@abc123defg:/home/workspace# g++ *.o
root@abc123defg:/home/workspace# ./a.out
```
Here, the * operator is a wildcard, so any matching file is selected.

But what if you make changes to the code? In that case, you can compile only that file, and use the existing object files from the other source files for linking. For example, if you only changed file_3.cpp in your code, and all other object files were already created, you could run:
```bash
root@abc123defg:/home/workspace# g++ -c file_3.cpp
root@abc123defg:/home/workspace# g++ *.o
root@abc123defg:/home/workspace# ./a.out
```
As mentioned previously, this works great for small programs, where all the files are easy to find, and you can remember which ones you have modified. For larger projects, it is helpful to use a build system which can compile the right files for you and take care of linking.
CMake and Make

CMake is an open-source, platform-independent build system. CMake uses text documents, labeled as CMakeLists.txt files, to manage platform-specific build environments, like make. Unfortunately, an in-depth tutorial on CMake is beyond the scope of this course, but we can discuss the basics of how CMake works, so you will be ready to use it in your project.
CMakeLists.txt

CMakeList.txt files have a hierarchical structure, and one CMakeList.txt file can be included in each directory of the project. These files can be used to specify the locations of necessary packages, set build flags and environment variables, specify build target names and locations, and other actions.
CMake Project

A typical CMake project will have a top-level CMakeLists.txt and a build directory. From within the build directory, you could run
```bash
root@abc123defg:/my_project/build# cmake ..
root@abc123defg:/my_project/build# make
```
The first line directs the cmake command at the top-level CMakeLists.txt file with ... This command uses the top-level CMakeLists.txt to configure the project and create a Makefile. In the second line, make finds the Makefile and uses the instructions in the Makefile to build the project.

In general, CMake only needs to be run once for a project, unless you are changing build options (e.g. using different build flags). Make will be able to keep track of which files have changed and compile only those that need to be before building.
