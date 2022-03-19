//
// Created by Adam G. on 3/18/22.
//

#include "Letter.h"

Letter::Letter() : Letter("-") {

}

Letter::Letter(const std::string& str) {
    setString(str);
    setFont(ResourceHolder::getFont("Roboto-Regular.ttf"));
}
