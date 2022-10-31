import cs50
height = cs50.get_int(f"Height: ")
for i in range(1, height + 1):
    print(" " * (height - i) + "#" * i + "  " + "#" * i)