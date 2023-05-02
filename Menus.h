#include <stdlib.h>
#include <stdio.h>

int menus(int menu);
int categories_title(char name[50], int y_axis);
int select_category();

int select_category()
{
    int selected;
    system("cls");
    gotoxy(35,2);printf("Furniture-Sales-and-Inventory-System");
    gotoxy(44,4);printf("PRODUCT ENCODING FORM");

    gotoxy(30,6);printf("1.) Bedroom");
    gotoxy(30,7);printf("2.) Living Room");
    gotoxy(30,8);printf("3.) Dining Room");
    gotoxy(30,10);printf("Select Category From 1-3");
    gotoxy(60,10);scanf("%d", &selected);
    return selected;
}

int categories_title(char name[50], int y_axis)
{
    gotoxy(2,y_axis);printf(name);
    y_axis+=2;
    gotoxy(8,y_axis);printf("ID");
    gotoxy(24,y_axis);printf("PRODUCT NAME");
    gotoxy(48,y_axis);printf("PRICE");
    gotoxy(66,y_axis);printf("BRAND");
    gotoxy(88,y_axis);printf("DESCRIPTION");

    return y_axis+=2;
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