# Problem 18 Maximum path sum I
#By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

#   3
#  7 4
# 2 4 6
#8 5 9 3

# That is, 3 + 7 + 4 + 9 = 23.

# Find the maximum total from top to bottom of the triangle below:

from bitarray import bitarray
from bitarray.util import *
import time

start_time = time.time()

triangle_array = [[75], 
    [95, 64],
    [17, 47, 82],
    [18, 35, 87, 10],
    [20, 4, 82, 47, 65],
    [19, 1, 23, 75, 3, 34],
    [88, 2, 77, 73, 7, 63, 67],
    [99, 65, 4, 28, 6, 16, 70, 92],
    [41, 41, 26, 56, 83, 40, 80, 70, 33],
    [41, 48, 72, 33, 47, 32, 37, 16, 94, 29],
    [53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14],
    [70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57],
    [91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48],
    [63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31],
    [4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23]]



max_chunk_size = 15
path_array = []
chunk_size = max_chunk_size
row = 0
max_rows = len(triangle_array)
temp_total_row = []

while(row < max_rows - 1):
    if(row + max_chunk_size <= max_rows):
        chunk_size = max_chunk_size
    else:
        chunk_size = max_rows - row

    path_array.clear()
    for x in range(2 ** (chunk_size - 1)):
        ba = int2ba(x, length=(chunk_size-1))
        path_array.append(ba)

    temp_total_row = triangle_array[row + chunk_size - 1].copy()

    for start_pos, start_num in enumerate(triangle_array[row]):
        
        for path in path_array:
            temp_row = row
            pos = start_pos 
            count = start_num

            for direction in path:
                temp_row += 1
                if (direction == True): pos += 1
                count += triangle_array[temp_row][pos]

            if(temp_total_row[pos] < count): temp_total_row[pos] = count

    for p, total in enumerate(temp_total_row):
        triangle_array[row + chunk_size -1][p] = temp_total_row[p]
    temp_total_row.clear()


    row += max_chunk_size - 1   

for x in triangle_array:
    print(x)

heighest_num = 0
for x in triangle_array[len(triangle_array) - 1]:
    if x > heighest_num: heighest_num = x

print("Heighest number  = ", heighest_num)
print("--- %s seconds ---" % (time.time() - start_time))  
