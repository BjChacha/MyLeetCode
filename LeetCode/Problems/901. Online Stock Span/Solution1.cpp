// mono stack
class StockSpanner {
private:
    stack<pair<int, int>> stk; 
    int id;
public:
    StockSpanner() {
        this->stk.push({INT_MAX, -1});
        this->id = -1;
    }
    
    int next(int price) {
        this->id ++;
        while (!this->stk.empty() && this->stk.top().first <= price) {
            this->stk.pop();
        }
        int res = this->id - stk.top().second;
        this->stk.push({price, this->id});
        return res;
    }
};
