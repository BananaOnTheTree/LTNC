#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
void unset(int &t, int pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(int &t, int pos)
{
    t |= (1ll << (pos - 1));
}
int getbit(int i,int k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(int &x, int y)
{
    x = min(x, y);
}
void maximize(int &x, int y)
{
    x = max(x, y);
}
int ADD(int x, int y)
{
    return (x + y) % MOD;
}
int MINUS(int x, int y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
int matrix[11][11], m, n, k, notBomb;
char flag[11][11];
bool gameOver;
int dx[] = {1, -1, 0};
int dy[] = {1, -1, 0};
int getMine(int x, int y)
{
    int ret = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!i && !j) continue;
            int nX = x + dx[i], nY = y + dy[j];
            if (!nX || !nY || nX > m || nY > n) continue;
            ret += (matrix[nX][nY] == -1);
        }
    }
    return ret;
}
void printMatrix()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++) cout << flag[i][j] << "  ";
        cout << "\n\n";
    }
}
void input()
{
    cout << "Nhap kich thuoc ma tran m, n = "; cin >> m >> n;
    cout << "\nNhap so luong min k = "; cin >> k;
    notBomb = m * n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int t = rand() % 100;
            if (t % 2 == 0 && k)
            {
                matrix[i][j] = -1;
                notBomb--;
                k--;
            }
            flag[i][j] = '.';
        }
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
        if (matrix[i][j] != -1) matrix[i][j] = getMine(i, j);
}
void loang(int x, int y)
{
    if (flag[x][y] != '.' && flag[x][y] != 'F') return;
    flag[x][y] = char(matrix[x][y] + '0');
    notBomb--;
    if (flag[x][y] != '0') return;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (!i && !j) continue;
            int nX = x + dx[i], nY = y + dy[j];
            if (!nX || !nY || nX > m || nY > n) continue;
            loang(nX, nY);
        }
    }
}
void play()
{
    int type, x, y;
    cout << "Nhap hanh dong: \n0. Cam co\n1. Xoa co\n2. Mo o\nHanh dong: ";
    cin >> type;
    cout << "\nNhap toa do: "; cin >> x >> y;
    if (!type)
    {
        if (flag[x][y] == '.') flag[x][y] = 'F';
        else cout << "Khong the cam co tai o nay!\n";
    }
    else if (type == 1)
    {
        if (flag[x][y] == 'F') flag[x][y] = '.';
        else cout << "Khong the xoa co tai o nay!\n";
    }
    else
    {
        if (flag[x][y] == 'F') cout << "O nay dang co co. Hay xoa co truoc khi mo o!\n";
        else if (matrix[x][y] == -1)
        {
            cout << "O HIEN TAI LA BOMB!";
            gameOver = 1;
        }
        else loang(x, y);
    }
}
main()
{
    srand(time(NULL));
    input();
    printMatrix();
    while (notBomb)
    {
        play();
        if (gameOver)
        {
            cout << "\nYOU LOSE!";
            return 0;
        }
        printMatrix();
    }
    cout << "YOU WIN!";
    return 0;
}
