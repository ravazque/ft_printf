# ft_printf
En este proyecto haremos una función réplica de "printf". El principal objetivo de este proyecto es entender el uso de funciones variádicas en C. Podremos crear tantos archivos cómo queramos y hacer uso de nuestra librería: "libft".

Hemos de saber antes de empezar que el valor de retorno de la funcion printf, más alla de imprimir caracteres, devuelve la cantidad de caracteres propiamente impresos.
En una funcion como por ejemplo: printf("Hola %s", "mundo")
Aquí imprimirá "Hola mundo" y devolverá 10 (la cantidad de caracteres impresos).

Además la función printf en C permite imprimir datos en función del formato de la cadena, es decir:

%c: Imprime un solo carácter.
%s: Imprime una cadena (string).
%p: Imprime un puntero en formato hexadecimal.
%d y %i: Imprimen números enteros en base 10.
%u: Imprime un número sin signo en base 10.
%x: Imprime un número hexadecimal en minúsculas.
%X: Imprime un número hexadecimal en mayúsculas.
%%: Imprime el símbolo %.

En este caso estos son todos los que tendremos que aplicar a nuestra funion ft_printf si es que decidimos no hacer el bonus

Tambien, para este proyecto, es necesario saber que  las funciones que aceptan un número indefinido de argumentos se manejan con macros de la librería `#include <stdarg.h>`, como va_start, va_arg, va_copy y va_end. Estas macros permiten acceder y gestionar los argumentos variables de manera segura y eficiente.

Principales macros:
va_start: Inicializa la lista de argumentos variables. Se usa con un va_list y debe indicarse el último parámetro fijo de la función.

Ejemplo: va_start(ap, n); donde ap es la lista y n el último parámetro fijo.
va_arg: Recupera el siguiente argumento de la lista, especificando su tipo.

Ejemplo: int x = va_arg(ap, int); toma el siguiente argumento como entero.
va_copy: Crea una copia de la lista de argumentos variables para reutilizarlos.

Ejemplo: va_copy(copy, ap); copia la lista ap a copy.
va_end: Libera los recursos usados por va_list después de haber procesado todos los argumentos.

Ejemplo: va_end(ap); cierra la lista de argumentos.
Estas macros permiten implementar funciones como printf que pueden recibir una cantidad indefinida de parámetros.
