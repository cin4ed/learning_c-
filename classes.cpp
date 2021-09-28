#include <iostream>

// In c++, structs and classes are identical. You can do the same things with
// both of them. The only difference is the default access specifer:
// - Public for structs
// - Private for classes

// The declaration of a class looks like the following code:
// class name {
// access specifier:
//     name();
//     ~name();
//
//     member1;
//     member2;
// };

// In a class, we first specify the access specifiers. There are three access
// specifiers: public, private, and protected:
// - public: all members are accessible from anywhere.
// - private: members are accessible from within the class intself only.
// - protected: members are accessed by other classes that inherit from the
// class.

// name(); and ~name(); are called the constructor and destructor of a class.
// They have the same name as the name of the class itself.

// The constructor is a special function that gets called when you create a new
// object of the class.

// The destructor is called when teh object is destroyed.

// We can customize a constructor to set values before using the member
// variables. This is called constructor overloading.

// Although the constructor and destructor are functions, no return is provided.
// This is because they are not there for returning values.

// Take a look at the next class:
class shape {
    int a, b;
public:
    shape(int _lenght, int _width) {
        a = _lenght;
        b = _width;

        std::cout << "Length is: " << a << " width is: " << b << "\n";
    }

    void area() {
        std::cout << "Area is: " << a * b << "\n";
    }
};

void func_1 () {
    shape square(4, 4);
    square.area();

    shape rectangle(10, 5);
    rectangle.area();
}

// ----------------------------------------------------------------------------

// With classes you are basically creating a new variable type.

class Player 
{
public:
    int x, y;
    int speed;   

    void move(int xa, int ya)
    {
        x = xa * speed;
        y = ya * speed;
    }
}; // <- you need a semicolon.

// You could make a function that change the player position:
void move(Player* player, int xa, int ya)
{
    player->x = xa * player->speed;
    player->y = ya * player->speed;
}

// Now, what if we move this function inside the class declaration?
// we could get rid of the reference thing and make it a class method!

int main(void)
{
    // Variables that are made from class types are called called objects and a 
    // new object variable is called an instance.
    
    // Here we instantiated a player object.
    Player player; 

    // If we want to set the player attributes, we could do the following:
    player.x = 10;

    // Altought if we try to access to "x" variable this way, we would get an
    // error, saying that 'x' is a private member of 'Player'.
    
    // This is for something called visibility, when you create a new class you
    // have the option to specify how visible the stuff in that class actually
    // is.
 
    // By default a class make everything private, which means only functions
    // inside that class can actually access that variables.
    
    // So you need to go inside the class definition and make it public, like
    // so:
    
    // class Player
    // {
    // public:
    //      int x, y;
    //      int speed;
    // }

    // public will allow us to access that variables outside of the class.

    func_1();
    return 0;
}
