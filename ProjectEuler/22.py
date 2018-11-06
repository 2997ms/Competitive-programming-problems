#import sys

if __name__ == "__main__":
	fp = open("i.txt")
	s = fp.read().split(',')
	ss = sorted(s)

	cnt = 1
	ans = 0
	for i in ss:
		t = 0
		for k in i:
			if(k != '"'):
				t+=ord(k)-ord('A')+1
		ans += t*cnt;
		cnt += 1
	print ans