import math

def binary_search(X, sum, start, end):
	if(X < sum[start]):
		print(start - 1)
	else:
		mid = int(math.floor((start + end)/2))
		if(X == sum[mid]):
			print(mid)
		elif(X < sum[mid]):
			binary_search(X, sum, start, mid-1)
		else:
			binary_search(X, sum, mid+1, end)


def main():
	sum = [0]*1000000
	
	sum[0] = 0
	for i in range(1000000):
		sum[i] = sum[i-1] + i*i

	T = input()
	for i in range(T):
		X = input()
		binary_search(X, sum, 0, 999999)


main()