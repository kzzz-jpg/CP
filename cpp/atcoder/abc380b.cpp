#include<bits/stdc++.h>
using namespace std;
string s;
signed main(){
        cin>>s;
        for(int l=1,r=1;r<s.size();r++){
                if(s[r]=='|') cout<<r-l<<' ',l=r+1;
        }
}
