class OrderedStream {
private:
    vector<string> stream;
    int ptr;
public:
    OrderedStream(int n) {
        stream = vector<string>(n, "");
        ptr = 0;
    }
    
    vector<string> insert(int idKey, string value) {
        stream[idKey-1] = value;
        vector<string> res;
        while (ptr < stream.size()) {
            if (stream[ptr] == "") {
                break;
            } else {
                res.push_back(stream[ptr]);
                ptr++;
            }
        }
        return res;
    }
};
