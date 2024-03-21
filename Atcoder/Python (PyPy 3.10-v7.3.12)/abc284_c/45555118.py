nandm = input().split()
n = int(nandm[0])
m = int(nandm[1])
adj = []
for i in range(n):
    adj.append([])
for i in range(m):
    list = input().split()
    one = int(list[0])
    two = int(list[1])
    one -= 1
    two -= 1
    adj[one].append(two)
    adj[two].append(one)
st = set()
def dfs(node):
    st.add(node)
    for x in adj[node]:
        if x in st:
            continue
        dfs(x)
cnt = 0
for i in range(n):
    if i in st:
        continue
    dfs(i)
    cnt += 1
print(cnt)




