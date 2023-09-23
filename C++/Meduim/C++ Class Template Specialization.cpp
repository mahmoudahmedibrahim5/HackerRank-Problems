#include <iostream>
using namespace std;
enum class Fruit { apple, orange, pear };
enum class Color { red, green, orange };

template <typename T> struct Traits;

template <> struct Traits <Fruit> {
    static string name(int index) 
    {
        string result;
        switch (index)
        {
        case 0:
            result = "apple";
            break;
        case 1:
            result = "orange";
            break;
        case 2:
            result = "pear";
            break;
        default:
            result = "unknown";
            break;
        }
        return result;
    }
};

template <> struct Traits <Color> {
    static string name(int index) 
    {
        string result;
        switch (index)
        {
        case 0:
            result = "red";
            break;
        case 1:
            result = "green";
            break;
        case 2:
            result = "orange";
            break;
        default:
            result = "unknown";
            break;
        }
        return result;
    }
};


int main()
{
	int t = 0; std::cin >> t;

    for (int i=0; i!=t; ++i) {
        int index1; std::cin >> index1;
        int index2; std::cin >> index2;
        cout << Traits<Color>::name(index1) << " ";
        cout << Traits<Fruit>::name(index2) << "\n";
    }
}
