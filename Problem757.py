#Problem 757
# A positive integer is stealthy, if there exist positive integers , , , such that and .
#For example,

#is stealthy.

#You are also given that there are 2851 stealthy numbers not exceeding


#How many stealthy numbers are there that don't exceed
#? 
#from operator import truediv
import time
import csv


start_time = time.time()

a = 2
b = c = d = 1
N = 1
count = 0
N_limit = 10000
file = open("p757.csv", 'w', encoding='UTF8', newline='')
writer = csv.writer(file)



for a in range(4, 1000):
    b = int(a/4)
    c = b + 1
    d = a + b - c - 1
    while b < a and a * b < N_limit:
              
        while c <= d and c < a:
            
            #ab = a * b
            #cd = c * d
            if a * b == c * d:
                #print(a, " ", b, " ", c, " ", d, " ", a * b, " ")
                if count > 0:
                    print("N = ", a * b, " count = ", count, " N/c = ", a * b / count)
                    row = [a * b]
                    writer.writerow(row)
                count = count + 1
            c = c + 1
            d = a + b - c - 1
            
        b = b + 1
        c = b + 1
        d = a + b - c - 1

print("time =", time.time() - start_time)
print("Number = ", count)
file.close()


