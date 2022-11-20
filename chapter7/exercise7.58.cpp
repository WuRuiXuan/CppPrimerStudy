#include <iostream>
#include <vector>

using namespace std;

class Example {
    public:
        // static double rate = 6.5;
        static double rate;
        static const int vecSize = 20;
        // static vector<double> vec(vecSize);
        static vector<double> vec;
};

double Example::rate  = 6.5;
vector<double> Example::vec(vecSize);

int main()
{
    
}