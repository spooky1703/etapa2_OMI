#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool esValida(string s) {
  stack<char> pila;

  for (char c : s) {
    if (c == '(' || c == '{' || c == '[') {
      pila.push(c);
    } else if (c == ')') {
      if (pila.empty() || pila.top() != '(') {
        return false;
      }
      pila.pop();
    } else if (c == '}') {
      if (pila.empty() || pila.top() != '{') {
        return false;
      }
      pila.pop();
    } else if (c == ']') {
      if (pila.empty() || pila.top() != '[') {
        return false;
      }
      pila.pop();
    }
  }

  return pila.empty();
}

int main() {
  string s;
  cin >> s;

  if (esValida(s)){
    cout << "verdadero" << endl;
  } else {
    cout << "falso" << endl;
  }

  return 0;
}