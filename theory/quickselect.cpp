#include <iostream>
#include <string>

using namespace std;

int bracketMatch( const string& text ) 
{
  int ans = 0;
  int nOpen = 0;
  int n = text.size();
  
  for(int i = 0; i < n; i++) {
    if (text[i] == '(') {
      nOpen++;
    } else {
      nOpen--;
      if (nOpen < 0) { // -1
        ans++;
        nOpen = 0;
      }
    }
  }
  
  ans += nOpen;
  return ans;
}

int main() {
  cout << bracketMatch("(()()))((");
  return 0;
}

/*

))))((()) 
nOpen = 1
ans = 4

ans += nOpen
ans = 5

*/