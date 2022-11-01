import cs50


def main():
    user_number = cs50.get_int("Number: ")
    brand = firstCheck(user_number)
    if brand != False and checksum(user_number) == True:
            print(brand)
    else:
        print("INVALID")

def firstCheck(cardNumber):
    card_string = str(cardNumber)
    card_length = len(card_string)
    if card_length == 15 and int(card_string[0] + card_string[1]) in [34, 37]:
        return "AMEX"
    elif card_length == 16 and int(card_string[0] + card_string[1]) in [51,52,53,54,55]:
        return "MASTERCARD"
    elif card_length == 13 or card_length == 16 and int(card_string[0]) in [4]:
        return "VISA"
    return False

def checksum(cardNumber):
    card_string = str(cardNumber)
    even_number = 0
    odd_number = 0
    for i in range(len(card_string) - 2, -1, -2):
        if int(card_string[i]) * 2 < 10:
            even_number += int(card_string[i])*2
        else:
            even_number += 1 + (int(card_string[i]) * 2 ) - 10
    for i in range(len(card_string) - 1, -1, -2):
        odd_number += int(card_string[i])
    if int(str(odd_number + even_number)[-1]) == 0:
        return True
    return False

if __name__ == "__main__":
    main()

