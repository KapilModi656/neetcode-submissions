class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count=0;
        int l=0;
        int n=blocks.size();
        int maxi=0;
        for(int r=0;r<n;r++){
            if(blocks[r]=='B') count++;
            while(r-l+1>k){
                if(blocks[l]=='B') count--;
                l++;
            }
            maxi = max(maxi,count);
        }
        return k-maxi;
    }
};