from cs50 import get_string

text = get_string("Text: ")
letcount = wordcount = sentcount = i = 0
length = len(text)

wordlist = text.split()  # .split() splits text into a list of words
wordcount = len(wordlist)  # len() counts number of items in wordlist

while i < length:
    if (text[i] > chr(64) and text[i] < chr(91)) or (text[i] > chr(96) and text[i] < chr(123)):
        letcount += 1

    if text[i] == '.' or text[i] == '?' or text[i] == '!':
        sentcount += 1
    i += 1

L = (letcount / wordcount) * 100
S = (sentcount / wordcount) * 100
grade = round((0.0588 * L) - (0.296 * S) - 15.8)

if (grade > 1 and grade < 16):
    print(f"Grade {grade}")
elif (grade < 1):
    print("Before Grade 1")
elif (grade >= 16):
    print("Grade 16+")
