def main():
    up = 1;
    down = 2;
    ans = 0
    for i in range(0, 1000):
        res = up + down;
        if(len(str(res)) > len(str(down))):
            ans+=1
        up = down*2 + up
        tmp = up
        up = down
        down = tmp
    print ans

if __name__ == '__main__':
    main()