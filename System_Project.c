#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int menus(int menu);
void item_menu();
void customer_menu();
void sales_menu();
void receiving_items_menu();
void reports_and_alerts_menu();

int main()
{
    while (1)
        {
        switch (menus(1))
            {
            case 1:item_menu(); break;
            case 2:customer_menu(); break;
            case 3:sales_menu(); break;
            case 4:receiving_items_menu(); break;
            case 5:reports_and_alerts_menu(); break;
            case 6:exit(0);
            default:printf("\nSelect 1-6 ONLY!\n"); system("pause");
            }
        }

}

int menus(int menu)
{
// main menu = 1
// item_menu = 2
// customer_menu = 3
// sales_menu = 4
// receiving_items_menu = 5
// reports_and_alerts_menu = 6
    int op;
    switch (menu)
        {
            case 1:// main menu 
                system("cls");
                printf("\tFurniture-Sales-and-Inventory-System\n\n");
                printf("\tMAIN MENU\n\n");
                printf("1.) Items\n");
                printf("2.) Customers\n");
                printf("3.) Sales\n");
                printf("4.) Receiving Items\n");
                printf("5.) Reports & Alerts\n");
                printf("6.) Exit\n");
                printf("Select: ");
                scanf("%d",&op);
                return op;
            break;

            case 2: // item_menu 
                system("cls");
                printf("\tFurniture-Sales-and-Inventory-System\n\n");
                printf("\tITEM MENU\n\n");
                printf("1.) Products Category\n");
                printf("2.) Product Encoding Form\n");
                printf("3.) Back to Main Menu\n");
                printf("Select: ");
                scanf("%d",&op);
                return op;
            break;

            case 3: // customer_menu 
                system("cls");
                printf("\tFurniture-Sales-and-Inventory-System\n\n");
                printf("\tCUSTOMER MENU\n\n");
                printf("1.) Customer Information Encoding Form\n");
                printf("2.) Customer Balance\n");
                printf("2.) Payment Form\n");
                printf("4.) Back to Main Menu\n");
                printf("Select: ");
                scanf("%d",&op);
                return op;
            break;

            case 4: // sales_menu 
                system("cls");
                printf("\tFurniture-Sales-and-Inventory-System\n\n");
                printf("\tSALES MENU\n\n");
                printf("1.) Point of Sale (POS) \n");
                printf("2.) Sales History Report\n");
                printf("3.) Back to Main Menu\n");
                printf("Select: ");
                scanf("%d",&op);
                return op;
            break;

            case 5: // receiving_items_menu = 5
                system("cls");
                printf("\tFurniture-Sales-and-Inventory-System\n\n");
                printf("\tRECIEVING ITEMS MENU\n\n");
                printf("1.) Received Items\n");
                printf("2.) Received History \n");
                printf("3.) Back to Main Menu\n");
                printf("Select: ");
                scanf("%d",&op);
                return op;
            break;

            case 6: // reports_and_alerts_menu 
                system("cls");
                printf("\tFurniture-Sales-and-Inventory-System\n\n");
                printf("\tREPORTS AND ALERTS MENU\n\n");
                printf("1.) Item Inventory / Inventory Report\n");
                printf("2.) Receivables / Accounts Receivable\n");
                printf("2.) Payment History\n");
                printf("4.) Back to Main Menu\n");
                printf("Select: ");
                scanf("%d",&op);
                return op;
            break;
        }
}

void item_menu()
{
    while (1)
    {
        switch (menus(2))
        {
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                return;
            break;
            
            default:printf("\nSelect 1-3 ONLY!\n"); system("pause");
        }
    }
}

void customer_menu()
{
    while (1)
    {
        switch (menus(3))
        {
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                printf("\t\t3\n"); system("pause");
            break;

            case 4: 
                return;
            break;
            
            default:printf("\nSelect 1-4 ONLY!\n"); system("pause");
        }
    }
}

void sales_menu()
{
    while (1)
    {
        switch (menus(4))
        {
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                return;
            break;
            
            default:printf("\nSelect 1-3 ONLY!\n"); system("pause");
        }
    }
}

void receiving_items_menu()
{
    while (1)
    {
        switch (menus(5))
        {
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                return;
            break;
            
            default:printf("\nSelect 1-3 ONLY!\n"); system("pause");
        }
    }
}

void reports_and_alerts_menu()
{
    while (1)
    {
        switch (menus(6))
        {
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                printf("\t\t3\n"); system("pause");
            break;

            case 4: 
                return;
            break;
            
            default:printf("\nSelect 1-4 ONLY!\n"); system("pause");
        }
    }
}

void gotoxy(int x,int y)
{
    COORD coordinate = {0,0};
    coordinate.X=x;
    coordinate.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinate);
}
