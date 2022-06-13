from cs50 import get_string

text = get_string("Text: ")
letcount = wordcount = sentcount = i = 0
length = len(text)


while i < length:
    if text[i].isalpha():
        letcount += 1

    if text[i] == " ":
    #     wordcount += 1
    # if (i == 0 and text[i] != " ") or (i != length and text[i] == " " and text[i + 1] != " "):
        wordcount += 1

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


    from cs50 import get_string

from cs50 import get_string

text = get_string("Text: ")
letcount = wordcount = sentcount = i = 0
length = len(text)
wordlist = text.split()
wordcount = len(wordlist)


while i < length:
    if (text[i] > chr(64) and text[i] < chr(91)) or (text[i] > chr(96) and text[i] < chr(123)):
        letcount += 1

    # if wordcount == len(wordlist):
    #     wordcount += 1
    # if (i == 0 and text[i] != " ") or (i != length and text[i] == " " and text[i + 1] != " "):
        # wordcount

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


# def main():

#     text = get_string("Text: ")

#     letnum = count_letters(text)
#     wordnum = count_words(text)
#     sentnum = count_sentences(text)
#     letavg = (letnum * 100) / wordnum
#     sentavg = (sentnum * 100) / wordnum
#     grade = (0.0588 * letavg) - (0.296 * sentavg) - 15.8

#     count_letters()
#     count_words()
#     count_sentences()

#     if (round(grade) > 1 and round(grade) < 16):
#         print("Grade %i\n", roundgrade)
#     if (round(grade) < 1):
#         print("Before Grade 1\n")
#     if (round(grade) >= 16):
#         print("Grade 16+\n")


# def count_letters(word):
#     letnum = 0
#     for i in word:
#         letter = word[i]
#         if (letter.isalpha):
#             letnum += 1
#     return letnum

# def count_words():
#     wordnum = 0
#     for chars in word:
#         letter = word[chars]
#         if (letter.isspace):
#             wordnum += 1
#     return wordnum

# def count_sentences():
#     sentnum = 0
#     for chars in word:
#         letter = word[chars]
#         if (letter == '.' or letter == '?' or letter == '!'):
#             sentnum += 1
#     return sentnum


# main()