#include <iostream>
#include <algorithm>
#include <vector>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;
	vector<int> childs;
	int rest = n;
	int win = 1;

	for (int i = 0; i < n; i++) {
		childs.push_back(i+1);
	}
	
	int i=0;
	int no=0;
	while (rest != 1) {
		
		i++;
		//cout << "±¨Êý" << i << endl;
		no++;
		
		if (no > rest) {
			no = 1;
		}
		//cout << "no" << no << endl;

		if (i%k == 0 || i % 10 == k) {
			
			childs.erase(childs.begin() + no-1);

			rest--;
			no--;
		//	cout << "yes" << endl;
		}
	}
	win = childs[0];
	cout << win << endl;
	//system("pause");
	return 0;
}