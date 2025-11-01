#include <iostream>
using namespace std;

// Base class
class Library
{
public:
    void showLibraryInfo()
    {
        cout << "Welcome to the Central Library!" << endl;
    }
};

// BookSection inherits Library virtually
class BookSection : virtual public Library
{
    // Virtual inheritance ensures only one Library in derived classes
};

// MagazineSection inherits Library virtually
class MagazineSection : virtual public Library
{
    // Virtual inheritance ensures only one Library in derived classes
};

// DigitalLibrary inherits from both BookSection and MagazineSection
class DigitalLibrary : public BookSection, public MagazineSection
{
    // No ambiguity now, only one copy of Library exists
};

int main()
{
    DigitalLibrary dl;

    dl.showLibraryInfo(); // Works fine: no ambiguity
    return 0;
}

