#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int menus(int menu);
void item_menu();
void customer_menu();
void sales_menu();
void receiving_items_menu();
void reports_and_alerts_menu();
<<<<<<< HEAD
=======
void gotoxy(int x, int y);

>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8

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
<<<<<<< HEAD
            case 1:// main menu 
=======
            case 1:// main menu
>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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

<<<<<<< HEAD
            case 2: // item_menu 
=======
            case 2: // item_menu
>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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

<<<<<<< HEAD
            case 3: // customer_menu 
=======
            case 3: // customer_menu
>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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

<<<<<<< HEAD
            case 4: // sales_menu 
=======
            case 4: // sales_menu
>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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

<<<<<<< HEAD
            case 6: // reports_and_alerts_menu 
=======
            case 6: // reports_and_alerts_menu
>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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
<<<<<<< HEAD
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                return;
            break;
            
=======
            case 1:
                product_category();
            break;

            case 2:
                printf("\t\t2\n"); system("pause");
            break;

            case 3:
                return;
            break;

>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
            default:printf("\nSelect 1-3 ONLY!\n"); system("pause");
        }
    }
}

<<<<<<< HEAD
=======
void product_category()
{
    int prod_id,quantity;

    system("cls");
    gotoxy(35,2);printf("Furniture-Sales-and-Inventory-System");
    gotoxy(44,3);printf("PRODUCT CATEGORY");

    //BEDROOM CATEGORY
    gotoxy(2,5);printf("Bedroom Category");
    gotoxy(8,6);printf("ID");
    gotoxy(24,6);printf("PRODUCT NAME");
    gotoxy(48,6);printf("PRICE");
    gotoxy(66,6);printf("BRAND");
    gotoxy(88,6);printf("DESCRIPTION");

    gotoxy(8,7);printf("10001");
    gotoxy(8,8);printf("10002");
    gotoxy(8,9);printf("10003");
    gotoxy(8,10);printf("10004");

    gotoxy(24,7);printf("Cabinets");
    gotoxy(24,8);printf("Study Table");
    gotoxy(24,9);printf("Bed Frame");
    gotoxy(24,10);printf("Vanity Mirror");

    gotoxy(47,7);printf("P 1500");
    gotoxy(47,8);printf("P 1500");
    gotoxy(47,9);printf("P 1500");
    gotoxy(47,10);printf("P 1500");

    gotoxy(65,7);printf("Brand X");
    gotoxy(65,8);printf("Brand X");
    gotoxy(65,9);printf("Brand X");
    gotoxy(65,10);printf("Brand X");

    gotoxy(88,7);printf("asdasdasd");
    gotoxy(88,8);printf("asdasdasd");
    gotoxy(88,9);printf("asdasdasd");
    gotoxy(88,10);printf("asdasdasd");

    //LIVING ROOM CATEGORY
    gotoxy(2,12);printf("Living room Category");
    gotoxy(8,13);printf("ID");
    gotoxy(24,13);printf("PRODUCT NAME");
    gotoxy(48,13);printf("PRICE");
    gotoxy(66,13);printf("BRAND");
    gotoxy(88,13);printf("DESCRIPTION");

    gotoxy(8,14);printf("10005");
    gotoxy(8,15);printf("10006");
    gotoxy(8,16);printf("10007");
    gotoxy(8,17);printf("10008");

    gotoxy(24,14);printf("Sofa");
    gotoxy(24,15);printf("TV Stand");
    gotoxy(24,16);printf("Table");
    gotoxy(24,17);printf("Bookshelf");

    gotoxy(47,14);printf("P 1500");
    gotoxy(47,15);printf("P 1500");
    gotoxy(47,16);printf("P 1500");
    gotoxy(47,17);printf("P 1500");

    gotoxy(65,14);printf("Brand X");
    gotoxy(65,15);printf("Brand X");
    gotoxy(65,16);printf("Brand X");
    gotoxy(65,17);printf("Brand X");

    gotoxy(88,14);printf("asdasdasd");
    gotoxy(88,15);printf("asdasdasd");
    gotoxy(88,16);printf("asdasdasd");
    gotoxy(88,17);printf("asdasdasd");

    //DINING ROOM
    gotoxy(2,19);printf("Dining room Category");
    gotoxy(8,20);printf("ID");
    gotoxy(24,20);printf("PRODUCT NAME");
    gotoxy(48,20);printf("PRICE");
    gotoxy(66,20);printf("BRAND");
    gotoxy(88,20);printf("DESCRIPTION");

    gotoxy(8,21);printf("10009");
    gotoxy(8,22);printf("100010");
    gotoxy(8,23);printf("100011");
    gotoxy(8,24);printf("100012");

    gotoxy(24,21);printf("Dining Table");
    gotoxy(24,22);printf("Bar Carts");
    gotoxy(24,23);printf("Pantry Cabinets");
    gotoxy(24,24);printf("Bar Stools");

    gotoxy(47,21);printf("P 1500");
    gotoxy(47,22);printf("P 1500");
    gotoxy(47,23);printf("P 1500");
    gotoxy(47,24);printf("P 1500");

    gotoxy(65,21);printf("Brand X");
    gotoxy(65,22);printf("Brand X");
    gotoxy(65,23);printf("Brand X");
    gotoxy(65,24);printf("Brand X");

    gotoxy(88,21);printf("asdasdasd");
    gotoxy(88,22);printf("asdasdasd");
    gotoxy(88,23);printf("asdasdasd");
    gotoxy(88,24);printf("asdasdasd");

    gotoxy(2,26);printf("Input Product ID: ");
    scanf("%d",&prod_id);
    gotoxy(2,27);printf("Input Quantity: ");
    scanf("%d",&quantity);
    gotoxy(2,29);system("pause");
}

>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
void customer_menu()
{
    while (1)
    {
        switch (menus(3))
        {
<<<<<<< HEAD
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
            
=======
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

>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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
<<<<<<< HEAD
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                return;
            break;
            
=======
            case 1:
                printf("\t\t1\n"); system("pause");
            break;

            case 2:
                printf("\t\t2\n"); system("pause");
            break;

            case 3:
                return;
            break;

>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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
<<<<<<< HEAD
            case 1: 
                printf("\t\t1\n"); system("pause");
            break;

            case 2: 
                printf("\t\t2\n"); system("pause");
            break;

            case 3: 
                return;
            break;
            
=======
            case 1:
                printf("\t\t1\n"); system("pause");
            break;

            case 2:
                printf("\t\t2\n"); system("pause");
            break;

            case 3:
                return;
            break;

>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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
<<<<<<< HEAD
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
            
=======
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

>>>>>>> e9728615869d30b64fd155edaac4148c43e696d8
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
