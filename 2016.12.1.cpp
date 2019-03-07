//sort() 从小到大 通过函数变成从大到小
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool fun(int a, int b) {
	return a > b;
}
int main(int argc, char** argv) {
	int n;
	cin >> n;
	vector<int> numbers;
	while (n--) {
		int m;
		cin >> m;
		numbers.push_back(m);
	}

	sort(numbers.begin(), numbers.end());
	vector<int> numbers2 = numbers;
	sort(numbers2.begin(), numbers2.end(), fun);
	auto ite1 = numbers.begin();
	auto ite2 = numbers2.begin();
	while (ite1!=numbers.end()&&*ite1 != *ite2) {
		ite1++;
		ite2++;
	}
	if (ite1 == numbers.end()) {
		cout << -1 << endl;
		return 0;
	}
	ite1 = find(numbers.begin(), numbers.end(), *ite1);
	ite2 = find(numbers2.begin(), numbers2.end(), *ite2);
	if (ite1 - numbers.begin() == ite2 - numbers2.begin()) {
		cout<<*ite1 << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}