#include<bits/stdc++.h>
#include <complex>
using namespace std;
using cp=complex<double>;
const double pi=acos(-1);
cp a[2000500],b[2000500];
string s1,s2;
int len;
int rev[2000500];
void fft(cp *x,int type){
    for(int i=0;i<(1<<len);i++) if(i<rev[i]) swap(i,rev[i]);
    for(int i=1;i<len;i*=2){
        cp wn(cos(pi/i),sin(pi/mid)*type);
        for(int j=0)
    }
}
signed main(){
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(int i=0;i<s1.size();i++) a[i]=(double)(s1[i]-'0');
    for(int i=0;i<s2.size();i++) b[i]=(double)(s2[i]-'0');
    while((1<<len)<max(s1.size(),s2.size())) len++;
    for(int i=0;i<(1<<len);i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(len-1));
}