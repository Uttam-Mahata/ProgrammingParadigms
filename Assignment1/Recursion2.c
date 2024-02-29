#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// function prototypes
int fact(int n);
int sum(int n);
int stringCompare(char *s1, char *s2);
int findLargest(int arr[], int n);
int findHCF(int n1, int n2);
int search(int arr[], int n, int num);

int fact(int n) {
  if (n == 1)
    return 1;
  else
    return n * fact(n - 1);
}

int sum(int n) {
  if (n == 1)
    return 1;
  else
    return n + sum(n - 1);
}

int stringCompare(char *s1, char *s2) {
  if (*s1 == '\0' && *s2 == '\0')
    return 0;
  else if (*s1 < *s2)
    return -1;
  else if (*s1 > *s2)
    return 1;
  else
    return stringCompare(s1 + 1, s2 + 1);
}

int findLargest(int arr[], int n) {
  if (n == 1)
    return arr[0];
  else {
    int last = arr[n - 1];
    int remainingMax = findLargest(arr, n - 1);
    return (last > remainingMax) ? last : remainingMax;
  }
}

int findHCF(int n1, int n2) {
  if (n2 == 0)
    return n1;
  else
    return findHCF(n2, n1 % n2);
}

int search(int arr[], int n, int num) {
  if (n == 0)
    return 0;
  else if (arr[0] == num)
    return 1;
  else
    return search(arr + 1, n - 1, num);
}
void printReverseList(int arr[], int n) {
  if (n == 0)
    return;
  else {
    printReverseList(arr + 1, n - 1);
    printf("%d ", arr[0]);
  }
}

int isPalindromeString(char *s, int start, int end) {
  if (start >= end)
    return 1;
  else if (s[start] != s[end])
    return 0;
  else
    return isPalindromeString(s, start + 1, end - 1);
}

void replaceCharString(char *s, char c1, char c2) {
  if (*s == '\0')
    return;
  else {
    if (*s == c1)
      *s = c2;
    replaceCharString(s + 1, c1, c2);
  }
}

void selectionSortArray(int arr[], int n) {
  if (n <= 1)
    return;
  else {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
      if (arr[i] > arr[maxIndex])
        maxIndex = i;
    }
    int temp = arr[maxIndex];
    arr[maxIndex] = arr[n - 1];
    arr[n - 1] = temp;

    selectionSortArray(arr, n - 1);
  }
}

int main() {
  int choice;
  do {

    printf("\nMenu:\n");
    printf("1. Factorial\n");
    printf("2. Sum of n integers\n");
    printf("3. String comparison\n");
    printf("4. Find largest among n integers\n");
    printf("5. Find HCF of two integers\n");
    printf("6. Search for a given integer in a given list\n");
    printf("7. Print a list in reverse order\n");
    printf("8. Check if a string is a palindrome\n");
    printf("9. Replace a character in a string\n");
    printf("10. Sort an array using selection sort\n");
    printf("0. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      int n;
      printf("Enter a number for factorial: ");
      scanf("%d", &n);
      printf("Factorial of %d is: %d\n", n, fact(n));
      break;
    }
    case 2: {
      int n;
      printf("Enter the value of n: ");
      scanf("%d", &n);
      printf("Sum of first %d integers is: %d\n", n, sum(n));
      break;
    }
    case 3: {
      char str1[50], str2[50];
      printf("Enter the first string: ");
      scanf("%s", str1);
      printf("Enter the second string: ");
      scanf("%s", str2);
      printf("String comparison result: %d\n", stringCompare(str1, str2));
      break;
    }
    case 4: {
      int n;
      printf("Enter the number of elements in the array: ");
      scanf("%d", &n);
      int arr[n];
      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      printf("Largest element in the array is: %d\n", findLargest(arr, n));
      break;
    }
    case 5: {
      int n1, n2;
      printf("Enter two numbers to find HCF: ");
      scanf("%d %d", &n1, &n2);
      printf("HCF of %d and %d is: %d\n", n1, n2, findHCF(n1, n2));
      break;
    }
    case 6: {
      int n, num;
      printf("Enter the number of elements in the array: ");
      scanf("%d", &n);
      int arr[n];
      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      printf("Enter the number to search: ");
      scanf("%d", &num);
      if (search(arr, n, num))
        printf("%d is found in the array.\n", num);
      else
        printf("%d is not found in the array.\n", num);
      break;
    }
    case 7: {
      int n;
      printf("Enter the number of elements in the array: ");
      scanf("%d", &n);
      int arr[n];
      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      printf("Array in reverse order: ");
      printReverseList(arr, n);
      printf("\n");
      break;
    }
    case 8: {
      char str[50];
      printf("Enter a string to check if it's a palindrome: ");
      scanf("%s", str);
      if (isPalindromeString(str, 0, strlen(str) - 1))
        printf("%s is a palindrome.\n", str);
      else
        printf("%s is not a palindrome.\n", str);
      break;
    }
    case 9: {
      char str[50], c1, c2;
      printf("Enter a string: ");
      scanf("%s", str);
      printf("Enter the character to replace: ");
      scanf(" %c", &c1);
      printf("Enter the replacement character: ");
      scanf(" %c", &c2);
      replaceCharString(str, c1, c2);
      printf("String after replacement: %s\n", str);
      break;
    }
    case 10: {
      int n;
      printf("Enter the number of elements in the array: ");
      scanf("%d", &n);
      int arr[n];
      printf("Enter the elements of the array: ");
      for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
      }
      selectionSortArray(arr, n);
      printf("Sorted array: ");
      for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
      }
      printf("\n");
      break;
    }

    case 0: {
      printf("Exiting the program.\n");
      break;
    }
    default:
      printf("Invalid choice! Please enter a valid option.\n");
    }

  } while (choice != 0);

  return 0;
}
