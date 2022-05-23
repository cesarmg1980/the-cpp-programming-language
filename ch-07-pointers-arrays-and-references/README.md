### Chapter 7 - Pointers, Arrays and References

- In C++ most objects have identity, meaning that they 'live' at a specific memory address.
- You can access and object if you know its memory address.

#### Pointers

- for a type T, T* is a 'pointer' to T (a variable that can hold the address of an object of type T).
- Fundamental operations on Pointers:
    - 'dereferencing' (refering to the object pointed to).
    - the dereferencing operator is the unary *

```
char c = 'a';
char *p = &c; // p holds the address of c, '&' is the address operator
char c2 = *p; // c2 == 'a' 
```

##### Void

- ``void*`` means 'pointer to object of unknown type'
- A pointer to any type of object can be assigned to a variable of type `void*`, but a pointer to function or pointer to member cannot
- **Important:** `void*` cannot be dereferenced
- Its' not safe to use a pointer that was cast to another type different than the original object pointed

##### `nullptr`

- Represents the null pointer, a pointer that does not point to an object

##### Arrays

```
float v[3]; // an array of three floats
char* a[32]; // an array of 32 pointers to char
```

- You can access an array using the subscription operator `[]` or through a pointers
- Access out of the range is disastrous
- The number of elements of an array must be a constant number if you need a variable size ise `vector`

```
void f(int n) {
    int v1[n]; // ERROR
    vector<int> v2(n); OK
}
```

```
void f() {
    int a2[20]; // 20 ints on the stack
    int* p = new int[40] // 40 int on the heap
}
```

- Avoid arrays in innterfaces (as function arguments)
- If you allocate an array on the free store, be sure to delete its pointer after use it (`delete[]`)
- If you allocate an array on thhe heap be sure to never `delete[]` it.

##### Array Initializers

```
int v1[] = {1, 2, 3, 4}; // list initializer
char v2[] = {'a', 'b', 'c'}
```

- There is no builtin copy operations for arrays

##### Strig Literals

- Is a sequence of characters enclosed in double quotes

- `==` when applied to pointers compares addresses not the pointer's value

##### Raw Character Strigs

##### Large Character Sets

##### Pointes into Arrays

- The name of the array can be used as a pointer to its initial element

```
int v[] = {1, 2, 3};
int* p1 = v; // pointer to initial element
int* p2 = &v[0]; // also pointer to initial element
int* p2 = v+1; // pointer to 2nd element
```

##### Navigating through an Array

- You can access an array through a pointer to the array plus an index or through a pointer to an element

```
void fi(char v[]) {
    for(int i = 0; v[i]!=0; ++i) // using the [] operator
        use(v[i]);
}

void fp(char v[]) {
    for(char* p = v; *p!=0; ++p) // using pointers
        use(*p);
}
```

##### Multidimensional Arrays

- Are arrays of arrays
- Represented `int ma[3][5]`
- Populated / Accessed using a double nestd `for`

##### Passing Arrays

- **Important:** Arrays cannot be passed directly by value, instead they're passed as a pointer to its first value.

##### Pointers and `const`

- `constexpr` Evaluated at compile time
- `const` means "do not modify in this scope"
- `const` **must be initialized**
- `const int* p;` this makes the object constant and **not** the pointer.
- `char *const p;` this makes the pointer constant and **not** the object.

##### Pointers and Ownership

##### References

- Like a pointer, a reference is an alias to an object
- The difference is:
    - You access a reference with the syntax as the name of the object
    - A reference always refers to the object to which it was initialized
    - There is no 'null reference'

```
template<typename T>
class vector {
    T* elem;
    ...
public:
    T& operator[](int i) {return elem[i];} // return a reference to element
    ...
}
```

##### Lvalue References

- `X&` means 'reference to X' often called lvalue reference

##### Rvalue Reference

- A non `const` lvalue reference refers to an object, to which the user of the reference can write.
- A `const` lvalue reference refers to a constant, it's immutable from the user's point of view.
- A rvalue reference refers to a temporary object, and the user of the reference can (and usually will) modify, assuming that the object will never be used again
- The `&&` means rvalue reference

