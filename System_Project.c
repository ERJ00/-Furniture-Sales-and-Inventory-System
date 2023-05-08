#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include "Menus.h"

#define MAX 500

int bedroom_marker,living_room_marker, dining_room_marker, customer_marker, key = 5;

time_t current_time;
struct tm * time_info;

typedef struct PRODUCTS
{
    int ID, price, quantity;
    char product_name[50], brand[50], description[1000], category[50], supplier[50], date[11];
}product_data;

typedef struct CATEGORIES
{
    product_data bedroom[MAX];
    product_data living_room[MAX];
    product_data dining_room[MAX];
}category_data;
category_data item;

void product_category();
void inventory();
void product_encoding_form();
void received_history();
void gotoxy(int x, int y);


void init();
void add_product();
void retrieve_product();
void save();
void add_item(product_data data, int category);
int is_full(int category);
int check_product_ID(int ID, int category);
int menu();
int product_checker(char name[50], char brand[50], int category);
void save_delivered_transaction(product_data data);

int main()
{
    init();
    retrieve_product();
    while (1)
        {
        switch (menu())
            {
            case 1:product_category(); break;
            case 2:inventory(); break;
            case 3:product_encoding_form(); break;
            case 4:received_history(); break;
            case 5:exit(0);
            default:gotoxy(45,20);printf("Select 1-5 ONLY!");gotoxy(45,21);system("pause");
            }
        }
}

void init()
{
    bedroom_marker = -1;
    living_room_marker = -1;
    dining_room_marker = -1;
    srand(time(NULL));
    time(&current_time);
    time_info = localtime(&current_time);

}

int menu()
{
    int op;
    system("cls");
    gotoxy(40,2);printf("Furniture-Inventory-System");
    gotoxy(45,4);printf("MAIN MENU");
    gotoxy(30,7);printf("1.) Product  Category / Available Products");
    gotoxy(30,8);printf("2.) Product Inventory / Out of Stock Products");
    gotoxy(30,9);printf("3.) Received Product / Product Encoding Form\n");
    gotoxy(30,10);printf("4.) Received History");
    gotoxy(30,11);printf("5.) Exit");
    gotoxy(30,12);printf("Select: ");
    scanf("%d",&op);
    return op;
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

void product_category()
{
    int y_axis;
    system("cls");
    gotoxy(40,2);printf("Furniture-Inventory-System");
    gotoxy(44,3);printf("PRODUCT CATEGORY");

    //BEDROOM CATEGORY
    y_axis = categories_title("BEDROOM", 5);
    for (int i=0; i<=bedroom_marker; i++)
    {
        if (item.bedroom[i].quantity > 0) {
            gotoxy(8,y_axis); printf("%d",item.bedroom[i].ID);
            gotoxy(24,y_axis); printf("%s",item.bedroom[i].product_name);
            gotoxy(48,y_axis); printf("%d",item.bedroom[i].price);
            gotoxy(66,y_axis); printf("%s",item.bedroom[i].brand);
            gotoxy(88,y_axis); printf("%s",item.bedroom[i].description);
            y_axis++;
        }
    }

    //LIVING ROOM CATEGORY
    y_axis = categories_title("LIVING ROOM", y_axis+=2);
    for (int i=0; i<=living_room_marker; i++)
    {
        if (item.living_room[i].quantity > 0) {
            gotoxy(8,y_axis); printf("%d",item.living_room[i].ID);
            gotoxy(24,y_axis); printf("%s",item.living_room[i].product_name);
            gotoxy(48,y_axis); printf("%d",item.living_room[i].price);
            gotoxy(66,y_axis); printf("%s",item.living_room[i].brand);
            gotoxy(88,y_axis); printf("%s",item.living_room[i].description);
            y_axis++;
        }
    }

    //DINING ROOM CATEGORY
    y_axis = categories_title("DINING ROOM", y_axis+=2);
    for (int i=0; i<=dining_room_marker; i++)
    {
        if (item.dining_room[i].quantity > 0) {
            gotoxy(8,y_axis); printf("%d",item.dining_room[i].ID);
            gotoxy(24,y_axis); printf("%s",item.dining_room[i].product_name);
            gotoxy(48,y_axis); printf("%d",item.dining_room[i].price);
            gotoxy(66,y_axis); printf("%s",item.dining_room[i].brand);
            gotoxy(88,y_axis); printf("%s",item.dining_room[i].description);
            y_axis++;
        }
    }

    printf("\n\n");
    system("pause");
}

int product_checker(char name[50], char brand[50], int category)
{
    char nm[50], br[50];
    if (category == 1)
    {
        for(int i=0; i<=bedroom_marker; i++)
        {
            strcpy(nm,item.bedroom[i].product_name);
            strcpy(br,item.bedroom[i].brand);
            if((strcmp(strupr(nm), strupr(name)) == 0) && (strcmp(strupr(br), strupr(brand)) == 0))
            {
                return i;
            }
        }
        return -1;
    }
    else if (category == 2)
    {
        for(int i=0; i<=living_room_marker; i++)
        {
            strcpy(nm,item.living_room[i].product_name);
            strcpy(br,item.living_room[i].brand);
            if((strcmp(strupr(nm), strupr(name)) == 0) && (strcmp(strupr(br), strupr(brand)) == 0))
            {
                return i;
            }
        }
        return -1;
    }
    else if (category == 3)
    {
        for(int i=0; i<=dining_room_marker; i++)
        {
            strcpy(nm,item.dining_room[i].product_name);
            strcpy(br,item.dining_room[i].brand);
            if((strcmp(strupr(nm), strupr(name)) == 0) && (strcmp(strupr(br), strupr(brand)) == 0))
            {
                return i;
            }
        }
        return -1;
    }
}

void product_encoding_form()
{
    int selected, index;
    product_data temp;

    selected = select_category();

    if ((selected == 1) || (selected == 2) || (selected == 3))
    {
        system("cls");
        gotoxy(40,2);printf("Furniture-Inventory-System");
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
        gotoxy(30,13);printf("Supplier Name: ");
        gotoxy(60,13);scanf(" %[^\n]s", &temp.supplier);
        strftime(temp.date, sizeof(temp.date), "%Y-%m-%d", time_info);
        gotoxy(30,14);printf("Received Date: %s", temp.date);

        save_delivered_transaction(temp);
        index = product_checker(temp.product_name, temp.brand, selected);
        if (index == -1)
        {
            add_item(temp, selected);
            save();
            gotoxy(30,16);printf("Added New Product Successfully!");
            gotoxy(30,17);system("pause");
        }
        else
        {
            if (selected == 1)
            {
                item.bedroom[index].quantity += temp.quantity;
                item.bedroom[index].price = temp.price;
                strcpy(item.bedroom[index].date, temp.date);
                strcpy(item.bedroom[index].description, temp.description);
                strcpy(item.bedroom[index].supplier, temp.supplier);
            }
            else if (selected == 2)
            {
                item.living_room[index].quantity += temp.quantity;
                item.living_room[index].price = temp.price;
                strcpy(item.living_room[index].date, temp.date);
                strcpy(item.living_room[index].description, temp.description);
                strcpy(item.living_room[index].supplier, temp.supplier);
            }
            else if (selected == 3)
            {
                item.dining_room[index].quantity += temp.quantity;
                item.dining_room[index].price = temp.price;
                strcpy(item.dining_room[index].date, temp.date);
                strcpy(item.dining_room[index].description, temp.description);
                strcpy(item.dining_room[index].supplier, temp.supplier);
            }
            save();
            gotoxy(30,16);printf("Update Product Successfully!");
            gotoxy(30,17);system("pause");
        }

    }
    else
    {
        gotoxy(30,12);printf("Invalid Input");
        gotoxy(30,13);system("pause");
        product_encoding_form();
    }
}

void inventory()
{
    int y_axis;
    system("cls");
    gotoxy(40,2);printf("Furniture-Inventory-System");
    gotoxy(44,4);printf("INVENTORY PRODUCT");

    gotoxy(8,6);printf("ID");
    gotoxy(24,6);printf("PRODUCT NAME");
    gotoxy(48,6);printf("UNIT PRICE");
    gotoxy(66,6);printf("BRAND");
    gotoxy(88,6);printf("Quantity");
    gotoxy(108,6);printf("Category");

    y_axis = 8;
    for (int i=0; i<= bedroom_marker; i++)
    {
        if (item.bedroom[i].quantity == 0)
        {
            gotoxy(8,y_axis); printf("%d",item.bedroom[i].ID);
            gotoxy(24,y_axis); printf("%s",item.bedroom[i].product_name);
            gotoxy(48,y_axis); printf("%d",item.bedroom[i].price);
            gotoxy(66,y_axis); printf("%s",item.bedroom[i].brand);
            gotoxy(88,y_axis); printf("%d",item.bedroom[i].quantity);
            gotoxy(108,y_axis); printf("%s",item.bedroom[i].category);
            y_axis++;
        }
    }

    for (int i=0; i<= living_room_marker; i++)
    {
        if (item.living_room[i].quantity == 0)
        {
            gotoxy(8,y_axis); printf("%d",item.living_room[i].ID);
            gotoxy(24,y_axis); printf("%s",item.living_room[i].product_name);
            gotoxy(48,y_axis); printf("%d",item.living_room[i].price);
            gotoxy(66,y_axis); printf("%s",item.living_room[i].brand);
            gotoxy(88,y_axis); printf("%d",item.living_room[i].quantity);
            gotoxy(108,y_axis); printf("%s",item.living_room[i].category);
            y_axis++;
        }
    }
    for (int i=0; i<= dining_room_marker; i++)
    {
        if (item.dining_room[i].quantity == 0)
        {
            gotoxy(8,y_axis); printf("%d",item.dining_room[i].ID);
            gotoxy(24,y_axis); printf("%s",item.dining_room[i].product_name);
            gotoxy(48,y_axis); printf("%d",item.dining_room[i].price);
            gotoxy(66,y_axis); printf("%s",item.dining_room[i].brand);
            gotoxy(88,y_axis); printf("%d",item.dining_room[i].quantity);
            gotoxy(108,y_axis); printf("%s",item.dining_room[i].category);
            y_axis++;
        }
    }
    gotoxy(50,y_axis+3);system("pause");
}

void received_history()
{
    FILE *fp;
    char line[256];
    int y_axis = 6;
    system("cls");
    gotoxy(40,2);printf("Furniture-Inventory-System");
    gotoxy(44,4);printf("RECEIVED HISTORY");

    fp = fopen("Delivered_Log.txt", "r");
    if (fp == NULL)
    {
        gotoxy(50,y_axis);printf("Failed to open the file.\n");
        return 1;
    }
    else
    {
        while (fgets(line, sizeof(line), fp) != NULL)
        {
            gotoxy(20,y_axis);printf("%s", line);
            y_axis++;
        }
    }

    fclose(fp);
    gotoxy(50,y_axis+3);system("pause");
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
            fscanf(fp," %[^\n]s\n",temp.supplier);
            fscanf(fp," %[^\n]s\n",temp.date);

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
    fp = fopen("Product_data.txt","w");
    if(fp==NULL)
    {
        printf("File error.\n");
        system("pause");
    }

    else
    {
        for(int i=0; i<=bedroom_marker; i++)
        {
            fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s\n%s\n%s\n", item.bedroom[i].ID,  item.bedroom[i].product_name,  item.bedroom[i].price,  item.bedroom[i].brand,  item.bedroom[i].description, item.bedroom[i].quantity, item.bedroom[i].category, item.bedroom[i].supplier, item.bedroom[i].date);
        }
        for(int i=0; i<=living_room_marker; i++)
        {
            fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s\n%s\n%s\n", item.living_room[i].ID,  item.living_room[i].product_name,  item.living_room[i].price,  item.living_room[i].brand,  item.living_room[i].description, item.living_room[i].quantity, item.living_room[i].category, item.living_room[i].supplier, item.living_room[i].date);
        }
        for(int i=0; i<=dining_room_marker; i++)
        {
            if (i == dining_room_marker)
            {
                fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s\n%s\n%s", item.dining_room[i].ID,  item.dining_room[i].product_name,  item.dining_room[i].price,  item.dining_room[i].brand,  item.dining_room[i].description, item.dining_room[i].quantity, item.dining_room[i].category, item.dining_room[i].supplier, item.dining_room[i].date);
            }
            else
            {
                fprintf(fp,"%d\n%s\n%d\n%s\n%s\n%d\n%s\n%s\n%s\n", item.dining_room[i].ID,  item.dining_room[i].product_name,  item.dining_room[i].price,  item.dining_room[i].brand,  item.dining_room[i].description, item.dining_room[i].quantity, item.dining_room[i].category, item.dining_room[i].supplier, item.dining_room[i].date);
            }
        }
        fclose(fp);
    }
}

void save_delivered_transaction(product_data data)
{
    FILE *fp;
    fp = fopen("Delivered_Log.txt","ab");
    if(fp==NULL)
    {
        printf("File error.\n");
        system("pause");
    }

    else
    {
        fprintf(fp,"\n[ %s ] | Item = %s | Brand = %s | Quantity = %d | Unit Price = %d | Supplier = %s", data.date, data.product_name, data.brand, data.quantity, data.price, data.supplier);
        fclose(fp);
    }
}
