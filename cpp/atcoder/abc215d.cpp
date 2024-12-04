#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops,no-stack-protector,fast-math")
#define int long long
using namespace std;
char readchar() {
	const int S = 1<<20; // buffer size
	static char buf[S], *p = buf, *q = buf;
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
int nextint() {
	int x = 0, c = readchar(), neg = false;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = true, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}
inline void output(int _x){
    if(!_x) putchar('0');
    char _buff[20]; int _f = 0;
    while(_x > 0)
    {
        _buff[_f++] = _x%10+'0';
        _x /= 10;
    }
    for(_f-=1; _f >= 0; _f--)
        putchar(_buff[_f]);
    putchar('\n');
}
int n,m;
int a[200500];
bitset<200500> vs;
signed main(){
        n=nextint(),m=nextint();
        for(int i=1;i<=n;i++){
                a[i]=nextint();
        }
        for(int i=1;i<=n;i++){
                for(int j=1;j<=sqrt(a[i])+5;j++){
                        if(a[i]%j==0)vs[j]=vs[a[i]/j]=1;
                }
        }
        vs[1]=0;
        vector<int> ans;
        int cnt=0;
        for(int i=1;i<=m;i++){
                bool flag=1;
                for(int j=1;j<=sqrt(i)+5;j++){
                        if(i%j==0){
                                if(vs[j]||vs[i/j]){
                                        flag=0;
                                        break;
                                }
                        }
                }
                if(flag){
                        cnt++;
                        ans.push_back(i);
                }
        }
        output(cnt);
        for(auto x:ans) output(x);
}
