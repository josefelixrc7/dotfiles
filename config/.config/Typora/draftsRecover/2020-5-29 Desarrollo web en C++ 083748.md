# Desarrollo web en C++

## Usando cgicc

### Compilando e instalando

1. Descargar el software y descomprimir
2. Configurar, compilar e instalar

```bash
cd cgicc-x.x.x ; mkdir build ; cd build
../configure --prefix=/usr
make
sudo make install
```

3. Asegurarse que las librerías de cgicc se instalaron

```bash
ls /usr/lib | grep cgicc
```

### Configurar uso de CGI en Apache

1. Abrir el archivo de configuración principal de Apache (puede estar en `/usr/local/apache2/conf/httpd.conf` o en `/etc/httpd/conf/httpd.conf`
2. Buscar la carga del módulo de `cgid`: `#LoadModule cgid_module modules/mod_cgid.so` y descomentar
3. Buscar el bloque `<IfModule alias_module>` y en `ScriptAlias /cgi-bin/ "/var/www/cgi-bin/"` establecer el directorio que tendrá los scripts a ejecutar
4. Establecer los permisos de ejecución en el directorio de scripts cgi

```
<Directory "/var/www/cgi-bin/">
    AllowOverride None
    Options +ExecCGI
    AddHandler cgi-script .cgi .pl .py
    Require all granted
</Directory>
```

5. Los scripts o ejecutables cgi en los directorios deben de tener el siguiente permiso: `chmod 775 script.cgi`

### Programa sencillo con librerías de cgicc

1. Incluimos las cabeceras principales de la librería cgicc

```c++
#include <cgicc/Cgicc.h> 
#include <cgicc/CgiDefs.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h>  
```

2. En donde vayamos a utilizar la programación web (para el uso de métodos GET y POST, por ejemplo) debemos instanciar un objeto del tipo `cgicc::Cgicc`:

```c++
cgicc::Cgicc formData;
```

3. Si queremos que nuestro ejecutable muestre un sitio web con estructura HTML y o diseños, podemos hacerlo añadiendo:

```c++
std::cout << "Content-type:text/html\r\n\r\n";
std::cout << "<!DOCTYPE HTML>\n";
std::cout << "<html>\n";
std::cout << "	<head>\n";
std::cout << "		<title>Using GET and POST Methods</title>\n";
std::cout << "	</head>\n";
std::cout << "	<body>\n";
std::cout << "		<p>Hola, todos.</p>\n";
std::cout << "	</body>\n";
std::cout << "</html>\n";
```

4. Para recibir parámetros mediante GET o POST debemos crear un objeto del tipo `cgicc::form_iterator`:

```c++
cgicc::form_iterator fi = formData.getElement("parametro");  
```

5. Para ver los datos recibidos por GET o POST debemos asegurarnos de que no esté vacío y sí se haya enviado:

```c++
if(!fi->isEmpty() && fi != (*formData).end()) {  
	std::cout << "parametro: " << **fi << "\n";  
} else {
    std::cout << "No se encontró valor para parámetro" << "\n";  
}
```

### Procesando checkboxes

1. creamos el formulario HTML:

```html
<form action="cpp_checkbox.cgi" metho="POST" target="_blank">
	<input type="checkbox" name="arroz" value="on" /> Arroz
   	<input type="checkbox" name="ensalada" value="on" /> Ensalada
   	<input type="submit" value="Selecciona comida" />
</form>
```

2. Creamos objetos booleanos que guardarán los valores de los checkboxes:

```c++
bool arroz_flag, ensalada_flag;
```

3. Procesamos y almacenamos en las variables los valores de los checkboxes:

```c++
arroz_flag = formData.queryCheckbox("arroz");
ensalada_flag = formData.queryCheckbox("ensalada");
```

### Accediendo a la información directamente

 Si no necesitas validar o modificar la información entrante, simplemente accede a la representación tipo `string` de la información:

```c++
std::string name = formData("name");
```

o si necesitas modifcar o validar:

```c++
name->getValue()
```

### Respuestas HTTP

cgicc provee de encabezados para un odcumento, a partir de html4 solo se necesita retornar un encabezado:

```c++
cout << cgicc::HTTPHTMLHeader() << endl;
```

Lo cual generará: `Content-Type: text/html\n\n`

### Impresiones HTML

cgicc provee una clase por cada etiqueta del estandar html4, esto para poder usar esas etiquetas en su programa:

```c++

```

