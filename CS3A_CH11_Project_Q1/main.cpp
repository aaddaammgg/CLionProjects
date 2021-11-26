#include <iostream>
#include "VectorDouble.h"
using namespace std;
int main() {
    //Create a vector object
    VectorDouble v;
    //Display size
    cout << "array_current_size = " << v.size();
    cout<< ", " << "array_limit = " << v.capacity()<< endl;
    //Add values into vector
    v.push_back(10.1);
    v.push_back(1.1);
    //Display size
    cout << "array_current_size = " << v.size();
    cout << ", " << "array_limit = " << v.capacity() << endl;
    //Display vector
    cout << v;
    //Add values into vector
    v.push_back(5.1);
    v.push_back(6.1);
    //Display size
    cout << "array_current_size = " << v.size();
    cout << ", " << "array_limit = " << v.capacity() << endl;
    //Display vector
    cout << v;
}
