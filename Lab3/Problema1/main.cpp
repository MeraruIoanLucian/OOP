#include "Math.cpp"
using namespace std;

int main()
{
    Math math;
    cout << math.Add(1, 2) << endl;
    cout << math.Add(1, 2, 3) << endl;
    cout << math.Add(1.1, 2.2) << endl;
    cout << math.Add(1.1, 2.2, 3.3) << endl;
    cout << math.Mul(2, 3) << endl;
    cout << math.Mul(2, 3, 4) << endl;
    cout << math.Mul(2.2, 3.3) << endl;
    cout << math.Mul(2.2, 3.3, 4.4) << endl;
    cout << math.Add(5, 7,6) << endl;
    cout << math.Add("Merge", "Bine") << endl;
    return 0;
}
