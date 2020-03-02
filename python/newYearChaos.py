def main():
    q = [1, 2, 5, 3, 7, 8, 6, 4]
    m = minBribes(q)
    print(f"Min bribes are {m}")


def minBribes(q) -> int:
    moves = 0
    Q = [P - 1 for P in q]
    for i, P in enumerate(Q):
        if P - i > 2:
            print("Too chaotic")
            return -1

        for j in range(max(P - 1, 0), i):
            if Q[j] > P:
                moves += 1

    return moves


if __name__ == "__main__":
    main()
