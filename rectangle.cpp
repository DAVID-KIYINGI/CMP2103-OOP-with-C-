#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double length;

public:
    // Constructors
    Rectangle() : width(0.0), length(0.0) {}
    Rectangle(double w, double l) : width(w), length(l) {}

    // Getters
    double getWidth() const { return width; }
    double getLength() const { return length; }

    // Setters (reject negative values)
    void setWidth(double w) {
        if (w >= 0) width = w;
        else cout << "Invalid width: must be non-negative.\n";
    }

    void setLength(double l) {
        if (l >= 0) length = l;
        else cout << "Invalid length: must be non-negative.\n";
    }

    // Calculations
    double area() const { return width * length; }
    double perimeter() const { return 2 * (width + length); }
};

int main() {
    // 1. Default constructor, then set dimensions
    Rectangle r1;
    r1.setWidth(4.0);
    r1.setLength(6.5);
    cout << "Rectangle 1\n";
    cout << "Width:     " << r1.getWidth() << "\n";
    cout << "Length:    " << r1.getLength() << "\n";
    cout << "Area:      " << r1.area() << "\n";
    cout << "Perimeter: " << r1.perimeter() << "\n\n";

    // 2. Parameterized constructor
    Rectangle r2(3.0, 3.0);
    cout << "Rectangle 2 (square)\n";
    cout << "Width:     " << r2.getWidth() << "\n";
    cout << "Length:    " << r2.getLength() << "\n";
    cout << "Area:      " << r2.area() << "\n";
    cout << "Perimeter: " << r2.perimeter() << "\n\n";

    // 3. Modify an existing object
    r2.setWidth(5.0);
    r2.setLength(10.0);
    cout << "Rectangle 2 after update\n";
    cout << "Width:     " << r2.getWidth() << "\n";
    cout << "Length:    " << r2.getLength() << "\n";
    cout << "Area:      " << r2.area() << "\n";
    cout << "Perimeter: " << r2.perimeter() << "\n\n";

    // 4. Invalid input is rejected, old value is kept
    cout << "Rectangle 1 invalid update\n";
    r1.setWidth(-2.0);
    cout << "Width is still: " << r1.getWidth() << "\n";

    return 0;
}
