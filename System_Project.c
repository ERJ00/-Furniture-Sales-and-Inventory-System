#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100 // Maximum number of items that can be received

// Struct for item information
typedef struct {
    char name[50];
    int quantity;
} Item;

// Struct for received item information
typedef struct {
    Item item;
    char date[20];
} ReceivedItem;

// Function to receive an item
void receiveItem(Item items[], int *numItems) {
    if (*numItems >= MAX_ITEMS) {
        printf("Maximum number of items reached!\n");
        return;
    }

    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);

    items[*numItems] = newItem;
    (*numItems)++;

    printf("Item received!\n");
}

// Function to display received item history
void displayHistory(ReceivedItem receivedItems[], int numReceivedItems) {
    printf("Received item history:\n");
    for (int i = 0; i < numReceivedItems; i++) {
        printf("Date: %s, Name: %s, Quantity: %d\n", receivedItems[i].date, receivedItems[i].item.name, receivedItems[i].item.quantity);
    }
}

int main() {
    Item items[MAX_ITEMS];
    int numItems = 0;

    ReceivedItem receivedItems[MAX_ITEMS];
    int numReceivedItems = 0;

    int choice;
    while (1) {
        printf("\n1. Receive item\n");
        printf("2. Display received item history\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                receiveItem(items, &numItems);
                // Add received item to history
                ReceivedItem receivedItem;
                strcpy(receivedItem.item.name, items[numItems-1].name);
                receivedItem.item.quantity = items[numItems-1].quantity;
                printf("Enter date (DD/MM/YYYY): ");
                scanf("%s", receivedItem.date);
                receivedItems[numReceivedItems] = receivedItem;
                numReceivedItems++;
                break;
            case 2:
                displayHistory(receivedItems, numReceivedItems);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
