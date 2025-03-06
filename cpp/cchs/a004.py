print(
    (
        lambda t, a, res: (
            [res.append(a[i] * (i + 1) + res[i]) for i in range(t)],
            res,
        )[1]
    )(int(input()), list(map(int, input().split())), [0])[-1]
)
