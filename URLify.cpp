#include<iostream>
#include<string>
#include<cstring>
using namespace std;


/*replace spaces in a char array with "%20", assuming that the array has enough space at the end*/
/*pass array to function: method 1: void URLify(char arr[], int len)
method 2: void URLify(char * arr, int len)
method 3: void URLify(char arr[1000], int len);
*/
class Solution {
public:
	void URLify(char arr [], int len) {
		int spaceCounts = 0;
		for (int i = 0; i < len; i ++)
			if (isspace(arr[i]))
				spaceCounts ++;
		int newLen = len + spaceCounts*2;
		arr[newLen--] = '\0';
		for (int i = len - 1; i >= 0; i --) {
			if (isspace(arr[i])) {
				arr[newLen] = '0';
				arr[newLen-1] = '2';
				arr[newLen-2] = '%';
				newLen -= 3;
			}	
			else {
				arr[newLen] = arr[i];
				newLen --;
			}
		}			
	}
};

int main() {
	class Solution sn;
	char arr[100] = "Mr John  Smith.";
	cout << arr << endl;
	sn.URLify(arr, strlen(arr));
	cout << arr << endl;
	return 0;
}
