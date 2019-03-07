//getline用法，遇到回车返回，不读入/n 但是读入空格 返回值不是false
//小心小错误！！！！！！
#include <iostream>
#include<string>
#include <fstream>

using namespace std;

string lines;
int i=0;
int length;


void Line();
void EM();
void Link();
bool LineWithN();
void Block();
void Head();
void Passage();
void UL();


void EatSpace() {
	while (lines[i] == ' ') {
		i++;
	}
	return;
}


void Mark() {
	Block();
	while (i < length) {
		while (lines[i] == '\n'&&i < length) {
			i++;
		}
		if (i < length)
			Block();
	}
	
}


bool IsHead() {
	int start = i;
	while (lines[i] == '#') {
		i++;
	}
	if (lines[i] == ' ') {
		i = start;
		return true;
	}
	else {
		i = start;
		return false;
	}
}

void Block() {
	if (IsHead()) {
		Head();
	}
	else if (lines[i] == '*'&&lines[i+1]==' ') {
		UL();
	}
	else {
		Passage();
	}
	return;
}



void UL() {
	cout << "<ul>" << endl;

	while (lines[i] != '\n') {
		cout << "<li>" ;
		i++;
		EatSpace();
		Line();
		cout << "</li>" << endl;
	}

	cout << "</ul>" << endl;
}


void Passage() {
	cout << "<p>";

	while (LineWithN()) {
		cout << endl;
	}

	cout << "</p>"<<endl;


}



void Head() {
	int count=0;
	while (lines[i] == '#') {
		count++;
		i++;
	}
	cout << "<h" << count << ">";
	EatSpace();
	Line();
	cout << "</h" << count << ">" << endl;
}

void Line() {
	while (true) {
		if (lines[i] == '_') {
			EM();
		}
		else if (lines[i] == '[') {
			Link();
		}
		else if(lines[i]=='\n'){
			i++;
			break;
		}
		else {
			cout << lines[i];
			i++;
		}
	}
	return;
}


bool LineWithN() {
	
		while (true) {
			if (lines[i] == '_') {
				EM();
			}
			else if (lines[i] == '[') {
				Link();
			}
			else if (lines[i] == '\n') {
				if (lines[i + 1] == '\n') {
					i++;
					return false;
				}
				else {
					i++;
					return true;
				}
			}
			else {
				cout << lines[i];
				i++;
			}
		}
	
}



void EM() {
	cout << "<em>";
	i++;
	while (lines[i] != '_') {
		if (lines[i] == '[') {
			Link();
		}
		else {
			cout << lines[i];
			i++;
		}
	}
	cout << "</em>";
	i++;
	return;
}


void Link() {
	int start = i;
	while (lines[i] != '(') {
		i++;
	}
	i++;
	cout << "<a href=\"";
	while (lines[i] != ')') {
		cout << lines[i];
		i++;

	}
	cout << "\">";
	int end = i + 1;
	i = start;
	i++;
	while (lines[i] != ']') {
		if (lines[i] == '_') {
			EM();
		}
		else {
			cout << lines[i];
			i++;
		}
	}
	cout << "</a>";
	i = end;
	return;

}


int main(int argc, char** argv) {
	ifstream fin("2017.3.3.txt");
	string line;
	while (getline(fin, line)) {
		lines += line+"\n";
	};
	
	lines += "\n";
	length = lines.length();
	Mark();


	return 0;
}