#include <iostream>

double pow(double num, double exponent);
int main()
{
    double num = 2;
    double exponent = 3;
    std::cout << pow(num, exponent) << std::endl;
    std::cout << num << std::endl;
    std::cout << exponent << std::endl;
    return 0;
}

double pow(double num, double exponent)
{
    int temp = num;
    for(int i=1; i<exponent; i++)
    {
        std::cout << i << "\n";
        num *= temp;
    }
    return num;
}
