def main():
	N = input()
	lines = []
	for i in range(N):
		line = raw_input()
		lines.append(line)

	T = input()

	for i in range(T):
		UKword = raw_input()
		count = 0


		USWord = UKword.replace("our", "or")

		for i in range(N):
			words = lines[i].split(" ")
			for word in words:
				if UKword == word:
					count = count + 1
				elif USWord == word:
					count = count + 1
		print(count)

main()