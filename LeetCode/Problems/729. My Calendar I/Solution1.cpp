class MyCalendar {
private:
    vector<pair<int, int>> e;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& p: e)
             if (p.second > start && end > p.first) return false;
        e.push_back({start, end});
        return true;
    }
};
