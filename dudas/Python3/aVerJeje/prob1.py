from sympy import *

x = symbols('x')
expr = sin(x)/x;

a = int(input("Introduce el valor a que tienda x: "))

limit_expr = limit(expr, x, a)

print("lim x->{} {} = {}".format(a, expr, limit_expr))
