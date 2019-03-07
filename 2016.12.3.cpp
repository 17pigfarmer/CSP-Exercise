//make_pair
//substr(起始下标，长度)
//字符串比较直接用==和java不同，同时compare函数返回0的时候说明两个字符串相同
//不要用pair来表示东西，直接自定义类
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
const int NO = 11;

using namespace std;
vector<pair<string, int>> Au;
unordered_map <string, vector<pair<string, int>>> Actor;
unordered_map <string, vector<pair<string, int>>> User;


class IsSameAu {
public:
	IsSameAu(string b) {
		a= b;
	};
	string a;

	bool operator () (const pair<string, int>& c)const {
		return a==c.first;
	}



};


int main(int argc, char** argv) {
	int num_app;
	cin >> num_app;
	while (num_app--) {
		string tmp;
		cin >> tmp;
		if (tmp.find(':') == -1) {
			Au.push_back(::make_pair(tmp,NO));
		}
		else {
			string s1, s2;
			int tmpf = tmp.find(':');
			s1 = tmp.substr(0, tmpf);
			s2 = tmp.substr(tmpf + 1, -1);
			Au.push_back(::make_pair(s1, stoi(s2)));
		}

	}

	int num_act;
	cin >> num_act;
	while (num_act--) {
		
		vector<pair<string, int>> autmp;
		string  name;
		cin >> name;
		pair<string, vector<pair<string, int>>> pairtmp;
		pairtmp.first = name;
		int numtmp;
		cin >> numtmp;
		while (numtmp--) {
			string tmp;
			cin >> tmp;
			if (tmp.find(':') == -1) {
				if(find(autmp.begin(),autmp.end(),::make_pair(tmp, NO))==autmp.end())
				autmp.push_back(::make_pair(tmp, NO));
				

			}
			else {
				string s1, s2;
				int tmpf = tmp.find(':');
				s1 = tmp.substr(0, tmpf);
				s2 = tmp.substr(tmpf + 1, -1);
				auto ite = find_if(autmp.begin(), autmp.end(), IsSameAu(s1));
				
				if(ite==autmp.end())
				autmp.push_back(::make_pair(s1, stoi(s2)));
				else {
					if (ite->second < stoi(s2)) {
						autmp.erase(ite);
						autmp.push_back(::make_pair(s1, stoi(s2)));
					}
				}
			}
		}
		pairtmp.second = autmp;
		Actor.insert(pairtmp);

	}

	int num_user;
	cin >> num_user;
	while (num_user--) {
		vector<pair<string, int>> autmp;
		string  name;
		cin >> name;
		pair<string, vector<pair<string, int>>> pairtmp;
		pairtmp.first = name;
		int numtmp;
		cin >> numtmp;
		while (numtmp--) {
			string actor;
			cin >> actor;
			 auto ite= Actor.find(actor);
			 vector<pair<string, int>> aus = ite->second;
			 for (auto au : aus) {
				 if (au.second == NO) {
					 if (find(autmp.begin(), autmp.end(), ::make_pair(au.first, NO)) == autmp.end())
						 autmp.push_back(::make_pair(au.first, NO));


				 }
				 else {
					 
					 auto ite = find_if(autmp.begin(), autmp.end(), IsSameAu(au.first));

					 if (ite == autmp.end())
						 autmp.push_back(au);
					 else {
						 if (ite->second < au.second) {
							 autmp.erase(ite);
							 autmp.push_back(au);
						 }
					 }
				 }
			 }

			
		}
		pairtmp.second = autmp;
		User.insert(pairtmp);

	}

	int num_query;
	cin >> num_query;
	while (num_query--) {
		string name;
		cin >> name;
		if (User.count(name) == 0) {
			string tmp;
			cin >> tmp;
			cout << "false" << endl;
			continue;
		}
		else {
			auto aus = User.find(name)->second;
			string tmp;
			cin>>tmp;
			if (tmp.find(':') == -1) {
				auto ite = find_if(Au.begin(), Au.end(), IsSameAu(tmp));
				if (ite == Au.end()) {
					cout << "false" << endl;
					continue;
				}
				else {
					if (ite->second == NO) {
						auto ite2 = find(aus.begin(), aus.end(), ::make_pair(tmp, NO));
						if (ite2 == aus.end()) {
							cout << "false" << endl;
							continue;
						}
						else {
							cout << "true" << endl;
							continue;
						}
					}
					else {
						auto ite2 = find_if(aus.begin(), aus.end(), IsSameAu(tmp));
						if (ite2 == aus.end()) {
							cout << "false" << endl;
							continue;
						}
						else {

							cout << ite2->second << endl;
							continue;
						}
					}
				}
			}
			else {
				string auname = tmp.substr(0, tmp.find(':'));
				auto ite2 = find_if(aus.begin(), aus.end(), IsSameAu(auname));
				if (ite2 == aus.end()) {
					cout << "false" << endl;
					continue;
				}
				else {
					bool b = ite2->second >= stoi(tmp.substr(tmp.find(':') + 1, -1));
					if (b) {
						cout << "true" << endl;
						continue;
					}
					else {
						cout << "false" << endl;
						continue;
					}
					
				}
			}
		}
		

	}



	
	return 0;
}