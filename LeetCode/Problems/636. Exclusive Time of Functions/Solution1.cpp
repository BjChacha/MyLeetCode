// stack
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> res(n, 0);
        stack<pair<int,int>> stk;
        int last = -1;
        for (const string& l: logs) {
            char op[10];
            int id, st;
            sscanf(l.c_str(), "%d:%[^:]:%d", &id, op, &st);
            
            if (op[0] == 'e') {
                auto p = stk.top();
                stk.pop();
                res[id] += (st - p.second + 1);
                if (!stk.empty()) stk.top().second = st + 1;
            } else {
                if (!stk.empty()) {
                    auto p = stk.top();
                    res[p.first] += (st - p.second);
                    stk.top().second = st + 1;
                }
                stk.push({id, st});
            }
        }
        return res;
    }
};
