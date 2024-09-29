#include "mymath.h"

#include <iostream>

using namespace std;

int main()
{
    int x=5, y=7;
    MyMath objMyMath;
    int result=objMyMath.calcSum(x,y);
    cout << "Lukujen "<<x<<" ja "<<y<<" summa = " <<result<< endl;
    return 0;
}
