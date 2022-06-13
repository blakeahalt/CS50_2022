from cs50 import get_int


def main():
    while True:
        num = get_int("What's your credit card number? ")
        if num >= 0:
            break  # look for the valid case here and break

    if check_validity(num):
        print_brand(num)
    else:
        print("INVALID")


def check_validity(ccn):
    return checksum(ccn)


def checksum(ccn):

    sum = 0
    for i in range(len(str())):
        if i % 2 == 0:
            sum += ccn % 10
        else:
            digit = 2 * (ccn % 10)
            sum += digit // 10 + digit % 10
        ccn //= 10
    return sum % 10 == 0


def print_brand(ccn):

    if (ccn >= 34e13 and ccn < 35e13) or (ccn >= 37e13 and ccn < 38e13):
        print("AMEX")
    elif (ccn >= 4e13 and ccn < 5e12) or (ccn >= 4e15 and ccn < 5e15):
        print("VISA")
    elif ccn >= 51e14 and ccn < 56e14:
        print("MASTERCARD")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()

# from cs50 import get_string

# num = get_string("What's your credit card number? ")
# reverse = num[::-1]
# total_sum = sum ( [ (int(x) * 2) // 10 + ( (int(x) * 2) % 10) for x in reverse[1::2]]) + sum ( [int(x) for x in reverse[0::2]] )

# if total_sum % 10 == 0:
#     if len(num) == 15 and num[0:2] in ['34', '37']:
#         print("AMEX")
#     elif len(num) == 16 and num[0:2] in ['51', '52', '53', '54', '55']:
#         print("MASTERCARD")
#     elif len(num) == 13 or 16 and num[0] in ['4']:
#     # elif len(num) in [13, 16] and num[0] == '4': # This also works
#         print("VISA")
#     else:
#         print("INVALID")
# else:
#     print("INVALID")