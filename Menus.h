#include <stdlib.h>
#include <stdio.h>

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
