def print_formatted(number):
    # your code goes here
    import math
    spaces = math.floor(math.log2(number)) + 1
    
    for i in range(1, number + 1, 1):
        decimal = str(i)
        octal = oct(i)[2:]
        hexadecimal = hex(i)[2:].upper()
        binary = bin(i)[2:]
        
        printedLine = (" " * (spaces - len(str(decimal)))) + decimal + " "
        printedLine += (" " * (spaces - len(str(octal)))) + octal + " "
        printedLine += (" " * (spaces - len(str(hexadecimal)))) + hexadecimal + " "
        printedLine += (" " * (spaces - len(str(binary)))) + binary
        
        print(printedLine)

if __name__ == '__main__':
    n = int(input())
    print_formatted(n)