#numero de letras
# 5 vidas
# preguntar las demas letras
import array as arr



from getpass import getpass
palabra = getpass("Introduce tu palabra secreta: ")
print(palabra)

#palabra = input("Introduce tu palabra secreta: ")
numeroLetra = len(palabra)


excepcionesNumeros = list()
palabraMisteriosa = '*' * numeroLetra

vidas = 5

def arrayContains(elemento):
    for i in excepcionesNumeros:
        if excepcionesNumeros[i]==elemento:
            return True

    return False


def printProperly():
    for i in range(numeroLetra):
        if arrayContains(palabra):
            print(palabra[i], end="")
        else:
            print(palabraMisteriosa[i],end="")
    print()

def contiene(letra):
    cont = 0
    global palabraMisteriosa
    for i, count in enumerate(palabra, 0):
        if palabra[i]==letra:
            excepcionesNumeros.append(i)
            cont = cont+1

    if cont>0:
        return True
    else:
        return False

while vidas>0:

    printProperly()
    print("Numero de vidas", vidas)
    letra = input("Introduce una letra: ")

    if contiene(letra[0])==False:
        vidas = vidas-1

if vidas==0:
    print("Valiste ")
else:
    print("Ganaste esta vez")
