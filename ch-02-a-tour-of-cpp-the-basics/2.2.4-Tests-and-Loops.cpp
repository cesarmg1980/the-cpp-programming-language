#include <iostream>
using namespace std;

bool accept();
bool accept2();
bool accept3();

int main() {
    accept();
    accept2();
    accept3();
    return 0;
}

bool accept() {
    std::cout << "Do you want to proceed (y or n)?\n";
    char answer = 0;
    std::cin >> answer;

    if (answer == 'y')
        return true;
    return false;
}

bool accept2() {
    std::cout << "Do you want to proceed (y or n)? \n";
    char answer;
    std::cin >> answer;

    switch (answer) {
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        std::cout << "I'll take that as a no.\n";
        return false;
    }
}

bool accept3() {
    int tries = 1;
    while(tries < 4) {
        std::cout << "Do you want to proceed (y or n)?\n";
        char answer = 0;
        cin >> answer;

        switch(answer) {
        case 'y':
            return true;
        case 'n':
            return false;
        default:
            std::cout << "Sorry, i don't understand that.\n";
            tries++;
        }
    }
    std::cout << "I'll take that as a no.\n";
    return false;
}
