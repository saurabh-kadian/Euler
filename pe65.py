Python 3.3.2 (v3.3.2:d047928ae3f6, May 16 2013, 00:06:53) [MSC v.1600 64 bit (AMD64)] on win32
Type "copyright", "credits" or "license()" for more information.
>>> def rev(t,p,x):
	deno = p+x
	num = 1
	num += deno*t
	return deno,num

>>> arr = [1,2]
>>> arr
[1, 2]
>>> k = 2
>>> k
2
>>> for i in range(3,50):
	arr.append(1)
	arr.append(1)
	arr.append(2*k)
	k += 1

	
>>> arr
[1, 2, 1, 1, 4, 1, 1, 6, 1, 1, 8, 1, 1, 10, 1, 1, 12, 1, 1, 14, 1, 1, 16, 1, 1, 18, 1, 1, 20, 1, 1, 22, 1, 1, 24, 1, 1, 26, 1, 1, 28, 1, 1, 30, 1, 1, 32, 1, 1, 34, 1, 1, 36, 1, 1, 38, 1, 1, 40, 1, 1, 42, 1, 1, 44, 1, 1, 46, 1, 1, 48, 1, 1, 50, 1, 1, 52, 1, 1, 54, 1, 1, 56, 1, 1, 58, 1, 1, 60, 1, 1, 62, 1, 1, 64, 1, 1, 66, 1, 1, 68, 1, 1, 70, 1, 1, 72, 1, 1, 74, 1, 1, 76, 1, 1, 78, 1, 1, 80, 1, 1, 82, 1, 1, 84, 1, 1, 86, 1, 1, 88, 1, 1, 90, 1, 1, 92, 1, 1, 94, 1, 1, 96]
>>> 2 + rev(0,1,1)
Traceback (most recent call last):
  File "<pyshell#21>", line 1, in <module>
    2 + rev(0,1,1)
TypeError: unsupported operand type(s) for +: 'int' and 'tuple'
>>> def add(a,b):
	a += b*2
	return b,a

>>> p,q = rev(0,1,1)
>>> add(p,q)
(1, 4)
>>> p,q
(2, 1)
>>> rev(2,1,1)
(2, 5)
>>> rev(0,1,1)
(2, 1)
>>> def add(a,b):
	a += b*2
	return a,b

>>> p,q = rev(0,1,0)
>>> add(p,q)
(3, 1)
>>> arr[99]
1
>>> arr[100]
68
>>> def rev(p,xn,xd):
	xn += p*xd
	return xd,xn

>>> p,q = rev(1,1,1)
>>> add(p,q)
(5, 2)
>>> p,q = rev(1,0,1)
>>> add(p,q)
(3, 1)
>>> def f():
	n,d = rev(arr[3],0,1)
	i = 2
	while i>=0:
		n,d = (arr[i],n,d)
		i-=1
	print(add(n,d))

	
>>> f()
Traceback (most recent call last):
  File "<pyshell#56>", line 1, in <module>
    f()
  File "<pyshell#55>", line 5, in f
    n,d = (arr[i],n,d)
ValueError: too many values to unpack (expected 2)
>>> def f():
	n,d = rev(arr[3],0,1)
	i = 2
	while i>=0:
		n,d = rev(arr[i],n,d)
		i-=1
	print(add(n,d))

	
>>> f()
(19, 7)
>>> def f():
	n,d = rev(arr[99],0,1)
	i = 98
	while i>=0:
		n,d = rev(arr[i],n,d)
		i-=1
	print(add(n,d))

	
>>> f()
(13823891428306770374331665289458907890372191037173036666131, 5085525453460186301777867529962655859538011626631066055111)
>>> def f():
	n,d = rev(arr[98],0,1)
	i = 97
	while i>=0:
		n,d = rev(arr[i],n,d)
		i-=1
	print(add(n,d))

	
>>> f()
(6963524437876961749120273824619538346438023188214475670667, 2561737478789858711161539537921323010415623148113041714756)
>>> t = str(6963524437876961749120273824619538346438023188214475670667)
>>> t
'6963524437876961749120273824619538346438023188214475670667'
>>> total = 0
>>> for i in range(0,len(t)):
	total += int(t[i])

	
>>> total
272
>>> 
