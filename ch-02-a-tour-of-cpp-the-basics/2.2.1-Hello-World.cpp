#include <iostream>
using namespace std;

double square(double);
void print_square(double);

int main() {
    std::cout << "Hello World\n";
    print_square(5);
}

double square(double x) {
    return x * x;
}

void print_square(double x) {
    std::cout << "The square of " << x << " is " << square(x) << "\n";
}
