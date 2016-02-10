red = 2;green = 3;blue = 4;black = 1;units = 50;fact = [];number = 1
fact.append(1)
for i in range(1,units+1):
    number = number*i
    fact.append(number)
red = int(units/red)
green = int(units/green)
blue = int(units/blue)
ways = 0
for redWalle in range(0,red+1):
    for greenWalle in range(0,green+1):
        if (2*redWalle)+(3*greenWalle) > units:
            continue
        for blueWalle in range(0,blue+1):
            if (2*redWalle)+(3*greenWalle)+(4*blueWalle) > units:
                continue
            blackWalle = units-(2*redWalle)-(3*greenWalle)-(4*blueWalle)
            num = fact[blackWalle+redWalle+greenWalle+blueWalle]
            num /= fact[blackWalle]
            num /= fact[redWalle]
            num /= fact[blueWalle]
            num /= fact[greenWalle]
            ways += num
            print("Black : " + str(blackWalle) + " Red : " + str(redWalle) + " Green : " + str(greenWalle) + " Blue : " + str(blueWalle) )
print(ways)

