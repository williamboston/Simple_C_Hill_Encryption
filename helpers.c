#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int get_m_val(int num)
{
    int ret_val;

    printf("Enter Key Matrix Value %d:\n", num);
    scanf("%d", &ret_val);

    return ret_val;
}

void matrix_transform(int *val1, int *val2, int matrix[], int *cipher_1, int *cipher_2)
{
    //assuming presence and preservation of spaces (mod 27)
    
    int one = ((matrix[0]*(*val1)) + (matrix[1]*(*val2)))%27;
    int two = ((matrix[2]*(*val1)) + (matrix[3]*(*val2)))%27;

    *cipher_1 = one;
    *cipher_2 = two;
}

char convert_to_char(int i)
{
    //no preservation of case

    if (i == 0)
    {
        return 'a';
    }
    else if (i == 1)
    {
        return 'b';
    }
    else if (i == 2)
    {
        return 'c';
    }
    else if (i == 3)
    {
        return 'd';
    }
    else if (i == 4)
    {
        return 'e';
    }
    else if (i == 5)
    {
        return 'f';
    }
    else if (i == 6)
    {
        return 'g';
    }
    else if (i == 7)
    {
        return 'h';
    }
    else if (i == 8)
    {
        return 'i';
    }
    else if (i == 9)
    {
        return 'j';
    }
    else if (i == 10)
    {
        return 'k';
    }
    else if (i == 11)
    {
        return 'l';
    }
    else if (i == 12)
    {
        return 'm';
    }
    else if (i == 13)
    {
        return 'n';
    }
    else if (i == 14)
    {
        return 'o';
    }
    else if (i == 15)
    {
        return 'p';
    }
    else if (i == 16)
    {
        return 'q';
    }
    else if (i == 17)
    {
        return 'r';
    }
    else if (i == 18)
    {
        return 's';
    }
    else if (i == 19)
    {
        return 't';
    }
    else if (i == 20)
    {
        return 'u';
    }
    else if (i == 21)
    {
        return 'v';
    }
    else if (i == 22)
    {
        return 'w';
    }
    else if (i == 23)
    {
        return 'x';
    }
    else if (i == 24)
    {
        return 'y';
    }
    else if (i == 25)
    {
        return 'z';
    }
    else if (i == 26)
    {
        return ' ';
    }
    else
    {
        return 0;
    }
}


int convert_to_int(char c)
{
    //size_t 27 alphabet

    if (c == 'a' || c == 'A')
    {
        return 0;
    }
    else if (c == 'b' || c == 'B')
    {
        return 1;
    }
    else if (c == 'c' || c == 'C')
    {
        return 2;
    }
    else if (c == 'd' || c == 'D')
    {
        return 3;
    }
    else if (c == 'e' || c == 'E')
    {
        return 4;
    }
    else if (c == 'f' || c == 'F')
    {
        return 5;
    }
    else if (c == 'g' || c == 'G')
    {
        return 6;
    }
    else if (c == 'h' || c == 'H')
    {
        return 7;
    }
    else if (c == 'i' || c == 'I')
    {
        return 8;
    }
    else if (c == 'j' || c == 'J')
    {
        return 9;
    }
    else if (c == 'k' || c == 'K')
    {
        return 10;
    }
    else if (c == 'l' || c == 'L')
    {
        return 11;
    }
    else if (c == 'm' || c == 'M')
    {
        return 12;
    }
    else if (c == 'n' || c == 'N')
    {
        return 13;
    }
    else if (c == 'o' || c == 'O')
    {
        return 14;
    }
    else if (c == 'p' || c == 'P')
    {
        return 15;
    }
    else if (c == 'q' || c == 'Q')
    {
        return 16;
    }
    else if (c == 'r' || c == 'R')
    {
        return 17;
    }
    else if (c == 's' || c == 'S')
    {
        return 18;
    }
    else if (c == 't' || c == 'T')
    {
        return 19;
    }
    else if (c == 'u' || c == 'U')
    {
        return 20;
    }
    else if (c == 'v' || c == 'V')
    {
        return 21;
    }
    else if (c == 'w' || c == 'W')
    {
        return 22;
    }
    else if (c == 'x' || c == 'X')
    {
        return 23;
    }
    else if (c == 'y' || c == 'Y')
    {
        return 24;
    }
    else if (c == 'z' || c == 'Z')
    {
        return 25;
    }
    else if (c == ' ')
    {
        return 26;
    }
    else
    {
        return 0;
    }
}