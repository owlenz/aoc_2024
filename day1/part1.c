#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) { return (*(int *)a - *(int *)b); }

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
    printf("Read integers: %d and %d\n", left[i], right[i]);
    i++;
  }
  qsort(left, 1000, sizeof(int), comp);
  qsort(right, 1000, sizeof(int), comp);

  int sum = 0;
  for (int i = 0; i < 1000; i++) {
    sum += abs((left[i] - right[i]));
  }
  printf("sum: %d", sum);
}
