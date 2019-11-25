import sympy as sym
sym.init_printing()
x,y = sym.symbols('x,y')
#c1 = sym.Symbol('c1')

a1 = int(input("Introduce el coeficiente a1: "))
g1 = int(input("Introduce el grado de x1: "))

b1 = int(input("Introduce el coeficiente b1: "))
g2 = int(input("Introduce el coeficiente y1: "))

r1 = int(input("Introduce el resultado deseado del lado derecho de la ecuacion 1: "))
######
a2 = int(input("Introduce el coeficiente a2: "))
g3 = int(input("Introduce el grado de x2: "))

b2 = int(input("Introduce el coeficiente b2: "))
g4 = int(input("Introduce el coeficiente y2: "))

r2 = int(input("Introduce el resultado deseado del lado derecho de la ecuacion 2: "))

f = sym.Eq(a1*(x**g1) + b1*(y**g2) , r1)
g = sym.Eq(a2*(x**g3) + b2*(y**g4) , r2)

solution = sym.solve([f,g],(x,y))

#print(f)
#print(solution)
print("La solucion de la ecuacion en x = {}".format(solution[x]))
print("La solucion de la ecuacion en y = {}".format(solution[y]))
