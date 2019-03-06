//迭代器转下标直接减去begin
//使用下标进行删除和修改 insert和erase方法
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;



int main(int argc, char** argv) {
	vector<int> que;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i < n + 1; i++) {
		que.push_back(i);
	}
	for (int i = 0; i < m; i++) {
		int sno,move;
		cin >> sno>>move;

		int q = find(que.begin(), que.end(), sno) - que.begin();

		int im=move > 0 ? move + 1 : move;
		que.insert(que.begin()+q + im, sno);
		int em = move > 0 ? 0 : 1;
		que.erase(que.begin() + q + em);
	}
	for (int i = 0; i < n ; i++) {
		if (i == n - 1) {
			cout << que[i] << endl;
		}
		else {
			cout << que[i] << " ";
		}
		
		
	}

	return 0;
}