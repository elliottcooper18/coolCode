#include <stdio.h>
#include <stdlib.h>

int sum(int);
int *createArray(int);
void inputElements(int*, int);
int getKey();
int binarySearch(int*, int, int, int, int);

int main()
{
	// binary search requires the list to be sorted 
    int *numbers, numberOfElements, *element, sizeOfArray, i = 0, key;

    // get user input
    printf("Enter the number of elements you would like to input: ");
    scanf("%d", &numberOfElements);

    //create array
    numbers = createArray(numberOfElements);

    //input elements into array
    inputElements(numbers, numberOfElements);

    //get key from user 
    key = getKey();

    // binary search
    if (binarySearch(numbers, key, 0, numberOfElements/2, numberOfElements-1))
        printf("%d is in list\n", key);

    else
        printf("%d is not in list\n", key);
    
    // free the dynamically allocated array
    free(numbers);
   
	return 0;
}


int binarySearch(int *array, int key, int low, int mid, int high)
{   
    if (low > high)
        return 0;

    if (array[mid] == key)  
        return 1;

    else if (key < array[mid])
        return binarySearch(array, key, low, (low + (mid-1)) / 2, mid-1);

    else
        return binarySearch(array, key, mid+1, (mid+1 + (high)) / 2, high);
    
}


void inputElements(int *numbers, int numberOfElements)
{
    int i, elementToAdd;

    printf("Input the elements in asceding order\n");

    for (i = 0; i < numberOfElements; i++)
    {   
        printf("Enter element %d: ", i+1);
        scanf("%d", &elementToAdd);

        *(numbers+i) = elementToAdd;

    }
}

int getKey()
{
    int key;

    printf("Enter the key: ");
    scanf("%d", &key);

    return key;

}

int *createArray(int numberOfElements)
{   
    int *numbers;

    numbers = (int*)malloc(numberOfElements * sizeof(int));
    return numbers;
    
}

int sum(int num)
{
    if (num <=1)
        return num;

    return num + sum(num-1);

}