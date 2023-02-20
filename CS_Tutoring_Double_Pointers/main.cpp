#include <iostream>
#include <fstream>
#include <string>

int readFromFile(char *fileName, int **id, std::string **name, int **grade);
void printData(int *id, std::string *name, int *grade, int count);

int main()
{
    int *id = nullptr;
    std::string *name = nullptr;
    int *grade = nullptr;
    char fileName[] = "data.txt";

    int count = readFromFile(fileName, &id, &name, &grade);

    std::cout << "The count is: " << count << std::endl << std::endl;

    printData(id, name, grade, count);

    // We should be freeing the memory of (fileName, id, name, grade)
    // But since we are at the end of the program it is not really needed.
    return 0;
}

void printData(int *id, std::string *name, int *grade, int count)
{
    for (int i = 0; i < count; ++i)
    {
        std::cout << id[i] << "\t\t" << name[i] << "\t\t" << grade[i] << std::endl;
    }
}

int readFromFile(char *fileName, int **id, std::string **name, int **grade)
{
    int count = 0;

    std::ifstream file;
    file.open(fileName);

    int _id, _grade;
    std::string _name;

    while (!file.eof())
    {
        file >> _id >> _name >> _grade;
        count++;
    }

    file.close();


    // Dereference then allocate memory
    *id = new int[count];
    *name = new std::string[count];
    *grade = new int[count];

    file.open(fileName);

    for (int i = 0; i < count; ++i)
    {
        file >> _id >> _name >> _grade;

        // The first way seems to look the best and probably makes more sense

        (*id)[i] = _id; // OR: *(*id + i)
        *(*name + i) = _name;
        *(*grade + i) = _grade;
    }

    file.close();

    // This was to check the data afterwards

    // for (int i = 0; i < count; ++i) {
    //   std::cout << *(*id + i) << "\t\t" << *(*name + i) << "\t\t" << *(*grade + i) << std::endl;
    // }

    return count;
}