// math
class Solution {
private:
    int getDistance(vector<int>& v1, vector<int>& v2) {
        int res = 0;
        for (int i = 0; i < v1.size(); ++i) {
            if (v1[i] != v2[i]) res += 1;
        }
        return res;
    }
    
    int encodeRow(vector<vector<int>>& matrix, int row) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            res = res * 2 + matrix[row][i];
        }
        return res;
    }

    int encodeCol(vector<vector<int>>& matrix, int col) {
        int res = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            res = res * 2 + matrix[i][col];
        }
        return res;
    }
// math
public:
    int movesToChessboard(vector<vector<int>>& board) {
        const int n = board.size();
        vector<int> t1(n, 0), t2(n, 0);
        for (int i = 0; i < n; i += 2) t1[i] = 1;
        for (int i = 1; i < n; i += 2) t2[i] = 1;

        // 计算第一行和第一列与两种交错序列的最短距离。
        // 距离必须为偶数，才有可交换的可能。
        int res = 0, tmp1, tmp2;
        // 行计算
        tmp1 = getDistance(board[0], t1);
        tmp2 = getDistance(board[0], t2);

        cout << tmp1 << " " << tmp2 << endl;
        if (tmp1 % 2 && tmp2 % 2) return -1; 
        else if (tmp1 % 2) res += tmp2 / 2;
        else if (tmp2 % 2) res += tmp1 / 2;
        else res += min(tmp1, tmp2) / 2;
        // 列计算
        vector<int> v(n, 0);
        for (int i = 0; i < n; ++i) v[i] = board[i][0];
        tmp1 = getDistance(v, t1);
        tmp2 = getDistance(v, t2);
        cout << tmp1 << " " << tmp2 << endl;
        for (auto a: t1) cout << a << " ";
        cout << endl;
        for (auto a: t2) cout << a << " ";
        cout << endl;
        for (auto a: v) cout << a << " ";
        cout << endl;
        if (tmp1 % 2 && tmp2 % 2) return -1; 
        else if (tmp1 % 2) res += tmp2 / 2;
        else if (tmp2 % 2) res += tmp1 / 2;
        else res += min(tmp1, tmp2) / 2;

        // 判断能否最终成为目标棋盘
        // 每行/列肯定只有两种互补的序列
        int rt, rt1, rt2, cnt1, cnt2;
        // 行检测
        rt1 = encodeRow(board, 0), rt2 = pow(2, n) - 1 - rt1;
        cnt1 = 1, cnt2 = 0, rt;
        for (int i = 1; i < n; ++i) {
            rt = encodeRow(board, i);
            if (rt == rt1) cnt1 ++;
            else if (rt == rt2) cnt2 ++;
            else return -1;
        }
        if (abs(cnt1 - cnt2) > 1) return -1;
        // 列检测
        rt1 = encodeCol(board, 0), rt2 = pow(2, n) - 1 - rt1;
        cnt1 = 1, cnt2 = 0;
        for (int i = 1; i < n; ++i) {
            rt = encodeCol(board, i);
            if (rt == rt1) cnt1 ++;
            else if (rt == rt2) cnt2 ++;
            else return -1;
        }
        if (abs(cnt1 - cnt2) > 1) return -1;
        return res;
    }
};
