#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
int main() {
	string s;
	bool output;
	while (cin >> s) {
    stack<char> a;
		output = true;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == ')') {
				if (a.empty() || a.top() != '(') {
					output = false;
					break;
				}
				a.pop();
			}
			else if (s[i] == ']') {
				if (a.empty() || a.top() != '[') {
					output = false;
					break;
				}
				a.pop();
			}
			else if (s[i] == '}') {
				if (a.empty() || a.top() != '{') {
					output = false;
					break;
				}
				a.pop();
			}
			else {
				a.push(s[i]);
			}
		}
		if (output&&a.empty())cout << "yes" << endl;
        else cout<<"no"<<endl;
	}
	return 0;
}