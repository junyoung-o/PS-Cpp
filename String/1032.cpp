#include <iostream>
#include <vector>
using namespace std;

#define max_num 51


vector<string> inputs;
string result;
int n;

void get_str();
void set_str();
void solution();
void compare(string cmp_str);

int main(void) {
	cin >> n;

	// . ? �� ��� ���� -> ��� . �� ���ٸ� .�� ����
	// �ִ��� ?�� ���� ��� -> ���� ���ڸ� ��� ã�Ƴ��� Ʋ���͸� ? ó��
	
	for(int i = 0; i < n; i++) {
		set_str();
	}

	solution();

	cout << result << endl;

	return 0;
}

void set_str() {
	string str;
	cin >> str;

	inputs.push_back(str +'\n');
}

void get_str() {
	for(int i = 0; i < n; i++) {
		cout << inputs[i] << endl;
	}
}

void solution() {
	result = inputs[0];
	for(int i = 1; i < inputs.size(); i++) {
		compare(inputs[i]);
	}
}

void compare(string cmp_str) {

	int ind = 0;
	while(true) {
		if(cmp_str[ind] == '\n') {
			break;
		}
		ind++;
	}

	for(int i = 0; i < ind; i++) {
		if(result[i] != cmp_str[i]) {
			if(result[i] != '?') {
				result[i] = '?';
			}
		}
	}
}