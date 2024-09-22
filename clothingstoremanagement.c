#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

// Define a structure to represent a clothing item
struct ClothingItem {
    int code;                    // Item code
    char name[MAX_NAME_LENGTH];  // Item name
    float price;                // Item price
};

// Function to add a new clothing item to the store
void addItem(struct ClothingItem items[], int *count) {
    if (*count < MAX_ITEMS) {
        printf("Enter item code: ");
        scanf("%d", &items[*count].code);
        printf("Enter item name: ");
        scanf("%s", items[*count].name);
        printf("Enter item price: ");
        scanf("%f", &items[*count].price);
        (*count)++;
        printf("Item added successfully.\n");
    } else {
        printf("Store is full. Cannot add more items.\n");
    }
}

// Function to display all available clothing items
void displayItems(struct ClothingItem items[], int count) {
    printf("\nAvailable Items:\n");
    printf("Code\tName\tPrice\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t%.2f\n", items[i].code, items[i].name, items[i].price);
    }
}

// Function to search for a clothing item by its code
void searchItem(struct ClothingItem items[], int count, int code) {
    for (int i = 0; i < count; i++) {
        if (items[i].code == code) {
            printf("\nItem Found:\n");
            printf("Code: %d\n", items[i].code);
            printf("Name: %s\n", items[i].name);
            printf("Price: %.2f\n", items[i].price);
            return;
        }
    }
    printf("\nItem not found.\n");
}

// Function to edit the details of a clothing item
void editItem(struct ClothingItem items[], int count, int code) {
    for (int i = 0; i < count; i++) {
        if (items[i].code == code) {
            printf("\nEditing Item:\n");
            printf("Enter new name: ");
            scanf("%s", items[i].name);
            printf("Enter new price: ");
            scanf("%f", &items[i].price);
            printf("Item edited successfully.\n");
            return;
        }
    }
    printf("\nItem not found.\n");
}

// Function to delete a clothing item from the store
void deleteItem(struct ClothingItem items[], int *count, int code) {
    for (int i = 0; i < *count; i++) {
        if (items[i].code == code) {
            for (int j = i; j < *count - 1; j++) {
                items[j] = items[j + 1];
            }
            (*count)--;
            printf("\nItem deleted successfully.\n");
            return;
        }
    }
    printf("\nItem not found.\n");
}

int main() {
    struct ClothingItem items[MAX_ITEMS];  // Create an array to store clothing items
    int itemCount = 0;  // Track the number of items in the store
    int choice, searchCode;

    // Display a menu and handle user input
    do {
        printf("\nClothing Store Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Search Item\n");
        printf("4. Edit Item\n");
        printf("5. Delete Item\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem(items, &itemCount);
                break;
            case 2:
                displayItems(items, itemCount);
                break;
            case 3:
                printf("Enter item code to search: ");
                scanf("%d", &searchCode);
                searchItem(items, itemCount, searchCode);
                break;
            case 4:
                printf("Enter item code to edit: ");
                scanf("%d", &searchCode);
                editItem(items, itemCount, searchCode);
                break;
            case 5:
                printf("Enter item code to delete: ");
                scanf("%d", &searchCode);
                deleteItem(items, &itemCount, searchCode);
                break;
            case 6:
                printf("THANK YOU!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    printf("hello");

    return 0;
}
