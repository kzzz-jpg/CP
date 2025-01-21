print('\n'.join(
    str(x) for x in (lambda n,q,a:
        (lambda nw:
        (lambda pos,val:
            [nw-a[pos-1]+val,a.__setitem__(pos-1,val)][0]
        )(*map(int,input().split())) for _ in range(q)
        )(sum(a))
    )(*map(int,input().split()),list(map(int,input().split())))
))