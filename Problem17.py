# Problem 17 - Number Letter Counts


#If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

#If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

#NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters. The use of "and" when writing out numbers is in compliance with British usage.


def SumOfLetters(list):
    total = 0
    for item in list:
        total += len(item)
    return total


digits_list = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
teens_list = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
 "seventeen", "eighteen", "nineteen"]
tens_list = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]
hundreds_list = ["hundred"]
thousands_list = ["onethousand"]

digits = SumOfLetters(digits_list)
teens = SumOfLetters(teens_list)
tens = SumOfLetters(tens_list)
hundreds = SumOfLetters(hundreds_list)
thousands = SumOfLetters(thousands_list)


OneToNineteen = digits + teens
TwentyToNinetyNine = (10 * tens) + (8 * digits) 
OneToNinetyNine = OneToNineteen + TwentyToNinetyNine
OnetoNineHNN = (100 * digits) + (900 * hundreds) + (891 * len("and")) + (10 * OneToNinetyNine)
OneToThousand = OnetoNineHNN + thousands

print(OneToThousand)

