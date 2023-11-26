## A Tour of C++: The Basics

### 2.2.1. Hello World

*See* `2.2.1-Hello-World.cpp`

### 2.2.2 Types, Variables, and Arithmetic

Every name and every expression has a type that determines the set of operations that can be performed on it.
A *declaration* is a statement that introduces a name into the program. It specifies a type for the named entry:

* A *type* defines a set of possible values and a set of operations (for an object).
* An *object* is some memory that holds a *value* of some *type*.
* A *value* is a set of bits interpreted according to its type.
* A *variable* is a named object.

A constant cannot be left uninitialized.
A variable should only be left uninitialized in **extremely rare** circumstances.

Sometimes you can leave the type out if it can be deduced from the initializer:

```
auto b = true; // a bool
auto ch = 'x'; // a char
auto i = 123; // an int
auto d = 1.2; // a double
auto z = sqrt(u); // z's type will be whatever sqrt returns
```

### 2.2.3 Constants

C++ supports 2 notions of immutability:

* `const` meaning "i promise not to change this value", used primarily in interfaces, the data passed to it won't be mofified, this is enforced by the compiler.
* `constexpr` "To be evaluated at compile time", used to specify constants, the data will be placed in read-only memory.

```
const int dmv = 17; // dmv is a named constant
int var = 17; // var is not a constant
constexpr double max1 = 1.4*square(dmv);  // OK if square(17) is a constant expression
constexpr double max2 = 1.4*square(var);  // error, var is not a constant expression
const double max3 = 1.4*square(var);  // OK, may be evaluated at run time
double sum(const vector<double>&);  // sum will not modif its argument
vector<double> v {1.2, 3.4, 4.5}  // OK, evaluated at runtime
constexpr double s2 = sum(v)  // error, sum(v) not a constant expression
```

For a function to be used in a *constant* expression, it must be defined as `constexpr`

`constexpr double square(double x) { return x*x; }`

### 2.2.4 Tests and Loops

*See* `2.2.4-Tests-and-Loops.cpp`

In a `switch` statement a value is tested agains a set of constants, the constants **must** be distinct and if any of the values match the constants the `default` branch is chosen, if no `default` is provided no action is taken.

