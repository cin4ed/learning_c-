# Preprocessor commands
So called directives, they begin with a pound or hash symbol (#). No white
spaces should appear before the #, and semi colon is not required at the end.

Many things that can be done during preprocessing phase include:

- Inclusion of other files through #include directive.
- Definition of symbolic constants and macros through #define directive.

Through some preprocessor directives you can also conditionally compile or
execute some preprocessor directives.

NOTE - The preprocessor phase of a C++ program occurs before a program is
compiled. The preprocessor is a PROGRAM that is executed before the source code
is compiled.

## #define
The #define preprocessor allow us to define symbolic names and constants. For
example:

```c++
#define PI 3.141559
```
This statement will translate every occurrence of PI in the program to 
3.141559. Define allows you to make substitutions before compiling the program.

## #pragma once
In the C and C++ programming languages, `#pragma once` is a non-standard but
widely supported preprocessor directive designed to cause the current source
file to be included only once in a single compilation. Thus, `#pragma once`
serves the same purpose as `#include` guards, but with several advantages,
including: less code, avoiding name clashes, and improved compile speed.
