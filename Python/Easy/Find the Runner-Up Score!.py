if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    
    sort = sorted(arr, reverse = True)
    i = 0
    while sort[i] == sort[i+1]:
        i += 1
    
    print(sort[i+1])
    
