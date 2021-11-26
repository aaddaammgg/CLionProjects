#include <iostream>

class CounterType {
private:
    int count = 0, counter = 0;
public:
    CounterType() {};
    CounterType(int input) { count = input; };

    void increaseCounter() { counter++; };
    void decreaseCounter() {
        counter--;
        if (counter <= 0) {
            counter = 0;
        }
    };

    void output(std::ostream& out) {
        std::cout << "Count: " << getCount() << std::endl
                  << "Counter: " << getCounter() << std::endl;
    };

    int getCount() { return count; };
    int getCounter() { return counter; };
};

int main() {
    int count;
    std::cout << "Enter a count: " << std::endl;
    std::cin >> count;
    CounterType counter(count);
    counter.output(std::cout);
    counter.increaseCounter();
    counter.output(std::cout);
    counter.decreaseCounter();
    counter.output(std::cout);
    return 0;
}
