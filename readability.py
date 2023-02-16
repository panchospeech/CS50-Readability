from cs50 import get_string

text = get_string('Text: ')

letters = 0
words = 1  # starts with 1 because we are counting the spaces between words and that is 1 less than words
sentences = 0

# go through each element of the string and count the elements
for i in range(0, len(text), 1):
    if (text[i].isalpha()):
        letters += 1
    if (text[i].isspace()):
        words += 1
    if (text[i] == '.' or text[i] == '!' or text[i] == '?'):
        sentences += 1

# defining average of the elements in the formula
L = (float) (letters / words) * 100
S = (float) (sentences / words) * 100

# formula in float has to be transformed in int
index = round(0.0588 * L - 0.296 * S - 15.8)

# printed options
if (index < 1):
    print(f'Before Grade 1')

elif (index >= 16):
    print(f'Grade 16+')

else:
    print(f'Grade {index}')