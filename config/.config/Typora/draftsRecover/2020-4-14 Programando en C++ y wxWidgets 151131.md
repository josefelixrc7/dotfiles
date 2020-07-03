# Programando en C++ y wxWidgets



## Resumen



## Prefacio



## Índice



## 1. Conceptos básicos

### Tipos de aplicaciones

Para escritorio hay dos tipos de aplicaciones importantes en las cuales se trabajará:

* Desktop GUI App: estas aplicaciones cuentan con interfaz gráfica de usuario. Cuentan con botones, ventanas, campos, entre otros. Ejemplos: Code::blocks
* Desktop CLI App: estas aplicaciones cuentan con la interfaz de la línea de comandos, sea desde una terminal, emulador de terminal. Estas aplicaciones se pueden ejecutar mediante comandos. Ejemplos: git, ssh, httpd, entre otros.



### 1.1. Configuración del entorno de pruebas

* Si estás utilizando Linux

  Si estás utilizando alguna distribución basada en GNU/Linux o Unix, sigue estos pasos:

  1. Instala la última versión del compilador `g++`. 

  2. Instala las últimas versiones de las herramientas `Autotools` y `Automake`.

  3. Instala en tu máquina el IDE `Code::blocks`. Este es un entorno de desarrollo integrado especialmente dedicado para aplicaciones en C++, C, Arduino, wxWidgets, qt, entre otros. Busca en la web cómo instalarlo y configurarlo en tu máquina correctamente.

  4. Crea un carpeta en un lugar donde vayas a colocar tus proyectos (trata que los nombres de los directorios no tengan caracteres especiales o espacios).

     ```bash
     mkdir ~/cppProject
     ```

Las herramientas y softwares previamente recomendados no son obligatorios, puedes elegir el IDE, compilador y herramientas que necesites. Pero, ten en cuenta, todo lo enseñado será basado en las herramientas mencionadas.

### 2.1. Hola mundo

En la programación, el *Hola mundo* es muy famoso entre los desarrolladores. La sensación de ver esa impresión en pantalla por primera vez es algo que un desarrollador anhela; al solo verlo, desea adentrarse más en el mundo infinito de ese lenguaje de programación. A continuación, se verá cómo realizar el tan aclamado *Hola mundo* en **C++**, también veremos las distintas formas o variaciones de cómo hacerlo, al igual que se explicará en detalle, no tanto a nivel técnico (porque para hacer esto necesitaríamos conocimientos básicos de este lenguaje) sino a nivel comparativo.



#### Caso práctico 1.1.: Tu primer *Hola mundo*

Para este caso, se creará una aplicación sin utilizar el IDE `Code::blocks`. Ve a tu carpeta de pruebas, crea una nueva carpeta llamada `test1`. Abre la carpeta que acabas de crear, crea un archivo llamado `test1.cpp`. Con tu editor de textos preferido (no con el IDE), abre el archivo `test1.cpp` y escribe lo siguiente:

```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "Hola mundo" << endl;
    return 0;
}
```

Ahora, guarda el archivo. Ve a la terminal, dirígite al directorio `test1` desde la terminal (Usa `cd ~/cppProjects/test1/`). Escribe:

```bash
g++ test1.cpp -o test1
```

Si vas al administrador de archivos y ves el contenido de la carpeta `test1`, podrás notar que hay un nuevo archivo, un archivo llamado `test1` si estás en Linux. Si estás en Windows, verás `test1.exe`.



#### Explicación del caso 1.1.

Revisemos el código línea a línea y entendamos que se está haciendo:

* `#include <iostream>`: en C++ se suelen incluir archivos de cabeceras o *headers files*, estos headers incluyen funciones, métodos, objetos, clases, entre otras cosas; necesarias para un programa. Si alguien quiere construir una silla, necesita primero tener las herramientas necesarias para crearla. En un programa de C++, las herramientas las proporcionan los archivos de cabeceras. Más adelante se explicará cómo crear archivos de cabecera y utilizarlos en una aplicación.
* `using namespace std;`: esta parte es un poco complicada de entender. En español lo que quiere decir esta sentencia es: "Usar el espacio de nombres std". Donde, `std` quiere decir *estandar*. 
* `int main()`: esta es la función principal que se ejecuta en tu aplicación. Es parecida a `static void Main()` de Java o de C#. Cuando arranca un aplicación, lo primero que ejecuta es esta función. Más adelante se hablará acerca de funciones en detalle.
* `cout << Hola mundo << endl;`: Esta sentencia imprime en pantalla *Hola mundo* y `endl` da un salto de línea. Fíjate que esta sentencia termina en `;`. Todas las sentencias terminan en `;` (no confundas sentencias con funciones o clases).
* `return 0`: Esta opción indica que todo ha finalizado normal. Si no se coloca habría un error al compilar la aplicación. 



### Salidas o impresiones

Las impresionas o salidas en pantalla son muy comunes para las Desktop CLI Apps, hay distintas formas de imprimir texto en pantalla, ya que, es muy útil al momento de interactuar con el usuario.



#### Caso práctico 1.2: impresión de texto

```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "Este es un texto" << " dentro de una sola línea" << endl;
    return 0;
}
```

En este ejemplo se puede ver que podemos concatenar varios textos en una sola línea.



#### Caso práctico 1.3: impresión de saltos de línea

```c++
#include <iostream>
using namespace std;

int main()
{
    cout << "Este es un texto" << endl << "de varias \n" << "líneas" << endl;
    return 0;
}
```

Este ejemplo podemos hacer uso tanto de `endl` como de `\n` para hacer saltos de línea. Se pueden hacer tantos saltos de línea sean necesarios.



### Comentarios

Los comentarios son muy útiles, ayudan a darle sentido al código, añaden documentación en el mismo código, ayuda a que desarrolladores trabajen y aporten mejoras a tu código. Sin comentarios, una aplicación está muy mal hecha. Hay que tener una disciplina estricta de comentarios, ya que esta ayudará a que la aplicación siga evolucionando y creciendo.



#### Caso práctico 1.4: comentarios de una línea

```c++
#include <iostream>
using namespace std;

int main()
{
    // Autor del código: José Rivas
    
    // Imprimimos un saludo
    	cout << "Hola, amigo.";
    // Imprimimos un salto de línea
    	cout << endl;
    // Imprimimos una pregunta
    	 cout << "¿Cómo estás?" << endl; // Este código imprime una pregunta importante
    return 0;
}
```

Como se puede ver, el comentar agrega mayor legibilidad al código, por lo que arreglar errores o mejoras será más rápido para el desarrollador.



#### Caso práctico 1.5: comentarios multilínea

```c++
#include <iostream>
using namespace std;

int main()
{
    /* 
    	Autor: 		José Rivas
    	Plataforma: Linux
    	Versión: 	1.0.3
        Comentarios:Los comentarios multilínea son especiales
        			al momento de tener mucho contenido que comentar. 
        			E, incluso, cuando necesites que cierta parte de
        			tu código no funcione, o, no sea leído por el
        			compilador simplemente agrégale comentarios
        			multilínea en vez de borrar el código.
    */
    
    return 0;
}
```

No dudes en utilizar estos comentarios para tus aplicaciones, le dará legibilidad a tu código que luego agredecerás.



#### Nota: aclarando el caso del `#`

En muchos lenguajes de programación, se utiliza el símbolo # (dash) para comentar líneas de código; pero, este no es el caso de C++. El compilador interpreta las líneas que empiezan por `#` como piezas fundamentales del código, etas añaden librerías o biblitecas, plugins, complements, APIs, entre otros. 



### Variables



### Entrada del usuario



## 2. Tipos de datos



### Operadores



### Cadenas de texto



### Expresiones matemáticas



### ¿Verdadero o falso?



## 3. Condiciones



### La sentencia `if` y sus variaciones



### Un `if` diferente: `switch`



## 4. Ciclos o bucles



### Los ciclos con `for`



### Los ciclos con `while`



### Un ciclo especial: `do-while`



### Paradas y continuaciones en los ciclos: `break` y `continue`



## 5. Arreglos o colecciones



### Casos básicos de arreglos



### Arreglos y los ciclos



### Arreglos de varias dimensiones



### Realizando cálculos con arreglos



## 6. Punteros



### Entendiendo los punteros



### Casos especiales de los punteros



## 7. Funciones



### Aclarando el concepto de función y su importancia con la OOP



### Creando funciones



### Llamadas a funciones



### Parametros o argumentos



* Tipos de parámetros
  * Por valor
  * Por referencia



### Sobrecarga de funciones



### Casos especiales de parámetros



* Parámetros por defecto
* Pasando arreglos como parámetros
* Parámetros por referencia



## 8. Introducción a la OOP



### Los paradigmas



### El concepto de abstracción



### Entendiendo las clases



### ¿Crear, declarar o instanciar?



## 9. Clases, objetos y métodos



### Creando clases



### Creando objetos



### Métodos: ¿algo familiar?

* ¿Funciones miembro o métodos?
* Formas de declarar métodos
* Creando métodos



### Casos especiales de métodos

* Constructores
* Destructores
* Getters 
* Setters



## 10. Partes de la OOP



### Variables que no varían: constantes



### Iniciando miembros



### Palabras claves

* `friend`
* `this`



### Especificadores de acceso



### Encapsulación



* Acceso a miembros privados



### Herencia



* Aplicando la herencia
* El especificador de acceso `protected`



### Polimorfismo

* Casos básicos de polimorfismo
* Las clases abstractas: funciones virtuales



## 11. Plantillas



## 12. Excepciones



## 13. Trabajando con archivos



## 14. Introducción a wxWidgets







