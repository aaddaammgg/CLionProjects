#include <iostream>
using namespace std;

void stars(int length, bool space) {
    if (space) {
        cout << " ";
    }

    // lil bit of boolean to integer conversion :)
    for (int i = space; i<length + space; i++) {
        if (i%2==0) {
            cout << "_";
        } else {
            cout << "*";
        }
    }

    cout << endl;
}

int main() {
    stars(9,false);
    stars(7,true);
    stars(9,false);

    return 0;
}