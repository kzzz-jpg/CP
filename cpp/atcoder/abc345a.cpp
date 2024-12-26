#include<bits/stdc++.h>
using namespace std;
string s;
bool flag=1;
signed main(){
        cin>>s;
        for(int i=1;i+1<s.size();i++) if(s[i]!='=') flag=0;
        if(s[0]=='<'&&s.back()=='>'&&flag){
                cout<<"Yes\n";
        }else cout<<"No\n";
}
