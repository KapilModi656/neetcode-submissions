class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int val = threshold*k;
        int e=k-1;
        int n=arr.size();
        int s=0;
        int sumi =0;
        int count=0;
        for(int i=0;i<=e;i++){
            sumi += arr[i];
        }
        if(sumi>=val) count++;
        for(int i=e+1;i<n;i++){
            sumi -= arr[s];
            sumi += arr[i];
            s++;
            if(sumi >= val) count++;
        }
        return count;
    }
};