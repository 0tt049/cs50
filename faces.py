def main():
    userImput = input("Say something: ")
    convert(userImput)


def convert(imput):
    print(imput.replace(":)", "🙂").replace(":(", "🙁"))


main()
