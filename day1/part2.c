#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *file = fopen("input.txt", "r");
  if (file == NULL) {
    perror("error opening file");
    return 0;
  }
  int *left = malloc(sizeof(int) * 1000);
  int *right = malloc(sizeof(int) * 1000);
  int i = 0;
  while (fscanf(file, "%d %d", &left[i], &right[i]) == 2) {
    i++;
  }

  int minValue = INT_MAX, maxValue = INT_MIN;
  for (int i = 0; i < 1000; i++) {
    if (right[i] < minValue)
      minValue = right[i];
    if (right[i] > maxValue)
      maxValue = right[i];
  }
  int range = maxValue - minValue + 1;
  int *map = calloc(range, sizeof(int));
  for (int i = 0; i < 1000; i++) {
    map[right[i] - minValue]++;
  }
  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    sum += (left[i] * map[left[i] - minValue]);
  }
  printf("sum: %d", sum);
}
