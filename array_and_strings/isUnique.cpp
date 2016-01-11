#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

/*write a function to check whether a string have all unique chars */
class Solution {
public:
	bool isUnique(string s) {
		unordered_set<char> se;
		for (auto & x: s) {
			if (se.find(x) != se.end())
				return false;
			else 
				se.insert(x);
		}
		return true;
	}
};

int main() {
	string a = "abcd";
	string b = "aacd";
	class Solution sn;
	cout << sn.isUnique(a) << endl;
	cout << sn.isUnique(b) << endl;

	return 0;
}
