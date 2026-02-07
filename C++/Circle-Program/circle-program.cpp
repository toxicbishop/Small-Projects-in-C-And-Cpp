#include <iostream>
#include <cmath>
#include <iomanip>

int main() {
    double radius = 0.0;
    double area = 0.0;
    double surfaceArea = 0.0;
    double volume = 0.0;
    const double PI = 3.14159;

    std::cout << "Enter the radius of the circle: ";
    std::cin >> radius;

    area = PI * std::pow(radius, 2); // Area = πr²
    surfaceArea = 4 * PI * std::pow(radius, 2); // Surface Area = 4πr²
    volume = (4.0/3.0) * PI * std::pow(radius, 3); // Volume = (4/3)πr³

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << area << "\n";
    std::cout << "Surface Area: " << surfaceArea << "\n";
    std::cout << "Volume: " << volume << "\n";

    return 0;
}