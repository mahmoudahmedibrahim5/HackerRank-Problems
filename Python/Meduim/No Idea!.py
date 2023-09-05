# Enter your code here. Read input from STDIN. Print output to STDOUT

if __name__ == "__main__":
    n, m = list(map(int, input().split(" ")))
    arr = list(map(int, input().split(" ")))
    A = set(map(int, input().split(" ")))
    B = set(map(int, input().split(" ")))
    happiness = 0
    for i in range(n):
        if(arr[i] in A):
            happiness += 1
        if(arr[i] in B):
            happiness -= 1
    print(happiness)
