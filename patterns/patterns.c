// hallow Square
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 || i == n || j == 1 || j == n)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// hallow rectangle
#include <stdio.h>
int main()
{
    int row, column;
    scanf("%d %d", &row, &column);
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= column; j++)
        {
            if (i == 1 || i == row || j == 1 || j == column)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
// hallow square with diagonal
#include <stdio.h>
int main()
{
    int row;
    scanf("%d", &row);
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= row; j++)
        {
            if (i == 1 || i == row || j == 1 || j == row || i == j || j == (row - i + 1))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
// hallow rhombus
#include <stdio.h>
int main()
{
    int row;
    scanf("%d", &row);
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= (row - i); j++)
        {
            printf("  ");
        }
        for (int k = 1; k <= row; k++)
        {
            if (i == 1 || k == 1 || i == row || k == row)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}
// mirror hallow right triangle
#include <stdio.h>
int main()
{
    int row;
    scanf("%d", &row);
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= (row - i); j++)
        {
            printf("  ");
        }
        for (int k = 1; k <= row; k++)
        {
            if (i == 1 || k == 1 || i == row || k == row)
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}