class StockSpanner {
public:
    stack<pair<int,int>>stockprice;
    StockSpanner() {
        
    }
    
    int next(int price) {
       pair<int,int>p;
       p.first = price;
       p.second = 1;
       while(!stockprice.empty() && price >= stockprice.top().first){
        p.second += stockprice.top().second;
        stockprice.pop();
       }
       stockprice.push(p);
       return stockprice.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */