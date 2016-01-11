#include<iostream>
#include<string>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

/*check whether a string is a permutation of another*/
class Solution {
public:
	/*time: O(NlogN); space: O(1) */
	bool checkPermutation1(string s1, string s2) {
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		return s1 == s2;
	}
	/*time: O(N) ; space O(N)*/
	bool checkPermutation2(string s1, string s2) {
		if (s1.length() != s2.length())
			return false;
		unordered_map<char, int> m;
		for (auto & x : s1) 
			m[x] ++;
		for (auto & x: s2) {
			if (m.find(x) == m.end())
				return false;
			else {
				m[x] --;
				if (m[x] == 0)
					m.erase(x);
			}
		}
		return m.size() == 0;
	}
};

int main() {
	class Solution sn;
	string a = "abbcd";
	string b = "cdbab";
	string c = "accde";
	cout << sn.checkPermutation1(a, b) << endl;
	cout << sn.checkPermutation2(a, b) << endl;

	cout << sn.checkPermutation1(a, c) << endl;
        cout << sn.checkPermutation2(a, c) << endl;

	return 0;
}
