#include <iostream>

// Before talking about namespaces, you need to know about naming collisions, a
// naming collision occurs when two idential identifiers are introduced into the
// same scope, and the compiler can't disambiguate which one to use.

// A way to avoid collisions is to put your functions into your own namespaces.
// For this reason the standard library was moved into the std namespace.

// Namespaces allow you to specify particular identifiers for usage, a name
// declared in a namespace won't be mistaken for an identical name declared in
// another scope. Namespace provides a scope (called namespace scope) to the
// names declared inside it.

// C++ allow us to define our own namepsaces via the namespace keyword.
// Namespaces that you create for your own declaration are called user-defined
// namespaces.

// Namespaces provided by C++ (such as the global namespace) or by libraries
// (such as namespace std) are not considered user-defined namespaces.

// -----------------------------------------------------------------------------

// Namespaces identifiers are typically non-capitalized.

// Check foo.cpp
// Check goo.cpp

// Now doSomething() inside of foo.cpp is inside the foo namespace, and the
// doSomething() inside of goo.cpp is inside the goo namespace.

// We put the forward declaration of the doSomething function:
int doSomething(int x, int y);

// If we run this as it is right now, we would get a linker error, because the
// linker could not find a definition for doSomething in the global namespace.
// This is because both of our versions of doSomething are no longer in the
// global namespace!

// Now there are two differnt ways to tell the compiler which version of
// doSomething() to use:
// - Via the scope resolution operator.
// - Via usint statements.

// -----------------------------------------------------------------------------

// Accessing a namespace with the scope resolution operator (::).

// The best way to tell the compiler look in a particular namespace for an
// identifier is to use the scope resolution operator (::). It tells the
// compiler that the identifier specified by the right-hand operand should be
// looked for in the scope of the left-hand operand.

// Here is an example of using the scope resolution operator to tell the
// compiler that we explicitly want to use the verson of doSomething() that
// lives in the foo namespace:

namespace foo { // Define a namespace named foo
    // This doSomething() belongs to namespace foo
    int doSomething(int x, int y) {
        return x + y;
    }
}

namespace goo { // Define a namespace named goo
    // This doSomething() belongs to namespace goo
    int doSomething(int x, int y) {
        return x - y;
    }
}

void foo_and_goo() {
    // use the doSomething() that exists in namespace foo:
    std::cout << foo::doSomething(10, 5) << "\n";

    // if we wanted to use the one that exists in namespace goo:
    std::cout << goo::doSomething(40, 30) << "\n";
}

// -----------------------------------------------------------------------------

// Using the scope resolution operator with no name prefix.

// The scope resolution operator can also be used in front of an identifier
// without providing a namespace (e.g ::doSomething). In such a case, the
// identifier (e.g doSomething) is looked for in the global namespace.

void print() { // This print lives in the global namespace
    std::cout << "Hello from global namespace!" << "\n";
}

namespace boo {
    void print() {
        std::cout << "Hello from boo namespace!" << "\n";
    }
}

void global_and_boo() {
    // call print() in global namespace (same as just calling print() in this
    // case)
    ::print();

    // call print() in boo namespace.
    boo::print();
}

// In the above example, the ::print() performs the same as if we'd called
// print() with no scope resolution, so use of the scope resolution operator is
// superfluous in this case.

// The next example shows a case where the scope resolution operator wih no
// namespace can be usefull.

// -----------------------------------------------------------------------------

// Identifier resolution from within a namespace

// If an identifier inside a namespace is used and no scope resolution is
// provided, the compiler will first try to find a matching declaration in that
// same namespace.

// If no matching identifier is found, the compiler will then check each
// containing namespace in sequence to see if a match is found, with the global
// namespace being checked last.

void bark() { // This bark lives in the global namespace.
    std::cout << "Woff! from global namespace dog." << "\n";
}

namespace poo {
    void bark() {
        std::cout << "Woff! from poo namespace dog." << "\n";
    }
    void callDog() {
        bark(); // Calls bark() in poo namespace.
        ::bark(); // Calls bark() in global namespace.
    }
}

void global_and_poo() {
    poo::callDog();
}

// In the above example, bark() is called with no scope provided. Because of
// print() is inside poo namespace, the compiler will first see if a declaration
// for poo::bark() can be found. Since one exists, poo:bark() is called.

// If foo::bark() had not been found, the compiler would have checked the
// containing namespace (in this case, the global namespace) to see if it could
// match a bark() there.

// Note that we also make use of the scope resolution operator with no namespace
// (::bark()) to explicitly call the global version of bark().

// -----------------------------------------------------------------------------

// Multiple namespace blocks are allowed

// It's legal to declare namespaces blocks in multiple location (either across
// multiple files, or multiple places within the same file). All declaration
// within the namespace are considered part of the namespace.

// check circle.h
// check growth.h

#include "circle.h" // For basicMath::pi
#include "growth.h" // For basicMath::e

void circle_and_growth() {
    std::cout << basicMath::pi << "\n";
    std::cout << basicMath::e << "\n";
}

// The standard library makes extensive use of this feature, as each standard
// library header file contains its declarations inside a namespace std block.
// Otherwise the entire standard library would have to be defined in a single
// header file.

// -----------------------------------------------------------------------------

// When you separate your code into multiple files, you'll have to use a
// namespace in the header and source file.

// check add.h

#include "add.h"

namespace basicMath {
    // define the function add()
    int add(int x, int y) {
        return x + y;
    }
}

// If the namespace is ommited in the source file, the linker won't find a
// definition of basicMath::add, because the source file only defines add
// (global namespace). If the namespace is ommited in the header file,
// "main.cpp" won't be able to use basicMath::add, because it only sees a
// declaration for add (global namespace).

// -----------------------------------------------------------------------------

// Nested namespaces

// Namespaces can be nested inside other namespaces. For example:
namespace voo {
    namespace zoo { // zoo is a namespace inside the foo namespace
        int add(int x, int y) {
            return x + y;
        }
    }
}

void voo_and_zoo() {
    std::cout << voo::zoo::add(4, 2) << "\n";
}

// Note that because naemespace zoo is inside namespace voo, we acces add as
// voo::zoo::add.

// Since C++17, nested namespaces can aslo be declared this way:
namespace voo::zoo {
    int subs(int x, int y) {
        return x - y;
    }
}

// -----------------------------------------------------------------------------

// Namespaces aliases

// Because typing the fully qualified name of a variable or function inside a
// nested namespace can be painful, C++ allow you to create namespace aliases,
// which allow us to temporarily shorten a long sequence of namespaces into
// something shorter:

void aliases() {
    namespace active = voo::zoo; // active now refers to voo::zoo
    std::cout << active::subs(10, 5) << "\n";
}

// One nice advantage of namespace aliases: if you evern want to move the
// functionality within voo::zoo to a different place, you can just update the
// active alias to reflect the new destination, rather than having to
// find/replace every instance of voo::zoo.
