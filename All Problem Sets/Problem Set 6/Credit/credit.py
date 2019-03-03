from cs50 import get_int

def main():

    sum1 = 0
    sum2 = 0
    counter = 0
    amex = 0
    mastercard = 0
    visa = 0
    amex1 = 0
    mastercard1 = 0

    while True:
        cc_number = get_int("Number: ")
        if cc_number > 0:
            break

    cc_number1 = cc_number
    cc_number2 = cc_number

    cc_number //= 10
    while cc_number:
        if cc_number % 10 <= 4:
            sum1 += 2 * (cc_number % 10)
        else:
            sum1 += (2 * (cc_number % 10)) // 10 + (2 * (cc_number % 10)) % 10
        cc_number //= 100

    while cc_number1:
        sum2 += cc_number1 % 10
        cc_number1 //= 100

    sum3 = sum1 + sum2
    if sum3 % 10 != 0:
        print("INVALID")
        return 0
    else:
        while cc_number2 > 10:
            cc_number2 //= 10
            counter += 1
            if counter == 12 and cc_number2 % 10 == 4:
                visa = 1
            if counter == 13 and (cc_number2 % 10 == 4 or cc_number2 % 10 == 7):
                amex1 = 1
            if counter == 14 and cc_number2 % 10 == 3 and amex1 == 1:
                amex = 1
            if counter == 14 and (cc_number2 % 10 == 1 or cc_number2 % 10 == 2 or cc_number2 % 10 == 3 or cc_number2 % 10 == 4 or cc_number2 % 10 == 5):
                mastercard1 = 1
            if counter == 15 and cc_number2 % 10 == 5 and mastercard1 == 1:
                mastercard = 1
            if counter == 15 and cc_number2 % 10 == 4:
                visa = 1

    if cc_number2 == 3 and amex == 1 and counter == 14:
        print("AMEX")
    elif cc_number2 == 4 and visa == 1 and counter == 15:
        print("VISA")
    elif cc_number2 == 5 and mastercard == 1 and (counter == 12 or counter == 15):
        print("MASTERCARD")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
