def main():
    t,n=map(int,input().split())
    a=[int(0) for _ in range(t+2)]
    for __ in range(n):
        l,r,e=map(int,input().split())
        a[l]+=e
        a[r+1]-=e
    for i in range(1,t+1):
        a[i]+=a[i-1]
        if a[i] <= 0:
            print("ICU")
            return
    print("Alive")
main()