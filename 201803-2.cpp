#include <iostream>
#include <vector>
#include<algorithm>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
struct Ball {
	int position;
	int towards;
	bool isColliding;//�������ײ��������ֱ��ж�һ��
};


class IsCollided {//�ο�find_if���÷�
public:
	IsCollided(const Ball & ba) {
		ba_ = &ba;
	}

	bool operator()(const Ball& ba) {
		if (ba.position == ba_->position&&ba.towards != ba_->towards)
			return true;
		return false;
	}


private:
	const Ball* ba_;
};

int main(int argc, char** argv) {
	int n;
	int L;
	int t;
	cin >> n >> L >> t;
	vector<Ball> balls;
	for (int i = 0; i < n; i++) {
		Ball ba;
		cin >> ba.position;
		ba.towards = 0;
		ba.isColliding = false;
		balls.push_back(ba);
	}
	for (int j = 0; j < t; j++) {

		//�ƶ�С�� 
		for (auto &ba : balls) {
			if (ba.towards == 0) {
				ba.position++;
			}

			else if (ba.towards == 1)
				ba.position--;
		}
		//�������� 
		for (auto &ba : balls) {
			if (ba.position == L + 1) {
				ba.position = L - 1;
				ba.towards = 1;
			}
			else if (ba.position == -1) {
				ba.position = 1;
				ba.towards = 0;
			}
		}
		//������ײ
		for (auto &ba : balls) {
			auto ite = find_if(balls.begin(), balls.end(), IsCollided(ba));
			if ( ite != balls.end()) {
				if (ite->isColliding == false)
					ba.isColliding = true;
				else {
					ite->isColliding = false;
					ba.towards = ba.towards == 0 ? 1 : 0;
					ite->towards = ite->towards == 0 ? 1 : 0;
				}
			}

		}



	}


	for (const auto &ba : balls) {
		cout << ba.position<<" ";
	}
	cout << endl;
	system("pause");

	return 0;
}