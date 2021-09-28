#include <iostream>

// One of the key features of C++ is inheritance, with which we can create
// classes that are derived from other classes so that the derived or the child
// class automatically includes some of it's parent's member variables and
// functions.

// The syntax for an inherited class is as follows:
// class inheritedClassName: accessSpecifier parenClassName {
//
// };

// accessSpecifier could be public, private, or protected depending upon the
// minimum access level you want to provide to the parent member variables and
// functions.

// Example of inheritance:
class shape {
protected:
    float a, b;
public:
    void setValues(float _length, float _width) {
        a = _length;
        b = _width;
        std::cout << "Length is: " <<  a << ", width is: " << b << "\n";
    }
    // the next for the circle - keep reading
    void setValues(float _a) {
        a = _a;
    }
    void area() {
        std::cout << "Area is: " << a * b << "\n";
    }
}; 

// Now if we want a triangle class to access a and b of the parent class, we
// have to set the access specifier to protected, as shown previously,
// otherwise, ti will be set to private by default, we also created a setValues
// funtion instead of the constructor to set the values for a and b.

// So we do something like this:
class triangle : public shape {
public:
    void area() {
        std::cout << "Area of the triangle is: " << 0.5f * a * b << "\n";
    }
};


// -----------------------------------------------------------------------------

// To calculate the area of a circle, we modify the shape class and add a new
// overloaded setValues function, as follows:

// We will then add a new inherited class, called circle:
class circle : public shape {
public:
    void area() {
        std::cout << "Area of the circle is: " << 3.14f * a * a << "\n";
    }
};

// -----------------------------------------------------------------------------

int main() {
    shape rectangle;
    rectangle.setValues(8.0f, 12.0f);
    rectangle.area();

    triangle tri;
    tri.setValues(3.0f, 23.0f);
    tri.area();

     circle c;
     c.setValues(5.0f);
     c.area();
    return 0;
}
