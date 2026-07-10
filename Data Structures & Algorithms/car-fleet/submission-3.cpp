class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> arr;
        int n=speed.size();
        for(int i=0;i<n;i++){
            arr.push_back({position[i],speed[i]});
        }
        sort(arr.begin(),arr.end());
        stack<pair<int,int>> st;
        st.push(arr[n-1]);
        for(int i=n-2;i>=0;i--){
            auto top = st.top();
            int p=top.first,s=top.second;
            double t1 = (target-p)/(double)s;
            double t2 = (target-arr[i].first)/(double)arr[i].second;
            if(t2>t1) st.push(arr[i]);
        }
        return st.size();
    }
};
