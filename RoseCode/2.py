f1 = 1
f2 = 1
while True:
    f3 = f2 + f1
    k = str(f3)
    sum = 0
    for i in range(len(str(f3))):
        sum += int(k[i])
    if sum > 100:
        print f3
        break
    f1 = f2
    f2 = f3