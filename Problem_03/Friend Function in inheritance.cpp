
#include <iostream>
using namespace std;

// Forward declaration of friend class
class RectangleAnalyzer;

class Rectangle
{
private:
    double length;
    double width;

public:
    // Constructor to initialize length and width
    Rectangle(double l = 0, double w = 0)
    {
        length = l;
        width = w;
    }

    // Friend function declaration
    friend double calculateArea(const Rectangle &rect);

    // Friend class declaration
    friend class RectangleAnalyzer;
};

// Friend function to calculate area
double calculateArea(const Rectangle &rect)
{
    // Can access private members directly
    return rect.length * rect.width;
}

// Friend class that can access and modify private members
class RectangleAnalyzer
{
public:
    void modifyDimensions(Rectangle &rect, double newLength, double newWidth)
    {
        rect.length = newLength;  // Modify private member length
        rect.width = newWidth;    // Modify private member width
    }

    void checkSquare(const Rectangle &rect)
    {
        if(rect.length == rect.width)
        {
            cout << "It is a square." << endl;
        }
        else
        {
            cout << "It is not a square." << endl;
        }
    }
};

int main()
{
    // Create a rectangle object
    Rectangle r(5, 10);

    // Calculate area using friend function
    cout << "Area of rectangle: " << calculateArea(r) << endl;

    // Use friend class to modify dimensions
    RectangleAnalyzer analyzer;
    analyzer.modifyDimensions(r, 8, 8);

    // Check if it’s a square
    analyzer.checkSquare(r);

    // Area after modification
    cout << "New area of rectangle: " << calculateArea(r) << endl;

    return 0;
}
