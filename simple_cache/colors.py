N = int(input())

colors = []

for i in range(N):
    s = input()
    s = s[s.index(";")+1:].split()
    
    for j in s:
        elem = j.split(',')[0]
        elem = elem.lower()
        if elem not in colors:
            colors.append(elem)

print(*sorted(colors))