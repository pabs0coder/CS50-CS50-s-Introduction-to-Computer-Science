from sys import argv, exit
import itertools
import csv
import re
from collections import Counter

#check for command line arguments
if len(argv) != 3:
    print("Usage: python dna.py pattern.csv sample.txt")
    exit(1)

#files management (checked stackoverflow for help)
with open(argv[1], "r") as database:
    reading = csv.reader(database)
    pattern = [row for row in reading]

with open(argv[2], "r") as dna_sample:
    sample = dna_sample.read()

#print(pattern)
#print(sample)
#got extra information on geeksforgeeks to know how to do it

check =  []
for i in range(1, len(pattern[0])):
    counting = 1
    char = pattern[0][i]
    while char * counting in sample:
        counting +=1
    check.append(str(counting-1))

for j in range(1, len(pattern)):
    if pattern[j][1:len(pattern[0])] == check:
        print(pattern[j][0])
        exit(0)

print("No match")


    #else:
    #    print("No Match")


#testing = pattern[0]
#print(testing)
#for i in sample



#for i in range(0, len(sample)):

#    frequencies = {}

    #for char in pattern:
    #    while i in frequencies:
    #        frequencies[char] += 1
    #else:
    #    frequencies[char] = 1

#print(frequencies)