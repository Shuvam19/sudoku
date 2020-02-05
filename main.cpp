#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<sudoku1.h>
void main()
{
clrscr();
/* To Enter the values from User
   The blank space in the filling should be kept as zero */
filltable();
/*This function Mainly Checks all the possibilities and puts the right value */
shudoku(s);
clrscr();
/The Answer to Show the Table*/
showtable(s);
getch();
}
