def f():
    i = 1389026623
    while i > 1010101010:
	num = i**2
	string = str(num)
	if i%1000000 == 0:
		print(i)
	if string[0] == '1' and string [2] == '2' and string [4] == '3' and string [6] == '4' and string [8] == '5' and string [10] == '6' and string [12] == '7' and string [14] == '8' and string [16] == '9' and string [18] == '0':
		print(i)
		break
	i = i-1
