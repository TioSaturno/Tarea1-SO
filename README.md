<h1 align="center"> Tarea 1 Sistemas Operativos 2025-2 </h1>
<p align="left">
<img src="https://img.shields.io/badge/STATUS-COMPLETADO-green">
</p>
Esta tarea consta de un sistema de chat básico, en el cual hay 3 procesos principales, los cuales se comunican entre si mediante pipes con nombre.
Disclaimer: Este proyecto fue desarrollado en un entorno unix con una distribucion Ubuntu, hay una funcionalidad que solo funciona en distribuciones con gnome, tenga eso en cuenta
## :hammer: Instrucciones para la prueba
- `Paso 1`: Abra como minimo 4 terminales y ejectue "cd rutaenlaqueestanlosprogramas"
- `Paso 2`: Ejecute los siguientes comandos, cada uno en distintas terminales (gcc client hay que ejecutarlo en 2 terminales distintas): 
```
gcc cliente.c -o Cliente
gcc log.c -o Log
gcc reports.c Reportes

```
- `Paso 3`: Siguiente de esto, ejecute los siguientes comandos en sus respectivas terminales:
```
./Cliente
./Log
./Reportes
```
Y listo, en cada cliente puede seguir las instrucciones que le saldran, y al momento de mandar un mensaje el log leera cada uno de los mensajes en el orden de llegada. Junto con esto en la terminal de reportes saldran mensajes cada vez que alguien sea reportado y cuando alguien sea expulsado de este, gracias por su atencion:D