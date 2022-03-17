#include <iostream>

int isPrime(int num);

int main() {
    for(int num = 3; num <= 100; num++) {
        if (isPrime(num)) {
            std::cout << num << " ";
        }
    }

    std::cout << "\n";

    return 0;
}

int isPrime(int num) {
   for (int i = 2; i <= num / 2; i++) {
       if (num % i == 0) {
           return false;
       }
   }

   return true;
}