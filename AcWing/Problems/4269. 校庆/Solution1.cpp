#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

unordered_set<string> a;
int n,m;

int cul(string x)
{
    return stoi(x.substr(6,8));
}

int main()
{
    cin >> n;
    int ans = 0;
    int lm = 1e9,rm = 1e9;
    string b[2];
    string s;

    while(n -- )
    {
        cin >> s;
        a.insert(s);
    }

    cin >> m;

    while(m -- )
    {
        cin >> s;
        int k = cul(s);
        if(a.count(s))
        {
            ans ++ ;
            if(k < lm)
            {
                lm = k;
                b[0] = s;
            }
        }
        else if(k < rm)
        {
            rm = k;
            b[1] = s;
        }
    }

    cout << ans << endl;
    if(!ans) cout << b[1];
    else cout << b[0];

    return 0;

}