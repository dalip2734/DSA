// Declaration of function
void insertion(int [],int,int,int);
void deletion(int[],int,int);
int  searching(int[],int,int);
void traverse(int[],int);
int sumArray(int[],int);
#include <stdio.h>


// Function to insert an element into the array
void insertion(int arr[], int size, int element, int position) {
    if (position < 0 || position > size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }

    arr[position] = element;
    printf("Element inserted successfully!\n");

}

// Function to delete an element from the array
void deletion(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position!\n");
        return;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    printf("Element deleted successfully!\n");
}

// Function to search for an element in the array
int searching(int arr[], int size, int element) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            return i;
        }
    }

    return -1; // Element not found
}

// Function to traverse and display the array elements
void traverse(int arr[], int size) {
    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the sum of array elements
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
  printf("Sum of the Array =%d",sum);
}

int main() {
    int arr[100];
    int size;;
    int choice;
  printf("Enter The Size Of Array :");
  scanf("%d",&size);
  for(int i = 0;i<size;i++)
    {
      scanf("%d",&arr[i]);
    }

    printf("Welcome to Array Operations Program!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search for an element\n");
        printf("4. Traverse array\n");
        printf("5. Calculate sum of array elements\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int element, position;
                printf("Enter the element to insert: ");
                scanf("%d", &element);
                printf("Enter the position to insert at: ");
                scanf("%d", &position);
                insertion(arr, size, element, position);
                size = size + 1;
                traverse(arr,size);
                break;
            }
            case 2: {
                int position;
                printf("Enter the position to delete from: ");
                scanf("%d", &position);
                deletion(arr, size, position);
                size = size -1;
              traverse(arr,size);
                break;
            }
            case 3: {
                int element;
                printf("Enter the element to search for: ");
                scanf("%d", &element);
                int result = searching(arr, size, element);
                if (result == -1) {
                    printf("Element not found!\n");
                } else {
                    printf("Element found at position: %d\n", result);
                }
                break;
            }
            case 4:
                traverse(arr, size);
                break;
            case 5: {
                int sum = sumArray(arr, size);
                printf("Sum of array elements: %d\n", sum);
                break;
            }
            case 6:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
