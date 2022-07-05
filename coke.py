# %%
amount_due = 50
while amount_due > 0:
    print(f"Amount Due: {amount_due}")
    payment = input("Insert Coin: ")
    amount_due = amount_due - int(payment)
amount_due = abs(amount_due)
print(f"Change Owed: {amount_due}")


# %%
