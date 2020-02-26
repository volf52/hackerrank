def countValleys(s: str) -> int:
    i = 0
    n = len(s)
    insideValley = False
    valleys = 0
    level = 0
    while i < (n - 1):
        if s[i] == "U":
            level += 1
        else:
            level -= 1

        if (not insideValley) and (level < 0):
            valleys += 1
            insideValley = True
        elif insideValley and (level >= 0):
            insideValley = False
        i += 1
    return valleys


if __name__ == "__main__":
    res = countValleys("DDUUDDUDUUUD")
    print(res)
