#include<bits/stdc++.h>
inline char readchar() {
  const int S = 1 << 20; // buffer size
  static char buf[S], *p = buf, *q = buf;
  if (p == q && (q = (p = buf) + fread(buf, 1, S, stdin)) == buf)
    return EOF;
  return *p++;
}
inline int nextint() {
  int x = 0, c = readchar(), neg = false;
  while (('0' > c || c > '9') && c != '-' && c != EOF)
    c = readchar();
  if (c == '-')
    neg = true, c = readchar();
  while ('0' <= c && c <= '9')
    x = x * 10 + (c ^ '0'), c = readchar();
  if (neg)
    x = -x;
  return x;
}
inline void wrtn(int x) {
  static char buf[15];
  static int len = -1;
  if (x >= 0) {
    do {
      buf[++len] = x % 10 + 48, x /= 10;
    } while (x);
  } else {
    putchar('-');
    do {
      buf[++len] = -(x % 10) + 48, x /= 10;
    } while (x);
  }
  while (len >= 0) {
    putchar(buf[len]), --len;
  }
}
#define min(a,b) a<b?a:b
#define max(a,b) b>a?b:a
int q;
int dp[1001][1<<9][10];
const int P=1e9+7,SS=(1<<9)-1;
inline int st(int s,int pos,int v){
	if(v==0) return s&(~(1<<(pos-1)));
	return s|(1<<(pos-1));
}
signed main(){
	for(int i=1;i<=9;i++){
		dp[1][1<<(i-1)][i]=1;
	}
	for(int i=1;i<=1000;i++){
		for(int s=0;s<(1<<9);s++){
			for(int j=1;j<=9;j++){
				if(!(s>>(j-1)&1)) continue;
				for(int k=max(1,j-2);k<=(min(9,j+2));k++){
					dp[i][s][j]=((dp[i][s][j]+dp[i-1][st(s,j,0)][k]%P)%P+dp[i-1][st(s,j,1)][k]%P)%P;
				}
			}
		}
	}
	q=nextint();
	int x,y;
	while(q--){
		x=nextint(),y=nextint();
		wrtn(dp[x][SS][y]),putchar('\n');
	}
}