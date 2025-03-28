**Ques1**: Difference between stactically allocated and dynamically allocated object.  
```cpp
Cricketer c1("Virat Kohli", 36, 25000, 57);
Cricketer* c2 = new Cricketer("Rohit Sharma", 42, 15000, 48);
```
Ans:  

- Statically allocated objects are created on the stack and automatically deallocated when they go out of scope.
- Dynamically allocated objects are created on the heap using `new` and must be manually deallocated using `delete`.
- The static has a fixed lifetime, while the dynamic can persist beyond the scope in which they were created until explicitly deleted.
- Stack memory is limited and faster to access, while heap memory is larger but slower to access.
- for comparsion size of static memory is around `8MB` and heap memory is around `2GB`.

**Justification:**  
```cpp
class Person {
    public:
        string name;
        Person() {}
        Person(string name) {
            this->name = name;
        }
        ~Person() {
            cout<<this->name<<" is deleted!";
        }
};
void justify () {
    Person c1("Virat Kohli");
    Person* c2 = new Person("Rohit Sharma");
}

int main() {   
    justify();
    // c1 is automatically deleted when it goes out of scope
    // c2 must be manually deleted
    return 0;
}
```

```text
Virat Kohli is deleted!
```
