// 1 ton n 
void sumOfDigits(int n) {
	if(n < 10) {
		return n;
	}
	
	return fun(n-1) + n%10;
}

int maxCuts(int n, int, a, int b, int c) {
	if(n == 0) return 0;
	if(n < 0) return -1;
	
	int res = max(maxCuts(n-a, a, b, c), maxCuts(n-b, a, b, c), maxCuts(n-c, a, b, c))
	
	if(res == -1) return -1;
	
	return res + 1;
}

void printSubSequences(string str, string cur="", index=0) {
	
	if(index == str.length()) {
		cout << cur << endl;
		return;
	}
	
	printSubSequences(str, cur, index+1);
	printSubSequences(str, cur+str[index], index+1);
}
