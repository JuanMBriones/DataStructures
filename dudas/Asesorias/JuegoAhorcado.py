#numero de letras
# 5 vidas
# preguntar las demas letras
import array as arr

from getpass import getpass
palabra = getpass("Introduce tu palabra secreta: ")
print(palabra)

#palabra = input("Introduce tu palabra secreta: ")
numeroLetra = len(palabra)

palabraMisteriosa = "*" * numeroLetra

vidas = 5

def contiene(letra):
    cont = 0
    global palabraMisteriosa
    for i, count in enumerate(palabra, 0):
        if palabra[i]==letra:
            newWord = ""

            for index, char in enumerate(palabra, 0):
                if char==letra:
                    newWord += letra
                    continue

                if palabraMisteriosa[index] != "*":
                    newWord += char
                    continue
                newWord += "*"

            palabraMisteriosa = newWord
            cont = cont+1

    if cont>0:
        return True
    else:
        return False

while vidas>0:
    print(palabraMisteriosa)
    print("Numero de vidas", vidas)
    letra = input("Introduce una letra: ")

    if contiene(letra[0])==False:
        vidas = vidas-1

if vidas==0:
    print("Valiste ")
else:
    print("Ganaste esta vez")
