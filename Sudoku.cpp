#include <iostream>
using namespace std;

#define BienX 0
#define N 9

class sudokuTable
{
public:
    int Mang[N][N] = {{0, 0, 0, 0, 0, 0, 0, 0, 2},
                      {0, 0, 0, 0, 0, 0, 9, 4, 0},
                      {0, 0, 3, 0, 0, 0, 0, 0, 5},
                      {0, 9, 2, 3, 0, 5, 0, 7, 4},
                      {8, 4, 0, 0, 0, 0, 0, 0, 0},
                      {0, 6, 7, 0, 9, 8, 0, 0, 0},
                      {0, 0, 0, 7, 0, 6, 0, 0, 0},
                      {0, 0, 0, 9, 0, 0, 0, 2, 0},
                      {4, 0, 8, 5, 0, 0, 3, 6, 0}};
};

class sudoku
{

public:
    sudokuTable *Table = new sudokuTable;

    int a[N][N];
    void setTable()
    {
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                cout << "Nhap ma tran "
                     << "[" << row << "]"
                     << "[" << col << "]: ";
                cin >> a[row][col];
            }
        }
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
            {
                this->Table->Mang[row][col] = a[row][col];
            }
        }
    }
    void Xuat()
    {
        cout << endl;
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
                cout << this->Table->Mang[row][col] << " ";
            cout << endl;
        }
    }

    bool SolveSudoku()
    {
        /*cout << "0, 0, 0, 0, 0, 0, 0, 0, 2" << endl;
        cout << "0, 0, 0, 0, 0, 0, 9, 4, 0" << endl;
        cout << "0, 0, 3, 0, 0, 0, 0, 0, 5" << endl;
        cout << "0, 9, 2, 3, 0, 5, 0, 7, 4" << endl;
        cout << "8, 4, 0, 0, 0, 0, 0, 0, 0" << endl;
        cout << "0, 6, 7, 0, 9, 8, 0, 0, 0" << endl;
        cout << "0, 0, 0, 7, 0, 6, 0, 0, 0" << endl;
        cout << "0, 0, 0, 9, 0, 0, 0, 2, 0" << endl;
        cout << "4, 0, 8, 5, 0, 0, 3, 6, 0" << endl;*/
        
        Xuat();

        if (SolveSudoku(this->Table) == true)
        {
            cout << endl
                 << "Dap ap bai toan sudoku:" << endl;
            XuatMang(this->Table);
        }
        else
            cout << "Khong co cach giai!!!";
        return 0;
    }

    bool SolveSudoku(sudokuTable *table)
    {
        int row, col;
        if (!TimX(table->Mang, row, col))
            return true;

        for (int num = 1; num <= N; num++)
        {
            if (Check(table->Mang, row, col, num))
            {
                table->Mang[row][col] = num;
                if (SolveSudoku(table))
                    return true;
                table->Mang[row][col] = BienX;
            }
        }
        return false;
    }

    bool TimX(int Mang[N][N], int &row, int &col)
    {
        for (row = 0; row < N; row++)
            for (col = 0; col < N; col++)
                if (Mang[row][col] == BienX)
                    return true;
        return false;
    }

    bool CheckRow(int Mang[N][N], int row, int num)
    {
        for (int col = 0; col < N; col++)
            if (Mang[row][col] == num)
                return true;
        return false;
    }

    bool CheckCol(int Mang[N][N], int col, int num)
    {
        for (int row = 0; row < N; row++)
            if (Mang[row][col] == num)
                return true;
        return false;
    }

    bool CheckBox(int Mang[N][N], int DauRow, int DauCol, int num)
    {
        for (int row = 0; row < 3; row++)
            for (int col = 0; col < 3; col++)
                if (Mang[row + DauRow][col + DauCol] == num)
                    return true;
        return false;
    }

    bool Check(int Mang[N][N], int row, int col, int num)
    {

        return !CheckRow(Mang, row, num) && !CheckCol(Mang, col, num) && !CheckBox(Mang, row - row % 3, col - col % 3, num) && Mang[row][col] == BienX;
    }

    void XuatMang(sudokuTable *table)
    {
        this->Table->Mang;
        for (int row = 0; row < N; row++)
        {
            for (int col = 0; col < N; col++)
                cout << this->Table->Mang[row][col] << " ";
            cout << endl;
        }
    }
};

class menu
{
public:
    menu()
    {
        int KyTu;
        do
        {
            sudoku b;
            cout << "\n1. Giai ma tran co san trong code";
            cout << "\n2. Giai ma tran nhap tu ban phim";
            cout << "\n3. Thoat";
            cout << "\nBan phim chon chuc nang: ";
            cin >> KyTu;
            switch (KyTu)
            {
            case 1:
                b.SolveSudoku();
                break;
            case 2:
                b.setTable();
                b.Xuat();
                b.SolveSudoku();
                break;
            }
        } while (KyTu != 3);
    }
};

int main()
{
    menu x;
    system("pause");
    return 0;
}