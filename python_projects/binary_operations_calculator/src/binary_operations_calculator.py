
# ones complement
def ones_complement(num_bin):
    one = ""

    for bit in num_bin:
        if bit == '0':
            one = one + '1'
        elif bit == '1':
            one = one + '0'
        else:
            return "Please enter a valid number"

    return one
    m = ones_complement(num_bin)
# num_bin = str(input("Enter your binary number:"))
# print("your One's complement is:", ones_complement(num_bin))



# two complement
# num = input("Enter your binary number:\n")
def two_complement(m, b):
    max_len = max(len(m), len(b))
    m = m.zfill(max_len)
    b = b.zfill(max_len)
    res = ''
    carry = 0
    for i in range(max_len - 1, -1, -1):
        if int(m[i]) + int(b[i]) + carry == 0:
            res = '0' + res
            carry = 0
        elif int(m[i]) + int(b[i]) + carry == 1:
            res = '1' + res
            carry = 0
        elif int(m[i]) + int(b[i]) + carry == 2:
            res = '0' + res
            carry = 1
        elif int(m[i]) + int(b[i]) + carry == 3:
            res = '1' + res
            carry = 1
    if carry == 1:
        res = '1' + res
    return res
    # print ("two’s complement is:" ,res)
# two_complement(num,b)


#Addition

# num_bin= input("Enter the first binary number:\n")
# num_bin2 = input("Enter the second binary number:\n")
def binary_addition(num_bin, num_bin2):
    max_len = max(len(num_bin), len(num_bin2))
    num_bin = num_bin.zfill(max_len)
    num_bin2 = num_bin2.zfill(max_len)
    result = ''
    carry = 0
    for i in range(max_len - 1, -1, -1):
        if int(num_bin[i]) + int(num_bin2[i]) + carry == 0:
            result = '0' + result
            carry = 0
        elif int(num_bin[i]) + int(num_bin2[i]) + carry == 1:
            result = '1' + result
            carry = 0
        elif int(num_bin[i]) + int(num_bin2[i]) + carry == 2:
            result = '0' + result
            carry = 1
        elif int(num_bin[i]) + int(num_bin2[i]) + carry == 3:
            result = '1' + result
            carry = 1
    if carry == 1:
        result = '1' + result
    return result
    # print (num_bin ,"+",num_bin2,"=",result)
# binary_addition(num_bin,num_bin2)


#Subtraction

# bin_num = input("Enter the first binary number:\n")
# bin_num2 = input("Enter the second binary number:\n")
def binary_subtraction(bin_num3, bin_num):
    max_len = max(len(bin_num), len(bin_num3))
    bin_num = bin_num.zfill(max_len)
    bin_num3 = bin_num3.zfill(max_len)
    result = ""
    borrow = 0
    for i in range(max_len - 1, -1, -1):
        bit1 = int(bin_num[i])
        bit2 = int(bin_num3[i])
        diff = bit2 - bit1 - borrow
        if diff < 0:
            diff += 2
            borrow = 1
        else:
            borrow = 0
        result = str(diff) + result
    return result.lstrip("0") or "0"
# result = binary_subtraction(bin_num, bin_num3)
# print("The sub is:",result)


while True:
    print("**Binary Calculator**\n""A) Insert new number\n""B) Exit Program")
    choice1 = input("Enter your choice (A/B):").upper()
    if choice1 == "A":
        num_bin = input("Enter your binary number:")
        b = "1"
        m = ones_complement(num_bin)
        length = len(num_bin)
        #while True:

        for i in range(length):


                x = num_bin[i]
                if x not in ("0","1"):
                    print("Please enter a valid number")
                    break




        else:
                print("the num is valid")

                print("*Please select an operation*\n""A) Compute one’s complement\n"
                      "B) Compute two’s complement\n""C) Addition\n""D) Subtraction")
                choice2 = input("Enter your choice (A/B/C/D):").upper()
                if choice2 == "A":
                    print("Your one’s complement is:", ones_complement(num_bin))
                elif choice2 == "B":
                    print("Your two’s complement is:", two_complement( m,b))
                elif choice2 == "C":
                    num_bin2 = input("Enter your second binary number:")
                    print("The sum is:", binary_addition(num_bin, num_bin2))
                elif choice2 == "D":
                    num_bin3 = input("Enter your second binary number:")
                    print("the sub is:", binary_subtraction(num_bin3, num_bin))
                else:
                    print("Please enter a valid choice")

                    break




    elif choice1 == "B":
        print("Exit Program")
    else:
        print("Please enter a valid choice")


