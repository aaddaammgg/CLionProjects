#include <iostream>

std::string lookupName(std::string targetName, std::string names[], std::string phoneNumbers[], int size);

int main() {
    using namespace std;
    string names[] = {"Michael Myers",
                      "Ash Williams",
                      "Jack Torrance",
                      "Freddy Krueger"};
    string phoneNumbers[] = {"333-8000", "333-2323",
                             "333-6150", "339-7970"};
    string targetName, targetPhone;

    char repeat;
    do {
        cout << "Enter a name to find the "
             << "corresponding phone number."
             << endl;

        getline(cin, targetName);
        targetPhone = lookupName(targetName, names, phoneNumbers, 4);
        if (targetPhone.length() > 0)
            cout << "The number is: "
                 << targetPhone << endl;
        else
            cout << "Name not found. "
                 << endl;
        cout << "Look up another name? (y/n)"
             << endl;
        cin >> repeat;
        cin.ignore();

    } while (repeat == 'y' || repeat == 'Y');
    return 0;
}

std::string lookupName(std::string targetName, std::string names[], std::string phoneNumbers[], int size) {
    int id = -1;
    for (int i = 0; i < size; i++) {
        if (names[i] == targetName) {
            id = i;
        }
    }

    if (id == -1) {
        return "000-0000";
    }

    return phoneNumbers[id];
}