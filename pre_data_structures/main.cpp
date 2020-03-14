#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
<<<<<<< HEAD:data_structures/main.cpp
=======

void up_and_down(int n) {
    printf("Level %d: n location %p\n", n, &n);
    if (n < 400) {
        up_and_down(n + 1);
    }
    printf("LEVEL %d: n location %p\n", n, &n);
}
>>>>>>> e771af29f34c6e938bd1507c125c129381d14763:pre_data_structures/main.cpp
