def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def egcd(a, b):
    if b == 0:
        return (a, 1, 0)
    else:
        (d1, x1, y1) = egcd(a, b)
        return (d1, y1, x1 - a // b * y1)
