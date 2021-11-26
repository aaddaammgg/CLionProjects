#include <iostream>

//Structure for a bank certificate of deposit:
class CDAccount {
private:
    double balance;
    double interest_rate;
    int term; //months until maturity
public:
    double getBalance() const;
    double getInterestRate() const;
    int getTerm() const;

    void setBalance(double balance);
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
    return balance;
}

double CDAccount::getInterestRate() const {
    return interest_rate;
}

int CDAccount::getTerm() const {
    return term;
}

void CDAccount::setBalance(double balance) {
    this->balance = balance;
}

void CDAccount::setInterestRate(double interest_rate) {
    this->interest_rate = interest_rate;
}

void CDAccount::setTerm(int term) {
    this->term = term;
}

void get_data(CDAccount& the_account) {
    double balance, interest_rate;
    int term;
    std::cout << "Enter account balance: $";
    std::cin >> balance;
    std::cout << "Enter account interest rate: ";
    std::cin >> interest_rate;
    std::cout << "Enter the number of months until maturity\n"
              << "(must be 12 or fewer months): ";
    std::cin >> term;

    the_account.setBalance(balance);
    the_account.setInterestRate(interest_rate);
    the_account.setTerm(term);
}