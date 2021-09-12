#include <iostream>
using namespace std;

class EightQueens
{
private:
     int n;

public:
     EightQueens()
     {
          cout << "Nhap kich thuoc ban co (tuong duong so quan hau): ";
          cin >> n;
          NQueens();
     }
     void result(int temp[])
     {
          int board[n][n];
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    board[i][j] = temp[n * i + j];
               }
          }

          static int k = 1;
          cout << "Cach giai " << k++ << ": " << endl;
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    cout << board[i][j] << " ";
               }
               cout << endl;
          }
          cout << endl;
     }

     // kiem tra 3 huong theo cot, trai tren, trai duoi de dat Queen
     bool check(int temp[], int row, int col)
     {
          int board[n][n];
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    board[i][j] = temp[n * i + j];
               }
          }

          int i, j;

          // kiem tra tren cung mot hang
          for (i = 0; i < col; i++)
          {
               if (board[row][i] == 1) // da ton tai Queen
               {
                    return false;
               }
          }

          // kiem tra huong trai tren
          for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
          {
               if (board[i][j] == 1) // da ton tai Queen
               {
                    return false;
               }
          }

          // kiem tra huong trai duoi
          for (i = row, j = col; j >= 0 && i < n; i++, j--)
          {
               if (board[i][j] == 1) // da ton tai Queen
               {
                    return false;
               }
          }

          return true; // cho phep dat Queen
     }

     // set vi tri cho Queen
     bool Solve(int temp[], int col)
     {
          int board[n][n];
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    board[i][j] = temp[n * i + j];
               }
          }

          if (col == n) // stop
          {
               result(temp);
               return true;
          }

          bool res = false;
          for (int i = 0; i < n; i++)
          {
               if (check(temp, i, col))
               {
                    board[i][col] = 1; // dat Queen
                    for (int i = 0; i < n; i++)
                    {
                         for (int j = 0; j < n; j++)
                         {
                              temp[n * i + j] = board[i][j];
                         }
                    }

                    res = Solve(temp, col + 1) || res; // kiem tra vi tri nay co dat Queen duoc khong
                    /*********************
                * if (Solve(temp, col + 1, n))
                * {
                *   res = true;
                * }
               *********************/

                    board[i][col] = 0; // lui lai (back-tracking)
               }
          }
          return res;
     }

     void NQueens()
     {
          int board[n][n];
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    board[i][j] = 0;
               }
          }

          int temp[n * n];
          for (int i = 0; i < n; i++)
          {
               for (int j = 0; j < n; j++)
               {
                    temp[n * i + j] = board[i][j];
               }
          }
          if (Solve(temp, 0) == false)
          {
               cout << "No Solution !!" << endl;
          }
     }
};

int main()
{
     EightQueens EQ;
     system("pause");
     return 0;
}