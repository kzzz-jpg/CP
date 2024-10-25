#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5+5;

struct trie {
    int s[mx][30], cnt=0;
    int data[mx];
    
    void insert(string& st) {
        int now = 0;
        for (int i=0;i<st.size();i++) {
            int c = st[i] - 'a';    
            if (!s[now][c]) s[now][c] = ++cnt;
            now = s[now][c];
        }
        data[now] = 1;
    }

    bool query(string& st) {
        int now = 0;
        for (int i=0;i<st.size();i++) {
            int c = st[i] - 'a';
            if (!s[now][c]) return 0;
            now = s[now][c];
        }
        return data[now] == 1;
    }
}t;

int main() {
    string s="abc";
    string ss = "ab";
    cout << t.query(s) << "\n";
    t.insert(s);
    cout << t.query(s) << " " << t.query(ss) << "\n";
}