from traceback import print_stack


def scambia(i, j, a):
    temp = a[i]
    a[i] = a[j]
    a[j] = temp


def selectionSort(n, a):
    if n == 1:
        return
    max = 0
    for i in range(0, n):
       if a[i] > a[max]:
            max = i
    scambia(n-1, max, a)
    selectionSort(n-1, a)

def main():
    a = []
    p = 1
    while p != 0:
        p = int(input())
        a.append(p)
    selectionSort(len(a), a)
    print(a)


if __name__ == "__main__":
    main()
