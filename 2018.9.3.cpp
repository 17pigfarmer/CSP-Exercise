//pop_back 会删除
//transform转大写,注意还有一个begin
//80分 未实现后代含id 思路为将id替换为路径
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <regex>

using namespace std;

const string NOID = "dwatrwateataefawf";

vector<string> st;
struct Node {
	string name;
	string id;
	unsigned int position;
};
vector<Node> Nodes;


void GetNode(string s) {
	int k = 0;
	while (s[k] == '.') {
		k++;
	}

	string selfname = s.substr(k, s.find(' ') - k);
	string id;
	if (s.find(' ') != -1)
		id = s.substr(s.find(' ') + 1, -1);
	else
		id = NOID;
	string fa = "";


	int depth = k / 2;

	
	if (depth < st.size()) {
		while (depth != st.size()) {
			st.pop_back();
		}
	}


	if (depth == st.size()) {
		if (st.size() != 0) {
			for (auto t : st) {
				fa += t;
			}
		}
		st.push_back(selfname+" ");
	}


	string name = fa + selfname;
	transform(name.begin(), name.end(), name.begin(), ::toupper);

	Nodes.push_back({ name,id,Nodes.size() + 1 });

}

void FindNode(string s) {
	int number=0;
	vector<int> lines;
	if (s[0] != '#') {
		transform(s.begin(), s.end(), s.begin(), ::toupper);

		for (Node node : Nodes) {
			auto ite1 = node.name.rbegin();
			auto ite2 = s.rbegin();
			bool flag = true;
			while (ite1 != node.name.rend() && ite2 != s.rend()) {
				if (*ite1 == *ite2) {
					ite1++;
					ite2++;
					
				}
				else {
					flag = false;
					break;
				}
			}
			if (ite1 == node.name.rend() && ite2 != s.rend()) {
				flag = false;
			}

			if (flag == true) {
				number++;
				lines.push_back(node.position);
			}

		}
		
	}
	else {
		for (Node node : Nodes) {
			if (node.id == s) {
				number++;
				lines.push_back(node.position);
			}
		}
	}


	cout << number << " ";
	if(number!=0)
		for (auto line : lines) 
			cout << line << " ";
	cout << endl;
}




int main(int argc, char** argv) {
	int n, m;
	string input;
	cin >> n >> m;
	getline(cin, input);

	while (n--) {
		
		getline(cin, input);
		GetNode(input);
	}
	
	


	while (m--) {
		getline(cin, input);
		FindNode(input);
	}

	return 0;
}