# Usando wxWidgets con C++

**wxWidgets** es una librería de interfaces gráficas escrita en C++. Con ella se pueden crear ventanas, botones, formularios y un sin fin de cosas; todo esto, para poder crear interfaces gráficas de usuarios exitosas (GUI Apps).

## Introducción

## 

## Capítulo 1. Conceptos básicos de Desktop GUI Apps

- Esto va en el header

  Incluimos la cabecera principal de **wxWidgets**.

```c++
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
```

Dentro de la clase debemos de crear todos los objetos, sean de las clases `wxDialog`*,* `wxFrame`*,* `wxTextCtrl`*,* `wxButton`, etc. Se puede hacer dentro de la función `OnInit` , pero, es más recomendable declararlos o instanciarlos en los archivos header.

```C++
class MyApp : public wxApp // deriva de wxApp
{
	public:
		virtual bool OnInit(); 	// Función booleana virtual que es la primera que inicia todo, no se puede cambiar el nombre
};
```

- En el C++

  La función principal `OnInit()` es la susituye a la función `int main()` de una app común de CLI. Esta es la que se ejecuta primero en cualquier programa.

```C++
bool MyApp::OnInit()
{
	// Función principal, aquí colocamos todo lo que hará nuestro programa
	return true;
}
```



## 2. Crear Frames o ventanas

### Forma normal

- Este código va en el header

  La clase `MyFrame` deriva de la clase `wxFrame` , y esta última es la que se encarga de proporcionarle todas las funciones y miembros necesarios para crear ventanas.

```C++
class MyFrame : public wxFrame // Clase derivada de wxFrame
{
	public:
		MyFrame(const wxString& title); // En este constructor le vamos a pasar el título de la ventana
};
```

- Este código va en el archivo C++

  Aquí se inicializa la función miembro constructor de la clase `wxFrame`, se le dan algunos valores para crear la ventana.

```c++
MyFrame::MyFrame(const wxString& title) : wxFrame(
    NULL, 				// Parent
    wxID_ANY, 			// Identificador
    title, 				//Título
    wxDefaultPosition, 	// Posición
    wxSize(250, 250))	// Tamaño
{
	Center(); //Centra la ventana
}
```

- En el header

  Hay que instanciar los objetos que se van a utilizar. 

```C++
MyFrame *ventana1;
```

Cabe destacar, si se realiza la creación de la clase, supóngase `MyFrame` en el mismo archivo *header* de la clase de la aplicación, supóngase `MyApp`, cuando se creen los objetos, las clases de dónde son esos objetos deben estar anteriormente ya creados. Por ejemplo:

```c++
class MyFrame : public wxFrame
{
	// ...
}
class MyApp : public wxApp
{
	MyFrame *frame1;
	// ...
}
MyApp::OnInit(){
	frame1 = new MyFrame();
}
```

- En el C++ 

  Esto va mayormente dentro de la función `OnInit`.

```c++
ventana1 = new MyFrame(wxT("Título de la ventana"));
```

*Nota: Aquí se crea la primera ventana del programa.*


### 2da manera de crear frames o ventanas:

- En el archivo C++

  Este código va mayormente dentro de la función `OnInit` y no necesita ser instanciada dentro de la creación de la clase.

```C++
wxFrame *ventana1 = new wxFrame(
    NULL, 				// Parent
    wxID_ANY, 			// Identificador
    "Titulo", 			// Título
    wxDefaultPosition, 	// Posición
    wxSize(350, 350)	// Tamaño
);	
```

### Trabajando con ventanas:

Abre una ventana (sea de diálogo o normal), la muestra en pantalla, se hace visible.

```c++
ventana1->Show(true); 
```

Oculta una ventana, la hace invisible, más no cierra sus procesos.

```c++
ventana1->Close(true);
```

Centra la ventana, puede ser tanto para `wxFrame` *como para* `wxDialog`.

```c++
ventana1->Center();
```



﻿## 3. Implementar una aplicación:

- En el C++

  Con esto se implementa una clase para ser una aplicación de **wxWidgets**,`MyApp` es el nombre de la clase derivada de `wxApp`.
  
  ```c++
wxIMPLEMENT_APP(MyApp);
  ```
  



## 4. Creando una aplicación sencilla



## 4. Haciendo una ventana de diálogo:

- En el header

  ```C++
wxDialog *objDialog;
  ```
  
  *En la construcción de la clase, se instancia el objeto*

- En el C++

  ```C++
objDialog = new wxDialog(
      NULL,					// Parent
      wxID_ANY,				// Identificador
      "Nombre del diálogo", 	// Título de la ventana
      wxDefaultPosition, 		// Posición
      wxSize(350, 250)		// Tamaño
  );
  ```
  
    *Nota: Aquí se construye el objeto, en la función miembro* `OnInit`
## 5. Para hacer un panel contenedor:

- En el header

  ```c++
  wxPanel *objPanel;
  ```

  *Un objeto del tipo* `wxPanel` *es un contenedor, o panel contenedor. Este tendrá el propósito de guardar dentro de él una serie de elementos (botones, cuadros de texto, selectores, entre otros).*

- En el C++

  ```c++
  objPanel = new wxPanel(
      frame o dialog, // Ventana o diálogo al que está enlazado
  	wxID_ANY		// Identificador
  );
  ```

  *Un panel es una sección del programa donde colocaremos botones u otras cosas, frame o dialog: allí debemos colocar el objeto (sea de* `wxFrame` *o de* `wxDialog`*) para indicar en donde estará el contenedor*

## 6. Para hacer un botón:

- En el header

```c++
wxButton *objButton;
```

*Los botones, al igual que la mayoría de los elementos de __wxWidgets__ derivan de clases.*

- En el C++

  ```c++
  objButton = new wxButton(
      objPanel, 				// Panel donde estará el botón, Parent
      wxID_ANY, 				// Identificador
      wxT("Texto del boton"), // Texto
      wxPoint(20, 20)			// Posición
  );
  ```

  *El boton se crea dentro de un panel, si el boton es para salir, hay que recordar que el id será* `wxID_EXIT`

### Manipulando los botones

```c++
objButton->setFocus();
```

*Esto le coloca el foco al boton.*

```c++
objButton->SetLabel("Texto...");
```

*Le cambia el texto al boton.*



## 7. Creando cajas de texto 

### Tipos de cajas de texto

* TextCtl: estas cajas de texto son conocidos como *cuadros de texto*, *input text*, *text box*, entre otros. Son cajas de texto en los cuales se puede escribir, tanto números como letras o signos.
* StaticText: son cajas de texto conocidas como *label text*, *etiqueta*, entre otros. Son cajas las cuales muestran un texto preestablecido por el desarrollador. El usuario no puede modificar el texto de estos, mas, se puede modificar el contenido de estos mediante funciones específicas.

### TextCtrl:

- En el header

  ```c++
  wxTextCtrl *txtN1;
  ```

  *Aquí iniciamos el objeto, lo dejamos hasta allí (en la creación de la clase), lo demás lo hacemos en la función* `OnInit()`

- En el C++

  ```c++
  txtN1 = new wxTextCtrl(
      Panel, 				// Elemento padre
      ID_ASIGNADO, 		// Identificador
      "Texto de fondo", 	// Texto
      wxPoint(150,20),	// Posición
      wxSize(100, 25), 	// Tamaño
      wxTE_RICH, 			// Tipo de TextCtl
      wxDefaultValidator, // Validador
      wxTextCtrlNameStr	// 
  );
  ```

  *Definimos el `TextCtrl`, en vez de usar `wxTE_RICH` (TextCtl de una línea) podemos usar `wxTE_MULTILINE |` o también usar `wxTE_PASSWORD` para contraseñas, en donde dice `"Texto de fondo"` podemos añadir `wxEmptyString` para que no se vea la clave sino asteriscos.*

#### Manejando los TextCtl

```c++
txtN1->SetEditable(false); 
```

*Con esto deshabilito el control*

```c++
txtN1->Clear(); 
```

*Para borrar el texto*

```
txtN1->SetMaxLength(5); 
```

*Limita la cantidad de caracteres que tendrá el texto.*

```c++
wxString valor = txtN->GetValue();
```

*Retornando el valor actual del TextCtl.*

```c++
wxString valor = txtN->GetValue().Trim();
```

*Elimina espacios en blanco y guardando el valor en un objeto `wxString`*

```c++
bool valor = txtN->GetValue().IsEmpty();
```

*Retornando si el objeto* `CtlText` *está vacío.*


### StaticText:

- En el header

  ```c++
  wxStaticText *sttN1;
  ```

  *Al igual que elementos anteriores, esta es la forma estandar de instanciar objetos en C++.*

- En el C++

```c++
sttN1 = new wxStaticText(
    ObjPanel, 			// Panel donde se añadirá, Parent
    wxID_ANY, 			// Identificador
    "Texto que dirá", 	// Texto
    wxPoint(20, 30), 	// Posición
    wxDefaultSize, 		// Tamaño
    wxALIGN_CENTER		// Alineación
); 
```

  De esta forma creamos los `StaticText, los podemos usar directos en el `OnInit`.



## 8. Estableciendo un icono a una ventana

- En el C++

```c++
objDialog->SetIcon(wx_ICON(icon_app));
```

  *`objDialog` puede ser tanto un frame (ventana normal) o un dialog (ventana de diálogo)*



## 9. Estableciendo y cargando recursos

- En un archivo de recursos
  *Los recursos se cargan en archivos .rc, que están aparte*

```c++
icon_app ICON icon.ico
```

  *Se estableció una constante que indica donde está el icono*



## 10. General:

* `exit(0);` Cierra la aplicación y todos sus procesos.

### Los enumerados:

- En el header

```c++
    enum
    {
        ID_USUARIO = wxID_HIGHEST + 1, 	
        ID_OTRO,
        ID_OTRO_2
    };
```

  `ID_USUARIO = wxID_HIGHEST + 1`,  Esta sentencia nos dará el ID más alto utilizado por *wxWidgets*, le sumaremos 1 para que no entre en conflicto con otros IDs.

  *Nota: En los enumerados, cuando se le asigna un valor entero a un ID, a los demás se les asigna ese mismo + 1, y así sucesivamente cada uno tendrá un ID diferente.*

### Funciones:

- En el header

```c++
void OnQuit(wxCommandEvent & event);
```

  Esta función está destinada a salir de la ventana, ella se agrega cuando se agrega la clase

```c++
void OnOk(wwxCommandEvent & event);
```

  Igual que la anterior.

### Cómo enlazar eventos

- En el C++

```c++
	Connect(
		wxID_EXIT, 								// Identificador
        wxEVT_COMMAND_BUTTON_CLICKED, 			//Evento
        wxCommandEventHandler(MyApp::OnQuit)	// Lo que se ejecutará
);
```

	Esto conecta al boton con el evento del `click` por medio del `ID`, el identificador puede ser otro; en caso de que no sea salir, el evento puede ser otro a parte de clickear, el manejador de evento ejecutará la función entre paréntesis.

```c++
objeto->Connect(
	wxEVT_COMMAND_BUTTON_CLICKED, 			//Evento
	wxCommandEventHandler(MyApp::function)	// Lo que se ejecutará
);
```

Se puede enlazar determinado objeto con un evento en específico, como cerrar una ventana al darle click al cierre de esa ventana, en este caso no se utiliza el  `ID` porque al especificar el objeto sabe a quién se está refiriendo

## 11. Mensajes de diálogo

- En el C++ (se puede separar la instancia en el header)

```c++
wxMessageDialog *msgPregunta = new wxMessageDialog(
	NULL,										// Parent
    wxT("Texto del diálogo"),					// Texto del diálogo
    wxT("Título del diálogo"),					// Texto del título
    wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION	// Características del diálogo
);
```


















