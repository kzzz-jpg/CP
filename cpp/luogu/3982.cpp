#include<bits/stdc++.h>
using namespace std;
#define int long long
string s,ans;
int getn(string str){
    int ret=0;
    for(int i=0;i<str.size();i++){
        ret<<=1;
        if(str[i]=='1'){
            ret|=1;
        }
    }
    return ret;
}
signed main(){
    cin>>s;
    if(s.size()%8){
        cout<<"Error\n";
        return 0;
    }
    for(auto x:s) if(x!='0'&&x!='1'){
        cout<<"Error\n";
        return 0;
    }
    for(int i=0;i<s.size();i+=8){
        if(s[i]=='1'&&s[i+1]=='0'&&s[i+2]=='1'){
            int ff=getn(s.substr(i+3,5));
            if(ff>25){
                cout<<"Error\n";
                return 0;
            }
            ans.push_back('A'+ff);
        }else if(s[i]=='1'&&s[i+1]=='1'&&s[i+2]=='1'){
            ans.push_back(' ');
        }else if(s[i]=='1'){
            cout<<"Error\n";
            return 0;
        }else{
            if(i+8>=s.size()){
                cout<<"Error\n";
                return 0;
            }
            int ff=getn(s.substr(i,8))>>1;
            i+=8;
            if(s[i]!='0'){
                cout<<"Error\n";
                return 0;
            }
            int ss=getn(s.substr(i,8))>>1;
            ss+=ff;
            ans+=to_string(ss);
        }
    }
    cout<<ans<<'\n';
}