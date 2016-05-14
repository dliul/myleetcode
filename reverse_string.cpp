#include <iostream>
#include <string>
using namespace std;


class Solution{
	public:
		string reverseString(string s){
			if(s.empty()) return "";
			string output = "";
			int len = s.length();
			for(int i=len-1; i>=0; --i) {
				output += s[i];
			}
			return output;
		}
};

int main(){
	Solution test;
	cout << test.reverseString("test");
	cout << "\n";
}


