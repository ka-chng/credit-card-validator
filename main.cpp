#include <iostream>
#include <string>

bool validateCardNumber(const std::string& cardNumber) {
    int nDigits = cardNumber.length();

    int nSum = 0;
    bool isSecond = false;

    for (int i = nDigits - 1; i >= 0; i--) {
        int d = cardNumber[i] - '0';

        if (isSecond)
            d = d * 2;

        nSum += d / 10;
        nSum += d % 10;

        isSecond = !isSecond;
    }
    return (nSum % 10 == 0);
}

int main() {
    std::string cardNumber;
    std::cout << "Enter a credit card number: ";
    std::cin >> cardNumber;

    if (validateCardNumber(cardNumber))
        std::cout << "This is a valid card number";
    else
        std::cout << "This is not a valid card number";

    return 0;
}
