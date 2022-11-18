#include <iostream>

char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
char **cp[] = {c + 3, c + 2, c + 1, c};
char ***cpp = cp;

int main(void) {
    std::cout << **++cpp;
    std::cout << *--*++cpp + 3;
    std::cout << " "  << *cpp[-2] + 3;
    std::cout << cpp[-1][-1] + 1;
    return 0;
}
