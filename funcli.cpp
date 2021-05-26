#include <cstring>
#include <iostream>
#include <conio.h>
#include <vector>
#include <iomanip>

using namespace std;
void menuPrint();

vector<uint64_t> fib_generator(int n){
    vector<uint64_t> fib(n); 
    fib[0] = 1;
    fib[1] = 1;

    for(int i = 2; i < n; i++){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib;

}

void returnMenu(){
    char m;
    std::cout << "\nReturn to menu?(Y/N): ";
    std::cin >> m;
    switch(tolower(m)){
        case('y'):
            menuPrint();
            break;
        case('n'):
            break;
        default:
            std::cout << "Error: not an option";
             returnMenu();
    }
}


void compountInterest(double initialAmount, double contribution, double years, double interestRate){
    interestRate = interestRate / 100;
    const char separator    = ' ';
    const int nameWidth     = 15;
    const int numWidth      = 15;
    std::cout << "\n";
    std::string arr[4] = { "Year", "Balance", "Contribution", "Total"};
    cout << left << setw(nameWidth) << setfill(separator) << "Year";
    cout << left << setw(nameWidth) << setfill(separator) << "Balance";
    cout << left << setw(nameWidth) << setfill(separator) << "Contribution";
    cout << left << setw(nameWidth) << setfill(separator) << "Total";
    cout << "\n";

    for(int i = 1; i < years + 1; i++) {
        double total = ((initialAmount + contribution) * (1+interestRate));
        cout << left << setw(numWidth) << setfill(separator) << i;
        cout << left << setw(numWidth) << setfill(separator) << initialAmount;
        cout << left << setw(numWidth) << setfill(separator) << contribution;
        cout << left << setw(numWidth) << setfill(separator) << total;
        cout << endl;
        initialAmount = total;
    }

}

void interestPrint(){
    double amount;
    int contribution;
    int years;
    double interestRate;

    std::cout << "\nEnter initial amount: ";
    std::cin >> amount;
    cout << endl;
    std::cout << "Enter annual contribution: ";
    std::cin >> contribution;
    cout << endl;
    std::cout << "Enter number of years: ";
    std::cin >> years;
    cout << endl;
    std::cout << "Enter interest rate: ";
    std::cin >> interestRate;
    cout << endl;
    compountInterest(amount, contribution, years, interestRate);

    returnMenu();
}

int powerTo(int base, int exp){ 
    if(exp == 0){
        return 1;
    }
   
    return base * powerTo(base, exp-1); 

};


void powerPrint(){

    int base;
    int exp;

    std::cout << "Enter your base: ";
    std::cin >> base;
    std::cout << "\nEnter your exponent: ";
    std::cin >> exp;

    int result = powerTo(base, exp);
    std::cout << "\n" << result << "\n";
    returnMenu();

};

void fibPrint(){
    int n;
    std::cout << "Enter n for fibonnaci: ";
    std::cin >> n;
    
    vector<uint64_t> result = fib_generator(n);
    for(int i: result){
        std::cout << i << "\n";
    }
    returnMenu();
}
void menuPrint(){
    std::string menu = "Enter 'e' to exit.\n\n1) Exponents\n2) Fibonacci Generator\n3) Loan Schedule\n\n";
    std::cout << menu;
    
std::string m;
std::cin >> m;

if(m.length() != 1){
    std::cout << "\nInvalid option.  Enter 1, 2, or 3\n";
    menuPrint();
}
else {
switch(m[0]){
    case('1'):
        powerPrint();
        break;
    case('2'):
        fibPrint();
        break;
    case('3'):
        interestPrint();
        break;
    case('e'):
        break;
    default:
        std::cout << "\nInvalid option.  Enter 1, 2, or 3\n";
        menuPrint();
        break;
}

}
}


int main() {

menuPrint();
return 0;


}