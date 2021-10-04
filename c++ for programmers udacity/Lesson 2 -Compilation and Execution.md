
# Compilation
Compiling is the process of translating the code that you've written into machine code that processors understand. 

# Object Files

Compiling source code, like a single .cpp file, results in something called an object file. An object file contains machine code but may not be executable in and of itself. Among other things, object files describe their own public APIs (usually called symbols) as well as references that need to be resolved from other object files. Depended upon object files might come from other source files within the same project or from external or system libraries.

# Linking
Linking is the process of creating an executable by effectively combining object files. During the linking process, the linker (the thing that does the linking) resolves symbolic references between object files and outputs a self-contained binary with all the machine code needed to execute.
