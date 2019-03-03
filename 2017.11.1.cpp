#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;





int main(int argc, char** argv) {
	int n;
	cin >> n;
	int x = n % 50;
	int y1 = n / 50;
	int y2 = x / 30;
	int y3 = x % 30 / 10;
	cout << y3 + y2 * 4 + y1 * 7 << endl;

	system("pause");
	return 0;
}