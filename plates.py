def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s: str):
    if 2 <= len(s) <= 6 and s[0:2].isalpha() and s.isalnum():
        if s.isalpha():
            return True
        else:
            for i in range(len(s) - 1):
                if s[i].isdecimal() == True:
                    if s[i] == "0":
                        return False
                    elif s[i:].isdigit() == True:
                        return True
    else:
        return False


main()
