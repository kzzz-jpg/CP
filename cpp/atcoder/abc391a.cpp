#include <bits/stdc++.h>
using namespace std;
string s;
signed main() {
  cin >> s;
  if (s == "N")
    cout << "S";
  if (s == "S")
    cout << "N";
  if (s == "W")
    cout << "E";
  if (s == "E")
    cout << "W";
  if (s == "NE")
    cout << "SW";
  if (s == "NW")
    cout << "SE";
  if (s == "SE")
    cout << "NW";
  if (s == "SW")
    cout << "NE";
}
