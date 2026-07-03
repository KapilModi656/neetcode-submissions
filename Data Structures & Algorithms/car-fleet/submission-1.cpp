class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<double> st;
        vector<pair<int,int>> arr;
        int n=position.size();
        for(int i=0;i<n;i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
        for(int i=n-1;i>=0;i--){
            int pos=arr[i].first;
            int spe=arr[i].second;
            double tta=(double)(target-pos)/spe;
            if(st.empty()){
                st.push(tta);
            }
            else if(tta>st.top()){
                st.push(tta);
            }

        }
        
        return st.size();
    }
};
