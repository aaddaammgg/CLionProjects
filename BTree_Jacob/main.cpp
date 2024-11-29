#include <iostream>

#include "BTree.h"

using namespace std;

int main()
{
    BTree root;

    // root.insertElement(1);
    // root.insertElement(2);
    // root.insertElement(4);
    // root.insertElement(5);
    // root.insertElement(3);

    // root.insertElement(1);
    // root.insertElement(2);
    // root.insertElement(3);
    // root.insertElement(4);
    // root.insertElement(5);
    // root.insertElement(6);
    // root.insertElement(7);
    // root.insertElement(8);
    // root.insertElement(9);
    // root.insertElement(10);

    // root.insertElement(10);
    // root.insertElement(22);
    // root.insertElement(7);
    // root.insertElement(5);
    // root.insertElement(13);
    // root.insertElement(17);
    // root.insertElement(2);
    // root.insertElement(15);

    // root.insertElement(47);
    // root.insertElement(25);
    // root.insertElement(66);
    // root.insertElement(93);
    // root.insertElement(55);
    // root.insertElement(56);
    // root.insertElement(57);
    // root.insertElement(58);
    // root.insertElement(59);
    // root.insertElement(60);
    // root.insertElement(67);
    // root.insertElement(68);
    // root.insertElement(69);
    // root.insertElement(70);
    // root.insertElement(71);
    // root.insertElement(48);
    // root.insertElement(49);
    // root.insertElement(50);
    // root.insertElement(51);
    // root.insertElement(30);

    root.insertElement(1);
    root.insertElement(2);
    root.insertElement(3);
    root.insertElement(4);
    root.insertElement(5);
    root.insertElement(6);
    root.insertElement(7);
    root.insertElement(8);
    root.insertElement(9);
    root.insertElement(10);
    root.insertElement(11);
    root.insertElement(12);
    root.insertElement(13);
    root.insertElement(14);
    root.insertElement(15);
    root.insertElement(16);
    root.insertElement(17);
    root.insertElement(18);


    cout << "Constructed B tree:" << endl << endl;
    root.print();

    int key = 0;
    do {
        cout << "Enter key to delete: ";
        cin >> key;

        root.removeElement(key);

        cout << "B-Tree after deleting" << key << endl;
        root.print();

    } while (key !=-1);




    return 0;
}
