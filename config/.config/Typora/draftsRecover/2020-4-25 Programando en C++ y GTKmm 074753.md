# Programando en C++ y GTKmm


Tipos de datos en C++

`short` (también conocido como `short int`): almacena 2 bytes
`int`: almacena 4 bytes
`long` (también conocido como `long int`): almacena 4 bytes
`long long int`: almacena 8 bytes
`char`: almacena 1 bytes
`bool`: almacena 1 bytes
`float`: almacena 8 bytes
`double`: almacena 8 bytes

`typedef`: podemos definir un tipo de dato, ejemplo:

```c++
typedef unsigned short int MI_INT;
```

Constantes

Hay dos tipos de constantes, simbólicas y literales. `true` y `false` son constantes literales

Constantes simbólicas

Son aquellas que son representadas por un nombre, como una variable.

```c++
const int KILL_BONUS = 5000;
```

Constantes literales

Son aquellas que sólo son léidas y sustituidas por el precompilador antes de compilar el programa. Lo que hace es sustituir cada similitud con el valor. Como no se tiene un tipo de dato, el compilador no asegura que la constante tiene valor propio.

```c++
#DEFINE KILLBONUS 5000
```

Constantes enumeradas

Son aquellas que se crean en una sola sentencia con la palabra clave `enum`

```c++
enum COLOR
{
	red,
	blue,
	yellow
};

Cada una de ellas tendrá un valor; red tendrá 0, blue 1 y yellow 2.

También puedes asignar los valores

enum COLOR
{
	red,
	blue = 100,
	yellow
};

Cada una de ellas tendrá un valor; red tendrá 0, blue 100 y yellow 101.

* `sizeof()`: muestra el tamaño de un tipo de dato


## Instalación

### Dependencias

Antes de instalar gtkmm-3.0, debe instalar


* libsigc++ 2.0
* GTK+ 3.0
* glibmm
* cairomm
* pangomm
* atkmm

Estas dependecias tienen otras dependecias como

* pkg-config
* glib
* ATK
* Pango
* cairo
* gdk-pixbuf

### Instalar en Linux y Unix

Hacer

​```bash
# ./configure --prefix=/usr
# make
# make install
```

## Básico

### Creación de una aplicación (básica)

Crea un archivo llamado `base.cpp` cuyo contenido sea

```c++
#include <gtkmm.h>

int main(int argc, char *argv[])
{
  auto mi_app = Gtk::Application::create(argc, argv, "org.gtkmm.examples.base");
  return 0;
}
```

Este código es esencial para toda aplicación de gtkmm, casi todas las básicas tienen el mismo contenido. 

Para compilar un programa de gtkmm3 usa

```bash
g++ base.cpp -o base `pkg-config gtkmm-3.0 --cflags --libs`
```

### Creación y manejo de ventanas

#### 1. Creación sencilla de ventanas

Para crear una ventana usa

```c++
Gtk::Window mi_ventana;
```

Para mostrar o ejecutar una ventana

```c++
mi_app->run(mi_ventana);
```

Si necesitas que el programa termine cuando se cierre tu ventana, entonces haz

```c++
return mi_app->run(mi_ventana)
```

Todo el código podría estar tranquilamente en la función `int main()` de la aplicación.

#### 2. Creación más estructurada con clases

Para crear una ventana hazlo con una clase, en la cual, estarán todos tus objetos

* En el header

```c++
#ifndef MIAPLICACION_H
#define MIAPLICACION_H

#include <gtkmm/button.h>
#include <gtkmm/window.h>

class miAplicacion : public Gtk::Window
{
	public:
		miAplicacion();
		virtual ~miAplicacion();

	protected:
		// Manejadores de señal

		// Widgets que vamos a utilizar en la App
};

#endif // MIAPLICACION_H
```

Aquí tenemos toda la definición de una clase. Esta tiene su constructor y destructor, es decir, cuando se vaya a crear la ventana se hará con el constructor, al querer destruirla se debe llamar al destructor. 

Cabe destacar que, podríamos incluir el header `#include <gtkmm.h>` (si estamos utilizando muchos widgets) para ahorrarnos declaraciones.

* En la fuente

```c++
#include "mi_header.h"
#include <iostream>

miAplicacion::miAplicacion() // Aquí debemos inicializar todos los widgets 
{
    /* 	Aquí configuramos los widgets, añadimos manejadores de
    	eventos, mostramos widgets, etc.
    */
	show_all_children();	// Mostramos todos los widgets que se han creado
}

HelloWorld::~HelloWorld()
{
    // Aquí se destruye la aplicación
}
```

Para inicializar los widgets que vamos a utilizar que previamente declaramos en nuestro *header*, hacemos:

```c++
miAplicacion::miAplicacion() :
widget1(valores),
widget2(valores),
widgetn(valores)
{
```

* En el `int main()`

```c++
#include "miAplicacion.h"
#include <gtkmm/application.h>

int main (int argc, char *argv[])
{
	// Creamos la aplicación
		Glib::RefPtr<Gtk::Application> mi_app = Gtk::Application::create(
			argc, 
			argv, 
			"org.gtkmm.example"
		); 
	// Creamos un objeto de la clase
		miAplicacion mi_ventana1; 

	//Mostramos la ventana y retornamos cuando se cierre
		return mi_app->run(mi_ventana1);
}
```

#### 3. Configurando las características de una ventana

Para establecer el título de una ventana

```c++
set_title("Título");
```

Para establecer el tamaño de una ventana 

```c++
set_default_size(200, 200);
```

Establecemos el ancho del borde de la ventana

```c++
set_border_width(10);
```

Ocultar una ventana

```c++
hide();
```

Para hacer modificable de tamaño una ventana

```c++
set_resizable();
```

### Creación más avanzada de aplicaciones

`miVentana.h`:

```c++
#ifndef MIVENTANA_H
#define MIVENTANA_H

#include <gtkmm.h>

class miVentana : public Gtk::ApplicationWindow
{
	public:
  		miVentana();

  		void open_file_view(const Glib::RefPtr<Gio::File>& file);
};

#endif /* MIVENTANA_H */
```

`miAplicacion.h`:

```c++
#ifndef MIAPLICACION_H
#define MIAPLICACION_H

#include <gtkmm.h>

class miVentana;

class miAplicacion: public Gtk::Application
{
    protected:
        miAplicacion();

    public:
        static Glib::RefPtr<miAplicacion> create();

    protected:
        // Anular manejadores de señal por defecto
            void on_activate() override;
            void on_open(
                const Gio::Application::type_vec_files& files,
                const Glib::ustring& hint
            ) override;

    private:
        miVentana* create_appwindow();
        void on_hide_window(Gtk::Window* window);
};

#endif /* MIAPLICACION_H */
```

`miAplicacion.cpp`:

```c++
#include "miAplicacion.h"
#include "miVentana.h"

miAplicacion::miAplicacion() :
    Gtk::Application("io.cpwonline.miaplicacion", // Identificador
    Gio::Application::Flags::HANDLES_OPEN)
{
}

Glib::RefPtr<miAplicacion> miAplicacion::create()
{
    return Glib::RefPtr<miAplicacion>(new miAplicacion());
}

/* Aquí creamos las ventanas */
miAplicacion* miAplicacion::create_appwindow()
{
    auto appwindow = new miVentana();

    // Aegúrarse que la aplicación corre mientras la ventana está abierta
        add_window(*appwindow);

    // Borrar la ventana mientras está oculta
        appwindow->signal_hide().connect(sigc::bind(
            sigc::mem_fun(
                *this,
                &ExampleApplication::on_hide_window
            ),
            appwindow)
        );

    return appwindow;
}

void miAplicacion::on_activate()
{
    // La aplicación ha sido creada, mostramos la ventana
        auto appwindow = create_appwindow();
        appwindow->present();
}

void miAplicacion::on_open(
    const Gio::Application::type_vec_files& files,
    const Glib::ustring& /* hint */)
{
    // La aplicación ha sido llamada para abrir varios archivos
    // entonces abriremos una ventana por cada uno
        miVentana* appwindow = nullptr;
        auto windows = get_windows();
        if (windows.size() > 0)
            appwindow = dynamic_cast<miVentana*>(windows[0]);

        if (!appwindow)
            appwindow = create_appwindow();

        for (const auto& file : files)
            appwindow->open_file_view(file);

        appwindow->present();
}

void miAplicacion::on_hide_window(Gtk::Window* ventana)
{
    delete ventana;
}
```

`main.cpp`:

```c++
#include "miAplicacion.h"

int main(int argc, char* argv[])
{
    auto App = miAplicacion::create();

    return App->run(argc, argv);
}
```

`miVentana.cpp`:

```c++
#include "miVentana.h"

miVentana::miVentana() : Gtk::ApplicationWindow()
{
}

void miVentana::open_file_view(const Glib::RefPtr<Gio::File>& /* file */)
{
}
```





## Uso de contenedores

La mayoría de los contenedores descienden de `Gtk::bin` (los de un solo item) o de `Gtk::Container` (los de múltiples items).

### Jerarquía del sistema de paquetes (packing)

* La Aplicación
  * Ventana n
    * Contenedor (múltiple o de un sólo item)
      * Items del contenedor (widgets, pueden ser otros contenedores)

 Mayormente, los contenedores tienen funciones comúnes

```c++
contenedor.add(widget);
contenedor.remove(widget);
```

Para mostrar todos los widgets de un contenedor hacemos

```c++
show_all_children();
```

### Contenedores de un solo item

#### 1. Frame

Estos encierran a un grupo de widgets dentro de una caja.

* En el header (en donde van todos los widgets)

```c++
Gtk::Frame* mi_frame1;
```

* En la fuente

```c++
add(mi_frame1);			// Añadimos el frame a la ventana
```

Las ventanas (al igual que los botones) solo pueden contener un hijo.

* `mi_frame1.set_label("Gtk::Frame Widget");`: le da una etiqueta título al frame
* `mi_frame1.set_label_align(Gtk::ALIGN_END, Gtk::ALIGN_START);`: alínea la etiqueta a la derecha 
* `mi_frame.set_shadow_type(Gtk::SHADOW_ETCHED_OUT);`: cambia el estilo de la etiqueta del frame

#### 2. Paned

Los paneles son un widget que se divide en dos partes, separadas por un divisor que se puede ajustar. Estos pueden ser ajustados horizontal o verticalmente.

* Los paneles tienen dos funciones `add1()` y `add2()` para añadir los widgets a cada parte del panel respectivamente
* `set_position()` ajusta la posición del divisor
* En el header

```c++
Gtk::Paned* panel_vertical;
```

* En la fuente

```c++
panel_vertical.add1(widget1);
panel_vertical.add2(widget2);
```

#### 3. ScrolledWindow

Este es un widget que crea un área que es *scrollable*. Puedes insertar cualquier tipo de widget dentro de este.

* `set_policy()`: son las políticas del ScrolledWindow, estas deben ser o `Gtk::POLICY_AUTOMATIC` o `Gtk::POLICY_ALWAYS. Gtk::POLICY_AUTOMATIC`
* En el header

```c++
Gtk::ScrolledWindow* mi_ScrolledWindow;
```

* En la fuentem_ScrolledWindow

```c++
mi_ScrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS); // El primero es la política horizontal y el segundo la vertical
```

#### 4. AspectFrame

Son como frames normales pero estos afectan el tamaño del widget que contienen

* En el header

```c++
Gtk::AspectFrame* mi_AspectFrame;
```

* En la fuente

```c++
miAplicacion::miAplicacion()
: mi_AspectFrame(
    "2x1", 				// Etiqueta
    Gtk::ALIGN_CENTER,	// Centro en x
    Gtk::ALIGN_CENTER,	// Centro en y
    2.0, 				// xsize/ysize = 2
    false 				//ignore child's aspect
{
```

### Contenedor de múltiples items

#### 1. Packing

Como sabrás, la mayoría de las ventanas son elásticas y hay muchas maneras de que los widgets también se adapten a esa elasticidad de una ventana. Un usuario puede cambiar el tamaño y posición de los elementos a su gusto y la idea es que los elementos de una aplicación se ajusten.

El sistema de empaquetamiento de gtkmm alinea la posición de los widgets en filas, columnas y/o rejas. La mayoría de widgets, establecen su tamaño de acuerdo a la cantidad de texto que contienen (o lo que contengan). gtkmm ordena los widgets jerárquicamente.

#### 2. Boxes (cajas)

Las cajas son contenedores invisibles en los cuales podemos colocar nuestros widgets. 

Cuando colocamos los widgets en una caja horizontal, estos son insertados horizontalmente de izquierda a derecha o de derecha a izquierda dependiendo si `pack_start()` o `pack_end()` es usado. En una caja vertical, los widgets son ordenados desde el tope hasta el fondo o viceversa. 

* `pack_start()`: este añade los widgets en una caja vertical de arriba hacia abajo y en una horizontal de derecha a izquierda
* `pack_end()`: añade los widgets en un caja vertical de abajo hacia arriba y en una horizontal de derecha a izquierda
* En el header

```c++
Gtk::Box mi_caja;
```

* En la fuente (esto va mayormente en el constructor de la ventana)

```c++
add(mi_caja); // Añadimos la caja a la ventana
mi_caja.show();
// Empacamos los widgets dentro de la caja
    mi_caja.pack_start(
        widget1,
        Gtk::PackOptions options = Gtk::PACK_EXPAND_WIDGET,
        guint padding = 0
    );
	widget1.show();
```

El primer argumento de `pack_start()` es el widget a añadir, el segundo puede tomar una de 3 opciones:

1. `Gtk::PACK_SHRINK`: El espacio es contraido al tamaño del widget, el widget tomará solo el espacio necesario y jamás se expandirá
2. `Gtk::PACK_EXPAND_PADDING` : extra espacio por tener relleno. Sus tamaños no cambiarán. Los widgets eventualmente serán llevados afuera pero sus tamaños no cambiarán. El espacio entre widgets serán vaciado.
3. `PACK_EXPAND_WIDGET`: Toma espacio extra al incrementar el tamaño del widget hijo sin cambiar la cantidad de espacio entre widgets hijos

Algunas opciones disponibles para este contenedor:

* `Gtk::ORIENTATION_HORIZONTAL` : pasarla por el constructor cuando se inicializa la caja, para que la caja sea horizontal
* `Gtk::ORIENTATION_VERTICAL` : pasarla por el constructor cuando se inicializa la caja, para que la caja sea vertical
* `void set_spacing(int spacing);`: establece el espaciado
* `void set_homogeneous(bool homogeneous = true);`: pasarle true a este método hará que todos los widgets dentro de la caja sean del mismo tamaño

#### 3. ButtonBoxes

Estos son la mejor forma de ordenar botones. Tienen configuraciones estandar.

* `get_layout()` y `set_layout()` sirven para obtener y establecer el estilo de disposición del contenedor

#### 4. Grid

Una reja establece las disposiciones de los widgets en filas y columnas

* `attach()`: los widgets pueden abarcar varias filas o columnas
* `attach_next_to()`: permite añadir a un widget existente dentro de la reja
* `set_row_homogeneous()` y `set_column_homogeneous()`: permiten establecer anchos y altos uniformes

* En la fuente

```c++
add(m_grid); // Añadimos la reja a la ventana
m_grid.add(m_button_1); //Añadimos el boton 1
m_grid.add(m_button_2); // Añadimos el boton 2
m_grid.attach_next_to(m_button_quit, m_button_1, Gtk::POS_BOTTOM, 2, 1); // Botón de quitar
```

Añadimos el botón de quitar en la siguiente fila (fila después del botón 1, ¿por qué? porque indicamos que estará en la posición de fondo: `Gtk::POS_BOTTOM`), abarcará dos columnas y una fila. 

#### 5. Notebook

Estas tienen un set de páginas, la cual, cada una de estas contienen diferentes widgets.

* `append_page()`, `prepend_page()` y `insert_page()`: estos métodos permiten añadir páginas tabuladas a la Notebook
* `get_current_page()`: permite ver la página actual
* `get_nth_page()`: si le pasamos como parametro el valor de `get_current_page()` este retornará un puntero hacia el widget hijo
* `set_current_page()`: cambia la página
* En la fuente

```c++
mi_Notebook.append_page(contenedor1, "Título");
```

#### 6. Assistant

Este contenedor convierte una operación compleja en simples pasos. Cada paso es una página. Estas contiene una cabecera, un widget hijo y un área de acción.

* `set_page_type()`: establecemos el tipo de página
* `Tiene los mismos métodos mencionados anteriormente de Notebook
* `add_action_widget()`: con este añadimos widgets al área de acción
* `add_action_widget()`: remueve widgets de acción
* En la fuente

```c++

m_box.pack_start(m_label1);
m_box.pack_start(m_entry);

append_page(m_box);
append_page(m_check);
append_page(m_label2);

set_page_title(*get_nth_page(0), "Page 1");
set_page_title(*get_nth_page(1), "Page 2");
set_page_title(*get_nth_page(2), "Confirmation");

set_page_complete(m_check, true);
set_page_complete(m_label2, true);

set_page_type(m_box, Gtk::ASSISTANT_PAGE_INTRO);
set_page_type(m_label2, Gtk::ASSISTANT_PAGE_CONFIRM);
```

## Botones

### Botón (simple)

Al igual que todo lo anterior, se deben instanciar en el header y podemos añadir su propiedades en el inicializador del constructor o dentro del constructor

* En el header

```c++
Gtk::Button* mi_boton1;
```

* En la fuente

```c++
mi_boton1 = new Gtk::Button("_Something", true);
```

Añadirle el guión bajo (underscore) detrás de una letra añadirá esa letra clave a la navegación rápida.

Podemos añadirle una imagen y un texto al botón

```c++
mi_boton.add_pixlabel("imagen.xpm", "Título de mi botón");
```

* `set_can_default()`: establece el por defecto
* `grab_default()`: graba al que es por defecto

### ToggleButton

Los ToggleButton más famosos son los RadioButton y los CheckButtons.

* `get_active()`: retorna el estado del botón
* `set_active()`: establece el estado del botón
* `toggled()`: para subirlo o bajarlo (lo fuerza a hacer cualquiera de las dos)

### CheckButton

* En el header

```c++
Gtk::CheckButton* check_boton;
```

* En la fuente

```c++
miAplicacion::miAplicacion :
	check_boton("Mi check")
{
```

### RadioButton

Estos son muy parecidos a los CheckButton, la diferencia es que estos trabajan en grupos.

* En el header

```c++
Gtk::RadioButton* mi_radio1, mi_radio2, mi_radio3;
```

* En la fuente

```c++
miAplicacion::miAplicacion() :
	m_radio1("amarillo"),
	m_radio2("azul"),
	m_radio3("rojo")
{
	m_radio2.join_group(m_radio1);
	m_radio3.join_group(m_radio1);
}
```

* Otra forma de crear RadioButtons (en la fuente):

```c++
	Gtk::RadioButton::Group group;
	Gtk::RadioButton* m_radio1 = Gtk::make_managed<Gtk::RadioButton>(group, "amarillo");
	Gtk::RadioButton* m_radio2 = Gtk::make_managed<Gtk::RadioButton>(group, "azul");
	Gtk::RadioButton* m_radio3 = Gtk::make_managed<Gtk::RadioButton>(group, "rojo");
```

* `set_active`: permite establecer cual RadioButton estará activado

## Widgets básicos

### Label (etiquetas)


Las etiquetas son los métodos principales para declarar textos no editables en una ventana.

* En el header

```c++
Gtk::Label* mi_etiqueta1;
```

* En la fuente

```c++
miAplicacion::miAplicacion :
	mi_etiqueta1("Texto de la etiqueta)
{
```

* `set_text()` o `set_markup()`: Puedes especificar el texto de la etiqueta en el contructor o luego
* El ancho de la etiqueta se establece automáticamente. 
* Se pueden hacer etiquetas multilínea colocándo `/n` en el texto de un label
* `set_justify()`: Justifica el texto
* `set_line_wrap()`: Aplicar *word-wrapping*
* `set_markup()`: Puedes usar muchos estilos de texto ingresando texto con la sintaxis de marcado de Pango

### Entry (Entradas)

Son widgets que permiten al usuario la entrada de texto.

* En el header

```c++
Gtk::Entry* entry_usuario;
```

* En la fuente

```c++
entry_usuario.set_activates_default();
```

* `set_text()`: permite establecer el texto que tendrá
* `get_text()`: retorna el texto contenido
* `set_editable()`: Para hacer una entrada de sólo lectura (read-only) pasarle el argumento `false`
* `set_visibility()`: Para contraseñas pasarle `false` al método 
* `activate` es emitido cuando se presiona la tecla Enter en un Entry
* `changed` es emitido cuando se cambia el texto del Entry
* `set_activates_default()` permite establecer el Entry por defecto cuando se presiona enter en una ventana
* `set_max_length()`: establece el máximo número de caracteres soportados por la entrada
* `select_region(0, n)`: Selecciona una región del texto de la entrada de 0 a n
* `get_text_length()`: devuelve la cantidad de caracteres que contiene la entrada

### SpinButton 

Estos permiten al usuario seleccionar un valor de un rango númerico de valores

* Los SpinButton usan un objeto `Adjustment` para establecer información del rango de valores
* Atributos `Adjustment` que son usados en un SpinButton:
	* value
	* lower
	* upper
	* step_increment
	* page_increment
* `set_digits()` establece el número de dígitos que puede contener un SpinButton
* `set_value()` establece el valor del SpinButton
* `get_value()` retorna el valor de un SpinButton
* Para usar sólo valores numéricos le pasamos `true` al método `set_numeric()`

### ProgressBar (barras de progreso)

Son aquellas que muestran el progreso de una tarea

* En el header

```c++
Gtk::Progressbar* mi_progreso1;
```

* En la fuente

```c++
// Establecemos algunos estilos a la barra de progreso
	mi_progreso1.set_halign(Gtk::ALIGN_CENTER);
	mi_progreso1.set_valign(Gtk::ALIGN_CENTER);
	mi_progreso1.set_text("Texto encima del progress");
	mi_progreso1.set_show_text(true);

bool ActivityMode = false;

if(ActivityMode)
	mi_progreso1.pulse(); // Lo ponemos así si está en modo actividad
else
{
	double new_val = mi_progreso1.get_fraction() + 0.01;

	if(new_val > 1.0)
		new_val = 0.0;

	mi_progreso1.set_fraction(new_val); // Podemos reiniciar el valor
  }
```

El código mostrado anteriormente, es ideal para utilizarlo con un temporizador (conector de señal con tiempo)

* `set_fraction()` establecer el valor del ProgressBar en formato de `0.0` a `1.0` double
* El modo actividad de este widget lo hace perfecto cuando se desconoce del tamaño o del tiempo que llevará hacer algo
* `set_orientation()`: puede cambiar la orientación (sea de derecha a izquierda o de izquierda a derecha, es por defecto la última)

### InfoBar (barra de información)

Estas aparecen en el tope de una ventana, están dentro de una ventana.

Estas almacenan pequeños items, mayormente para hacer preguntas.

* Clase `Gtk::InfoBar`

### ToolTips

Estos aparecen cuando pasas el click por encima de un widget durante unos segundos.

La idea de ellos es dar una pequeña información acerca de un widget

## Range widgets (widgets de rango)

### Scrollbar Widgets

* Estos serían utilizados solamente para desplazarse dentro de otro widget (tanto como Gtk::Entry o Gtk::Viewport)
* La orientación de Gtk::Scrollbar puede ser horizontal o vertical.

### Scale widgets (también conocidos como sliders)

Estos permiten al usuario visualmente utilizar un valor dentro de un rango específico.

* En el header 

```c++
Gtk::Scale* mi_escala;
```

* `set_draw_value()` cambia el número de dígitos del slider
* `set_value_pos()` cambia la posición por defecto del slider

## Introducción a las señales (signals)

Cuando un evento ocurre (tanto presionar un botón como el presionar el click) una apropiada señal será emitida al widget que fue presionado.

* Cada widget tiene un diferente conjunto de señales que puede emitir.
* Para hacer el click de un botón en una acción se puede configurar una manejador de señal (signal handler) para capturar la señal "click" del botón.
* gtkmm usa la librería libsigc++ para implementar señales. 
* En el header

```c++
// Manejadores de señal
	void on_button_clicked();
// Widgets que vamos a utilizar en la App
	Gtk::Button btn1;
```

* En la fuente

```c++
miAplicacion::miAplicacion :
	btn1("Hacer click")
{
	btn1.signal_clicked().connect( sigc::mem_fun(
		*this, 
		&HelloWorld::on_button_clicked
	));
}
void miAplicacion::on_button_clicked()
{
	std::cout << "Hizo click";
}
```

Ejemplo de cómo conectar la señal click de un `Gtk::button` con un manejador de señal llamado `on_button_clicked`

* Añadiendo un temporizador para actualizar el valor de la barra de progreso

```c++
m_connection_timeout = Glib::signal_timeout().connect(
	sigc::mem_fun(
		*this,
		&ExampleWindow::on_timeout
	), 
	50
);
```

* Añadiendo una señal para saltar de página (o paso) en una Notebook

```
 m_Notebook.signal_switch_page().connect(sigc::mem_fun(
	*this,
	&ExampleWindow::on_notebook_switch_page
));
```

## Menús y barra de herramientas

### Forma sencilla

* En el header

```c++
Gtk::MenuBar menuBar;
```

* En la fuente

```c++
mainBox.pack_start(menuBar, Gtk::PACK_SHRINK); // Añadimos el menú a la caja
```

Añadiendo sub menús

```c++
// Creando un item (que luego será un submenú)
	Gtk::MenuItem menuFiles;
	menuFiles.set_label("Files");
	menuBar.append(menuFiles);

// Creando el submenú en el item
	Gtk::Menu subMenuFiles;
	menuFiles.set_submenu(subMenuFiles);
```

Añadiendo items a los submenús

```c++
// Creando un item (con imagen)
	Gtk::ImageMenuItem menuNew(Gtk::Stock::NEW);
	subMenuFiles.append(menuNew);
```

Hacer de un item un nuevo submenú y añadirle items

```c++
// Creando un item (con imagen)
	    Gtk::MenuItem menuRecentFiles("Recent files", true);
	    subMenuFiles.append(menuRecentFiles);

// Le agregamos el submenú al item
	    Gtk::Menu subMenuRecentFiles;
	    menuRecentFiles.set_submenu(subMenuRecentFiles);

// Le agregamos los items al nuevo submenú
	    Gtk::MenuItem recentFile1("File1.txt");
	    subMenuRecentFiles.append(recentFile1);

Gtk::MenuItem recentFile1("File1.txt");
subMenuRecentFiles.append(recentFile1);
```

### Forma avanzada

* En el header

```c++
public:
	miAplicacion(const Glib::RefPtr<Gtk::Application>& app);

private:
	// Manejadores de señal

	// Widgets hijos
		Glib::RefPtr<Gtk::Builder> mi_const_Menus;
		Glib::RefPtr<Gio::SimpleActionGroup> mi_MenuGroup;
		Glib::RefPtr<Gio::SimpleAction> mi_MenuLluvia;

		Gtk::Box* mi_caja;
};
```

* En la fuente

```c++
// Definimos los actions
	// Creamos el grupo de menús
		mi_MenuGroup = Gio::SimpleActionGroup::create();

	// Añdimos los actions a nuestro grupo de menús
		mi_MenuGroup->add_action(
			"Nuevo",
			sigc::mem_fun(
				*this, 
				&ExampleWindow::on_action_file_new
			) 
		);
		mi_MenuGroup->add_action(
			"Abrir",
			sigc::mem_fun(
				*this, 
				&ExampleWindow::on_action_others
			) 
		);

		// Añadimos un action_bool (parecido a un RadioButton)
		  	mi_MenuLluvia = mi_MenuGroup->add_action_bool(
				"Activar",
		   		sigc::mem_fun(
					*this, 
					&ExampleWindow::on_action_toggle
				),
		    		false
			);

	  	mi_MenuGroup->add_action(
			"Salir",
	    		sigc::mem_fun(
				*this, 
				&ExampleWindow::on_action_file_quit
			) 
		);

	  	mi_MenuGroup->add_action(
			"Cortar",
	    		sigc::mem_fun(
				*this, 
				&ExampleWindow::on_action_others
			) 	
		);
	  	mi_MenuGroup->add_action(
			"Copiar",
	    		sigc::mem_fun(
				*this, 
				&ExampleWindow::on_action_others
			) 
		);
	  	mi_MenuGroup->add_action(
			"Pegar",
	    		sigc::mem_fun(
				*this, 
				&ExampleWindow::on_action_others	
			) 
		);

	// Indexamos el grupo de menú
  		insert_action_group("menuID", mi_MenuGroup);

	// Creamos el constructor de menu
  		mi_const_Menus = Gtk::Builder::create();

  	// Disposición de las acciones en la barra de menú y de herramientas
	  	const char* UI_Menu =
				"	<interface>"
		    	"  		<menu id='menubar'>"
		    	"    		<submenu>"
		   		"      			<attribute name='label' translatable='yes'>_File</attribute>"
		   		"      			<section>"
		    	"       	 		<item>"
		    	"       	   			<attribute name='label' translatable='yes'>_New</attribute>"	
		    	"       	   			<attribute name='action'>menuID.new</attribute>"
		    	"       	   			<attribute name='accel'>&lt;Primary&gt;n</attribute>"
		    	"       	 		</item>"
		    	"       	 		<item>"
		    	"       	   			<attribute name='label' translatable='yes'>_Open</attribute>"	
		    	"       	   			<attribute name='action'>menuID.open</attribute>"
		    	"       	   			<attribute name='accel'>&lt;Primary&gt;o</attribute>"
		    	"       	 		</item>"
		    	"      			</section>"
		    	"      			<section>"
		    	"       	 		<item>"
		    	"       	   			<attribute name='label' translatable='yes'>Rain</attribute>"	
		   		"       	   			<attribute name='action'>menuID.rain</attribute>"
		   		"       	 		</item>"
		    	"      			</section>"
		    	"      			<section>"
		    	"       	 		<item>"
		    	"       	   			<attribute name='label' translatable='yes'>_Quit</attribute>"
		    	"       	   			<attribute name='action'>menuID.quit</attribute>"
		    	"       	   			<attribute name='accel'>&lt;Primary&gt;q</attribute>"
		    	"       	 		</item>"
		    	"      			</section>"
		    	"    		</submenu>"
		    	"    		<submenu>"
		    	"      			<attribute name='label' translatable='yes'>_Edit</attribute>"
		    	"      			<item>"
		    	"       	 		<attribute name='label' translatable='yes'>_Cut</attribute>"
		    	"       	 		<attribute name='action'>menuID.cut</attribute>"
		    	"       	 		<attribute name='accel'>&lt;Primary&gt;x</attribute>"
		    	"      			</item>"
		    	"      			<item>"
		    	"       			<attribute name='label' translatable='yes'>_Copy</attribute>"
		    	"      	 			<attribute name='action'>menuID.copy</attribute>"
		    	"      	 			<attribute name='accel'>&lt;Primary&gt;c</attribute>"
		    	"      			</item>"
		    	"      			<item>"
		    	"      	 			<attribute name='label' translatable='yes'>_Paste</attribute>"	
		   		"      	 			<attribute name='action'>menuID.paste</attribute>"
		   		"      	 			<attribute name='accel'>&lt;Primary&gt;v</attribute>"
		   		"      			</item>"
		   		"    		</submenu>"
		    	"  		</menu>"
		    	"	</interface>";

	// Agregamos aceleradores claves
	// Cuando una barra de herramientas es hija de un Gtk::Window, las teclas claves no están
  	// automáticamente relacionadas con Gio::Menu
  		app->set_accel_for_action("menuID.new", "<Primary>n");
  		app->set_accel_for_action("menuID.open", "<Primary>o");
  		app->set_accel_for_action("menuID.quit", "<Primary>q");
  		app->set_accel_for_action("menuID.cut", "<Primary>x");
  		app->set_accel_for_action("menuID.copy", "<Primary>c");
  		app->set_accel_for_action("menuID.paste", "<Primary>v");

	// Añadimos bloque try catch para verificar que todo el menú está correcto
  		try
  		{
    			mi_const_Menus->add_from_string(UI_Menu); // Añadimos la UI del menú
  		}
  		catch(const Glib::Error& ex)
  		{
    			std::cerr << "Building menus and toolbar failed: " <<  ex.what();
  		}

  	// Obtenemos la barra de menú creando algunos objetos
  		auto object = mi_const_Menus->get_object("menubar");
  		auto gmenu = Glib::RefPtr<Gio::Menu>::cast_dynamic(object); // Establecemos el menú gráfico
  		if (!gmenu)
    			g_warning("GMenu not found");
  		else
  		{
    			auto pMenuBar = Gtk::make_managed<Gtk::MenuBar>(gmenu);

    			// Añadimos la barra de menú a la ventana
    				mi_caja->pack_start(*pMenuBar, Gtk::PACK_SHRINK);
  		}

  	show_all_children();
```

## Dialogs (Ventanas de diálogo)

### MessageDialogs

Son usadas como ventanas secundarias para proporcionar información o realizar preguntas.

* `run()`: este es proporcionado por `Gtk::Dialog` para que cuando un diálogo aparezca el usuario no pueda ignorarlo, este retorna un `int`

* `get_content_area()`: sirve para empacar un Dialog dentro de un `Gtk::Box`

* Simple Diálogo de mensaje en la fuente

```c++
Gtk::MessageDialog dialog(
    *this, "This is an INFO MessageDialog");
dialog.set_secondary_text("And this is the secondary text that explains things.");

dialog.run();
```

* En la fuente (2da forma)

```c++
Gtk::MessageDialog dialog(
    *this, "This is a QUESTION MessageDialog",
	false, // Usamos markup
    Gtk::MessageType::QUESTION,
    Gtk::ButtonsType::OK_CANCEL
);
dialog.set_secondary_text("And this is the secondary text that explains things.");

int result = dialog.run();

//Handle the response:
switch(result)
{
    case Gtk::ResponseType::OK:
        {
            std::cout << "OK clicked." << std::endl;
            break;
        }
    case Gtk::ResponseType::CANCEL:
        {
            std::cout << "Cancel clicked." << std::endl;
            break;
        }
    default:
        {
            std::cout << "Unexpected button clicked." << std::endl;
            break;
        }
}
```

### FileChooserDialog (Diálogo para elegir archivos)

Es un diálogo para seleccionar tanto directorios como ficheros.

* Seleccionar un directorio, en la fuente

```c++
Gtk::FileChooserDialog dialog(
	"Please choose a folder",
  	Gtk::FileChooser::Action::SELECT_FOLDER
);
dialog.set_transient_for(*this);

// Añadimos botones de respuesta al diálogo
	dialog.add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog.add_button("Select", Gtk::ResponseType::OK);

int result = dialog.run();

// Manejamos la respuesta
	switch(result)
	{
		case Gtk::ResponseType::OK:
		{
			std::cout << "Select clicked." << std::endl;
			std::cout << "Folder selected: " << dialog.get_filename() << std::endl;
			break;
		}
		case Gtk::ResponseType::CANCEL:
		{
			std::cout << "Cancel clicked." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Unexpected button clicked." << std::endl;
			break;
		}
}
```

* Seleccionar un fichero

```c++
Gtk::FileChooserDialog dialog(
	"Please choose a file",
  	Gtk::FileChooser::Action::OPEN
);
dialog.set_transient_for(*this);

// Añadimos botones de respuesta
	dialog.add_button("_Cancel", Gtk::ResponseType::CANCEL);
	dialog.add_button("_Open", Gtk::ResponseType::OK);

// Añadimos filtros, para que sólo cierto tiepo de archivos puedan ser seleccionados

	auto filter_text = Gtk::FileFilter::create();
	filter_text->set_name("Text files");
	filter_text->add_mime_type("text/plain");
	dialog.add_filter(filter_text);

	auto filter_cpp = Gtk::FileFilter::create();
	filter_cpp->set_name("C/C++ files");
	filter_cpp->add_mime_type("text/x-c");
	filter_cpp->add_mime_type("text/x-c++");
	filter_cpp->add_mime_type("text/x-c-header");
	dialog.add_filter(filter_cpp);

	auto filter_any = Gtk::FileFilter::create();
	filter_any->set_name("Any files");
	filter_any->add_pattern("*");
	dialog.add_filter(filter_any);

// Mostramos el diálogo y esperamos respuesta
	int result = dialog.run();

// Manejamos la respuesta
	switch(result)
	{
		case Gtk::ResponseType::OK:
		{
			std::cout << "Open clicked." << std::endl;

			// Nota que el resultado es un std::string, no un Glib::ustring.
			auto filename = dialog.get_filename();
			std::cout << "File selected: " <<  filename << std::endl;
			break;
		}
		case Gtk::ResponseType::CANCEL:
		{
			std::cout << "Cancel clicked." << std::endl;
			break;
		}
		default:
		{
			std::cout << "Unexpected button clicked." << std::endl;
			break;
		}
	}
```

### ColorChooserDialog

### FontChooserDialog

