def mmc(num1, num2):
    a = num1
    b = num2

    check = 0
    while check == 0:
        resto = a % b
        a  = b
        b  = resto

    return (num1 * num2) / a

print(mmc(561,1995))