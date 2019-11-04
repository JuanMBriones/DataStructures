# Crea un convertidor de unidades que convierta de kilogramos a libras,
#de metros a pies y de millas a metros según elija el usuario


# Cómo dueño de Hashtags Inc. necesitas hacer un programa que imprima
#pirámides del caracter GATO según el tamaño que el usuario te pida.
#(ejemplo en el pizarrón)


opcion = int(input("1)Kg->lb\n2)m->ft\n3)mi->Km\n"))

resultado = 0.0
if opcion==1:
    opcion = int(input("1)Kg->lb\n2)lb->Kg"))
    kg = float(input("Introduce la unidad que quieras convertir: "))
    resultado = kg * 2.20462
    if opcion==1:
        print(resultado," lb")
    else:
        print(1/resultado," Kg")

elif opcion==2:
    opcion = int(input("1)m->ft\n2)ft->m"))
    m = float(input("Introduce la unidad que quieras convertir: "))
    resultado = m * 3.28084
    if opcion==1:
        print(resultado," ft")
    else:
        print(1/resultado," m")
else:
    opcion = int(input("1)mi->Km\n2)Km->mi"))
    mi = float(input("Introduce la unidad que quieras convertir: "))
    resultado = mi * 1.60934
    if opcion==1:
        print(resultado," Km")
    else:
        print(1/resultado," mi")
