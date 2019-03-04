//字符串删除所有空格，auto itor = remove_if(s.begin(), s.end(), ::isspace);
//s.erase(itor, s.end());
//map用法：find
//使用编译的方法写主体

#include <iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;

string s;
unordered_map<string, string> map1;
int i=0;



string STR() {
	i++;
	string str;

	while (s[i] != '\"') {
		if (s[i] == '\\') {
			i++;
		}
		str += s[i];
		i++;
	}
	i++;
	return str;
}


void Object(string fa,int flag){
	//判断object是否为空
	if (s[i] == '{' && s[i + 1] == '}') {
		i += 2;
		return;
	}
	int haschild;
	i++;//, {
	string key;
	if (flag >= 1)
		 key= fa + "." + STR();
	else if (flag == 0)
		 key = STR();

	i++;//:

	string value;
	if (s[i] == '"') {
		value = STR();
		haschild = 0;
	}
	else if (s[i] == '{') {
		Object(key, flag+1);
		haschild = 1;
	}

	if (haschild == 0) {
		map1.insert(pair<string, string>(key, value));
	}
	else {
		map1.insert(pair<string, string>(key, "oooooo"));
	}
	if (s[i] == '}') {
		i++;
		flag--;
	}

	if (s[i] == ',') {
		Object(fa, flag);
	}
	

	
	
}


void Match(string s) {
	auto ite = map1.find(s);
	if (ite == map1.end()) {
		cout << "NOTEXIST" << endl;
	}
	else {
		if (ite->second == "oooooo") {
			cout << "OBJECT" << endl;
		}
		else {
			cout << "STRING" <<" "<< ite->second << endl;
		}
	}

}




int main(int argc, char** argv) {
	int n, m;
	cin >> n >> m;
	cin.ignore();
	
	while(n--) {
		string str;
		getline(cin, str);
		s += str;
	}
	
	vector<string> query;

	while (m--) {
		string tmp;
		cin >> tmp;
		query.push_back(tmp);
	}


	auto itor = std::remove_if(s.begin(), s.end(), ::isspace);
	s.erase(itor, s.end());
	Object("",0);

	for (auto tmp : query) {
		Match(tmp);
	}



	
	


	return 0;
}