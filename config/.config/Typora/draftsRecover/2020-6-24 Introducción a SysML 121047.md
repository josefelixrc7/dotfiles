Introducción a SysML

## 1. Básico

### Definición

Lenguaje de modelado de sistemas (SysML): SysML es un lenguaje de modelado de arquitectura de uso general para aplicaciones de ingeniería de sistemas.

* SysML admite la especificación, análisis, diseño, verificación y validación de una amplia gama de sistemas y sistemas de sistemas. 
Estos sistemas pueden incluir hardware, software, información, procesos, personal e instalaciones.
* SysML es un dialecto de UML 2 y se define como un perfil UML 2. 
(Un perfil UML es un dialecto UML que personaliza el idioma a través de tres mecanismos: estereotipos, valores etiquetados y restricciones).
* SysML es una tecnología habilitadora para la Ingeniería de Sistemas Basada en Modelos (MBSE).

El SysML fue creado originalmente por el Proyecto de Especificación de Código Abierto SysML de los Socios de SysML en 2003. 
El SysML fue adaptado y adoptado por el Grupo de Gestión de Objetos (OMG) como OMG SysML en 2006. 

### Taxonomía

El SysML se compone de nueve (9) tipos de diagramas y Tablas de asignación para asignar elementos del lenguaje a través de los tipos de diagramas:

Diagrama | Abreviatura | Tipo de diagrama | Referencia a UML2 | Uso en SDLC
---|---|---|---|---
Diagrama de requisitos | REQ | Estructura estática [Declarativo] | N / A | Análisis de requisitos
Diagrama de casos de uso | UC | Comportamiento [No simulable] | Casos de uso | Análisis de requerimientos
Diagrama de actividades | ACT | Comportamiento dinámico [Simulable] | Actividades [Modificaciones menores] | Análisis de sistemas, análisis funcional, diseño de sistemas
Diagrama de secuencias | SEQ | Comportamiento dinámico [Simulable] | Secuencia | Diseño de sistemas 
Diagrama de máquina de estado | STD | Comportamiento dinámico [Simulable] | Máquina de estado | Análisis de sistemas, diseño de sistemas 
Diagrama de definición de bloques | BDD | Estructura estática [Definición de caja negra] | Clase  [modificaciones moderadas] | Análisis de sistemas, diseño de sistemas 
Diagrama de bloque interno | IBD         | Estructura estática [Definición de caja blanca] | Estructura compuesta [modificaciones moderadas] | Análisis de sistemas, diseño de sistemas 
Diagrama paramétrico | PAR         | Estructura estática [Definición de caja blanca] | N/A                                             | Análisis de sistemas, diseño de sistemas 
Diagrama de paquetes | PKG         | Estructura estática [Agrupación]                | Paquetes [Modificaciones menores]               | Todas las fases del SDLC 
Tabla de asignación |             | N/A  [Matriz de relaciones]                     | N/A                                             | Todas las fases del SDLC 

Cabe destacar que SDLC quiere decir *System Development Life Cicle* o Ciclo de Vida del Desarrollo de Software

### Por qué usar SysML

Si usted es un ingeniero de sistemas y desea mejorar la precisión y la eficiencia de sus comunicaciones con otros ingenieros de sistemas y otras partes interesadas del sistema y del negocio (por ejemplo, clientes, ingenieros de software, ingenieros eléctricos, ingenieros mecánicos), entonces debería considerar el uso de un modelo de arquitectura de sistemas Lenguaje (también conocido como Lenguaje de descripción de arquitectura) estándar como lengua franca (lenguaje común) para sus proyectos

El lenguaje de modelado de sistemas (SysML) se ha convertido en el lenguaje de modelado de arquitectura de sistema estándar de facto para aplicaciones de ingeniería de sistemas basados en modelos (MBSE). SysML es un dialecto de UML 2, que extiende el estándar del Lenguaje Unificado de Modelado (UML) para aplicaciones intensivas en software para que pueda aplicarse con éxito a las aplicaciones de Ingeniería de Sistemas.

Aquí hay una lista de razones por las cuales los ingenieros de sistemas pueden querer usar SysML y un enfoque de ingeniería de sistemas basado en modelos para su trabajo de misión crítica:

* Facilitar la comunicación entre varias partes interesadas en todo el ciclo de vida del desarrollo del sistema (SDLC), incluidos ambos lados del modelo V del sistema;
* Capture y gestione la propiedad intelectual corporativa relacionada con arquitecturas de sistemas, análisis, diseños y procesos;
* Facilitar los estudios de comercio y comparar y contrastar las soluciones "tal cual" y "ser";
* Proporcionar estructura escalable para la resolución de problemas;
* Proporcione ricas abstracciones para gestionar el tamaño y la complejidad;
* Explore múltiples soluciones o ideas simultáneamente con un riesgo mínimo; y
* Detecta errores y omisiones temprano en el ciclo de vida del desarrollo del sistema (SDLC)

### Quién creó SysML

El lenguaje de modelado de sistemas (SysML) fue creado por los socios de SysML, una asociación informal de expertos en ingeniería de sistemas y herramientas de modelado de software que fue organizada por Cris Kobryn en 2003 para crear un perfil (dialecto) del lenguaje de modelado unificado v. 2 (UML 2) que podría usarse para aplicaciones de Ingeniería de Sistemas.

Dado que Kobryn había liderado con éxito los equipos de diseño de lenguaje UML 1.xy UML 2.0, David Oliver y Sanford Friedenthal de INCOSE solicitaron que dirigiera su esfuerzo conjunto para responder al UML del Grupo de Gestión de Objetos para RFP de Ingeniería de Sistemas emitido en marzo de 2003. Como Presidente de los Socios de SysML, Kobryn acuñó el nombre de lenguaje "SysML" (abreviatura de "Lenguaje de modelado de sistemas"), diseñó el logotipo original de SysML y organizó el equipo de Diseño de lenguaje de SysML como un proyecto de especificación de código abierto.

David Oliver, copresidente del Grupo de trabajo de diseño impulsado por modelos INCOSE y miembro de INCOSE, fue un contribuyente fundamental para los socios de SysML durante todo el proyecto. Sandy Friedenthal, presidenta del Grupo de Interés Especial de Ingeniería de Sistemas de OMG, se desempeñó como Vicepresidenta de los Socios SysML durante el inicio del proyecto.

## 2. Diagrama de requisitos

### Requisito 

Un requisito (notación: rectángulo con palabra clave «requisito») es una capacidad o condición que un sistema debe ("debe") satisfacer. Un requisito funcional (palabra clave «funcionalRequirement ») especifica una función que un sistema debe realizar, mientras que un requisito no funcional (NFR) especifica criterios de calidad que se pueden utilizar para probar la efectividad de las funciones del sistema.

SysML predefine las siguientes especializaciones de estereotipo de NFR:

- «performanceRequirement»
- «interfaceRequirement»
- «designConstraint»
- «physicalRequirement»

### Diagrama de requisitos (REQ)

Un diagrama de requisitos de SysML es un diagrama estructural estático que muestra las relaciones entre las construcciones de requisitos ("requisitos"), los elementos del modelo que los satisfacen ("satisfacen" la dependencia) y los casos de prueba que verifican ("verifican" la dependencia ) ellos.

### Propósito

El propósito de los diagramas de requisitos es especificar requisitos funcionales y no funcionales dentro del modelo para que puedan rastrearse a otros elementos del modelo que los satisfagan y a los casos de prueba que los verifiquen.

## 3. Diagrama de casos de uso
Caso de uso: Un caso de uso (notación: oval / elipse) representa una transacción del sistema con un usuario externo del sistema, llamado Actor (notación: figura de palo). Los casos de uso a veces se consideran requisitos funcionales de alto nivel.

### Diagrama de casos de uso (UC): 
Un diagrama de casos de uso muestra las comunicaciones entre transacciones del sistema (casos de uso) y usuarios externos (actores) en el contexto de un límite del sistema (Asunto; notación: rectángulo). Los actores pueden representar software (personas, organizaciones, instalaciones), sistemas de software o sistemas de hardware. La definición de relaciones entre el sujeto del sistema y los actores del sistema es una forma informal efectiva de definir el alcance del sistema.

### Propósito

El propósito de los diagramas de casos de uso es proporcionar una vista de alto nivel del sistema en cuestión y transmitir los requisitos del sistema de nivel superior en términos no técnicos para todas las partes interesadas, incluidos los clientes y gerentes de proyectos, así como los arquitectos e ingenieros. Se necesitan diagramas SysML adicionales más rigurosos para especificar un Modelo de Arquitectura del Sistema (SAM) escalable y simulable.

## 4. Diagrama de actividades

### Actividad
Una actividad (notación: rectángulo redondeado o "redondeo") representa un flujo de comportamientos funcionales que pueden incluir flujos opcionales de objetos (datos). Los flujos de control y de objeto pueden ser secuenciales (por defecto) o paralelos (indicados por los nodos de unión y bifurcación) según las condiciones.

### Acción
Actividad atómica, es un comportamiento ejecutable primitivo.

### Flujo de control
Flujo de comportamientos funcionales

### Flujo de objetos
Flujo de datos de entradas / salidas de objetos hacia / desde una actividad o acción.

### Diagrama de actividad (ACT)
Un diagrama de actividad muestra el comportamiento dinámico del sistema utilizando un modelo combinado de flujo de control y flujo de objetos (datos).

Las actividades (e indirectamente los diagramas de actividad) pueden descomponerse recursivamente ("anidarse") alternando entre las definiciones de actividad y los usos de la acción de comportamiento de llamada.

Las actividades y acciones se pueden asignar (a través de particiones que representan bloques de control (es decir, bloques que representan el sistema, subsistemas, subsistemas, ..., estructuras atómicas);

Los bloques de datos (es decir, los bloques que representan almacenes de datos persistentes) y las señales que contienen bloques de datos se pueden asignar a parámetros de actividad y pines de acción.

### Propósito

El propósito de los diagramas de actividad es especificar comportamientos dinámicos del sistema que satisfacen ("satisfacen" la dependencia) requisitos funcionales del sistema utilizando flujos de control y de objeto (datos). Cuando se aplica correctamente. Los diagramas de actividad son escalables y simulables de forma recursiva.

## Diagrama de definición de bloque

### Bloque
Un bloque (notación: rectángulo con palabra clave «bloque») representa un componente del sistema, una unidad estructural modular que encapsula sus contenidos (propiedades, comportamientos, restricciones) y admite interfaces de primera clase (es decir, se puede dibujar y manipular directamente en el repositorio de modelos). Los comportamientos encapsulados por bloques incluyen: operaciones, señales y máquinas de estado. Los puntos de interacción únicos para conectar y conectar ("cableado") interfaces de bloque se denominan puertos.

- Los bloques pueden especificar componentes de software, hardware, mecánica y software (personas, organizaciones, instalaciones).
- Los bloques admiten las interfaces proporcionadas (implementadas o realizadas) y requeridas (usadas) tanto para la información como para los flujos físicos.
- Los bloques pueden descomponerse recursivamente en partes, donde cada parte también debe definirse mediante un bloque. (Consulte las Notas de uso a continuación).

### Diagrama de definición de bloque (BDD)
Un diagrama de definición de bloque es un diagrama estructural estático que muestra los componentes del sistema, sus contenidos (propiedades, comportamientos, restricciones), interfaces y relaciones.

- Los bloques se pueden descomponer recursivamente ("anidar") en partes alternando entre las definiciones del Diagrama de definición de bloque (BDD) y los usos del Diagrama de bloque interno (IBD).
- Los comportamientos pueden encapsularse mediante bloques (p. Ej., Operaciones, señales y máquinas de estado) o asignarse (mediante la asignación de dependencia) a bloques (p. Ej., Actividades / acciones) directa o indirectamente (a través de interfaces).
- Los bloques se pueden restringir matemáticamente a través de bloques de restricción para producir diagramas paramétricos matemáticamente simulables.
- comparar y contrastar: diagramas de clase y componente UML 2; Diagramas de contexto y estructura del sistema SA / SD; IDEF IDEF1X diagramas.

### Propósito

El propósito de los Diagramas de definición de bloque es especificar las estructuras estáticas del sistema que se utilizarán para los Objetos de control, Objetos de datos y Objetos de interfaz. Cuando se aplica correctamente los diagramas de bloques son escalables de forma recursiva y simulables matemáticamente (paramétricamente) 

### Notas de uso

Definición de bloque de BDD versus dicotomía de uso de bloque de IBD

Los BDD y los IBD se complementan entre sí  y apoyan las técnicas de descomposición estructural recursiva durante el Análisis y diseño del sistema.

- Un BDD define las propiedades de un bloque, incluidas sus propiedades de parte (partes de propiedad exclusiva) y propiedades de referencia (partes compartidas)
- Un IBD especifica los usos o roles de las Propiedades de las partes y las Propiedades de referencia en el contexto estructural del Bloque que los encapsula. Dicho de otra manera, las Propiedades de Parte y las Propiedades de Referencia en un IBD pueden tener diferentes usos o roles dependiendo de cómo se realicen ("conectan") en la IBD.

## 5. Diagrama de bloques internos

### Bloque

Todas las definiciones de bloque en un BDD son aplicables aquí.

### Diagrama de bloque interno (IBD)
Un diagrama de bloque interno es un diagrama estructural estático propiedad de un bloque en particular que muestra su contenido estructural encapsulado: partes, propiedades, conectores, puertos e interfaces. Dicho de otro modo, una EII es una perspectiva de "caja blanca" de un bloque encapsulado ("caja negra").

- Los bloques se pueden descomponer recursivamente ("anidar") en partes alternando entre las definiciones del Diagrama de definición de bloque (BDD) y los usos del Diagrama de bloque interno (IBD)
- Los comportamientos pueden encapsularse mediante bloques (p. Ej., Operaciones, señales y máquinas de estado) o asignarse (mediante la asignación de dependencia) a bloques (p. Ej., Actividades / acciones) directa o indirectamente (a través de interfaces).
- Los bloques se pueden restringir matemáticamente a través de bloques de restricción para producir diagramas paramétricos matemáticamente simulables.
- comparar y contrastar: diagramas de clase y componente UML 2; Diagramas de contexto y estructura del sistema SA / SD; IDEF IDEF1X diagramas.

### Propósito

El propósito de los Diagramas de bloques internos (IBD) es mostrar el contenido estructural encapsulado (Partes, Propiedades, Conectores, Puertos, Interfaces) de los Bloques para que puedan descomponerse recursivamente y "conectarse" utilizando técnicas de Diseño Basadas en Interfaz. Cuando se usan correctamente, los BDD + IBD son recursivamente escalables y matemáticamente (paramétricamente) simulables.

## 6. Diagrama paramétrico

### Bloque de restricción

Un bloque de restricción (notación: rectángulo con palabra clave = «restricción») define una regla matemática (restricción) y parámetros de regla, donde estos últimos están vinculados a propiedades de valor de bloque para que los cambios en una propiedad de valor de bloque se propaguen a otro Bloque de las propiedades de valor de forma coherente con la regla matemática.

### Diagrama paramétrico (PAR)

Un diagrama paramétrico es una especialización de un diagrama de bloque interno (IDB) que aplica reglas matemáticas (restricciones) definidas por bloques de restricción a través de las propiedades internas del valor de parte unidas por los parámetros de bloque de restricción.

Los conectores de enlace (palabra clave = «igual») entre los parámetros del bloque de restricción y las propiedades internas del valor de la parte afectan la satisfacción de la restricción (propagación)

### Propósito

El propósito de los diagramas paramétricos (PAR) es imponer reglas matemáticas en las propiedades de valor de bloque. Cuando se usan correctamente, los BDD + IBD + PAR son recursivamente escalables y matemáticamente simulables.
