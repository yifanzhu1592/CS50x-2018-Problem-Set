from cs50 import get_int

while True:
    print("Height: ")
    height = get_int()
    if 0 <= height <= 23:
        break

for i in range(height):
    print(" " * (height - i - 1) + "#" * (i + 1) + "  " + "#" * (i + 1))
