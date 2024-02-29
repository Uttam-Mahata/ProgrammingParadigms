#include <stdio.h>

int findLargestNode(int A[], int n, int index) {

	if(index <  0) {
		return -1;

	}
        int lchild = 2*index +1;
	int rchild = 2*index + 2;
	
	int largest = A[index];

	if(lchild < n) {
		int lmax = findLargestNode(A,n,lchild);
		if(lmax > largest) {
			largest = lmax;

		}

	} 
	if(rchild < n) {
		int rmax = findLargestNode(A,n,rchild);
		if(rmax < largest) {
		largest = rmax;	

		}

	}

}

int main() {
  int n;
  printf("Enter the size of the tree: ");
  scanf("%d", &n);
  printf("\n");
  int treeArray[n];
  printf("Enter the elements of thre tree array: ");
  for(int i=0; i<n; i++) {
 scanf("%d", &treeArray[i]);
  } 
  int largestNode = findLargestNode(treeArray, n, 0);
 printf("\nLargest Node of the tree Array:%d", largestNode);
 printf("\n");
  return 0;
}
