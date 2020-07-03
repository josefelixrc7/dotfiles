# Usando wxWidgets con C++

**wxWidgets** es una librería de interfaces gráficas escrita en C++. Con ella se pueden crear ventanas, botones, formularios y un sin fin de cosas; todo esto, para poder crear interfaces gráficas de usuarios exitosas (GUI Apps).



## 1. Crear una aplicación:

- Esto va en el header

```c++
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
```

*Nota: Incluimos la cabecera principal de* __wxWidgets__.

```C++
class MyApp : public wxApp // deriva de wxApp
{
	public:
		virtual bool OnInit(); 	// Función booleana virtual que es la primera que inicia todo, no se puede cambiar el nombre
};
```

*Nota: Dentro de la clase debemos de crear todos los objetos, sean de las clases* `wxDialog`*,* `wxFrame`*,* `wxTextCtrl`*,* `wxButton`*, etc. Se puede hacer dentro de la función* `OnInit` *, pero, es más recomendable declararlos o instanciarlos en los archivos header.*

- En el C++

```C++
bool MyApp::OnInit()
{
	// Función principal, aquí colocamos todo lo que hará nuestro programa
	return true;
}
```

*Nota: La función principal* `OnInit(){}` *es la susituye a* `int main(){}` *de una app de CLI. Esta es la que se ejecuta primero en cualquier programa.*



## 2. Crear Frames o ventanas:

### Forma normal

- Este código va en el header

```C++
class MyFrame : public wxFrame // Clase derivada de wxFrame
{
	public:
		MyFrame(const wxString& title); // En este constructor le vamos a pasar el título de la ventana
};
```

*Nota: La clase* `MyFrame` *deriva de la clase* `wxFrame` *, y esta última es la que se encarga de proporcionarle todas las funciones y miembros necesarios para crear ventanas.*

- Este código va en el archivo C++

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

*Aquí inicializa el miembro que es el constructor de la clase* `wxFrame`, dándole algunos valores para crear la ventana*

- En el header

```C++
MyFrame *ventana1;
```

*Nota: Hay que instanciar los objetos que se van a utilizar.*

- En el C++ (mayormente dentro de la función `OnInit`)

```c++
ventana1 = new MyFrame(wxT("Título de la ventana"));
```

*Nota: Aquí creamos nuestra primera ventana de programa*


### 2da manera de crear frames o ventanas:

- En el archivo C++

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

```c++
ventana->Show(true); 
```

*Abre una ventana (sea de diálogo o normal), la muestra en pantalla, se hace visible.

```c++
ventana->Close(true);
```

*Oculta una ventana, la hace invisible, más no cierra sus procesos*

```c++
ventana->Center();
```

*Centra la ventana, puede ser tanto para* `wxFrame` *como para* `wxDialog`

﻿## 3. Implementar una aplicación:

- En el C++

  ```c++
  wxIMPLEMENT_APP(MyApp);
  ```

  *Con esto se implementa una clase para ser una aplicación de* __wxWidgets__*,`MyApp` *es el nombre de la clase derivada de* `wxApp`

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

## 6. Para hacer un boton:

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

### Manejando las cajas de texto

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

  **



- En el C++
`
	sttN1 = new wxStaticText(ObjPanel, 		// Panel donde se añadirá
			wxID_ANY, 		// Identificador
			"Texto que dirá", 	// Texto
			wxPoint(20, 30), 	// Posición
			wxDefaultSize, 		// Tamaño
			wxALIGN_CENTER		// Alineación
); 
`
*Con esto creamos los static text, los podemos usar directos en el OnInit*


## Estableciendo un icono a una ventana

- En el C++
`
objDialog->SetIcon(wx_ICON(icon_app));
`
*objDialog puede ser tanto un frame (ventana normal) o un dialog (ventana de diálogo)*

## Estableciendo y cargando recursos

- En un archivo de recursos
*Los recursos se cargan en archivos .rc, que están aparte*
`
icon_app ICON icon.ico
`
*Se estableció una constante que indica donde está el icono*


## General:

`
exit(0);
`
*Cierra la aplicación y todos sus procesos*

### Los enumerados:

- En el header
`
enum
{
	ID_USUARIO = wxID_HIGHEST + 1, 	// Esto nos dará el ID más alto utilizado por 
					//wxWidgets y le sumaremos 1 para que no entre 
					//en conflicto con otros IDs.
	ID_OTRO, 			// En los enumerados, cuando se le asigna un valor 
					// entero a un ID, a los demás se les asigna ese
					// mismo + 1, y así sucesivamente cada uno tendrá un ID diferente. 
	ID_OTRO_2
};
`

### Funciones:

- En el header
`
void OnQuit(wxCommandEvent & event);
`
*Esta función está destinada a salir de la ventana, ella se agrega cuando se agrega la clase*

`
void OnOk(wwxCommandEvent & event);
`
*Igual que la anterior*


### Cómo enlazar eventos

- En el C++
`
	Connect(wxID_EXIT, 				// Identificador
	wxEVT_COMMAND_BUTTON_CLICKED, 		//Evento
	wxCommandEventHandler(MyApp::OnQuit)	// Lo que se ejecutará
);
`
*Esto conecta al boton con el evento del click por medio del id, el identificador puede ser otro en caso de que no sea salir, el evento puede ser otro a parte de clickear, el manejador de evento ejecutará la función entre paréntesis*


`
objeto->Connect(
	wxEVT_COMMAND_BUTTON_CLICKED, 		//Evento
	wxCommandEventHandler(MyApp::function)	// Lo que se ejecutará
);
`
*Se puede enlazar determinado objeto con un evento en específico, como cerrar una ventana al darle click al cierre de esa ventana, en este caso no se utiliza el* __ID__ *porque al especificar el objeto sabe a quién se está refiriendo*

## Mensajes de diálogo

- En el C++ (se puede separar la instancia en el header)

`
wxMessageDialog *msgPregunta = new wxMessageDialog(
	NULL,																				// Parent
	wxT("Texto del diálogo"),										// Texto del diálogo
	wxT("Título del diálogo"),									// Texto del título
	wxYES_NO | wxNO_DEFAULT | wxICON_QUESTION		// Características del diálogo
);
`
**
















