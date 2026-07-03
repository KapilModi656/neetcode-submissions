class StockSpanner {
public:
    stack<int> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        stack<int> a=st;
        int count=1;
        while(!a.empty()){
            if(a.top()<=price){
                a.pop();
                count++;
            }
            else{
                break;
            }
        }
        st.push(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */