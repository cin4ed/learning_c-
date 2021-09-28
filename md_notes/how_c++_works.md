
The basic workflow of writing a C++ program is that you have a series of source
files in which you write actual text, and then you pass them through a compiler
which compiles it into some kind of binary. 

That binary can be some sort of library or it can be an actual executable 
program.

## What compiler does when it receives a source file
Only `.cpp` files gets compiled, no header files.

Preprocessor statements get preprocessed, anything that begins with a "#" is a 
preprocessor statement.

For example the `#include <iostream>` statement, `#include` will find a file, in
this case it's looking for a file called `iostream`, it'll take all of the
contents of that file and just paste it into this current file.

That files that you include are typically called header files.

The reason behind why we would include `iostream` is because we need a
**declaration** for a function called `cout` which lets us print stuff to our
console.

Another thing that the compiler does when it compiles a source file is that it
checks if there is a **declaration** or a **definition** for a given function
that we use. You could provide a declaration for it without a defition and the
compiler will trust you and succeed the compilation process. Finding the
definition of that given function is task to be donde by the linker.

All the previous happens with every `.cpp` file, they all get compiled 
individually into something called an **object** file.

## What linker does when compiler has finished its work
Once we have all of those individual `obj` files, we need some way to stitch
them together into one `exe` file, that is where the **linker** comes in.

Remember those functions with only declarations? well, the linker now can
check if that definition for your function is in any other `obj` file that was
previously compiled.

If the linker cannot found a definition for a given function then you will get a
**linker error**.

Basically what the linker does is that it takes all the `obj` files and it glues
them together producing one `exe` file.

## Resume
1. All the `cpp` files get compiled.
2. When compiling the first thing the compiler does is look for preprocessor
  statements, and preprocess them.
3. When the compiler finishes compiling a file, it will output an `object` file,
  it will do this for every single `cpp` file (it doesn't output a `exe` file).
4. Once all the `cpp` files get compiled into `object` files, the linker will
   stitch them together outputting an `exe` file. 
