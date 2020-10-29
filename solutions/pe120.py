from time import time
if __name__ == '__main__':
    startTime = time()
    answer = 0
    for a in range(3,1001):
        n = a//2
        if a%2 == 0:
            answer += 2 * (n-1) * a
        else:
            answer += 2 * n * a
    print("Answer for problem 120: %s is %0.2f secs" % (answer, time()-startTime))