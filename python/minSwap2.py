def swapsRequired(arr):
    swaps = 0
    n = len(arr)
    arrpos = [*enumerate(arr)]
    arrpos.sort(key=lambda x: x[1])
    visited = [False] * n
    for i in range(n):
        if visited[i] or (arr[i] - 1) == i:
            continue

        cycleSize = 0
        j = i
        while not visited[j]:
            visited[j] = True
            j = arr[j] - 1
            cycleSize += 1

        if cycleSize > 0:
            swaps += cycleSize - 1

    return swaps


def main():
    # arr = [1, 3, 5, 2, 4, 6, 7]
    arr = [1, 3, 5, 2, 4, 6, 7]
    swaps = swapsRequired(arr)
    print(swaps)


if __name__ == "__main__":
    main()
