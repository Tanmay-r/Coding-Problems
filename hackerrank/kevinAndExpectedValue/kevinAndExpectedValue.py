import math

globalArray = [0]*10000001

def expression(n):
	return (n+2.0*(math.sqrt(5.0)/6.0 - 0.75 + pow(4.0*n+1.0, 1.5)/12.0 + math.sqrt(4.0*n+1.0)/4.0))/(n+1.0)


def preProcess():
	globalArray[0] = 0
	for i in range(1, len(globalArray)):
		globalArray[i] = globalArray[i-1] + math.sqrt(1 + 4*i)

def main():
	T = input()
	for i in range(T):
		X = input()
		if(X < 10000001):
			print float(((X-1) + globalArray[X-1])/(2.0*float(X)))
		else:
			print expression(X-1)

preProcess()
main()