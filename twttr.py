# %% [markdown]
# *Twttr
# Take user imput and suppress all vowels from it's string
# %%
def main():
    user_imput = input("Input: ").strip()
    supressVowels(user_imput)
# %%


def supressVowels(input):
    vowels = ["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]
    for i in input:
        if i not in vowels:
            print(i, end="")


# %%
main()
