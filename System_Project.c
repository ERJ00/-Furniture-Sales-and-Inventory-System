#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "Menus.h"

#define MAX 500
int bedroom_marker,living_room_marker, dining_room_marker;

typedef struct PRODUCTS
{
    int ID, price, quantity;
    char product_name[50], brand[50], description[1000], category[50];
}product_data;

typedef struct CATEGORIES
{
    product_data bedroom[MAX];
    product_data living_room[MAX];
    product_data dining_room[MAX];
}category_data;
category_data item;

void item_menu();
void customer_menu();
void sales_menu();
void receiving_items_menu();
void reports_and_alerts_menu();
void gotoxy(int x, int y);

void product_category();
void product_encoding_form();
void init();
void add_product();
void retrieve_product();
void save();
void add_item(product_data data, int category);
int is_full(int category);
int check_product_ID(int ID, int category);

int main()
{
    init();
    retrieve_product();
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
    bedroom_marker = -1;
    living_room_marker = -1;
    dining_room_marker = -1;
    srand(time(NULL));
}

int is_full(int category)
{
    if(category == 1)
    {
        if(bedroom_marker == MAX-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(category == 2)
    {
        if(living_room_marker == MAX-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else if(category == 3)
    {
        if(dining_room_marker == MAX-1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int check_product_ID(int ID, int category)
{
    if (category == 1)
    {
        for (int i=0; i <= bedroom_marker; i++)
        {
            if (item.bedroom[i].ID == ID)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else if (category == 2)
    {
        for (int i=0; i <= living_room_marker; i++)
        {
            if (item.living_room[i].ID == ID)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
    else if (category == 3)
    {
        for (int i=0; i<=dining_room_marker; i++)
        {
            if (item.dining_room[i].ID == ID)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
    }
}

void add_item(product_data data, int category)
{
    if (is_full(category) == 1)
    {
        system("cls");
        printf("\n\n\tTHE STORAGE OF THE IS FULL.\n");
        system("pause");
    }
    else
    {

        if (category == 1)
        {
            if (check_product_ID(data.ID, category) == 1)
            {
                return;
            }
            else
            {
                bedroom_marker++;
                item.bedroom[bedroom_marker] = data;
            }
        }
        else if (category == 2)
        {
            if (check_product_ID(data.ID, category) == 1)
            {
                return;
            }
            else
            {
                living_room_marker++;
                item.living_room[living_room_marker] = data;
            }
        }
        else if (category == 3)
        {
            if (check_product_ID(data.ID, category) == 1)
            {
                return;
            }
            else
            {
                dining_room_marker++;
                item.dining_room[dining_room_marker] = data;
            }
        }
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
                product_encoding_form();
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
    int y_axis;
    system("cls");
    gotoxy(35,2);printf("Furniture-Sales-and-Inventory-System");
    gotoxy(44,3);printf("PRODUCT CATEGORY");

    //BEDROOM CATEGORY
    y_axis = categories_title("BEDROOM", 5);
    for (int i=0; i<=bedroom_marker; i++)
    {
        gotoxy(8,y_axis); printf("%d",item.bedroom[i].ID);
        gotoxy(24,y_axis); printf("%s",item.bedroom[i].product_name);
        gotoxy(48,y_axis); printf("%d",item.bedroom[i].price);
        gotoxy(66,y_axis); printf("%s",item.bedroom[i].brand);
        gotoxy(88,y_axis); printf("%s",item.bedroom[i].description);
        y_axis++;
    }

    //LIVING ROOM CATEGORY
    y_axis = categories_title("LIVING ROOM", y_axis+=2);
    for (int i=0; i<=living_room_marker; i++)
    {
        gotoxy(8,y_axis); printf("%d",item.living_room[i].ID);
        gotoxy(24,y_axis); printf("%s",item.living_room[i].product_name);
        gotoxy(48,y_axis); printf("%d",item.living_room[i].price);
        gotoxy(66,y_axis); printf("%s",item.living_room[i].brand);
        gotoxy(88,y_axis); printf("%s",item.living_room[i].description);
        y_axis++;
    }

    //DINING ROOM CATEGORY
    y_axis = categories_title("DINING ROOM", y_axis+=2);
    for (int i=0; i<=dining_room_marker; i++)
    {
        gotoxy(8,y_axis); printf("%d",item.dining_room[i].ID);
        gotoxy(24,y_axis); printf("%s",item.dining_room[i].product_name);
        gotoxy(48,y_axis); printf("%d",item.dining_room[i].price);
        gotoxy(66,y_axis); printf("%s",item.dining_room[i].brand);
        gotoxy(88,y_axis); printf("%s",item.dining_room[i].description);
        y_axis++;
    }

    printf("\n\n");
    system("pause");
}

void product_encoding_form()
{
    int selected;
    product_data temp;

    selected = select_category();

    if ((selected == 1) || (selected == 2) || (selected == 3))
    {
        system("cls");
        gotoxy(35,2);printf("Furniture-Sales-and-Inventory-System");
        gotoxy(44,4);printf("PRODUCT ENCODING FORM");

        if (selected == 1)
        {
            strcpy(temp.category, "BEDROOM");
            gotoxy(44,6);printf("Product Category: Bedroom");
        }
        else if (selected == 2)
        {
            strcpy(temp.category, "LIVING ROOM");
            gotoxy(44,6);printf("Product Category: Living Room");
        }
        else if (selected == 3)
        {
            strcpy(temp.category, "DINING ROOM");
            gotoxy(44,6);printf("Product Category: Dining Room");
        }
        do{
        temp.ID = rand()%9999+1111;
        } while (check_product_ID(temp.ID, selected) == 1);

        gotoxy(30,7);printf("Product ID: %d", temp.ID);
        gotoxy(30,8);printf("Product Name: ");
        gotoxy(60,8);scanf(" %[^\n]s", temp.product_name);
        gotoxy(30,9);printf("Product Brand: ");
        gotoxy(60,9);scanf(" %[^\n]s", temp.brand);
        gotoxy(30,10);printf("Product Price: ");
        gotoxy(60,10);scanf(" %d", &temp.price);
        gotoxy(30,11);printf("Product Description: ");
        gotoxy(60,11);scanf(" %[^\n]s", temp.description);
        gotoxy(30,12);printf("Product Quantity: ");
        gotoxy(60,12);scanf(" %d", &temp.quantity);
        add_item(temp, selected);
        save();
        gotoxy(30,15);printf("Added Product Successfully!");
        gotoxy(30,16);system("pause");
    }
    else
    {
        gotoxy(30,12);printf("Invalid Input");
        gotoxy(30,13);system("pause");
        product_encoding_form();
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

void retrieve_product()
{
    // 1 = bedroom
    // 2 = living room
    // 3 = dining room

    FILE *fp;
    product_data temp;
    fp = fopen("Product_data.txt","r");
    if (fp)
    {
        while (!feof(fp))
        {
            fscanf(fp," %d\n", &temp.ID);
            fscanf(fp," %[^\n]s\n", temp.product_name);
            fscanf(fp," %d\n", &temp.price);
            fscanf(fp," %[^\n]s\n",temp.brand);
            fscanf(fp," %[^\n]s\n",temp.description);
            fscanf(fp," %d\n", &temp.quantity);
            fscanf(fp," %[^\n]s\n",temp.category);

            if (strcmp(temp.category, "BEDROOM") == 0)
            {
                add_item(temp, 1);
            }
            else if (strcmp(temp.category, "LIVING ROOM") == 0)
            {
                add_item(temp, 2);
            }
            else if (strcmp(temp.category, "DINING ROOM") == 0)
            {
                add_item(temp, 3);
            }
        }
        fclose(fp);
    }
    else
    {
        system("cls");
        printf("File not found!.\n");
        system("pause");
    }
}

void save()
{
    FILE *fp;
    char filename[] ="Product_data.txt";
    fp = fopen(filename,"w");
    if(fp==NULL)
    {
        printf("File error.\n");
        system("pause");
    }

    else
    {
        for(int i=0; i<=bedroom_marker; i++)
        {
            fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s\n", item.bedroom[i].ID,  item.bedroom[i].product_name,  item.bedroom[i].price,  item.bedroom[i].brand,  item.bedroom[i].description, item.bedroom[i].quantity, item.bedroom[i].category);
        }
        for(int i=0; i<=living_room_marker; i++)
        {
            fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s\n", item.living_room[i].ID,  item.living_room[i].product_name,  item.living_room[i].price,  item.living_room[i].brand,  item.living_room[i].description, item.living_room[i].quantity, item.living_room[i].category);
        }
        for(int i=0; i<=dining_room_marker; i++)
        {
            if (i == dining_room_marker)
            {
                fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s", item.dining_room[i].ID,  item.dining_room[i].product_name,  item.dining_room[i].price,  item.dining_room[i].brand,  item.dining_room[i].description, item.dining_room[i].quantity, item.dining_room[i].category);
            }
            else
            {
                fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s\n", item.dining_room[i].ID,  item.dining_room[i].product_name,  item.dining_room[i].price,  item.dining_room[i].brand,  item.dining_room[i].description, item.dining_room[i].quantity, item.dining_room[i].category);
            }
       }
        fclose(fp);
    }
}
