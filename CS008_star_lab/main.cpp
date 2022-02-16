#include <iostream>

/*

*
**
 *
****
  *
  **
   *
********
    *
    **
     *
    ****
      *
      **
       *

 */


void star(int n, int space);

int main() {
    star(8, 0);
    return 0;
}

void star(int n, int space) {
    if (n == 1) {
        std::cout << '*' << std::endl;
    } else {
        star(n / 2, space);

        std::cout << std::string(space, ' ');
        std::cout << std::string(n, '*') << std::endl;
        std::cout << std::string(n/2 + space, ' ');

        star(n / 2, n / 2 + space);
    }
}