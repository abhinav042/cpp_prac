def binary_to_int(binary_string):
    binary_string = binary_string[::-1]
    num = 0
    index = 0
    for ch in binary_string:
        num = num + int(ch) * (2 ** index)
        index += 1
    return num
