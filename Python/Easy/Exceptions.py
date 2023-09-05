# Enter your code here. Read input from STDIN. Print output to STDOUT

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        a, b = input().split(" ")
        try:
            result = int(a)//int(b)
            print(result)
        except ZeroDivisionError as e:
            print ("Error Code:", e)
        except ValueError as e:
            print ("Error Code:", e)   
