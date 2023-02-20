// 1 ton n 
void fun(int n) {
	if(n == 0) {
		return;
	}
	fun(n-1);
	cout << n << endl;
}

//~ making it tail recursive
void fun(int n, int k=1) {
	if(n<1) return;
	cout << k << " ";
	fun(n-1, k+1);
}

//~ tail recursion of factorial
void fact(int n, int val=1) {
	if(n==0) return val;
	
	return fact(n-1, n*val);
}

void isPal(string str, int s, int e) {
	if(s >= e) return true;
	
	if(str[s] != str[e]) {
		return false;
	}
	
	return isPal(str, s+1, e-1);
}
