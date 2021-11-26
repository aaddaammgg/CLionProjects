#include <iostream>
#include <cstring>

bool isPalindrome(char* cstr);

int main() {
    char s1[50] = "neveroddoreven";
    char s2[50] = "not a palindrome";
    std::cout << isPalindrome(s1) << std::endl;
    std::cout << isPalindrome(s2) << std::endl;
    return 0;
}

bool isPalindrome(char* cstr) {
    char* front = cstr;
    char* back = cstr + std::strlen(cstr) - 1;

    while (front < back) {
        if (*front != *back) {
            return false;
        }
        front++;
        back--;
    }
    return true;
}