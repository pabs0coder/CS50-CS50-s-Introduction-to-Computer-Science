from cs50 import get_string

card_number = get_string("Number: ")

digit_1 = int(card_number[0])
digit_12 = int(card_number[0:2])

if digit_1 == 4:
    print("VISA")
elif digit_12 == 34 or digit_12 == 37:
    print("AMEX")
elif digit_12 in range(51, 56) :
    print("MASTERCARD")
else:
    print("INVALID")