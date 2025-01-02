# Problem 67 Maximum path sum 2 (see Problem 18 for part 1)
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
import csv

start_time = time.time()

import csv

triangle_row = []
triangle_array = []


with open('Problem67_data.txt') as csv_file:
    csv_reader = csv.reader(csv_file, delimiter=' ')
    for row in csv_reader:
        for data in row:
            triangle_row.append(int(data))
        triangle_array.append(triangle_row)
        triangle_row = []
          
max_chunk_size = 19
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

heighest_num = 0
for x in triangle_array[len(triangle_array) - 1]:
    if x > heighest_num: heighest_num = x

print("Heighest number  = ", heighest_num)
print("--- %s seconds ---" % (time.time() - start_time))  
