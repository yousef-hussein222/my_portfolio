#Mohammed Ismail Mohammed  20231135
#Yousef Hussein Mohammed   20231211
#Abdallah Gamal Rabie      20231102

#decimal to binary

def dec_to_bin(num):
    #num = int(input("Enter your decimal number:"))
    bin = 0
    i = 0
    while num > 0:
        digit = num % 2
        bin = bin + digit * (10 ** i)
        num = num // 2
        i = i + 1
    #print("Your binary number is:",bin)
#dec_to_bin()
    return bin

#decimal to octal

def dec_to_oct(num):
    #num = int(input("Enter your decimal number:"))
    oct = 0
    i = 0
    while num > 0:
        digit = num % 8
        oct = oct + digit * (10 ** i)
        num = num // 8
        i = i + 1
    #print("Your octal number is:",oct)
    return oct
#dec_to_oct()

# decimal to hexadecimal

def dec_to_hex(num):
    # num = int(input("Enter your decimal number:"))
    hexa_chars = "0123456789ABCDEF"
    hex = ""
    while num > 0:
        digit = num % 16
        hex = hexa_chars[digit] + hex
        num = num // 16
        # print("Your hexadecimal number is:",hex)
    return hex
# dec_to_hex()

# binary to decimal

def bin_to_dec(num):
    # num = int(input("Enter your binary number:"))
    dec = 0
    i = 0
    while num > 0:
        digit = num % 10
        dec = dec + digit * (2 ** i)
        num = num // 10
        i = i + 1
        # print("your decimal number is",dec)
    return dec
# bin_to_dec()



def bin_to_dec(num):
    # num = int(x)
    # input("Enter your binary number:")
    dec = 0
    i = 0
    while num > 0:
        digit = num % 10
        dec = dec + digit * (2 ** i)
        num = num // 10
        i = i + 1
    # print("Your decimal number is", dec)
    return dec


#Decimal to octal

def dec_to_oct(num):
    # num = int(x)
    # input("Enter your decimal number:")
    oct = 0
    i = 0
    while num > 0:
        digit = num % 8
        oct = oct + digit * (10 ** i)
        num = num // 8
        i = i + 1
    return oct if oct else '0'
    dec_to_oct(num)

#Binary to octal

def bin2oct(octal_value, num):
    decimal_value = bin_to_dec(num)
    octal_value = dec_to_oct(decimal_value)
    # print(octal_value)
    return octal_value

#binary to hexadecimal

def bin_to_dec(num):
    #num = int()
    #input("Enter your binary number:")
    dec = 0
    i=0
    while num > 0:
        digit = num % 10
        dec = dec + digit* (2**i)
        num = num //10
        i =i+1
    #print("your decimal number is:", dec)
    return dec





def dec_to_hex(num):
    #num = int(dec)
    hexa_chars = "0123456789ABCDEF"
    hexal = ""
    while num > 0:
        digit = num % 16
        hexal = hexa_chars[digit] + hexal
        num = num // 16
    #print(hex)
    return hexal if hexal else '0'

def bin2hex( hexa_value,num):
    decimal_value = bin_to_dec(num)
    hexa_value = dec_to_hex(decimal_value)
    #print(octal_value)
    return hexa_value

# octal to decimal
def oct_to_dec(num):
    # num = int(input("Enter your octal number:"))
    dec = 0
    i = 0
    while num > 0:
        digit = num % 10
        dec = dec + digit * (8 ** i)
        num = num // 10
        i = i + 1
        # print("Your decimal number is:",dec)
    # oct_to_dec()
    return dec
#octal to binary
def oct_to_dec(num):
  #num = int(x)
  dec = 0
  i = 0
  while num > 0:
    digit = num % 10
    dec = dec + digit* (8**i)
    num = num //10
    i = i+1
  if dec :
    return dec
  else:
    return "0"
#print(oct_to_dec(num))
  return decimal
def dec_to_bin(num):
    #num = int(x)
    bin = 0
    i = 0
    while num > 0:
        digit = num % 2
        bin = bin + digit * (10 ** i)
        num = num // 2
        i = i + 1
    #print(bin)
    return bin

def oct_to_bin(binary_value,num):
    decimal_value = oct_to_dec(num)
    binary_value = dec_to_bin(decimal_value)
    return binary_value

#octal to hexadecimal
def oct_to_dec(num):
  #num = int(x)
  dec = 0
  i = 0
  while num > 0:
    digit = num % 10
    dec = dec + digit* (8**i)
    num = num //10
    i = i+1
  if dec :
    return dec
  else:
    return "0"
  #print(oct_to_dec(num))
  return decimal

def dec_to_hex(num):
    #num = int(dec)
    hexa_chars = "0123456789ABCDEF"
    hex = ""
    while num > 0:
        digit = num % 16
        hex = hexa_chars[digit] + hex
        num = num // 16
    #print(hex)
    return hex if hex else '0'
def oct_to_hex(hexa_value,num):
    decimal_value = oct_to_dec(num)
    hexa_value = dec_to_hex(decimal_value)
    #print(octal_value)
    return hexa_value

# hexadecimal to decimal
def hex_to_dec(num):
    z = list(num)
    length = len(z)
    total = 0
    for i in range(length):
        last_element = z.pop()
        x = last_element
        if x == "1":
            total = total + (16 ** i) * 1
        elif x == "2":
            total = total + (16 ** i) * 2
        elif x == "3":
            total = total + (16 ** i) * 3
        elif x == "4":
            total = total + (16 ** i) * 4
        elif x == "5":
            total = total + (16 ** i) * 5
        elif x == "6":
            total = total + (16 ** i) * 6
        elif x == "7":
            total = total + (16 ** i) * 7
        elif x == "8":
            total = total + (16 ** i) * 8
        elif x == "9":
            total = total + (16 ** i) * 9
        elif x.upper() == "A":
            total = total + (16 ** i) * 10
        elif x.upper() == "B":
            total = total + (16 ** i) * 11
        elif x.upper() == "C":
            total = total + (16 ** i) * 12
        elif x.upper() == "D":
            total = total + (16 ** i) * 13
        elif x.upper() == "E":
            total = total + (16 ** i) * 14
        elif x.upper() == "F":
            total = total + (16 ** i) * 15
        elif x.upper() == "0":
            total = total + (16 ** i) * 0
            # print("your decimal number is:", total)
    return total
# hex_to_dec(num)

# hexadecimal to binary
def hex_to_dec(num):
    z = list(num)
    length = len(num)
    total = 0
    for i in range(length):
        last_element = z.pop()
        x = last_element
        if x == "1":
            total = total + (16 ** i) * 1
        elif x == "2":
            total = total + (16 ** i) * 2
        elif x == "3":
            total = total + (16 ** i) * 3
        elif x == "4":
            total = total + (16 ** i) * 4
        elif x == "5":
            total = total + (16 ** i) * 5
        elif x == "6":
            total = total + (16 ** i) * 6
        elif x == "7":
            total = total + (16 ** i) * 7
        elif x == "8":
            total = total + (16 ** i) * 8
        elif x == "9":
            total = total + (16 ** i) * 9
        elif x.upper() == "A":
            total = total + (16 ** i) * 10
        elif x.upper() == "B":
            total = total + (16 ** i) * 11
        elif x.upper() == "C":
            total = total + (16 ** i) * 12
        elif x.upper(num) == "D":
            total = total + (16 ** i) * 13
        elif x.upper(num) == "E":
            total = total + (16 ** i) * 14
        elif x.upper(num) == "F":
            total = total + (16 ** i) * 15
        elif x.upper(num) == "0":
            total = total + (16 ** i) * 0
    #print("your decimal number is", total)
    return total

def dec_to_bin(total):
    total =int(total)
    bin = 0
    i = 0
    while total > 0:
        digit = total % 2
        bin = bin + digit * (10 ** i)
        total= total // 2
        i = i + 1
    #print(bin)
    return bin
def hex_to_bin(num):
    decimal_value = hex_to_dec(num)
    binary_value = dec_to_bin(decimal_value)
    return binary_value

# hexadecimal to octal
def hex_to_dec(num):
    z = list(num)
    length = len(num)
    total = 0
    for i in range(length):
        last_element = z.pop()
        x = last_element
        if x == "1":
            total = total + (16 ** i) * 1
        elif x == "2":
            total = total + (16 ** i) * 2
        elif x == "3":
            total = total + (16 ** i) * 3
        elif x == "4":
            total = total + (16 ** i) * 4
        elif x == "5":
            total = total + (16 ** i) * 5
        elif x == "6":
            total = total + (16 ** i) * 6
        elif x == "7":
            total = total + (16 ** i) * 7
        elif x == "8":
            total = total + (16 ** i) * 8
        elif x == "9":
            total = total + (16 ** i) * 9
        elif x.upper() == "A":
            total = total + (16 ** i) * 10
        elif x.upper() == "B":
            total = total + (16 ** i) * 11
        elif x.upper() == "C":
            total = total + (16 ** i) * 12
        elif x.upper() == "D":
            total = total + (16 ** i) * 13
        elif x.upper() == "E":
            total = total + (16 ** i) * 14
        elif x.upper() == "F":
            total = total + (16 ** i) * 15
        elif x.upper() == "0":
            total = total + (16 ** i) * 0
    #print("your decimal number is:", total)
    return total
def dec_to_oct(total):
    total = int(total)
    oct = 0
    i = 0
    while total > 0:
        digit = total % 8
        oct = oct + digit * (10 ** i)
        total = total //  8
        i = i + 1
    #print(oct)
    return oct if oct else '0'
#dec_to_oct()
def hex_to_oct(num):
    decimal_value = hex_to_dec(num)
    octal_value = dec_to_oct(decimal_value)
    #return octal_value

    return octal_value

#hexa_input =y
#octal_output = hex_to_oct(hexa_input)
#print(f"Hexadecimal: {hexa_input},octal: {octal_output}")

while True:
    print("**Numbering System Converter**\n""A) Insert a number\n""B) Exit program")
    choice1 = input("Please enter your choice (A/B):").upper()
    if choice1 == "A":
        num = input("Please insert a number:")
        print("Please select the base you want to convert a number from:\n"
              "A)Decimal\n""B)Binary\n""C)Octal\n""D)Hexadecimal")
        choice2 = input("Please enter your choice (A/B/C/D):").upper()
        if choice2 not in ["A", "B", "C", "D"]:
            print("Please enter a valid choice")
            continue

        print("Please select the base you want to convert a number to:")
        print("A)Decimal\n""B)Binary\n""C)Octal\n""D)Hexadecimal")
        choice3 = input("Please enter your choice (A/B/C/D):").upper()
        if choice3 not in ["A", "B", "C", "D"]:
            print("Please enter a valid choice")
        elif choice2 == "B" and choice3 == "A":
            num = int(num)
            print(bin_to_dec(num))
        elif choice2 == "A" and choice3 == "D":
            num = int(num)
            print(dec_to_hex(num))
        elif choice2 == "C" and choice3 == "A":
            num = int(num)
            print(oct_to_dec(num))
        elif choice2 == "A" and choice3 == "A":
            num = int(num)
            print(num)
        elif choice2 == "B" and choice3 == "B":
            num = int(num)
            print(num)
        elif choice2 == "C" and choice3 == "C":
            num = int(num)
            print(num)
        elif choice2 == "D" and choice3 == "D":
            num = str(num)
            print(num)
        elif choice2 == "D" and choice3 == "A":
            num = str(num)
            print(hex_to_dec(num))
        elif choice2 == "A" and choice3 == "B":
            num = int(num)
            print(dec_to_bin(num))
        elif choice2 == "A" and choice3 == "C":
            num = int(num)
            print(dec_to_oct(num))
        elif choice2 == "B" and choice3 == "C":
            num = int(num)
            # decimal_value = bin_to_dec(num)
            octal_value = dec_to_oct(num)
            print(f"Binary: {num}, Octal: {bin2oct(octal_value, num)}")
        elif choice2 == "B" and choice3 == "D":
            num = int(num)
            hexa_value = dec_to_hex(num)
            print(f"Binary: {num},Hexadecimal: {bin2hex(hexa_value, num)}")
        elif choice2 == "C" and choice3 == "B":
            num = int(num)
            binary_value = dec_to_bin(num)
            print(f"Octal: {num},Binary : {oct_to_bin(binary_value, num)}")
        elif choice2 == "C" and choice3 == "D":
            num = int(num)
            # decimal_value = bin_to_dec(num)
            hexa_value = dec_to_hex(num)

            print(f"Octal: {num}, Hexa: {oct_to_hex(hexa_value, num)}")
        elif choice2 == "D" and choice3 == "B":
            num = str(num)
            #octal_value = dec_to_oct(num)
            print(f"Hexadecimal: {num},Binary: { hex_to_bin(num)}")
        elif choice2 == "D" and choice3 == "C":
            num = str(num)
            # octal_value = dec_to_oct(num)
            print(f"Hexadecimal: {num},octal: {hex_to_oct(num)}")
    elif choice1 == "B":
        print("Exit program")
    else:
        print("Please select a valid choice")
