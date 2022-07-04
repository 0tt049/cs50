# %%
def main():
    time = input("What time is it? ")
    if 7.0 <= convert(time) <= 8.0:
        print(f"breakfest time")
    elif 12.0 <= convert(time) <= 13.0:
        print(f"lunch time")
    elif 18.0 <= convert(time) <= 19.0:
        print(f"dinner time")
# %%


def convert(time):
    hour, minutes = time.split(":")
    decimalTime = int(hour) + int(minutes)/60
    return float(decimalTime)


# %%
if __name__ == "__main__":
    main()

# %%
