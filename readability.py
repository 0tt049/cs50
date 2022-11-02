import cs50

# Asks user imput
text = cs50.get_string("Text: ")

letters = len(list(filter(str.isalpha, text)))
print(letters)
words = len(text.rsplit())
print(words)
sentences = len(text.rsplit(".")) - 1
print(sentences)

# Coleman algo
L = (letters / words) * 100
S = (sentences / words) * 100
indexfloat = (0.0588 * L) - (0.296 * S) - 15.8
index = round(indexfloat)

# Print result
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
