#include <iostream>

class PostalCode {
private:
    int zipCode;
    std::string barCode;

    bool checkBarCode();
    bool checkTwoOnes();
    int calculateZipCode();
    std::string getFiveDigitValues();

public:
    PostalCode(int zipCode);
    PostalCode(std::string barCode);

    int getZipCode();
    std::string getBarCode();
};

int main() {
    PostalCode pc("110100101000101011000010011");
    std::cout << "The ZIP code is: " << pc.getZipCode();
    std::cout << std::endl;
    PostalCode pstl(99504);
    std::cout << "The Bar Code is: " << pc.getBarCode();
    std::cout << std::endl;
    return 0;
}

PostalCode::PostalCode(int zipCode) : zipCode(zipCode) {

}

PostalCode::PostalCode(std::string barCode) : barCode(barCode){

}

bool PostalCode::checkBarCode() {
    bool result = false;
    if ((barCode.length() == 27) && (((barCode[0]) - 48) == 1) && (((barCode[26]) - 48) == 1)) {
        result = true;
    }

    return result;
}

bool PostalCode::checkTwoOnes() {
    bool fiveCases[5], result = true;
    int arrCount = 0, numberOnes;

    for (int i = 1; i <= 25; i += 5) {
        numberOnes = 0;
        for(int j = i; j <= i + 4; j++) {
            if ((barCode[j] - 48) == 1) {
                numberOnes++;
            }
        }
        if (numberOnes == 2) {
            fiveCases[arrCount] = true;
        } else {
            fiveCases[arrCount] = false;
        }
        arrCount++;
    }

    for (int i = 0; i < 5; i++) {
        if (!fiveCases[i]) {
            result = false;
            break;
        }
    }
    return result;
}

int PostalCode::calculateZipCode() {
    int result = 0, sumArr[5], arrCounter = 0, sum, tempCounter;

    for (int i = 1; i <= 25; i += 5) {
        sum = 0;
        tempCounter = 1;

        for (int j = i; j <= i+4; j++) {
            if (tempCounter == 1) {
                sum += (barCode[j] - 48) * 7;
                tempCounter++;
            } else if (tempCounter == 2) {
                sum += (barCode[j] - 48) * 4;
                tempCounter++;
            } else if (tempCounter == 3) {
                sum += (barCode[j] - 48) * 2;
                tempCounter++;
            } else if (tempCounter == 4) {
                sum += (barCode[j] - 48) * 1;
                tempCounter++;
            } else if (tempCounter == 5) {
                sum += (barCode[j] - 48) * 0;
                tempCounter++;
            }

        }

        if (sum == 11) {
            sum = 0;
        }

        sumArr[arrCounter] = sum;
        arrCounter++;
    }

    int multiplier = 10000;

    for (int i = 0; i<5; i++) {
        result += sumArr[i] * multiplier;
        multiplier = multiplier / 10;
    }
    return result;
}

std::string PostalCode::getFiveDigitValues() {
    std::string result = "";
    int divisor = 10000, number = zipCode, currentDigit;

    for (int i = 0; i < 5; i++) {
        currentDigit = number / divisor;
        switch (currentDigit) {
            case 0:
                result += "11000";
                break;
            case 1:
                result += "00011";
                break;
            case 2:
                result += "00101";
                break;
            case 3:
                result += "00110";
                break;
            case 4:
                result += "01001";
                break;
            case 5:
                result += "01010";
                break;
            case 6:
                result += "01100";
                break;
            case 7:
                result += "10001";
                break;
            case 8:
                result += "10010";
                break;
            case 9:
                result += "10100";
                break;
            default:
                result += "00000";
        }

        number %= divisor;
        divisor /= 10;
    }
    return result;
}

int PostalCode::getZipCode() {
    zipCode = 0;

    if (checkBarCode() && checkTwoOnes()) {
        zipCode = calculateZipCode();
    }

    return zipCode;
}

std::string PostalCode::getBarCode() {
    barCode = "1" + getFiveDigitValues() + "1";
    return barCode;
}