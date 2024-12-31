#include<bits/stdc++.h>
using namespace std;
string s,t;
int k;
signed main(){
    cin>>k;
    cin>>s>>t;
    if(s.size()==t.size()){
        int dif=0;
        for(int i=0;i<s.size();i++) dif+=s[i]!=t[i];
        if(dif<=1)cout<<"Yes\n";
        else cout<<"No\n";
    }else if(abs((int)s.size()-(int)t.size())>1) cout<<"No\n";
    else{
        int dif=0;
        for(int l=0,r=0;l<s.size()&&r<t.size();l++,r++){
            if(s[l]==t[r]) continue;
            if(l+1<s.size()&&s[l+1]==t[r]) dif++,l++;
            else if(r+1<t.size()&&s[l]==t[r+1]) dif++,r++;
            else return cout<<"No\n",0;
        }
        if(dif<=1) cout<<"Yes\n";
        else cout<<"No\n";
    }
}