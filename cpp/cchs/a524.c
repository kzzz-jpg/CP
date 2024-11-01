#include<stdio.h>
const int S = 1<<20; // buffer size
char buf[1<<20], *p = buf, *q = buf;
char readchar() {
	if(p == q && (q = (p=buf)+fread(buf,1,S,stdin)) == buf) return EOF;
	return *p++;
}
int nextint() {
	int x = 0, c = readchar(), neg = 0;
	while(('0' > c || c > '9') && c!='-' && c!=EOF) c = readchar();
	if(c == '-') neg = 1, c = readchar();
	while('0' <= c && c <= '9') x = x*10 + (c^'0'), c = readchar();
	if(neg) x = -x;
	return x; // returns 0 if EOF
}
void write(int X) {
  if (X < 0) {putchar('-'); X = ~ (X - 1);}
  int s[50], top = 0;
  while (X) {s[++top] = X % 10; X /= 10;}
  if (!top) s[++top] = 0;
  while (top) putchar(s[top--] + '0');
  putchar('\n');//根据情况自行修改
  return;
}
const int P=10009;
int n,m,a[100500];
int main(){
	n=nextint(),m=nextint();
	for(int i=1;i<=n;i++)a[i]=nextint(),(a[i]=a[i]+a[i-1])%P;
	int l,r;
	while(m--){
		l=nextint(),r=nextint();
		write((a[r]+P-a[l-1])%P);
	}
}
