#include<iostream>
using namespace std;

int main() {
	int num1, num2, num3, temp = -1;

	// Circulate them instead of direct 2 swaps
	cin>>num1>>num2>>num3;
	temp = num1;
	num1 = num2;
	num2 = num3;
	num3 = temp;

	cout<<num1<<" "<<num2<<" "<<num3<<"\n";


	return 0;
}
