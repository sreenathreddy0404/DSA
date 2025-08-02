#include <iostream>
using namespace std;

// * * * * *
// * * * * *
// * * * * *
// * * * * *
// * * * * *
void pattern1(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

void pattern2(int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}
int main()
{
    int N = 5;
    pattern1(N);
    pattern2(N);
    // pattern3(N);
    // pattern4(N);
    // pattern5(N);
    // pattern6(N);
    // pattern7(N);
    // pattern8(N);
    // pattern9(N);
    // pattern10(N);
    return 0;
}