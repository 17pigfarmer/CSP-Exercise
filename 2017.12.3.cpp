#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <algorithm>
#include <sstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

vector<string> split(const string& s, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}




int ReturnWeekDay(int year, int month, int day) {
	int c, y, m, d;

	if (month == 1 || month == 2)
	{
		c = (year - 1) / 100;
		y = (year - 1) % 100;
		m = month + 12;
		d = day;
	}
	else
	{
		c = year / 100;
		y = year % 100;
		m = month;
		d = day;
	}


	int weekday_caile = abs(y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1)%7;
	int weekday = weekday_caile == 0 ? 7 : weekday_caile;
	return weekday;
}

bool LeapYear(int year) {
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) {
		return true;
	}
	return false;
}

int DPerM(int month,int year){
	if (month == 1 ||
		month == 3 ||
		month == 5 ||
		month == 7 ||
		month == 8 || 
		month == 10 ||
		month == 12  )
		return 31;
	else if (month == 2) {
		if (LeapYear(year)) {
			return 28;
		}
		else {
			return 29;
		}
	}
	else if (month == 4 || 
			month == 6||
			month == 9||
			month == 11) {
		return 30;
	}
}


class Time {
public:
	int year;
	int month;
	int day;

	int hour;
	int minute;
	int weekday;
	void PassAMinute() {
		minute++;
		if (minute == 60) {
			minute = 0;
			hour++;
			if (hour == 24) {
				hour = 0;
				day++;
				weekday++;
				if (weekday == 8) {
					weekday = 1;
				}
				if (day == DPerM(month, year)+1) {
					day = 1;
					month++;
					if (month == 13) {
						month = 1;
						year++;
					}
				}
			}
		}
	}
	long long GetTime() {
		long long time = 0;
		time = minute + hour * 100 + day * 10000 + month * 1000000 + year * 100000000ll;
		return time;
	}
	void SetTime(long long time) {
		year = (int)(time / 100000000);
		month = time / 1000000 % 100;
		day = time / 10000 % 100;
		hour = time / 100 % 100;
		minute = time % 100;
		weekday = ReturnWeekDay(year, month, day);
	}

};


struct Rule {
	string pattern;
	string cmd;
};


string Format(string str) {
	vector<string> values = split(str, ',');
	string res = "(";
	for (string value : values) {
		if (value.find('-') != -1) {
			vector<string> tmp = split(value, '-');
			int min = stoi(tmp[0]);
			int max = stoi(tmp[1]);
			for (int i = min; i <= max; i++) {
				if (i < 10) {
					res += "0" + to_string(i) + "|";
				}
				else if (i >= 10) {
					res += to_string(i) + "|";
				}
			}
		}
		else {
			int intvalue = stoi(value);
			if (intvalue < 10) {
				res += "0" + value + "|";
			}
			else if (intvalue >= 10) {
				res += value + "|";
			}
		}
	}
	res.erase(res.length() - 1);
	res += ")";
	return res;
}

void GenerateRule(const vector<string>& ctab, vector<Rule>& rules) {
	Rule rule;
	rule.cmd = ctab[5];
	string min = ctab[0];
	string hour = ctab[1];
	string day = ctab[2];
	string month = ctab[3];
	string weekday = ctab[4];
	transform(month.begin(), month.end(), month.begin(), ::toupper);
	transform(weekday.begin(), weekday.end(), weekday.begin(), ::toupper);
	vector<string> MON = { "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC" };
	vector<string> WEEK = {  "MON", "TUE", "WED", "THU", "FRI", "SAT","SUN" };
	for (int i = 0; i < 12; i++) {
		regex r1(MON[i]);
		month = regex_replace(month, r1,to_string(i+1));

	}
	for (int i = 0; i < 7; i++) {
		regex r1(WEEK[i]);
		weekday = regex_replace(weekday, r1, to_string(i + 1));
	}

	//Äê
	rule.pattern = "\\d{4}";
	//month
	if (month == "*") {
		rule.pattern += "\\d{2}";
	}
	else {
		rule.pattern += Format(month);
	}
	//day
	if (day == "*") {
		rule.pattern += "\\d{2}";
	}
	else {
		rule.pattern+= Format(day);
	}
	//hour
	if (hour == "*") {
		rule.pattern += "\\d{2}";
	}
	else {
		rule.pattern += Format(hour); 
	}
	//minute
	if (min == "*") {
		rule.pattern += "\\d{2}";
	}
	else {
		rule.pattern += Format(min);
	}
	//weekday
	if (weekday == "*") {
		rule.pattern += "\\d{2}";
	}
	else {
		rule.pattern += Format(weekday);
	}
	
	
	rules.push_back(rule);
	return;
}


int main(int argc, char** argv) {
	vector<Rule> rules;
	int n;
	long long begintime, endtime;
	cin >> n >> begintime >> endtime;
	
	for (int i = 0; i < n; i++) {
		vector<string> tmpvec;
		for (int j = 0; j < 6; j++) {
			string tmp;
			cin >> tmp;
			tmpvec.push_back(tmp);
		}
		GenerateRule(tmpvec, rules);
	}



	Time t1,t2;
	t1.SetTime(begintime);
	t2.SetTime(endtime);
	while (t1.GetTime() != t2.GetTime()) {
		t1.PassAMinute();
		long long currenttime = t1.GetTime();
		string strtime = to_string(currenttime)+"0"+to_string(t1.weekday);
		for (auto rule : rules) {
			regex re(rule.pattern);
			if (regex_match(strtime, re)) {
				cout << currenttime << " " << rule.cmd << endl;
			}
		}
	}

	system("pause");
	return 0;
}