
op = int(input("1)Kg->lb\n2)mi->m\n3)m->ft\n"))

res = 0.0
if op==1:
    num = float(input("Introduce los kg que quieras convertir: "))
    res = num * 2.20462
    print(res,"lb")
elif op==2:
    mi = float(input("Introduce las millas que quieras convertir: "))
    res = (mi * 1609.344)/1000
    print(res,"M")
else:
    m = float(input("Introduce los metros que quieras convertir: "))
    res = m * 3.28084
    print(res,"Ft")
