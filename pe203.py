numberToPrimes = {}
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53]
def generateNumberToPrimes():
    for number in range(1,55):
        if number == 1:
            numberToPrimes[number] = {}
        else:
            numberToPrimes[number] = {}
            tempNumber = number
            for prime in primes:
                counter = 0
                while number % prime == 0:
                    counter += 1
                    number /= prime
                if counter != 0:
                    numberToPrimes[tempNumber].update({prime:counter})

def generateUniqueCombinations():
    uniqueNumbers = set()
    for num in range(1, 51):
        for den in range(1, num + 1):
            if den > (num+1)/2:
                continue
            totalMap = {}
            for index in range(1, den+1):
                upper = num - index + 1
                upperPrimesRep = numberToPrimes[upper]
                for key in upperPrimesRep.keys():
                    if key in totalMap.keys():
                        totalMap[key] += upperPrimesRep[key]
                    else:
                        totalMap[key] = upperPrimesRep[key]
            for index in range(2, den+1):
                lower = index
                lowerPrimesRep = numberToPrimes[lower]
                for key in lowerPrimesRep.keys():
                    totalMap[key] -= lowerPrimesRep[key]
            product = 1
            isSquare = False
            for key in totalMap.keys():
                if totalMap[key] != 0 and totalMap[key] >= 2:
                    isSquare = True
            if isSquare:
                continue
            for key in totalMap.keys():
                if totalMap[key] != 0:
                    product *= (key**totalMap[key])
            uniqueNumbers.add(product)
    return uniqueNumbers                  


if __name__ == '__main__':
    # 7 C 1 -> 8th row
    # 50 C 1 -> 51st row
    generateNumberToPrimes()
    numbers = generateUniqueCombinations()
    print("Answer to problem 203: %s" % (sum(numbers)))
