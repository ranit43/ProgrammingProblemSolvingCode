#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void printArr(int numArr[], int n) {
//~ printarr
		for(int i=0; i<n; i++) {
			cout << numArr[i] << " ";
		}
		cout << endl;
}

void reverse(int arr[], int stI, int enI) {
		
		if(enI<=stI) return;
	
		int md = (enI-stI + 1)/2;
		for(int i=0; i<md; i++) {
				swap(arr[stI+i], arr[ enI-i]);
		}
}

void npReArrangeMerge(int arr[], int l1, int r1, int l2, int r2) {
		
		int m1=l1, m2=r2;
		
		while(m1<=r1 && arr[m1]<0) m1++;
		
		while( m2 >= l2 && arr[m2]>0) m2--;
		
		
		reverse(arr, m1, r1);
		reverse(arr, l2, m2);
		reverse(arr, m1, m2);
}

void npReArrange(int arr[], int beg, int en) {
	// code here
	if(beg>=en) return;
	
	int mid = (beg+en)/2;
	npReArrange(arr, beg, mid);
	npReArrange(arr, mid+1, en);
	
	npReArrangeMerge(arr, beg, mid, mid+1, en);
}


int main() {
	
	freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);

	int n;
	while( cin >> n) {
	//~ vector<int> var;
		int numArr[100305];
		
		for(int i=0; i<n; i++) {
			int a;
			cin >> a;
			//~ var.push_back(a);;
			numArr[i] = a;
		}
		
		//~ rearrange without order
		//~ Note: Order of elements is not important here.
		npReArrange(numArr, 0, n-1);
		
		//~ printarr
		for(int i=0; i<n; i++) {
			cout << numArr[i] << " ";
		}
		cout << endl;
	
 }
}

/*

9
12 11 -13 -5 6 -7 5 -3 -6
5
-3 -2 -1 2 1
3
2 -1 3
5
2 3 -1 -2 -3
5
1 2 3 4 5
1
1
2 
1 2
2
-1 -2


 * */
