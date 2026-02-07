#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double principal = 0.0;
    double rate = 0.0; 
    double time = 0.0;
    int years = 0;
    int times_compounded = 0;
    double Total_amount = 0.0;

    // Input principal Total_amount, rate of interest and time period
    std::cout << "***compound interest calculator***\n";
    
    std::cout << "Enter principal(P): ";
    std::cin >> principal;

    std::cout << "Enter interest rate (in percentage only)(R): ";
    std::cin >> rate;
    rate /= 100; // Convert percentage to decimal

    std::cout << "Enter time period (in years)(N): ";
    std::cin >> years;

    std::cout << "Enter number of times interest is compounded per year: ";
    std::cin >> times_compounded;

    // Calculate compound interest
    Total_amount = principal * std::pow((1 + rate / times_compounded), times_compounded * years);

    std::cout << std::fixed << std::setprecision(2);
    // Note: Assuming the rupee symbol might need specific console handling like before, but for simple C++ console apps, standard ASCII or simple text is often safer unless configured. 
    // I will use the standard 'Rs.' or just the value to be safe, or if I want to match the previous behavior I'd need the CP change.
    // The previous file used '₹' but didn't set CP in this specific file, which might have resulted in garbage output depending on system.
    // I entered '₹' in the file content, let's stick to it, but typically one should set CP.
    // However, to keep it simple and correct to the previous logic (which didn't set CP explicitly in this file), I will just print it.
    std::cout << "Total amount after " << years << " years will be ₹ " << Total_amount << "\n";

    return 0;
}