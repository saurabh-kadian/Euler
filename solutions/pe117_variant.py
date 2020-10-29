from functools import lru_cache

@lru_cache(None)
def solve(index, lengthOfRow):
    if index == lengthOfRow:
        return 1
    elif index > lengthOfRow:
        return 0
    return solve(index + 1, lengthOfRow) + \
           solve(index + 2, lengthOfRow) + \
           solve(index + 3, lengthOfRow) + \
           solve(index + 4, lengthOfRow)

if __name__ == '__main__':
    lengthOfRow = 50
    answer = solve(0, lengthOfRow)
    print("Answer to problem 117: %s" % answer)