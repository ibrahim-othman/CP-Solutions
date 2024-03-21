t = int(input())
for T in range(t):
    n = int(input())
    cnt = 0;
    arr=list(map(int,input().split()))
    for i in range(n):
        x = int(arr[i]);
        if x%2 == 1:
            cnt += 1
    print(cnt)

