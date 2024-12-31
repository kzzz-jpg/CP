#include<bits/stdc++.h>
using namespace std;
string a,b,s,t;
signed main(){
        cin>>s>>t;
        for(int i=0;i<s.size();i++){
                if(a.size()<=1||a.back()!=s[i]||a[a.size()-2]!=s[i]) a.push_back(s[i]);
        }
        for(int i=0;i<t.size();i++){
                if(b.size()<=1||b.back()!=t[i]||b[b.size()-2]!=t[i]) b.push_back(t[i]);
        }
        bool flag=1;
        for(int i=0,j=0;i<s.size();i++,j++){
                int l=i,r=j;
                while(l+1<s.size()&&s[l+1]==s[i]) l++;
                while(r+1<t.size()&&t[r+1]==t[j]) r++;
                if(l-i+1>r-j+1) {
                        flag=0;
                        break;
                }
                i=l,j=r;
        }
        if(a==b&&flag) cout<<"Yes\n";
        else cout<<"No\n";
}
