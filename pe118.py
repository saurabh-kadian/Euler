from functools import lru_cache

@lru_cache(None)
def isPrime(number):
    if number == '1':
        return False
    if number == "":
        return True
    number = int(number)
    if number == 2 or number == 3:
        return True
    if number % 2 == 0 or number % 3 == 0:
        return False
    index = 5
    while index**2 <= number:
        if number % index == 0 or number % (index + 2) == 0:
            return False
        index += 6
    return True

def fact(x):
    if x == 1:
        return 1
    return x*fact(x-1)

@lru_cache(None)
def solve(digits, previousNumber, lenw):
    indices = [(i + 1) for i, ch in enumerate(digits) if ch == 'F']
    if len(indices) == 0:
        if isPrime(previousNumber):
            return 1.0/fact(lenw + 1)
        else:
            return 0
    # use previousNumber
    useAnswer = 0
    for index in indices:
        tempDigits = list(digits)
        tempDigits[index-1] = 'T'
        digits = ''.join(tempDigits)
        useAnswer += solve(digits, previousNumber + str(index), lenw)
        tempDigits = list(digits)
        tempDigits[index-1] = 'F'
        digits = ''.join(tempDigits)
    # don't use previousNumber
    answer = 0
    for index in indices:
        tempDigits = list(digits)
        tempDigits[index-1] = 'T'
        digits = ''.join(tempDigits)
        if isPrime(previousNumber):
            answer += solve(digits, str(index), lenw + 1)
        tempDigits = list(digits)
        tempDigits[index-1] = 'F'
        digits = ''.join(tempDigits)
    return useAnswer + answer
    

if __name__ == '__main__':
    digits = ''.join(['F' for i in range(1, 10)])
    answer = 0
    for index in range(1, 10):
        tempDigits = list(digits)
        tempDigits[index-1] = 'T'
        answer += solve(''.join(tempDigits), str(index), 0)
    print("Answer to problem 118: %s" % round(answer))