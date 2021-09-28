#include <iostream>
#include <string>

// Structures or structs are used to group data together.

// A struct can have different data elements in it, called members, integers,
// floats, chars, and so on.

// You can create many objects of a similar struct and store values in the
// struct for data management.

// The syntax of a struct is as follows:
struct Dog {
    std::string name;
};

// An object is an instance of a struct to which we can assign properties to the
// data types we created when creating the struct.

// Another expample:
// In a situation in which you want to maintain a database of students'ages and
// the height of a section, your struct definition will look like this:
struct Student {
    int age;
    float height;
};

// Now you could create an array of objects an sotre the values for each
// student:
void func_1() {
    Student section[2];

    section[0].age = 17;
    section[0].height = 1.77f;

    section[1].age = 18;
    section[1].height = 1.80f;
}

// -----------------------------------------------------------------------------
 
// The main difference between a class and a struct is the default visibility of
// their attributes.

// Struct - by default all the attributes are public. 
// Class  - by default all the attributes are private.

struct StructPerson {
    int age;
} typedef StructPerson;

class ClassPerson {
    int age;
};

int main(void) {
    StructPerson structMe;
    structMe.age = 19; // This is valid because age is public.

    ClassPerson classMe;
    // classMe.age = 19;  This is invalid because age is private.
    
    return 0;
}


