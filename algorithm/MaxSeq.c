#include <stdio.h>

void printSubset(int arr[], int length)
{
	printf("{");
	for (int i = 0; i < length; i++)
	{
		if (i == length - 1) {
            printf("%d", arr[i]);
        }
		else {
			printf("%d,", arr[i]);
		}
	}
	printf("}\n");
}

/*
 * 查找所有的子集
 * @param arr[] 要查找的子集
 * @param length 要查找的子集的长度
 * @param subset[] 要查找的子集
 * @param subsetSize 要查找的子集的长度
 * @param index 查找当前数组的index
*/
void findAllSubsets(int arr[], int length, int subset[], int subsetLength, int index)
{
	printSubset(subset,subsetLength);

	for(int i = index; i < length; i++)
	{
		subset[subsetLength] = arr[i];
		findAllSubsets(arr, length, subset, subsetLength + 1, i + 1);
	}

}



int main()
{
	int arr[] = {1,2,3 };
	int length = sizeof(arr)/sizeof(arr[0]);
	int subset[length];

	findAllSubsets(arr, length, subset, 0, 0);
	
}