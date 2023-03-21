#include <iostream> 
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
//========================================================================0========================================================================//

int getLen(const char* a)
{
    int ret = 0;
    while (a[ret] != '\0') ret++;
    return ret;
}
struct String
{
    int n;
    char *s;
    String()
    {
        n = 0;
        s = new char;
    }
    String (const char* _s)
    {
        n = getLen(_s);
        s = new char[n];
        for (int i = 0; i < n; i++) s[i] = _s[i];
    }
    ~String()
    {
        n = 0;
        delete []s;
        s = NULL;
    }
    void print()
    {
        for (int i = 0; i < n; i++) cout << s[i];
    }
    void append(const char* b)
    {
        int m = getLen(b);
        char* ret = new char[n + m];
        for (int i = 0; i < n; i++) ret[i] = s[i];
        for (int i = 0; i < m; i++) ret[n + i] = b[i];
        n += m;
        delete []s;
        s = new char[n];
        for (int i = 0; i < n; i++) s[i] = ret[i];
    }
};

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    String a("Hi");
    a.append(" there");
    a.print();
    return 0;
}
