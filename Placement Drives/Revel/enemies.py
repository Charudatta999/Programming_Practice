


def pair(n, F_value):
    pairs = 0
    for i in range(n - 1):
        for j in range(1, n):
            if (j + 1) - (i + 1) != F_value[j] - F_value[i]:
                pairs += 1
    return pairs

t = int(input())
for i in range(t):
    n = int(input())
    F_value = list(map(int, input().split()))

    print(pair(n, F_value))
