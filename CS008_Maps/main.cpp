#include <iostream>
#include <map>
#include <unordered_map>

template <class T, class S>
struct pair {
    T first;
    S second;
};

int main() {
    std::unordered_map<std::string, bool> m;

    m["screen_on"] = false;
    m["wireless_keyboard"] = false;
    m["desktop"] = true;
    m["power_on"] = false;

//    std::cout << m["power_on"] << std::endl;

    for (const auto& p : m) {
        std::cout << p.first << " " << p.second << std::endl;
    }

    m.insert(std::pair<std::string, bool>("hello", false));

    return 0;
}
