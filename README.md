# ft_printf

El proyecto **ft_printf** consiste en la creación de una función que replica el comportamiento de la función estándar **printf** en C. El objetivo principal de este proyecto es aprender a trabajar con funciones que aceptan un número indefinido de argumentos mediante el uso de funciones variádicas en C.

‎  

## Funcionalidad
La función **ft_printf** no solo imprime caracteres, sino que también devuelve la cantidad de caracteres impresos. Por ejemplo, en la llamada:


`printf("Hola %s", "mundo");`

Se imprimirá: `Hola mundo`, y se devolverá el valor **10**, que es la cantidad total de caracteres impresos.

‎

## Formatos soportados
El comportamiento de la función **ft_printf** dependerá de los especificadores de formato en la cadena de entrada. Estos son los formatos que deberás implementar:

- `%c` ➜ Imprime un solo carácter.
- `%s` ➜ Imprime una cadena de caracteres (string).
- `%p` ➜ Imprime un puntero en formato hexadecimal.
- `%d` | `%i` ➜ Imprime números enteros en base 10.
- `%u` ➜ Imprime un número sin signo en base 10.
- `%x` ➜ Imprime un número hexadecimal en minúsculas.
- `%X` ➜ Imprime un número hexadecimal en mayúsculas.
- `%%` ➜ Imprime el símbolo `%`.

Estos son los formatos necesarios para la versión obligatoria de **ft_printf**. El proyecto puede expandirse con funciones adicionales si decides hacer el **bonus**.

‎

## Uso de argumentos variádicos
La implementación de **ft_printf** requiere manejar una cantidad indefinida de argumentos. Para esto, se utilizan macros de la librería **`<stdarg.h>`**, que permite acceder y gestionar estos argumentos de forma eficiente.

Las principales macros son:

- **`va_start`** ➜ Inicializa la lista de argumentos variables. Debe ser usada con un **`va_list`** e indicarse el último parámetro fijo de la función.

    ```c
    va_start(ap, n);
    ```

- **`va_arg`** ➜ Recupera el siguiente argumento de la lista, especificando su tipo.

    ```c
    int x = va_arg(ap, int);
    ```

- **`va_copy`** ➜ Crea una copia de la lista de argumentos variables.

    ```c
    va_copy(copy, ap);
    ```

- **`va_end`** ➜ Libera los recursos utilizados por **`va_list`** al finalizar el procesamiento de los argumentos.

    ```c
    va_end(ap);
    ```

Estas macros son esenciales para implementar funciones como **ft_printf**, ya que permiten gestionar una lista de parámetros que puede variar en número y tipo.


----

> [!NOTE]
> **ft_printf** es un proyecto fundamental para entender las funciones variádicas en C y nos ayudará a mejorar nuestras habilidades de programación para futuros proyectos más complejos.
