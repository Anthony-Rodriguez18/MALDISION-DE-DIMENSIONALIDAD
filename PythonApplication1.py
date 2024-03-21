import matplotlib.pyplot as plot
import math

def leer_archivo(nombre_archivo):
    distancias = []
    with open(nombre_archivo, 'r') as archivo:
        for linea in archivo:
            distancia = float(linea.strip())
            distancias.append(distancia)
    return distancias

dim = r'C:\Users\RVDO\source\repos\Maldicion\Maldicion\distancias_dim_5000.txt'
distancias = leer_archivo(dim)
inte = range(math.floor(min(distancias)), math.ceil(max(distancias)) + 2)

valores=[]
for i in range(0, 100):
    value = i * 0.3
    valores.append(value)


dc=[]
for i in range(0, 10):
    value = i * 3.5
    dc.append(value)

plot.hist(x=distancias, bins=valores, color='#F2AB6D', rwidth=0.85)
plot.title('Distancias eucledianas en dimension 5000')
plot.xlabel('distancias')
plot.ylabel('Frecuencia')
plot.xticks(dc)

plot.show() #dibujamos el histograma
nombre_archiv = r'C:\Users\RVDO\source\repos\Maldicion\Maldicion\distancias_dim_50.txt'