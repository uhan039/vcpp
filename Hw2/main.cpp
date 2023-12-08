#include <stdio.h>
#include <conio.h>

int main()
{
    printf("  행복한 VC++ \n");

    int count = 0;
    char prev = 'a';
    char current = 'a';
    int err = 0;
    while (current != 27)
    {
        if (count == 0)
            printf("command>");
        prev = current;
        current = _getch();
        count++;

        if (current == 13)  //엔터라면
        {
            printf("\n");


            if (count == 2)
            {
                switch (prev)
                {
                case 'q':
                    printf("qwer 화이팅\n");
                    break;
                case 'w':
                    printf("과제 너무 좋다\n");
                    break;
                case 'e':
                    printf("담주부턴 과제량 3배다\n");
                    break;
                case 'r':
                    printf("행복합니다. \n");
                    break;
                default:
                    err = 1;
                    break;
                }
            }
            else
                err = 1;

            count = 0;

        }
        else
        {
            printf("%c", current);
        }

        if (err == 1)
        {
            printf("다시 입력해주세요.\n");
            err = 0;
        }





    }
    return 0;
}