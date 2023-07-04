#include <iostream>
template <typename T>
struct counter {
    static int created;
    static int alived;

    counter() {
        created++;
        alived++;
    }
    counter(counter &) {
        created++;
        alived++;
    }
protected:
    virtual ~counter() {
        --alived;
    }
};
template <typename T>
int counter<T>::created = 0;

template <typename T>
int counter<T>::alived = 0;

class plane : counter<plane> {
};
class rocket : counter<rocket> {
};
int main() {
    plane plane1, plane2, *plane3 = new plane;
    plane plane4 = plane2;
    rocket rocket1, rocket2;
    std::cout << counter<plane>::created << std::endl;   // 4
    delete plane3;
    std::cout << counter<plane>::alived << std::endl;    // 3

    std::cout << counter<rocket>::created << std::endl;  // 2
    std::cout << counter<rocket>::alived << std::endl;   // 2

    return 0;
}