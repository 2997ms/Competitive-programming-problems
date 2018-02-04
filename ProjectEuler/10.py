

def main():
    p = dict()
    sum = 0
    for i in range(2,2000000):
        if p.has_key(i):
            continue
        sum += i
        j = i
        while(j<=2000000):
            p[j]=1
            j+=i
    print sum
if __name__ == "__main__":
    main()