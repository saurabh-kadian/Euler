def f():
	a = []
	b = []
	for i in range(2,100):
		for j in range(2,100):
			number = i**j
			string = str(number)
			sum = 0
			for z in range(0,len(string)):
				sum += int(string[z])
			if sum == i:
				a.append(int(str(i)+str(number)))
				b.append(number)
	a.sort()
	b.sort()
	print(b[29])
