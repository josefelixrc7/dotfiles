# Red Hat Enterprise Linux Technical Overview

## ¿Qué es Linux, software de código abierto y una distribución?



## Introducción a la shell

* Es el entorno en el que se trabaja
* Red Hat utiliza la Shell Bash por defecto
* Cuando se está en la shell bash, se puede ver el signo `$`, que indica que se ha iniciado sesión como un usuario normal.
* Cuando se ve un signo `#` es porque se ha iniciado sesión como usuario administrativo
* El usuario administrativo en Linux se llama root
* Cuando se lee documentación y se tiene que ejecutar un comando con  el signo `$`, significa que no se necesita ser administrador para ejecutar ese comando. Cuando se tiene `#`, el comando debe de ser ejecutado como usuario  `root`.
* Los argumentos son los objetos con los que trabaja un comando
* Desde la shell, uno de los comandos interesantes es el comando man, el cual da acceso al manual del comando. Que indica qué hace el comando y cómo funciona. También nos indica la serie de opciones que tiene ese comando.

### Los manuales

* En un manual, lo que está encerrado entre corchetes son entidades opcionales, esto nos quiere decir que podemos ejecutar el comando sin esa opción, o, en algunas ocasiones, el comando solo. Como lo dice, son opcionales, se pueden prescindir de ellas. 

* Los tres puntos suspensivos en un manual nos indica que el comando soporta varias opciones a ser ejecutadas, o, un argumento puede ser utilizado múltiples veces.

* En algunos manuales, sale la opción `[FILE]`, esto nos indica que podemos ejecutar el comando a un archivo. Es decir, este argumento es un archivo, y es opcional si se está con corchetes.

* En la sinopsis (Synopsis), muchas veces se pueden ver argumentos que son de la forma: `-a, --All` esto nos indica que se puede usar cualquiera de los dos, significan lo mismo, se puede usar como argumento `-a` o `--All`.

  ```bash
  $ ls -a
  ```

* Cuando las opciones entre corchetes están separadas por un pipe `|` es porque solo debe usarse una opción.

* Para salir de una página de manual presiona la tecla `q`.

### La shell remota

* la ssh o *secure shell* es un protocolo para conectarse remotamente a un servidor.

* La sintaxis para hacerlo es:

  ```bash
  ssh usuario@servidor
  ```

  

* Cuando se inicia sesión hay que fijarse en el prompt, cuando estás en tu computadora dice: `tu_usuario@tu_pc` y cuando te conectas por ssh dice: `usuario@servidor`.

## El kernel y espacios de usuario

* El kernel es el corazón del sistema operativo Linux, es responsable de programar los procesos en ejecución, archivos y seguridad. 
* El trabajo de la shell es apoyar a programas que ejecutan los usuarios, como la un navegador web u otro programa. 
* Cada espacio tiene un espacio de memoria virtual privado.
* Los procesos también tienen estado, para saber si se está ejecutando actualmente. 

* ¿Cómo identificar un proceso? Los procesos tienen IDs únicas comúnmente conocidas como PID.

### Tipos de procesos

* Procesos de usuario: está relacionado con un usuario particular que esté ejecutando algún programa
* Proceso de gruñido completo (foreground process): es cuando se está recibiendo información de una terminal, porque controlan el prompt de la shell. Muchas veces están en segundo plano, pero no toman información de la terminal, sino que muestran información en la terminal. 
* Demon process: son procesos que no están asociados con la terminal en lo absoluto. Ellos se ejecutan y piden recursos al kernel para proporcionar cosas como recursos de red, tareas te mantenimiento, entre otros. 
* Kernel threads (procesos hilos del kernel): estos procesos son parte del kernel y se ejecutan como si fueran procesos de usuario normal o demonio, pero, no está asociado con la terminal. Hay partes del kernel que son representadas como si fueran procesos regulares.

### Obteniendo información acerca de los comandos

* Se utiliza el comando `ps`. Si se corre este comando directamente en la terminal, se verán procesos asociados con la shell. 
* TTY quiere Tele Type (tipo de terminal).
* Para obtener más información acerca de todos los procesos del sistema se usa `ps -ef`
* La opción `-e` del comando `ps` muestra todos los procesos del sistema, la opción `f` muestra más información detallada acerca de los procesos.
* PPID quiere decir *Parent Process ID*.
* Mayormente, se puede ver el dueño del proceso en corchetes `[]`.



## Orientación a la interfaz gráfica de usuario

* La GUI de RHEL8 y  está impulsada por GNOME3.
* Para cambiar de espacios de trabajo en GNOME3 pulsamos `Ctl + alt + Arriba`, puede ser arriba o abajo.



## File management in Linux

* En Linux, todas las cosas son archivos.
* Si se quiere obtener más información acerca de un archivo, se utiliza `ls -l`.
* En un archivo listado con `ls -l` se pueden ver archivos como con unos permisos parecidos a: `drwxr-x--x`, la `d` quiere decir que es un directorio. Cuando se tiene un guión `-` (dash) es porque es un archivo. Cuando se puede ver algo como `lrwxr-x--x`, la `l` quiere decir que es un *link*.
* Un link es un archivo especial que apunta hacia otro.
* 