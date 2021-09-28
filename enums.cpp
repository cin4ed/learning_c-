#include <iostream>

// Enums are used for enumerating items in a list. When comparing items, it is
// easier to compare names rather than just numbers.

// For example the days in a week. In a program we could assign Monday to 0,
// tuesday to 1, and Sunday to 7.

// To check wheter today is Friday, you will have to count to and arrive at 5.

// However, wouldn't it be easier to just chekc if Today == Friday?

// Enumerations are declared as follows:
enum Weekdays {
    Monday = 0,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
};

// If we don't use initializers, the first item's value is set to 0. Each
// following item that does not use an initializer will use the value of the
// preceding item plus 1 for its value.

int main() {
    Weekdays today;

    today = Friday;

    if (today == Friday) {
        std::cout << "The weekend is here!!!" << "\n";
    }

    return 0;
}
