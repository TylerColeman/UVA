from sys import stdin

def main():
    # x = int(stdin.readline())
    # for i in range(0, x):
    #     y = stdin.readline()
    #     v1, v2 = y.split(' ')
    #     v1 = int(v1)
    #     v2 = int(v2)
    #     if v1 < v2:
    #         print("<")
    #     elif v1 > v2:
    #         print(">")
    #     else:
    #         print("=")
    y = []
    for i in range(0,10):
        x = stdin.readline()
        y.append(int(x))

    print(y)

if __name__ == '__main__':
  main()