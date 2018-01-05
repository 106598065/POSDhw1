#include <gtest/gtest.h>
#include <iostream>
#include "parser.h"
#include "scanner.h"
#include "exp.h"
#include <sstream>

using namespace std;


string& checkcomanndcc123456(string &s) {
int i = 0, index = 0;
string ss = "";

  if (s.empty()) {
    return s;
  }
    for(i=0 ; i<s.size() ; i++){
      if(s[i] != ' '){
          index = i;
          ss = ss + s[i];
      }
    }
    s = ss;
    return s;
  }

int main( int argc , char **argv ) {
  string input;

	do {
		cout << "?-";
		getline(cin, input);
		if (checkcomanndcc123456(input) == "halt."){
      break;
    }
		if (checkcomanndcc123456(input) == ""){
      continue;
    }
		Scanner s(input);
		Parser p(s);
		try{
			p.buildExpression();
			string result = p.getExpressionTree()->getExpressionResult() + '.';
			cout << result << endl;
		} catch (std::string & msg) {
			cout << msg << endl;
		}
	} while(true);
  return 0;
}
