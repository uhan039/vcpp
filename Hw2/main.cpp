#include <stdio.h>
#include <conio.h>

int main()
{
    printf("  �ູ�� VC++ \n");

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

        if (current == 13)  //���Ͷ��
        {
            printf("\n");


            if (count == 2)
            {
                switch (prev)
                {
                case 'q':
                    printf("qwer ȭ����\n");
                    break;
                case 'w':
                    printf("���� �ʹ� ����\n");
                    break;
                case 'e':
                    printf("���ֺ��� ������ 3���\n");
                    break;
                case 'r':
                    printf("�ູ�մϴ�. \n");
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
            printf("�ٽ� �Է����ּ���.\n");
            err = 0;
        }





    }
    return 0;
}