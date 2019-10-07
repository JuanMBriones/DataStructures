def paridad(num):
    temp = 0
    while temp<=num:
        if temp%2:
            print(temp, "IMPAR")
        else:
            print(temp, "PAR")
        temp = temp + 1

numero = int(input("Hasta que numero: "))
paridad(numero)
