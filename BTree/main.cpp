#include <iostream>

#include "BTree.h"

using namespace std;

int main()
{
     int count = 5;
     cout << "Enter the number of elements : ";
     cin >> count;

    BTree root;
    for(int i = 0; i < count; i++){
         int element;
         cout << "Enter the key " << i +1 << " : ";
         cin >> element;
         root.insertElement(element);
//         root.insertElement(i + 1);
    }

    cout << "Constructed B tree:" << endl << endl;
    root.print();

    int key = 0;
    do {
        cout << "Enter key to delete: ";
        cin >> key;

        root.remove(key);

        cout << "B-Tree after deleting" << key << endl;
        root.print();

    } while (key !=-1);




    return 0;
}
