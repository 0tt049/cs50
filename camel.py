# %%
def main():
    camelCase = input("camelCase: ").strip()
    camel2snake(camelCase)
# %%


def camel2snake(camel):
    for i in camel:
        if i.isupper() == 0:
            print(i, end="")
        else:
            i = i.lower()
            print(f"-{i}", end="")


# %%
main()
