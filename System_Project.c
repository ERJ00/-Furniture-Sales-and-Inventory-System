#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_ITEMS 100

void gotoxy(int x,int y);

// Struct for item information
typedef struct items {
    char name[50];
    int quantity;
} Item;

// Struct for received item information
typedef struct History_item {
    Item item;
    char date[20];
    struct History_item* next;
} ReceivedItem;

// Function to receive an item
void receiveItem(Item items[], int *numItems) {
    if (*numItems >= MAX_ITEMS) {
        printf("Maximum number of items reached!\n");
        return;
    }

    Item newItem;
    gotoxy(30, 5); printf("Enter item name: ");
    gotoxy(47, 5); scanf("%s", newItem.name);
    gotoxy(30, 7); printf("Enter quantity: ");
    gotoxy(47, 7); scanf("%d", &newItem.quantity);

    items[*numItems] = newItem;
    (*numItems)++;

    gotoxy(30, 9); printf("Item received!\n");

}

// Function to display received item history
void displayHistory(ReceivedItem receivedItems[], int numReceivedItems) {
    printf("Received item history:\n");
    for (int i = 0; i < numReceivedItems; i++) {
            system("cls");
            gotoxy(30, 5); printf("Date");
            gotoxy(45, 5); printf("Name");
            gotoxy(60, 5); printf("Quantity");
            gotoxy(27, 6);  printf("%s",receivedItems[i].date);
            gotoxy(44, 6);  printf("%s",receivedItems[i].item.name);
            gotoxy(63, 6);  printf("%d\n",receivedItems[i].item.quantity);

         gotoxy(56, 8); system("pause");

    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    ReceivedItem receivedItems[MAX_ITEMS];
    int numReceivedItems = 0;

    int choice;
    while (1) {
        system("cls");
        gotoxy(30, 5); printf("1. Receive item");
        gotoxy(30, 6); printf("2. Display received item history\n");
        gotoxy(30, 7); printf("3. Exit\n");
        gotoxy(30, 9); printf("Enter choice: ");
        gotoxy(44, 9); scanf("%d", &choice);

        switch (choice) {
            case 1:
                system("cls");
                receiveItem(items, &numItems);
                // Add received item to history
                ReceivedItem receivedItem;
                strcpy(receivedItem.item.name, items[numItems-1].name);
                receivedItem.item.quantity = items[numItems-1].quantity;
                gotoxy(30, 9); printf("Enter date (DD/MM/YYYY): ");
                scanf("%s", receivedItem.date);
                receivedItems[numReceivedItems] = receivedItem;
                numReceivedItems++;
                break;

            case 2:
                system("cls");
                displayHistory(receivedItems, numReceivedItems);
                break;
                system("cls");

            case 3:
                system("cls");
                exit(0);

            default:
                system("cls");
                printf("Invalid choice!\n");
        }
    }

    system("cls");

    return 0;
}

void saveHistory(ReceivedItem receivedItems[], int numReceivedItems) {
    FILE *fp;
    fp = fopen("received_items.txt", "w+");
    if (fp == NULL) {
        printf("Error: Failed to open file for writing.\n");
        return;
    }

    for (int i = 0; i < numReceivedItems; i++) {
        fprintf(fp, "%s,%s,%d\n", receivedItems[i].date, receivedItems[i].item.name, receivedItems[i].item.quantity);
    }

    fclose(fp);
    printf("Received item history saved to file.\n");
}

void retrieveHistory(ReceivedItem receivedItems[], int *numReceivedItems) {
    FILE *fp;
    fp = fopen("received_items.txt", "r+");
    if (fp == NULL) {
        printf("Error: Failed to open file for reading.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        char *token = strtok(line, ",");
        ReceivedItem receivedItem;
        strcpy(receivedItem.date, token);
        token = strtok(NULL, ",");
        strcpy(receivedItem.item.name, token);
        token = strtok(NULL, ",");
        receivedItem.item.quantity = atoi(token);
        receivedItems[*numReceivedItems] = receivedItem;
        (*numReceivedItems)++;
    }

    fclose(fp);
    printf("Received item history retrieved from file.\n");
}

void gotoxy(int x,int y)
{
    COORD coord = {0,0};
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
