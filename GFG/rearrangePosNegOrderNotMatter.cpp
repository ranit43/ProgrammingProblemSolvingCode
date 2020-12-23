#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void reverse(int arr[], int stI, int enI) {
		int md = (enI-stI + 1)/2;
		for(int i=stI; i<md; i++) {
				swap(i, enI-i);
		}
}

void leftRotate(int arr[], int n, int d) {
		// code here
		reverse(arr, 0, d-1);
		reverse(arr, d, n-1);
		reverse(arr, 0, n-1);
}

int main() {
	
	freopen("in.txt", "r", stdin);
	//~ freopen("out.txt", "w", stdout);

	int n;
	cin >> n;
	vector<int> var;
	for(int i=0; i<n; i++) {
		int a;
		cin >> a;
		var.push_back(a);
	}
	
	//~ rearrange without order
	//~ Note: Order of elements is not important here.
	
	int sz = var.size(), npi=0;
	for(int i=0; i<sz; i++) {
		if(var[i] < 0 ) {
			swap(var[i], var[npi]);
			npi++;
		}		
	}
	
	//~ printarr
	for(int i=0; i<sz; i++) {
		cout << var[i] << " ";
	}
	cout << endl;
}

/*

9
12 11 -13 -5 6 -7 5 -3 -6

 * */
