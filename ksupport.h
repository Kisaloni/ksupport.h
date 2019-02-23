#ifndef KSUPPORT_H_INCLUDED
#define KSUPPORT_H_INCLUDED

/*
*place ksupport.h in include folder of compiler
*if you're using #include<ksupport.h>
*or place ksupport.h in the folder where your source file is placed
*if you're using #include"ksupport.h"
*/

#include<windows.h>
/************************************************************************************/
void Set_col(int bg,int t);
void Set_tcol(int t);
void gotoxy(int x,int y);
/************************************************************************************/
void gotoxy(int x,int y)
{
    COORD c;
    fflush(stdout);
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
/************************************************************************************/
int _b_g=15;
void Set_col(int bg,int t)
{
    if((bg<0||bg>15)||(t<0||t>15))
    {
        Set_tcol(0);
        printf("Invalid input to void Set_col(int,int) !");
    }
    else
    {
        _b_g=bg;
        char *Bg_color[16]={"COLOR 0F","COLOR 1F","COLOR 2f","COLOR 3f","COLOR 4f","COLOR 5F",\
        "COLOR 6F","COLOR 7F","COLOR 8F","COLOR 9F","COLOR AF","COLOR BF","COLOR CF",\
        "COLOR DF","COLOR EF","COLOR F1"};
        system(Bg_color[_b_g]);
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int txt=_b_g*16+t;
        SetConsoleTextAttribute(hConsole,txt);
    }
}
/************************************************************************************/
void Set_tcol(int t)
{
    if((t<0||t>15))
    {
        Set_tcol(0);
        printf("Invalid input to void Set_col(int,int) !");
    }
    else
    {
        HANDLE hConsole;
        hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        int txt=_b_g*16+t;
        SetConsoleTextAttribute(hConsole,txt);
    }
}
/************************************************************************************/
/*
*****************
Name | Value
|
Black | 0
Blue | 1
Green | 2
Cyan | 3
Red | 4
Magenta | 5
Brown | 6
Light Gray | 7
Dark Gray | 8
Light Blue | 9
Light Green | 10/A
Light Cyan | 11/B
Light Red | 12/C
Light Magenta| 13/D
Yellow | 14/E
White | 15/F
*****************
*/

/************************************************************************************/

#endif // KSUPPORT_H_INCLUDED
/************************************************************************************/
