#include <iostream>
using namespace std;

bool ok(int q[], int c) {//if the queen in column c is ok than it'll return true
   for (int i = 0; i < c; i++)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i){
         return false;
      }
   return true;

}

void print(int q[]) {
   static int setNum = 1;
   int i, j, k, l;
    typedef char box[5][7];   // box is now a data type: a 5x7 2D array of characters
   box bb, wb, *board[8][8];

   // Fill in bb (black box) and wb (white box).

   for (i=0; i<5; i++)
      for (j=0; j<7; j++) {
         bb[i][j] = ' ';
         wb[i][j] = char(219);
      }

      // Create 2 more boxes to represent the queens, by drawing a picture of each queen in the 2D array.
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };

   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };

    // Fill board with pointers to bb and wb in alternate positions.
   for(i=0; i<8; i++)
      for(j=0; j<8; j++)
         if((i+j)%2 == 0)
            board[i][j] = &wb;
         else
            board[i][j] = &bb;

       // Place black queens on white squares and white queens on black squares, so that you will be able to see them when printing.
   for(i=0; i<8; i++)
      if((i+q[i])%2 == 0)
         board[q[i]][i] = &bq;
      else
         board[q[i]][i] = &wq;

    cout << "\n"<< "Solution Set# " << setNum++ <<endl;

    // Print upper border
   for (i=0; i<7*8; i++)
      cout << '_';
   cout << "\n";

   // Print the board
   for (i=0; i<8; i++)          // each board row
      for (k=0; k<5; k++) {     // each box row
         cout << char(179);
         for (j=0; j<8; j++)    // each board column
            for (l=0; l<7; l++) // each box column
		// board[i][j] is the box pointer in the i th row, j th column of the board.
               // *board[i][j] is the box being pointed to.
               // (*board[i][j])[k][l] is the kth row, lth column of the box.

               cout << (*board[i][j])[k][l];
         cout << char(179) << "\n";
      }

      // Print lower border
   cout << " ";
   for (i=0; i<7*8; i++)
      cout << char(196);
   cout << "\n\n";
}

 void backtrack(int &c){
    c--;
    if(c == -1)
        exit(1);

        }

int main() {
    int q[8];
    q[0]=0;
    int c = 0;
   //int setNum = 0;
   while (c <8) {
      if (c != 7) {
            q[++c] = -1;

      }
      else{
          print(q);
         backtrack(c);
      }


     while(q[c]<8){
         q[c]++;
         if (q[c] == 8){
            backtrack(c);
         }
         else if (ok(q, c)) //queen is ok then it will break and go beginnig of the loop
            break;
      }
   }
   return 0;
}

