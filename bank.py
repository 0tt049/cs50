greeting = input("").strip().lower()

if greeting.startswith("hello") == True:
    print(f"$0")
elif greeting.startswith("h") == True:
    print(f"$20")
else:
    print(f"$100")
