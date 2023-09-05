if __name__ == '__main__':
    for _ in range(int(input())):
        name = input()
        score = float(input())
        if(_ == 0):
            first = score
            first_name = [name]
            second = score
            second_name = [name]
        else:
            if( (score > first) & (first == second) ):
                second = score
                second_name = [name]
            elif(score < first):
                second = first
                second_name = first_name
                first = score
                first_name = [name]
            elif(score == first):
                first_name.append(name)
            elif(score == second):
                second_name.append(name)
            elif(score < second):
                second = score
                second_name = [name] 
            
                           
    sort = sorted(second_name, reverse = False)
    for i in sort:
        print(i)
        
