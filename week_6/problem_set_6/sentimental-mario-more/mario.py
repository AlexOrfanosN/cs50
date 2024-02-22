from cs50 import get_int

while True:
    height = get_int("Height: ")
    if 1 <= height <= 8:
        break

for i in range(height):
    # Print spaces
    print(" " * (height - i - 1), end="")

    # Print the first set of hashes
    print("#" * (i + 1), end="")

    # Print the gap
    print("  ", end="")

    # Print the second set of hashes
    print("#" * (i + 1))
