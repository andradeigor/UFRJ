h = 1000
v = 10


for i in range(100000):
    h_old = h
    h = h*1.01
    v = 0.99*v + 0.01*h_old

print(f"Humanos:{h} Vampiros: {v}") 