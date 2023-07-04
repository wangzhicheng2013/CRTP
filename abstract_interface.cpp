#include <iostream>
template <class T>
class base {
public:
    bool interface() {
        return (static_cast<T *>(this))->implement();
    }
};
class derive1 : public base<derive1> {
public:
    bool implement() {
        std::cout << "implement derive1" << std::endl;
    } 
};
class derive2 : public base<derive2> {
public:
    bool implement() {
        std::cout << "implement derive2" << std::endl;
    } 
};
int main() {
    base<derive1>base1;
    base<derive2>base2;
    base1.interface();
    base2.interface();

    return 0;
}