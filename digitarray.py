# Digit Array
# v1
import time

class DigitArray:

    def __init__(self, number, length = 0):
        self.max_length = length
        self.base_number = number
        self.trimmed_number = self.trim_extra_digits(number)

    def trim_extra_digits(self, num):        
        strNum = str(num) [-self.max_length::] #picks the last max_lengths digits from the string
        return int(strNum)

    def multiply(self, num):
        return self.trim_extra_digits(self.base_number * num)
       
    def power(self, pwr):
        return self.recursive_power(self.trimmed_number, pwr)

    def value(self):
        return self.trimmed_number

    def change_length(self, length):
        self.max_length = length
        self.trimmed_number = self.trim_extra_digits(self.base_number)

    def recursive_power(self, base, exp):
        exp = int(exp)
        if (exp == 0): return 1
        temp = self.recursive_power(base, exp / 2)
        if (exp % 2 == 0):
            return self.trim_extra_digits(temp * temp)
        else:
            if (exp > 0):
                return self.trim_extra_digits(temp * temp * base)
            else:
                return self.trim_extra_digits(temp * temp / base)







