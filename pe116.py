from functools import lru_cache

@lru_cache(None)
def solve(index, lengthOfRow, colorTile):
    if index == lengthOfRow:
        return 1
    elif index > lengthOfRow:
        return 0
    return solve(index + 1, lengthOfRow, colorTile) + \
           solve(index + colorTile, lengthOfRow, colorTile)

if __name__ == '__main__':
    lengthOfRow = 50
    answer = solve(0, lengthOfRow, 2) + \
             solve(0, lengthOfRow, 3) + \
             solve(0, lengthOfRow, 4) - 3
    print("Answer to problem 116: %s" % answer)