#include <stdio.h>
#include <stdlib.h>

void checkPalindrome(char kata_yg_dicek[], int index)
{
    int len = strlen(kata_yg_dicek) - (index + 1);
    if (kata_yg_dicek[index] == kata_yg_dicek[len])
    {
        index += 1;
        if(len - index <= 1)
        {
            printf("Palindrom\n");
            return;
        }
        checkPalindrome(kata_yg_dicek, index);
    }
    else
    {
        printf("Bukan palindrom\n");
    }
}

int main()
{
    int index = 0;
    char kata[255];
    printf("aaaa : ");
    scanf("%s", kata);
    checkPalindrome(kata,index);
}
