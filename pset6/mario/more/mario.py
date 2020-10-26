from cs50 import get_int

luigi = 0

while True:
    luigi = get_int("Height: ")
    if luigi > 0 and luigi < 9:
        break

for i in range(1, luigi + 1):
    block = i
    space = luigi - block
    print(" " * space, end="")
    print("#" * block, end="")
    print("  ", end = "")
    print("#" * block, end="")
    print()
