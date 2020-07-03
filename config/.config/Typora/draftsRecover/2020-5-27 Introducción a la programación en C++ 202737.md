# Introducción a la programación en C++

José Félix Rivas Carrasco

Primera edición



Excepto donde se indique lo contrario, este documento está bajo licencia de Creative Commons Atribución CompartirIgual 4.0 Internacional por José Félix Rivas Carrasco. Para ver una copia de esta licencia, visite

[Creative Commons License B-SA]: http://creativecommons.org/licenses/by-sa/4.0/	"Licencia BY-SA de Creative Commons"



## Resumen



## Prefacio

C++ es un lenguaje de programación multiplataforma, alto nivel, portátil, multiparadigma, derivado de C. Se desarrolló con el propósito de extender al lenguaje C.

Fue creado en 1979 por Bjarne Stroustrup, el nombre colocado a C++ en el laboratorio de pruebas era C con clases (C with classes), hacien referencia que sería un lenguaje de programación orientado a objetos.

Su última versión estable es la ISO/IEC 14882:2017 (de 2017), mayormente conocido como C++17. La versión de pruebas más reciente es C++20.




## Índice

[TOC]


En C++ los métodos de las clases abstractas se definen como funciones virtuales puras. 

`<<` y `>>`: Son operadores inteligentes, se adaptan al tipo de dato que reciben (excepto para los creados para el usuario, para ello hay que definir el comportamiento de esa entrada/salida.

¿Por qué los miembros deben de iniciarse sólo en el constructor de la clase en la que fueron declarados?

C++ provee una lista de inicializadores de miembros, también llamada inicializadora de constructores

A los objetos constantes no se les puede poner un valor después de la declaración. La lista de inicializadores de miembros puede ser usada para objetos normales también



## Otros

Whitespaces: todo lo que sea tabulación, espacio en blanco, saltos de línea, etc.

Expressions: las expresiones, son cualquier parte de un programa que retorne un valor (la suma de algo, por ej.)

Operador: es aquel símbolo que le dice al compilador que realice una operación (tanto una asignación, multiplcación, lo que sea)

El punto `.` es el operador de selección para objetos normales. En punteros, el operador de selección es `->`

- `#` operador de preprocesador, son sentencias exclusivas para que las lea este
- 



## 1. Conceptos básicos

### Resolución de problemas mediante el pensamiento lógico

El razonamiento es la habilidad del ser humano de evaluar opciones y elegir la más adecuada mediante el pensamiento lógico

Este tipo de pensamiento es:

* Deductivo: parte de ideas generales para llegar a conclusiones específicas
* Analítico: se desglosan las ideas para tener un entendimiento del problema
* Organizado: organiza las ideas para analizarlas una detrás de otra

#### Abstracción y detección de variables

El pensamiento lógico permite abstraer un programa, es decir, retener la información relevante de una situación o problema 

#### Resolución de problemas

Para abstraer un problema, debemos de hacer lo siguiente:

1. Identificar la necesidad o problema
2. Abstrae los componentes elementales del problema y determina las variables
3. Identifica restricciones (la necesidad o problema está ligada a restricciones que deben cumplirse)
4. Escribe los pasos a seguir para solucionar el problema
5. Resuelve el problema siguiendo los pasos anteriores
6. Evalua el exito de la propuesta una vez implementado

### Diseño de algoritmos

Un algoritmo es una serie de instrucciones detalladas, finitas y escritas en un lenguaje cotidiano

Sirven para resolver problemas o ejecutar acciones mediante el pensamiento lógico

#### Tipos

* Cualitativos: se utilizan para describir los pasos a seguir en actividades diarias (preparar una bebida o peinarse)
* Cuantitativos: se basan en operaciones matemáticas

#### Definiendo un algoritmo

1. Define las entradas del proceso (elementos necesarios para realizar una acción)
2. Define las acciones (Enumera cada instrucción del proceso)
3. Define el resultado al cual se pretende llegar

### Operadores aritméticos

Son aquellos que permiten realizar operaciones matemáticas

Al realizar operaciones con operadores, agrupa con paréntesis para fácilitar el cálculo

### Operadores lógicos



## La programación 

* Los programas ejecutan bloques de instrucciones de código escritos en algún lenguaje de programación, estos hacen posibles las acciones de los usuarios por medio de un equipo de cómputo
* Un lenguaje de programación es como un idioma, pero en vez de ser para los humanos, este es para comunicarse con una máquina
* Los lenguajes de programación tienen reglas para poder escribir su *idioma*, conocido como sintaxis; además de palabras claves, simbolos, estructuras del lenguaje (semántica)
* El propósito de un programa es de resolver un problema
* Los computadores o máquinas no pueden entender los lenguajes de programación directamente, para ello, estos son convertidos












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
int main()
{
    /* 
    	Autor: 		José Rivas
    	Plataforma: Linux
    	Versión: 	1.0.3
        Comentarios:Los comentarios multilínea son especiales
        			al momento de tener mucho contenido que comentar. 
        			E, incluso, cuando necesites que cierta parte
    */
    
    return 0;
}
```





### Variables

Global variables: estas son declaradas fuera de cualquier función en programa de C++. Estas están disponibles para cualquier parte del programa

### Entrada del usuario



### Variables que no varían: constantes

Hay tres tipos de constantes, simbólicas,  literales y enumeradas. `true` y `false` son constantes literales

#### Constantes simbólicas

Son aquellas que son representadas por un nombre, como una variable.

```c++
const int KILL_BONUS = 5000;
```

#### Constantes literales

Son aquellas que sólo son léidas y sustituidas por el precompilador antes de compilar el programa. Lo que hace es sustituir cada similitud con el valor. Como no se tiene un tipo de dato, el compilador no asegura que la constante tiene valor propio.

```c++
#DEFINE KILLBONUS 5000
```

#### Constantes enumeradas

Son aquellas que se crean en una sola sentencia con la palabra clave `enum`

```c++
enum COLOR
{
	red,
	blue,
	yellow
};
```

Cada una de ellas tendrá un valor; red tendrá 0, blue 1 y yellow 2.

También puedes asignar los valores

```c++
enum COLOR
{
	red,
	blue = 100,
	yellow
};
```

Cada una de ellas tendrá un valor; red tendrá 0, blue 100 y yellow 101.

- `sizeof()`: muestra el tamaño de un tipo de dato

## 

## 2. Tipos de datos



### Types (tipos)

En C++ un tipo es un objeto con información y un set de habilidades. El mecanismo para crear nuevos tipos es creando clases. Las clases serán luegos discutidas en profundidad.

Se definen los siguientes conceptos para poder saber de que se está hablando:

* Tipo (type): un tipo de dato define una cantidad de posibles valores o también de operaciones que tendrá, este concepto está asociado al concepto de *objeto*.
* Objeto (object): un objeto es un lugar de memoria que maneja un valor de un tipo de dato que fue establecido previamente.
* Valor (value): un valor es un conjunto de bits guardados en un objeto según un tipo de dato preestablecido.
* Variable (variable): es el *nombre* de un objeto.
* Declaración (declaration): es una sentencia que le establece el nombre a un objeto (en sí, se declara una variable).
* 



### Tipos de datos en C++

* `short` (también conocido como `short int`): almacena 2 bytes
* `int`: almacena 4 bytes
* `long` (también conocido como `long int`): almacena 4 bytes
* `long long int`: almacena 8 bytes
* `char`: almacena 1 bytes
* `bool`: almacena 1 bytes
* `float`: almacena 8 bytes
* `double`: almacena 8 bytes

### Definiendo tipos de datos

La palabra reservada `typedef` ppermitedefinir un tipo de dato, ejemplo:

```c++
typedef unsigned short int MI_INT;

MI_INT valor = 25;
```

## 

### Operadores

#### Operadores matemáticos

#### Precedencia de operadores

1. Potencias
2. Multiplicación y divisón
3. Módulo y resto
4. Suma y resta

Los operadores son sumamente importantes para la construcción de sistemas complejos.

#### Operadores relacionales



#### Operadores lógicos

Estos se utilizan para evaluar expresiones que contienen operadores relacionales. La finalidad es determinar si la expresión total es `true` o `false`. Estos determinan el valor booleano de una expresión

Tipos de operadores:

| Operador | Conocido como                 | Significado                                                  |
| :------: | ----------------------------- | ------------------------------------------------------------ |
|    &&    | Operador de conjución o `AND` | Si ambas expresiones son verdaderas, la expresión general será verdadera. Más si una de las expresiones es falsa, y la otra verdadera, la expresión general será falsa |
|   \|\|   | Disyunción u `OR`             | Si al menos una de las expresiones es verdadera, la expresión general será verdadera. Si todas las expresiones son falsas, la expresión general será falsa |
|   NOT    | Negación                      | Esta cambia el resultado de la expresión general: si después de evaluar las expresiones, la expresión general resulta verdadera, `NOT` hará que esta cambie a falsa |



### Cadenas de texto



### Expresiones matemáticas



### ¿Verdadero o falso?



### Conversiones seguras

Como se puede ver, en anteriores casos, el tipo de dato `char` se puede comparar a un tipo de dato `int` e incluso a un `double` y otros más. C++ provee formas para realizar conversiones en ambos casos. Las siguientes conversiones son seguras:

* `bool` a `char`
* `bool` a `int`
* `bool` a `double`
* `char` a `int`
* 

## 3. Condiciones



### La sentencia `if` y sus variaciones



### Un `if` diferente: `switch`



## 4. Ciclos o bucles



### Los ciclos con `for`



### Los ciclos con `while`



### Un ciclo especial: `do-while`



### Paradas y continuaciones en los ciclos: `break` y `continue`



### For-loops avanzados

```c++
for(int x = 0, int y = 0; x < 10; x++, y++)
{
	std::cout << x * y << endl;
}
```



## 5. Vectores

Los vectores son la forma más simple y sencilla de almacenar información en forma de lista.

### Declarando vectores

```c++
vector<tipo_dato> nombre_Variable;
```

```c++
vector<int> numeros = {23, 12, 55, 34};
std::cout << "Vector tiene un tamaño de: " << numeros.size(); << "\n";

std::cout << "numeros[1]: " numeros[1] << "\n";
numeros[1] = 24;
std::cout << "numeros[1]: " numeros[1] << "\n";
```

*Tenemos un vector de 4 enteros*

```c++
vector<string> guitarras = 
{
    "Fender",
    "Gibson",
    "Martin",
    "Jackson",
    "Ibanez"
};
```

Se puede declarar un vector sin inicializar sus elementos, solo dando el tamaño del vector

```c++
vector<double> sueldos(5);
```

### Atravesando vectores

Estos pueden ser fácilmente atravesados por un ciclo, ya sea `for`, `while` o `do-while`

```c++
vector<int> puntaje = {5, 8, 2, 9};
for(int a = 0; a < puntaje.size(); a++)
{
    std::cout << "\nPuntaje " << a << ": " << puntaje[a];
}
```

Podemos asignarle valores a un vector mediante un ciclo:

```c++
vector<int> puntaje(5)
for(int a = 0; a < puntaje.size(); a++)
{
    std::cout << "\nEscriba su puntaje " << a << ": ";
    std::cin >> puntaje[a];
}
```



### Usando un `range-for-loop`

Este tipo de bucle es muy útil, ya que solo iterará por la cantidad de elementos que este posea

```c++
vector<string> carros = 
{
    "Ford",
    "Chevrolet",
    "Renault",
    "BMW",
    "Mercedez"
};
for(string valor : carros)
{
    std::cout << valor << "\n";
}
```

### Agregando elementos

La función `push_back()` de un vector permite añadir un elementos más a este, incluso luego de haber sido declarado con un número determinado de elementos.

```c++
vector<char> abecedario;
abecedario.push_back('a');	// Añade la letra a en la posición abecedario[0]
abecedario.push_back('b');	// Añade la letra a en la posición abecedario[1]
abecedario.push_back('c');	// Añade la letra a en la posición abecedario[2]
abecedario.push_back('d');	// Añade la letra a en la posición abecedario[3]
```



## 5. Arreglos o colecciones

Es necesario inicializar los miembros estáticos de manera explícita, no importa que no hayan objetos creados. 

### Casos básicos de arreglos

```c++
int numeros[4];

numeros[0] = 21;
numeros[1] = 22;
numeros[2] = 23;
numeros[3] = 24;

float pesos[2] = {0.25, 0.56};

float pesos[] = {0.25, 0.56};
```

Saber el tamaño de un array con `sizeof`

- esta es una función `built-in`

```c++
const int size = sizeof(numeros) / sizeof(numeros[0]);
```

Se puede inicializar un array con pocos valores

```c++
int edad[5] = {12, 36};
```

## 

### Arreglos y los ciclos



### Arreglos de varias dimensiones

```c++
int edad[5] = {12, 36};

int box[5][3] = { 8, 6, 7, 5, 3, 0, 9, 2, 1, 7, 8, 9, 0, 5, 2 };

int box[5][3] = {
	{8, 6, 7},
	{5, 3, 0},
	{9, 2, 1},
	{7, 8, 9},
	{0, 5, 2} 
};

box[5][3] = 12;
```

### Realizando cálculos con arreglos

### Character Array

Una cadena es un array de caracteres (estos terminan en un caracter especial `\0`

```c++
char yum[] = { 
	''‘Z’, ‘o’, ‘m’, ‘b’, ‘i’, ‘e’, ‘ ‘,’E’,’a’,’t’,’ ‘, ‘B’, ‘r’, ‘a’, ‘i’, ‘n’, ‘s’, ‘\0’ 
};

char yum[] = "Zombie Eat Brains"; // Podemos ignorar el símbolo, el compilador no coloca automáticamente
```

## 

## 6. Prefacio a los punteros



### Entendiendo los punteros

Son lo que le dan la potencia a C++ y es lo que lo diferencia de muchos otros lenguajes.

- Los punteros son para señalar cosas
- Un punteros sirve para señalar al objeto al que nos estamos refieriendo (y para manipularlos)
- Cada byte de la memoria tiene una dirección llamada dirección de memoria. Cada dirección de memoria contiene un byte.
- El microprocesador trabaja con *word*, su unidad básica.
- Dependiendo del microprocesador, una palabra (word) puede estar compuesta de 8, 16, 32, 64 bytes, etc. Dependiendo de la plataforma.
- La mayor parte de los objetos que usamos en nuestros programas no caben en una dirección de memoria
- Para poder utilizar objetos que ocupen más de un byte podemos usar direcciones de memoria correlativas
- Si un objeto ocupa 4 bytes, la idea será usar la dirección de memoria de la primera posición n del objeto, las otras 3 posiciones se calcularán de n a n + 3
- Un puntero contiene la dirección de memoria de un objeto
- En la dirección de memoria puede haber cualquier tipo de objeto (char, int, float)
- Los punteros apuntan a un tipo en específico
- A diferencia de las variables, que almacenan información en la memoria de la computadora, los punteros son variables especiales que almacenan direcciones de memoria. Estos permiten manipular la memoria de la computadora directamente en un programa.

```c++
int* var1;

int* var2, var3;
```

El puntero solo apunta a la primera variable declarada (var1 y var2). En este ejemplo, es un puntero a *int*. En el caso de `var3` es sólo es un objeto tipo int. 

See lee como *var1 ... es un objeto del tipo puntero a...*

### Punteros a objetos

Esto es lo fundamental de un puntero, el apuntar a objetos.

- Para saber la dirección de memoria de cualquier objeto, usamos el operador de dirección o de referencia `&`. Se lee como *la dirección de...*

```c++
int num1;
int* p;

p = &num1;
```

El puntero `p` contiene la dirección de memoria de `num1`

### Objeto apuntado

Lo contrario a la dirección de memoria es el objeto apuntado, para hacer esto usamos el operador de indirección o de desreferencia `*`. Es el mismo usado para crear punteros, pero con otro fin. Se lee como *el objeto apuntado por...*

```c++
int edad1 = 25;
int edad2;
int* p = &edad2;

*p = edad1;
```

Al objeto apuntado por p (edad2) le asignamos el valor de edad1

Para evitar que los punteros creados contengan basura, le asignamos un valor.

```c++
int* var1 = 0;
```

Se le asigna ese valor ya que es un puntero a `int`, aún no apunta a un objeto (no tiene la dirección de memoria de un objeto)

Por referencia

```c++
int num1;
int &num2 = num1;
```

En este ejemplo, tanto `num1` como `num2` son los mismos, ccualquier cambio que se haga en uno se hará en otro

- Hay que recordar que `*` crea un puntero, más si se utiliza de la siguiente forma:

```c++
int v1;
int* v2;
int v3;

v2 = &v1; // Le asignamos la dirección de v1 al puntero v2
v3 = *v2; // Le asignamos el valor del objeto apuntado
```

La expresión `*v2` se lee como *el valor u objeto apuntado por v2*.

- Una cosa importante es:
  - La dirección (de memoria) que un puntero maneja
  - El valor de la dirección (de memoria) que un puntero maneja
- Luego que el puntero se le asigna una dirección de memoria, se puede usar el puntero para acceder a los datos almacenados en la variable u objeto.
- El valor de un puntero es la dirección de memoria de un objeto
- NOTA: Ahora, ¿por qué guardar un valor en un puntero cuando tenemos acceso desde la variable? Si es más cómodo y más fácil acceder a la variable. Bueno, la respuesta a esto es que con ello demostramos cómo trabajan los punteros. 

### Uso de los punteros

Los punteros son más comúnes para las siguientes tres tareas:

1. Administrar información o data en el `heap` o `montón`
2. Acceso a información de miembros de clases y funciones
3. Pasar variables por referencia a funciones



## 7. Funciones



### Aclarando el concepto de función y su importancia con la OOP

Las funciones correctas están hechas para realizar una tarea, tareas más complejas deben dividirse en múltiples funciones

Local variables: una variable creada dentro de una función se llama variable local. Los parámetros de una función también se consideran variables locales



### Creando funciones



### Llamadas a funciones



### Parametros o argumentos



* Tipos de parámetros
  * Por valor
  * Por referencia



### Sobrecarga de funciones



### Casos especiales de parámetros



* Parámetros por defecto

  Cuando una función se declara con un parámetro por defecto, este puede ser omitido al llamar la función

  ```c++
  int año(int anno = 2020)
  {
  	return anno + 2;
  }
  int main()
  {
  	anno();
  }
  ```

  Esto retorna 2022

* Pasando arreglos como parámetros

* Parámetros por referencia



## 8. Introducción a la OOP



### Los paradigmas



### El concepto de abstracción



### Entendiendo las clases



### ¿Crear, declarar o instanciar?



## 10. Estructuras y uniones

Las estructuras son un tipo de dato estructurado parecidos a los arrays.

Nos permiten manipular registros que tengan alguna relación. Son muy parecidos a los registros de las bases de datos.

- Podemos definir objetos dentro de ellas
- Tanto el identificador como los objetos dentro son opcionales, pero al menos uno debe de estar
- Una vez definida la estructura, se puede referenciar como cualquier otro tipo
- Las estructuras y las clases son muy similares
- Las estructuras deben usarse para definir tipos o funciones que sean sencillas, de fácil manipulación
- Estas también tienen constructores y destructores

Sintaxis:

```c++
struct identificador {
   	tipo variable;
	tipo variable;
} nombreObjeto;
```

Ejemplo

```c++
struct cliente 
{
	char nombre[50];
	int edad;
} robert;

int main()
{
	std::cout << cliente.nombre << "\n";
	return 0;
}
```

En el ejemplo anterior se definió una estructura de tipo `cliente` cuyo objeto es `robert`.

Inicialización de estructuras

```c++
struct A {
   	int i;
   	int j;
   	int k;
};

struct B {
   	int x;
   	struct C {
		char c;
      		char d;
   	} y;
   	int z;
};

A ejemploA = {10, 20, 30};
B ejemploB = {10, {'a', 'b'}, 20};
```

Asignación de estructuras

```c++
struct complejo {
   complejo() { real=0; imaginario = 0; }
   complejo(double r, double i) { real=r; imaginario = i; }
   complejo(double r) { real=r; imaginario = 0; }
   double real;
   double imaginario;
};
```

Arrays de estructuras

```c++
struct cliente
{
	char nombres[50];
	char empresa[50];
	float pagos[100];
} activos[100];
```

```c++
std::cout << activos[56].nombres;
```

El ejemplo anterior muestra los nombres del cliente activo 56

Estructuras anidadas

```c++
struct clientes
{
	struct personal
	{
		char nombres[20];
		char apellidos[20];
		short edad;
	}
	bool activo;
	char expiracion[10];
};

struct pedidos
{
	char producto[50];
	clientes cliente;
	float precio;
};
```

### Union (unión)

Las uniones son un tipo especial de estructuras, permiten almacenar diferentes elementos en las mismas posiciones de memoria (no a la vez)

Las uniones toman el valor de memoria del tipo que almacene más memoria

- Tienen las mismas características de las estructuras

```c++
struct vector
{ 
   	int X, Y, Z; 
};
 
union unCoor3D 
{ 
   	struct vector v1; 
   	int coordenada[3]; 
} Punto;

Punto.v1.Y = 15;
Punto.coordenada[0] = 23;
```

Estructuras anónimas

```c++
union unCoor3D 
{ 
	struct
	{ 
	   	int X, Y, Z; 
	};
   	int coordenada[3]; 
} Punto;

Punto.Y = 15;
Punto.coordenada[0] = 23;
```

Inicialización de uniones

```c++
unEjemplo x = {10}; // int
unEjemplo y = {'a'}; // char
unEjemplo z = {10.02}; // double
```

Se deben inicializar igual que los arreglos y las estructuras. Se inicializan con llaves un por uno, ya que todos los elementos tienen la misma posición de memoria.

Usando discriminadores

Las uniones son perfectas cuando queremos crear arrays que contengan diferentes tipos de datos.

Ejemplo: una biblioteca

```c++
struct tipoLibro 
{
    	int codigo;
    	char autor[80];
    	char titulo[80];
    	char editorial[32];
    	int anno;
};

struct tipoRevista 
{
    	int codigo;
    	char nombre[32];
    	int mes;
    	int anno;
};

struct tipoPelicula 
{
    	int codigo;
    	char titulo[80];
    	char director[80];
    	char productora[32];
    	int anno;
};

enum eEjemplar 
{ 
	libro, 
	revista, 
	pelicula 
};

struct tipoEjemplar 
{
    	eEjemplar tipo;
    	union 
	{
        	tipoLibro l;
        	tipoRevista r;
        	tipoPelicula p;
    	};
};

tipoEjemplar bibliotecaCentral[10];

bibliotecaCentral[0].tipo = 

```

- Según ANSI, todos los elementos dentro de las estructuras deben de ser públicos



## 10. Clases, objetos y métodos



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

#### Funciones miembros constantes

Esto indica que la función no cambiará el valor de ningún miembro de la clase.

```c++
void saludar() const;
```

- Los getters mayormente deben de ser constantes
- Es buena programación declarar las funciones miembro como constantes tanto que sea posible

Cuando se usa &variable como argumento se está referenciando
Cuando se usa *variable como argumento se está desreferenciando

#### Funciones miembro estáticas

Los miembros estáticos son aquellos los cuales no importa la cantidad de objetos diferentes se creen, la información dentro de estas funciones será la misma para todas. Si se cambia la información de estas a partir de un objeto se cambiará para todos los objetos.

```c++
#include <iostream>
using namespace std;
 
class Numero {
  public:
   Numero(int v = 0);
   ~Numero();
   
   void Modifica(int v);
   int LeeValor() const { return Valor; }
   int LeeCuenta() const { return Cuenta; }
   int LeeMedia() const { return Media; }
   
  private:
   int Valor;
   static int Cuenta;
   static int Suma;
   static int Media;
   
   void CalculaMedia();
};
 
Numero::Numero(int v) : Valor(v) { 
   Cuenta++; 
   Suma += Valor;
   CalculaMedia();
}
 
Numero::~Numero() {
   Cuenta--;
   Suma -= Valor;
   CalculaMedia();
}
 
void Numero::Modifica(int v) {
   Suma -= Valor;
   Valor = v; 
   Suma += Valor;
   CalculaMedia();
}
 
// Definición e inicialización de miembros estáticos
int Numero::Cuenta = 0;
int Numero::Suma = 0;
int Numero::Media = 0;
 
void Numero::CalculaMedia() {
   if(Cuenta > 0) Media = Suma/Cuenta;
   else Media = 0;
}
 
int main() {
   Numero A(6), B(3), C(9), D(18), E(3);
   Numero *X;
 
   cout << "INICIAL" << endl;
   cout << "Cuenta: " << A.LeeCuenta() << endl;
   cout << "Media:  " << A.LeeMedia() << endl;

   B.Modifica(11);
   cout << "Modificamos B=11" << endl;
   cout << "Cuenta: " << B.LeeCuenta() << endl;
   cout << "Media:  " << B.LeeMedia() << endl;
    
   X = new Numero(548);
   cout << "Nuevo elemento dinámico de valor 548" << endl;
   cout << "Cuenta: " << X->LeeCuenta() << endl;
   cout << "Media:  " << X->LeeMedia() << endl;

   delete X;   
   cout << "Borramos el elemento dinámico" << endl;
   cout << "Cuenta: " << D.LeeCuenta() << endl;
   cout << "Media:  " << D.LeeMedia() << endl;

   return 0;
}
```

#### Funciones miembro inline

Cuando llamamos a una función normal, el compilador lo que hace es llamar a la función que creó anteriormente. Si una función es llamada de 10 veces, se crea una copia una vez y esa copia es llamada 10 veces, la función no se copia 10 veces. Las funciones inline lo que hace es que el compilador las copia (exactamente) cada vez que se hace una llamada a la función, se copia el código de las sentencias en el lugar donde se llama la función, 

- Estas funciones pueden permitir que el programa sea más rápido.
- La idea es que las funciones sean pequeñas, porque el ejecutable tendrá mayor tamaño

```c++
inline void sumar();
```

## 

## 11. Punteros



### Áreas de memoria

Los programadores mayormente operan con 5 área de memoria:

1. Espacio de nombres global (Global namespace): aquí están las variables globales.

2. El montón (the heap): aquí se reserva la memoria dinámicamente.

3. Registros: estos son usados para *internal housekeeping functions*.

4. Espacio de código (Code space): aquí se almacena el código.

5. La pila (the stack): aquí se almacenan las variables locales y los parámetros de funciones.

### Problemas comúnes

El problema de las variables locales es que no son persistentes, cuando la función retorna valores, estas son desechadas. Las variables globales solventan ese problema, más admiten otro problema que es que se puede acceder desde cualquier lugar a ellas. Colocar datos en el *heap* solventa estos dos problemas

### Stack o pila

El stack es conocido como pila, se le conoce así por su concepto de trabajo LIFO (last in first out). El primero en salir de la pila es aquel que esté en el tope

La pila (stack) es limpiada automáticamente cuando una función retorna su valor. Todas las variables son desechadas

### El montón, almacenamiento libre o heap

El heap es conocido como almacenamiento libre o *el montón*, el heap permite almacenar memoria dinámicamente. También en él son almacenadas las variables globales y estáticas

El montón o heap funciona de esta manera: debemos pensar en ellos como miles de cubículos enumerados que esperan por tu información. Estos cubículos no pueden ser etiquetados. Hay que preguntar por su dirección de memoria y reservarla en un puntero.

Propongamos un ejemplo: un centro de atención al cliente

Un centro de atención al cliente tiene miles de personas trabajando, esperando a que se reciba una llamada para atenderla. Cuando un cliente llama a la empresa, uno de esos miles o cientos de empleados contesta la llamada. El cliente no sabrá cuál es número personal del que le atendió, ni cómo llegar a él; solo sabe que al llamar a ese número general de atención al cliente se le atenderá

- El espacio libre o montón (heap) no es limpiado cuando tu programa termina y es tu responsabilidad limpiar cualquier espacio de memoria que hayas utilizado. La ventaja del heap es que la memoria que hayas reservado se mantiene así hasta que la liberes. Si reservas memoria en el heap mientras estés en una función, esta memoria seguirá disponible cuando la función retorne
- La ventaja de reservar memoria en el heap (a diferencia del global namespace) es que sólo las funciones con acceso al puntero pueden acceder a la información.

### Trabajando en el heap: `new` y `delete`

Estos son peradores de manejo de memoria.

`new` sirve para reservar memoria dinámica y `delete` para limpiar o desreservar ese espacio de memoria. 

```c++
signed short int* valor;
valor = new signed short int;
delete valor;
```

También podemos inicializar o reservar la memoria desde la declaración:

```c++
signed short int* valor = new signed short int;
delete valor;
```

Asignando un valor

```c++
valor = 205;
```

¿Qué quiere decir esto? Esto representa lo siguiente: asígnale el valor 205  al área del heap apuntada por `valor`. Se recuerda que, en este caso, `valor` apunta a una dirección de memoria del tipo `signed short int`

```c++
char* nombre;

nombre = new char[20];

nombre = "Jose";
delete[] nombre;
```

Podemos ver que `nombre` se crea apuntando a `char`, luego se inicializa con `new` para que `nombre` apunte a un array de 20 elementos tipo `char`

`tablaSalarios` se crea apuntando a un puntero que apunta a `float`, luego con `new`para que `tablasSalarios` apunte a un puntero que apunta a un array de 10 elementos tipo float.

```c++
int* edad;

edad = new int(45);
std::cout << edad << "\n";
delete[] edad;
```

Primero, edad apunta a `int` (un espacio de memoria tipo `int` o  entero). Luego, con `new`, le asignamos al espacio de memoria el valor 45.

### Fuga de memoria  y punteros extraviados

Cuando reservamos memoria dinámicamente con `new`  en una función y la función retorna y no liberamos la memoria reservada en el heap se produce algo llamado fuga de memoria (memory leak). Recordemos, también, que cuando nuestro programa finalice, esa memoria seguirá estando reservada.

Otra forma de crear fugas de memoria es cuando reservamos consecutivamente memria dinámicamente en un mismo puntero sin antes borrar el espacio reservado anteriormente.

```c++
short int *entero = new short int;
*entero = 50;
entero = new short int;
*entero = 100;
```

Hacer lo anterior es incorrecto y crea fugas de memoria que pueden ir consumiendo memoria de la máquina. Es sumamente importante asegurarse de que la memoria sea liberada o que vuelva al heap, por cada `new` que tengamos debe de haber un `delete`.

Parecido a la fuga de memoria, están los punteros extraviados (stray pointers), estos se producen cuando se intenta acceder a un puntero 

### Creando objetos en el Heap o espacio libre

Así como se pueden crear punteros que apunten a direcciones de memoria tipo `int`, `float`, `char`, entr otros; también puedes crear punteros que apunten a objetos de clases. Es decir, puedes crear objetos en el Epacio libre (heap) como también en la pila (stack).

```c++
class carro
{
    public:
    	carro();
    	~carro();
};
carro::carro()
{
    std::cout << "Llamada al constructor.\n";
}
carro::~carro()
{
    std::cout << "lamada al destructor.\n";
}
int main()
{
    carro *ford = new carro;
    delete ford;
}
```

*Se puede ver el funcionamiento del puntero `ford` inicializado en el heap.*

#### Miembros de datos en el heap

De igual forma, se pueden crear miembros de datos en el heap, haciendo de los punteros una herramienta muy interesante para la manipulación de información almacenando todo en memoria, dinámicamente. 

```c++
class carro
{
    public:
    	carro();
    	~carro();
    
    	unsigned short int getAnno() const { return *anno; }
    	void setAnno(unsigned short int a){ *anno =  a; }
    
    private:
    	unsigned short int *anno;
};
carro::carro()
{
    *anno = NULL;
}
carro::~carro()
{.
    delete anno;
}
int main()
{
    carro *ford = new carro;
    std::cout << "Año del carro: " << ford->getAnno(); << "\n";
    
    ford->setAnno(1950);
    std::cout << "Año del carro: " << ford->getAnno(); << "\n";
    
    delete ford;
    return 0;
}
```



### Punteros de punteros

Creamos una tabla dinámicamente. Los arrays normales deben de tener establecido el número de elementos cuando se está creando el programa. En cambio, los arrays dinámicos pueden ser definidos durante la ejecución.

```c++
float** tablaSalarios;

tablaSalarios = new *float[10];

for(int a = 0; a < 10; a++) tablaSalarios[a] = new float[10]; // Ahora tablaSalarios es un array de 10 * 10

tablaSalarios[5][2] = 41.98;

// Liberar memoria dinámica

for(int a = 0; a < 10; a++) delete[] tablaSalarios[a];
delete[] tablaSalarios;
```

Podemos crear arrays dinámicos de cualesquieras dimensiones

### Usando el puntero `this`

* Toda función miembro tiene un parámetro oculto: el puntero `this`
* Su función es apuntar al objeto que invocó a la función
* Este puntero es útil es distintas ocasiones, cabe destacar que muchas veces es mal utilizado y puede ser redundante.

```c++
class carro
{
    public:
    	carro();
    	~carro();
    
    	short getAnno() const { return anno; }
    	short getModel(){ return this->model; }
    
    private:
    	unsigned short int anno;
};
carro::carro()
{
    anno = 1910;
    model = 143;
}
carro::~carro()
{
    
}
int main()
{
    carro ford;
    std::cout << "Año del carro: " << ford.getAnno(); << "\n";
    std::cout << "Modelo del carro: " << ford.getModel(); << "\n";
    
    ford->setAnno(1950);
    ford->setAnno(223);
    std::cout << "Año del carro: " << ford.getAnno(); << "\n";
    std::cout << "Modelo del carro: " << ford.getModel(); << "\n";
    
    return 0;
}
```

Aunque en este caso no se le va mucha utilidad al puntero `this` este será discutido luego en profunfidad.

### Punteros constantes

Para declarar un puntero como constante basta de especificar la palabra reservada `const` antes o después del tipo de dato. 

## 12. Partes de la OOP



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



## 13. Plantillas



## 14. Funciones Lambda

 Estas funciones son incluidas a partir del standard C++11. Son un tipo de función especial con distintas ventajas, ya que, estas son creadas en tiempo de ejecución.

### Sintaxis

```c++
auto nombreFuncion = [valoresDeCaputura](parametrosNormales) -> tipoDato {
	sentencias...
};
```

* `nombreFuncion`: este es el nombre el cual la función tendrá para poder ser llamada
* `valoresDeCaptura`: aquí se escriben las variables que queremos que la función capture, aunque estén fuera de la función. Si queremos que capture todo lo que está en la pila (stack), usamos `&` para tener acceso por referencia. Si no quremos tener acceso por referncia sino crear copias, podemos usar `=`
* `parametrosNormales`: como cualquier función normal o método, esta función recibe parámetros
* `tipoDato`: este es el tipo de dato el cual será retornado (`int`, `float`, `char`, entre otros), podemos especificar `void` si no queremos retorno
* `sentencias`: son las acciones que realizará la función

```
class Foo
{
public:
    int m_attr;
    void foo()
    {
        auto f = [this](){};
            m_attr;
        };
    };
};
```

En este caso tenemos una clase `Foo`, queremos devolver  una función que tenga acceso a los parámetros de la clase, además  creamos una función lambda y en el cuerpo de captura podemos indicar que  capture el this. Con lo cual, inmediatamente, en la función lambda que  estamos declarando, si tenemos un atributo, en el cuerpo de la función  lambda podemos acceder directamente a esos atributos.

**Esto es muy interesante para hacer wrappers**, para  enviar datos a threads y compartir los datos entre ellos, o para generar  nuestras propias factorías de funciones, que se modifiquen dependiendo  del scope o dependiendo de la funcionalidad que nosotros queramos.

## 14. Excepciones



## 15. Trabajando con archivos

C++ ofrece la librería estandar `fstream` o *file stream*.

Esta librería define tres tipos de datos:

* `ofstream`: *out file stream* o salida de flujo de archivo, este crea y escribe información hacia y/o en archivos
* `ifstream`: *input file stream* o entrada de flujo de archivo lee información de archivos
* `fstream`: Flujo de archivo genérica, contempla ambas de capacidades, tanto de `ofstream` como de `ifstream` para escriber, leer, crear archivos

```c++
    file = new std::ofstream;
    file->open("data/backupsList.db", std::ios::app);

    if(file->is_open())
    {
        *file << "Hola" \n;
    }

    file->close();
    delete file;
```

Existen otros parámetros importantes para la función `open()`:

* `std::ios::app`: este agrega al final del archivo el contenido
* `std::ios::ate`: este va al final del archivo al abrir
* `std::ios::binary`: abre el archivo en modo binario
* `std::ios::in`: abre el archivo en modo solo lectura
* `std::ios::out`: abre el archivo en modo solo escritura
* `std::ios::trunc`: borra los contenidos del archivo si existen

## 16. Trabajando con bases de datos

## 17. Trabajando en simultáneo: hilos

Para trabajar con hilos debemos hacer uso de la librería estandar de C++ `std::thread`, la cual está disponible desde C++11

Un objeto del tipo `std::thread` crea un solo hilo de programa.

En Linux hay distintos tipos de programas multitareas o *multitasking*:

* Multitareas basadas en procesos: son los programas comúnes que la máquina permite correr en "simultáneo"
* Multitareas basadas en hilos: programas que se ejecutan más de una vez

Para crear un nuevo hilo solo se debe crear el objeto del tipo `std::thread` y pasarle la función a ejecutar

Podemos hacer hilos haciendo llamadas a:

* Funciones normales
* Funciones miembros u objetos
* Expresiones lambda

Ejemplo sencillo:

```c++
#include <iostream>
#include <thread>

void saludar(short valor)
{
	for(short a = 0; a < valor; a++)
	{
		std::cout << "¡Hola! " << a << "\n"; 
	}
}
void despedir(short valor)
{
	for(short a = 0; a < valor; a++)
	{
		std::cout << "¡Adiós! " << a << "\n"; 
	}
}
int main(int argc, char argv[])
{
	// Creamos los hilos
		std::thread hilo1(saludar, 5);
		std::thread hilo2(despedir, 5);
	// Esperamos a que terminen
		hilo1.join();
		hilo2.join();

	return 0;
}
```

Debemos enlazar a `pthread` para poder compilar con `g++ -lpthread`

## 18. Introducción a GTKmm







