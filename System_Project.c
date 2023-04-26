#include <stdio.h>
#include <stdlib.h>

int menu();

int main()
{
    while (1)
        {
        switch (menu())
            {
            case 1:printf("\t\t1\n"); system("pause");break;
            case 2:printf("\t\t2\n"); system("pause");break;
            case 3:printf("\t\t3\n"); system("pause");break;
            case 4:printf("\t\t4\n"); system("pause");break;
            case 5:printf("\t\t5\n"); system("pause");break;
            case 6:exit(0);
            default:printf("\nSelect 1-6 ONLY!\n"); system("pause");
            }
        }

}

int menu()
{
    int op;
    system("cls");
    printf("\tFurniture-Sales-and-Inventory-System\n\n");
    printf("\tMAIN MENU\n\n");
    printf("1.) Items\n");
    printf("2.) Customers\n");
    printf("3.) Sales\n");
    printf("4.) Receiving Items\n");
    printf("5.) Reposrts & Alerts\n");
    printf("6.) Exit\n");
    printf("Select: ");
    scanf("%d",&op);
    return op;
}
