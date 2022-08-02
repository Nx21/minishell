
a = int(input())
b = int(input())

while b != 0:
    if a > b:
        a = a - b
    else:
        b = b - a
print(a)