#include <stdio.h>
#include <stdlib.h>

void sort(int *s_nums, int count){
  int i, j, mi, tmp;
	for (i = 0; i < count - 1; i++) {
		/* najdeme minimum */
		mi = i;
		for (j = i+1; j < count; j++) {
			if (s_nums[j] < s_nums[mi]) {
				mi = j;
            }
        }
		/* vyměníme data[i] a data[mi] */
		tmp = s_nums[i];
		s_nums[i] = s_nums[mi];
		s_nums[mi] = tmp;
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
  int *s_nums = malloc(sizeof(int) * (nums1Size + nums2Size));
  double result = 0.0;

  int i = 0;

  while (i < nums1Size + nums2Size){
    if (i < nums1Size)
      s_nums[i] = nums1[i];
    else
      s_nums[i] = nums2[i - nums1Size];
    i++;
  }

  sort(s_nums, nums1Size + nums2Size);

  if ((nums1Size + nums2Size) % 2 == 0){
    result = (double)(s_nums[(nums1Size + nums2Size) / 2] + s_nums[(nums1Size + nums2Size) / 2 - 1]) / 2;
  } else {
    result = (double)s_nums[(nums1Size + nums2Size) / 2];
  }
  for (i = 0; i < nums1Size + nums2Size; i++){
    printf("%d ", s_nums[i]);
  }
  return result;
}


int main (){
  int nums1[] = {1, 3};
  int nums2[] = {2};
  int nums1Size = 2;
  int nums2Size = 1;
  double result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
  printf("result: %f\n", result);
  return 0;
}

