/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.

Please make sure you try to solve this problem without using library functions. Make sure you only traverse the string once.
*/
int Solution::lengthOfLastWord(const string A) {

	int last = A.size() - 1;
	int begin = A.size() - 1;
	bool firstChar = false;
	

	for (int i = A.size() - 1; i >=0; i--) {
	    char current = A[i];
	    
	    if (current != ' ' && !firstChar) {
	        firstChar = true;
	        last = i;
	        begin = i;
	    } else if (current != ' ' && firstChar) {
	        begin = i;
	    } else if (current == ' ' && firstChar) {
	        return last - begin + 1;
	    }
	    
	}
	
	return (!firstChar) ? 0 : last - begin + 1;
}