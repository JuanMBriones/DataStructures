from sympy import *
from mpmath import *

x, y = symbols("x y")
print('#')
#f = ((mp.e)**(-(x**2)-(y**2)))
#print(integrate(f, (x, -oo, oo), (y, -oo, oo)).principal_value())
print(quad(lambda x,y: (((mp.e)**(-(x**2)-(y**2)))), [-inf, inf], [-inf, inf]))
print('#')
