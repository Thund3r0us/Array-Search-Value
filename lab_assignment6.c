#include <stdio.h>

int search(int numbers[], int low, int high, int value) {
  // Base case: value is not found
  if (low > high) {
    return -1;
  }

  // Find the middle value
  int mid = (high - low) + low / 2;

  // Return mid if the middle value is the value we are looking for
  if (numbers[mid] == value) {
    return mid;
  }

  // If the middle number is lower than our value, recurse with the upper half
  else if (numbers[mid] < value) {
    return search(numbers, mid + 1, high, value);
  }

  // If the middle number is higher than our value, recurse with the lower half
  else {
    return search(numbers, low, mid - 1, value);
  }
  
  return -1;
}

void printArray(int numbers[], int sz) {
  int i;
  printf("Number array : ");
  for (i = 0;i<sz;++i)
  {
    printf("%d ",numbers[i]);
  }
  printf("\n");
}

int main(void) {
  int i, numInputs;
  char* str;
  float average;
  int value;
  int index;
  int* numArray = NULL;
  int countOfNums;
  FILE* inFile = fopen("input.txt","r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0)
  {
    fscanf(inFile, " %d\n", &countOfNums);
    numArray = (int *) malloc(countOfNums * sizeof(int));
    average = 0;
    for (i = 0; i < countOfNums; i++)
    {
      fscanf(inFile," %d", &value);
      numArray[i] = value;
      average += numArray[i];
    }

    printArray(numArray, countOfNums);
    value = average / countOfNums;
    index = search(numArray, 0, countOfNums - 1, value);
    if (index >= 0)
    {
      printf("Item %d exists in the number array at index %d!\n",value, index);
    }
    else
    {
      printf("Item %d does not exist in the number array!\n", value);
    }

    free(numArray);
  }

  fclose(inFile);
}
