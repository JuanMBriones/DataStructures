class Circulo:
        pi = 3.1416
        def __init__(self, radio):
            self.radio = radio
        def perimetro(self):
            return 2.0 * self.pi * self.radio
        def area(self):
            return self.pi * (self.radio * self.radio)

a = 1
periTotal = 0
areaTotal = 0

while a>0:
    print("0)Salir\n1)Agregar circulo\n2)Area total\n3)Perimetro total")
    a = int(input())
    if a==1:
        radio = float(input("Radio del circulo: "))
        c1 = Circulo(radio)
        periTotal += c1.perimetro()
        areaTotal += c1.area()
    elif a==2:
        print("Area total es:", areaTotal)
    elif a==3:
        print("Perimetro total es:", periTotal)
    else:
        break
