import matplotlib.pyplot as plt
import numpy as np
import os
import time

nhilos = 5
maxt = 0
mint = 10

tiempos=[]

plt.ion()
fig = plt.figure(figsize=(11,5))
plt.axis([0,20,0,3])

x = []

for hilos in range (1,nhilos+1):
    comando = "mat.exe "+ str(2**(hilos-1))
    start = time.time()
    os.system(comando)
    stop = time.time()
    if maxt<(stop-start):
        maxt=stop-start
    if mint > (stop-start):
        mint=stop-start
    plt.axis([0,2**(hilos-1),mint,maxt])
    tiempos.append(stop-start)
    #x = np.linspace(1, hilos, hilos)
    x.append(2**(hilos-1))
    plt.clf()
    plt.suptitle('Multiplicacion de matriz 2048x2048', fontsize=14, fontweight='bold')
    plt.subplot(121, title='Tiempo vs Numero de Hilos')
    plt.plot(x,tiempos,linestyle='-',marker='+', markeredgecolor='b', color='r')
    for a,b in zip(x, tiempos):
        plt.text(a, b, str(b)[0:5])
    plt.xlabel("Numero de hilos")
    plt.ylabel("Tiempo")
    plt.subplot(122, title='Speedup vs Numero de Hilos')
    plt.plot(x,  (np.asarray(tiempos[0]))/np.asarray(tiempos)*x ,linestyle='-',marker='+', markeredgecolor='b', color='r')
    for a,b in zip(x, (np.asarray(tiempos[0]))/np.asarray(tiempos)*x): 
        plt.text(a, b, str(b)[0:5])
    plt.xlabel("Numero de hilos")
    plt.ylabel("Speedup")
	
    plt.show()
    plt.pause(0.0001)

print tiempos
plt.show(block=True)



