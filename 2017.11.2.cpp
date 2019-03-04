//vector find
//queue
//vec.erase(vec.begin() + 1, vec.begin() + 3);
//vec.erase(vec.begin() + 1);
//int index = &*it - &temp[0]

#include <iostream>
#include<vector>
#include <queue>;
#include <algorithm>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Trans {
	int time;
	int type;//1Îª½è£¬2Îª»¹
	int key;
	bool operator < (const Trans &a) const
	{
		if (time == a.time) {
			if (type == a.type) {
				return key > a.key;
			}
			else {
				return type < a.type;
			}
		}
		else {
			return time > a.time;
		}
	}
};




int main(int argc, char** argv) {
	int n, k;
	cin >> n >> k;
	priority_queue<Trans> trans;
	vector<int> keys;
	keys.resize(n);
	for (int i = 0; i < n; i++) {
		keys[i] = i + 1;
	}
	for (int i = 0; i < k; i++) {
		Trans tran1,tran2;
		
		cin >> tran1.key >> tran1.time;
		tran1.type = 1;
		cin >> tran2.time;
		tran2.time += tran1.time;
		tran2.type = 2;
		tran2.key = tran1.key;
		trans.push(tran1);
		trans.push(tran2);
	}

	while (!trans.empty()) {
		Trans tran = trans.top();
		if (tran.type == 1) {
			auto iter = find(keys.begin(), keys.end(), tran.key);
			*iter = 0;
		}
		else if (tran.type == 2) {
			auto it = find(keys.begin(), keys.end(), 0);
			*it = tran.key;
		}
		trans.pop();
	}
	for (int i = 0; i < n-1; i++) {
		cout << keys[i] << " ";
	}
	cout << keys[n - 1] << endl;
	//system("pause");
	return 0;
}