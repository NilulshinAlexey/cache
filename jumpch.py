file = input()

with open(file, 'r') as f:
    List = f.read().split('\n')

champ_res = 0

for i in List:
    points = i[i.index(';')+1:].split(';')
    res = sum(list(map(int, points)))
    if res > champ_res:
        champ_res = res
        champ = i[:i.index(';')]

print(champ)


