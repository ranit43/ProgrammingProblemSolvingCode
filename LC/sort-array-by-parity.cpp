class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int sz = A.size();
        int nei = 0; //next to be negative index
        for(int i=0; i<sz; i++) {
            if(A[i]%2==0) {
                swap(A[i], A[nei]);
                nei++;
            }
        }
        return A;
    }
};
