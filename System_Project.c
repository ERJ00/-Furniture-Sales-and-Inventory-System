#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

#define MAX 100
int marker;

typedef struct BEDROOM
{
    int ID, price;
    char product_name[50], brand[50], description[10];
}DATAs;
DATAs bedroom[MAX];

int menus(int menu);
void item_menu();
void customer_menu();
void sales_menu();
void receiving_items_menu();
void reports_and_alerts_menu();
void gotoxy(int x, int y);

void product_category();
void init();
void add_product();
void retrieve_products();
void add_item(DATAs data);
int is_full();

int main()
{
    init();
    retrieve_products();
    product_category();
    system("\npause");
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

void init()
{
    marker = -1;
}

int is_full()
{
    if(marker == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void add_item(DATAs data)
{
    if (is_full() == 1)
    {
        system("cls");
        printf("\n\n\tTHE STORAGE OF THE IS FULL.\n");
        system("pause");
    }
    else
    {
        marker++;
        if (check_product_name(data.product_name) == 1)
        {
            marker--;
        }
        else
        {
            bedroom[marker] = data;
        }
    }
}

int check_product_name(char name[])
{
    for (int i = 0; i <= marker; i++)
    {
        if ((strcmp(strupr(bedroom[i].product_name), strupr(name))) == 0)
        {
            return 1;
        }
    }
    return 0;
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
                product_category();
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

void product_category()
{
    system("cls");
    gotoxy(35,2);printf("Furniture-Sales-and-Inventory-System");
    gotoxy(44,3);printf("PRODUCT CATEGORY");

    //BEDROOM CATEGORY
    gotoxy(2,5);printf("Bedroom Category");

    gotoxy(8,7);printf("ID");
    gotoxy(24,7);printf("PRODUCT NAME");
    gotoxy(48,7);printf("PRICE");
    gotoxy(66,7);printf("BRAND");
    gotoxy(88,7);printf("DESCRIPTION");

    for (int i=0; i<MAX; i++)
    {
        gotoxy(8,8+i); printf("%d",bedroom[i].ID);
        gotoxy(24,8+i); printf("%s",bedroom[i].product_name);
        gotoxy(48,8+i); printf("%d",bedroom[i].price);
        gotoxy(66,8+i); printf("%s",bedroom[i].brand);
        gotoxy(88,8+i); printf("%s",bedroom[i].description);
    }
    

    // gotoxy(8,7);printf("10001");
    // gotoxy(8,8);printf("10002");
    // gotoxy(8,9);printf("10003");
    // gotoxy(8,10);printf("10004");

    // gotoxy(24,7);printf("Cabinets");
    // gotoxy(24,8);printf("Study Table");
    // gotoxy(24,9);printf("Bed Frame");
    // gotoxy(24,10);printf("Vanity Mirror");

    // gotoxy(47,7);printf("P 1500");
    // gotoxy(47,8);printf("P 1500");
    // gotoxy(47,9);printf("P 1500");
    // gotoxy(47,10);printf("P 1500");

    // gotoxy(65,7);printf("Brand X");
    // gotoxy(65,8);printf("Brand X");
    // gotoxy(65,9);printf("Brand X");
    // gotoxy(65,10);printf("Brand X");

    // gotoxy(88,7);printf("asdasdasd");
    // gotoxy(88,8);printf("asdasdasd");
    // gotoxy(88,9);printf("asdasdasd");
    // gotoxy(88,10);printf("asdasdasd");

    // //LIVING ROOM CATEGORY
    // gotoxy(2,12);printf("Living room Category");
    // gotoxy(8,13);printf("ID");
    // gotoxy(24,13);printf("PRODUCT NAME");
    // gotoxy(48,13);printf("PRICE");
    // gotoxy(66,13);printf("BRAND");
    // gotoxy(88,13);printf("DESCRIPTION");

    // gotoxy(8,14);printf("10005");
    // gotoxy(8,15);printf("10006");
    // gotoxy(8,16);printf("10007");
    // gotoxy(8,17);printf("10008");

    // gotoxy(24,14);printf("Sofa");
    // gotoxy(24,15);printf("TV Stand");
    // gotoxy(24,16);printf("Table");
    // gotoxy(24,17);printf("Bookshelf");

    // gotoxy(47,14);printf("P 1500");
    // gotoxy(47,15);printf("P 1500");
    // gotoxy(47,16);printf("P 1500");
    // gotoxy(47,17);printf("P 1500");

    // gotoxy(65,14);printf("Brand X");
    // gotoxy(65,15);printf("Brand X");
    // gotoxy(65,16);printf("Brand X");
    // gotoxy(65,17);printf("Brand X");

    // gotoxy(88,14);printf("asdasdasd");
    // gotoxy(88,15);printf("asdasdasd");
    // gotoxy(88,16);printf("asdasdasd");
    // gotoxy(88,17);printf("asdasdasd");

    // //DINING ROOM
    // gotoxy(2,19);printf("Dining room Category");
    // gotoxy(8,20);printf("ID");
    // gotoxy(24,20);printf("PRODUCT NAME");
    // gotoxy(48,20);printf("PRICE");
    // gotoxy(66,20);printf("BRAND");
    // gotoxy(88,20);printf("DESCRIPTION");

    // gotoxy(8,21);printf("10009");
    // gotoxy(8,22);printf("100010");
    // gotoxy(8,23);printf("100011");
    // gotoxy(8,24);printf("100012");

    // gotoxy(24,21);printf("Dining Table");
    // gotoxy(24,22);printf("Bar Carts");
    // gotoxy(24,23);printf("Pantry Cabinets");
    // gotoxy(24,24);printf("Bar Stools");

    // gotoxy(47,21);printf("P 1500");
    // gotoxy(47,22);printf("P 1500");
    // gotoxy(47,23);printf("P 1500");
    // gotoxy(47,24);printf("P 1500");

    // gotoxy(65,21);printf("Brand X");
    // gotoxy(65,22);printf("Brand X");
    // gotoxy(65,23);printf("Brand X");
    // gotoxy(65,24);printf("Brand X");

    // gotoxy(88,21);printf("asdasdasd");
    // gotoxy(88,22);printf("asdasdasd");
    // gotoxy(88,23);printf("asdasdasd");
    // gotoxy(88,24);printf("asdasdasd");

    // gotoxy(2,26);printf("Input Product ID: ");
    // scanf("%d",&prod_id);
    // gotoxy(2,27);printf("Input Quantity: ");
    // scanf("%d",&quantity);
    // gotoxy(2,29);system("pause");
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

void retrieve_products()
{
    FILE *fp;
    DATAs temp;
    fp = fopen("Bedroom.txt","r");
    if (fp==NULL){
        printf("File not found!.\n");
        system("pause");
        exit(0);
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp," %d", &temp.ID);
            fscanf(fp," %[^\n]s\n", temp.product_name);
            fscanf(fp," %d", &temp.price);
            fscanf(fp," %[^\n]s\n",temp.brand);
            fscanf(fp," %[^\n]s\n",temp.description);
            add_item(temp);
        }
        fclose(fp);
    }
}
