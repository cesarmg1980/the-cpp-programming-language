#include <cstdlib>
#include <iostream>
using namespace std;

void copy_one_array_into_another();
void print_array();
void increment_array_element();
void count_x(char *, char);

int main() {
    copy_one_array_into_another();
    print_array();
    increment_array_element();

    char x[] = {'a', 'b', 'a', 'c', 'd', 'c', 'a', 'c', 'c'};
    // we count the occurrences of 'a'
    count_x(x, 'a');
    // we count the occurrences of 'c'
    count_x(x, 'c');
    return 0;
}

void copy_one_array_into_another() {
    int v1[10] = {0,1,2,3,4,5,6,7,8,9};
    int v2[10];                             // to become a copy of v1

    std::cout << "The content of v1 is: ";
    for(auto i=0; i<10; i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << "\n";

    for(auto i=0; i<10; i++) {
        v2[i] = v1[i];
    }

    std::cout << "The content of v2 is: ";
    for(auto i=0; i<10; i++) {
        std::cout << v2[i] << " ";
    }
    std::cout << "\n";
}

void print_array() {
    int v[] = {100,200,300,400,500};
    std::cout << "Printing a predefined v array" << '\n';
    for (auto x: v)
        std::cout << x << " ";
    std::cout << '\n';
    std::cout << "Printing an array defined in the for loop" << '\n';
    for (auto x: {1000,2000,3000,4000,5000})
        std::cout << x << " ";
    std::cout << '\n';
}

void increment_array_element() {
    int v[] = {100,200,300,400,500};
    std::cout << "v status before increment: ";
    for(auto& x: v)
        std::cout << x << " ";
    std::cout << '\n';

    std::cout << "incrementing v..." << '\n';
    for(auto& x: v)
        ++x;

    std::cout << "v status after increment: ";
    for(auto& x: v)
        std::cout << x << " ";
    std::cout << '\n';
}

void count_x(char* p, char x) {
    // counts the number of occurrences of x in p[]
    // p is assumed to point to a zero-terminated array of char (or nothing)
    int count = 0;
    if(p==nullptr) {
        std::cout << "p is not pointing to anything" << '\n';
        exit(1);
    }
    for(; *p!=0; p++)
        if(*p == x)
            count++;
    std::cout << "occurrences of " << x << ": " << count << '\n';
}
