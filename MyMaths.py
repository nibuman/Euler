# MyMaths
# Common maths functions

def Common_Factors(num1, num2):
    common_factors = []
    products = [num1, num2]
    for x in range(1, min(products)):
        if num1 % x == 0 and num2 % x == 0:
            common_factors.append(x)
    return common_factors


# print(Common_Factors(123456789, 987654321))
