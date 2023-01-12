#include<iostream>
using namespace std;

auto main() -> int {

	int b = 20;
    int d = 40;
    int c = 30;
    int a = 10;

    cout << (a + b == c) << "\n";                       // 10 + 20 == 30    1
	cout << (a + b + c >= 2 * d) << "\n";               // 60 >= 80         0

	cout << (a > 5 || d < 30) << "\n";                  // 1
	cout << (a > 5 && d < 30) << "\n";                  // 0
	cout << (a <= b && b <= c) << "\n";                 // T && T = 1

	cout << ((a > 5 && d < 30) || (c - b == 10)) << "\n";   // 30-20 == 10  1
	cout << (a <= b && b <= c && c <= d) << "\n";       // T && T && T = 1

	cout << ((a > 5 && d < 30) || (c > d || d % 2 == 0)) << "\n";       // 1
	cout << ((a > 5 && d < 30) || (c > d && d % 2 == 0)) << "\n";       // 0

	cout << (a == 10 || (b != 20  && c != 30) || d != 40) << "\n";   // 1
	cout << (((a == 10 || b != 20) && c != 30) || d != 40) << "\n";   // 0
}