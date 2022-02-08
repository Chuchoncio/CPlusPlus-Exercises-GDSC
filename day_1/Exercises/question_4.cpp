#include <iostream>

using namespace std;

int main() {

    float money_borrow, annual_rate, time_length,
          interest, amount, total_paid;

    money_borrow = 100;
    annual_rate = 0.05;
    time_length = 2;

    interest = money_borrow * annual_rate * time_length;
    total_paid = money_borrow + interest;

    cout << "You need to pay a total of $" << total_paid << endl;

    return 0;
}