import math

def main():
	T = input()
	for i in range(T):
		N = input()
		if(N < 0):
			print 4
		else:
			result = 1
			temp = N
			a = 2
			while (temp > 0):
				if (temp%2==1):
					result *= a
					result %= 1000000007
				temp /= 2
				a *= a
				a %= 1000000007

			print (4 + (2*(result%1000000007 - 1)%1000000007))%1000000007

main()