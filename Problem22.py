# Problem 22 - Name Scores



# Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

# For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

# What is the total of all the name scores in the file?

import csv

names_list = []
total_score = 0

with open('Problem22_names.txt', "r") as names_file:
    csv_reader = csv.reader(names_file, delimiter=",")
    for row in csv_reader:
        for name in row: names_list.append(name)

names_list.sort()
for pos, name in enumerate(names_list):
    score = 0
    for letter in name:
        score += (ord(letter) - 64)
    total_score += score * (pos + 1)

print(total_score)

