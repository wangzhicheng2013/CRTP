#include <iostream>
template <typename concrete_printer>
class printer {
public:
    printer(std::ostream *os) : os_(os) {
    }
    template <typename T>
    concrete_printer& print(T&& t) {
        (*os_) << t;
        return static_cast<concrete_printer&>(*this);
    }
    template <typename T>
    concrete_printer& println(T&& t) {
        (*os_) << t << std::endl;
        return static_cast<concrete_printer&>(*this);
    }
private:
    std::ostream *os_;
};
class my_printer : public printer<my_printer> {
public:
    my_printer() : printer(&(std::cout)) {}
    my_printer& set_color(int color) {
        return *this;
    }
};
int main() {
    my_printer().print("Hello").set_color(0).println(" World!");

    return 0;
}