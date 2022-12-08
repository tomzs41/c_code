#include <stdio.h>
#include <assert.h>

int BinarySearch(int* a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
			begin = mid+1;
		else if (a[mid] > x)
			end = mid-1;
		else
			return mid;
	}

	return -1;
}


// 计算阶乘递归Fac的时间复杂度？
long long Fac(size_t N)
{
	if (0 == N)
		return 1;

	for (size_t i = 0; i < N; ++i)
	{
		printf("%d", i);
	}
	printf("\n");

	return Fac(N - 1)*N;
}

// 计算斐波那契递归Fib的时间复杂度？
long long Fib(size_t N)
{
	if (N < 3)
		return 1;

	return Fib(N - 1) + Fib(N - 2);
}

int main()
{
	/*int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	for (int i = 0; i < sizeof(a)/sizeof(int); ++i)
	{
		printf("%d\n", BinarySearch(a, 10, i));
	}*/

	printf("%lld\n", Fib(50));

	return 0;
}