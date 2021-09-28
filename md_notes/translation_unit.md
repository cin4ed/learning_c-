## Translation unit
A translation unit is the basic unit of compilation int c++. It consists of the
contents of a single source file, plus the contents of any header files directly
or indirectly included by it, minus those lines that were ignored using
conditional preprocessing statements.

A translation unit can be compiled into an object file, library, or executable
program.

cpp file -> translation unit -> object file

A cpp file doesn't necessarilly have to equal a translation unit, for example
you could include many cpp files inside one cpp file, this resulting in a big
cpp file, well, even if you include many of them into one, this only will result
into one translation unit.
