#include<bits/stdc++.h>
using namespace std;
string s;
int n;
bool flag=1;
set<string> st;
signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s;
        if((s[0]=='H'||s[0]=='D'||s[0]=='C'||s[0]=='S')&&(s[1]=='A'||s[1]=='T'||s[1]=='Q'||s[1]=='K'||s[1]=='J'||(s[1]<='9'&&s[1]>='2'))) st.insert(s);
        else flag=0;
    }
    if(flag&&st.size()==n) cout<<"Yes\n";
    else cout<<"No\n";
    return 0;
}