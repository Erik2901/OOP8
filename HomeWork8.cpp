#include <iostream>

///// exercise 1

template<typename T>
T div(T a, T b) {
    if (b == 0)
    {
        throw "Division by Zero";
    }

    return a/b;
}

/////////

////// exercise 2

class Ex {
    int x;
public:
    Ex(int _x) : x(_x) {}
};

class Bar {
    int y;
public:
    Bar(int _y = 0) : y(_y) {}
    void set(int a) {
        if (y+a>100)
        {
            throw Ex(a*y);
        }
        else
        {
            y = a;
        }
    }

    int gety() const { return y; }
};

////////////

///////// exercise 3

class OffTheField {
    int a;
public:
    OffTheField(int _a) : a(_a) {}

    int geta() { return a; }
};

class IllegalCommand {
    int a;
public:
    IllegalCommand(int _a) : a(_a) {}

    int geta() { return a; }
};

class Robot {
    int x = 0;
    int y = 0;
public:
    Robot(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    void xx() 
    { 
        if ( x < 10)
        {
            x++;
        }
        else {
            throw OffTheField(x);
        }
    }
    void yy() 
    { 
        if (y < 10)
        {
            y++;
        }
        else {
            throw OffTheField(y);
        }
    }
    void setposx(int _x) {
        if (_x > 10)
        {
            throw IllegalCommand(_x);
        }
        else
        {
            x = _x;
        }
    }
    void setposy(int _y) {
        if (_y > 10)
        {
            throw IllegalCommand(_y);
        }
        else
        {
            y = _y;
        }
    }
    int getx() const { return x; }
    int gety() const { return y; }
};

/////////
int main()
{
    ////// exercise 1

    try
    {
        std::cout << div<int>(10, 0);
    }
    catch (const char* exeption)
    {
        std::cout << exeption << std::endl;;
    }

    ////////

    /////////exercise 2

    Bar b(5);
    int n = 1;
    while (n!=0)
    {
        try
        {
            std::cin >> n;
            b.set(n);
        }
        catch (Ex(n))
        {
            std::cout << "Error." << b.gety() << " wrong number." << std::endl;
        }
        
    }
    
    //////////

    /////// exercise 3

    Robot r1;

    for (size_t i = 0; i < 12; i++)
    {
        try
        {
            r1.yy();
            r1.xx();
            r1.setposy(i);
            r1.setposx(i);

        }
        catch (OffTheField(i))
        {
            std::cout << "X: " << r1.getx() << std::endl << "Y: " << r1.gety() << std::endl << "Error. Trying to get out " << OffTheField(i).geta() - 10 << " more position(s)" << std::endl;

        }
        catch (IllegalCommand(i))
        {
            std::cout << "X: " << r1.getx() << std::endl << "Y: " << r1.gety() << std::endl << "Error. Trying to get out " << IllegalCommand(i).geta() - 10 << " more position(s)" << std::endl;
        }
    }

    ///////

    system("pause");
    return 0;
}

