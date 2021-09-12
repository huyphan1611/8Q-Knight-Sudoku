#include <iostream>
using namespace std;

const int n = 8;
int a[n][n];
int X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int Y[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int t;

class MaDiTuan
{
public:
    //khoi tao ban co rong (chua co quan ma di qua)
    void Init(int a[][n])
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = 0;
    }

    //in ket qua di tuan cua quan ma
    void OutPut()
    {
        for (int i = 0; i < t; i++)
        {
            for (int j = 0; j < t; j++)
                cout << a[i][j] << "	";
            cout << endl
                 << endl;
        }
    }

    //i: So luot da di, (x,y): toa do ma o vi tri cuoi cung
    void Try(int a[][n], int i, int x, int y, int &q)
    {
        int k, u, v;

        for (k = 0; k < 8; k++)
        {
            u = x + X[k];
            v = y + Y[k];

            if ((0 <= u) && (u < t) && (0 <= v) && (v < t) && (a[u][v] == 0))
            {
                //thu nuoc di ke tiep
                a[u][v] = i + 1;

                if (i == t * t - 1) //hoan tat
                    q = 1;
                else
                {
                    Try(a, i + 1, u, v, q); // di tiep
                    if (!q)
                        a[u][v] = 0; //tra lai nhu cu
                }
            }
        }
    }
};

int main()
{
    int q = 0;
    int x, y;
    cout << "Nhap kich thuoc ban co: ";
    cin >> t;
    cout << "Nhap vi tri ban dau:";
    cout << "\nNhap vao so dong x = ";
    cin >> x;
    cout << "\nNhap vao so cot y = ";
    cin >> y;
    MaDiTuan mdt;
    mdt.Init(a);
    a[x][y] = 1;
    mdt.Try(a, 1, x, y, q);
    if (q)
        mdt.OutPut();
    else
        cout << "khong tim duoc loi giai!\n";
    system("pause");
    return 0;
}