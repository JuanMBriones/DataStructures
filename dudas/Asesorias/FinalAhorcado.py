#numero de letras
# 5 vidas
# preguntar las demas letras

from getpass import getpass
palabra = getpass("Introduce tu palabra secreta: ")
#print(palabra)

#palabra = input("Introduce tu palabra secreta: ")
numeroLetra = len(palabra)

palabraMisteriosa = "*" * numeroLetra

vidas = 5

def contiene(letra):
    si_existe = False
    newWord = ""
    global palabraMisteriosa

    for index, char in enumerate(palabra, 0):
        if char==letra:
            newWord += letra
            si_existe = True
            continue

        if palabraMisteriosa[index] != "*":
            newWord += char
            continue

        newWord += "*"
    palabraMisteriosa = newWord
    #print(palabraMisteriosa)

    return si_existe


while vidas>0:
    print(palabraMisteriosa)
    if palabraMisteriosa==palabra:
        break
    print("Numero de vidas", vidas)
    letra = input("Introduce una letra: ")

    if contiene(letra)==False:
        vidas -= 1

if vidas==0:
    print("Valiste ")
else:
    print("Ganaste esta vez")
