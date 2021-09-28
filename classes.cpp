#include <iostream>

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

    // public we'll allow us to access that variables outside of the class.
    return 0;
}
