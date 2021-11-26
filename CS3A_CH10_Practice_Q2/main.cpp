#include <iostream>

//Structure for a bank certificate of deposit:
class CDAccount {
private:
    int dollars_part;
    int cents_part;
    double interest_rate;
    int term; //months until maturity
    double fraction(double percent);
    double percent(double fraction) const;
public:
    double getBalance() const;
    double getInterestRate() const;
    int getTerm() const;

    void setBalance(int dollars_part, int cents_part);
    void setInterestRate(double interest_rate);
    void setTerm(int term);
};

void get_data(CDAccount& the_account);

int main() {
    CDAccount account{};
    get_data(account);

    double rate_fraction, interest, balance;
    rate_fraction = account.getInterestRate() / 100.0;
    interest = account.getBalance() * rate_fraction * (account.getTerm() / 12.0);
    balance = account.getBalance() + interest;

    std::cout.setf(std::ios::fixed);
    std::cout.setf(std::ios::showpoint);
    std::cout.precision(2);

    std::cout << "When your CD matures in "
              << account.getTerm() << " months,\n"
              << "it will have a balance of $"
              << balance << std::endl;

    return 0;
}

double CDAccount::getBalance() const {
    return (dollars_part + .01 * cents_part);
}

double CDAccount::getInterestRate() const {
    return (percent(interest_rate));
}

int CDAccount::getTerm() const {
    return term;
}

void CDAccount::setBalance(int dollars_part, int cents_part) {
    this->dollars_part = dollars_part;
    this->cents_part = cents_part;
}

void CDAccount::setInterestRate(double interest_rate) {
    this->interest_rate = fraction(interest_rate);
}

void CDAccount::setTerm(int term) {
    this->term = term;
}

double CDAccount::fraction(double percent) {
    return (percent / 100.0);
}

double CDAccount::percent(double fraction) const {
    return (fraction * 100);
}

void get_data(CDAccount& the_account) {
    double interest_rate, balance, temp;
    int term, dollars_part, cents_part;
    std::cout << "Enter account balance: $";
    std::cin >> balance;
    std::cout << "Enter account interest rate: ";
    std::cin >> interest_rate;
    std::cout << "Enter the number of months until maturity\n"
              << "(must be 12 or fewer months): ";
    std::cin >> term;

    dollars_part = balance;
    temp = (balance - dollars_part) * 100;
    cents_part = temp;

    the_account.setBalance(dollars_part, cents_part);
    the_account.setInterestRate(interest_rate);
    the_account.setTerm(term);
}