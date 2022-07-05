# %%
amount_due = 50
while amount_due > 0:
    print(f"Amount Due: {amount_due}")
    payment = input("Insert Coin: ")
    payment = int(payment)
    if payment == 25 or payment == 10 or payment == 5:
        amount_due = amount_due - payment
amount_due = abs(amount_due)
print(f"Change Owed: {amount_due}")


# %%
