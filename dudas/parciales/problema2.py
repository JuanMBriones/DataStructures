# Cómo dueño de Hashtags Inc. necesitas hacer un programa que imprima
#pirámides del caracter GATO según el tamaño que el usuario te pida.
#(ejemplo en el pizarrón)


tam = int(input("Introduce el tamaño: "))

for i in range(1, tam+1):
    for j in range(0, i):
        print("#", end='')
    print()
