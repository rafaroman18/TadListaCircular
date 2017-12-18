# Definición:
Una lista circular es una secuencia de elementos de un mismo tipo en la que todos tienen
un predecesor y un sucesor, es decir, es una secuencia sin extremos.

Su longitud coincide con el número de elementos que la forman; si es 0, entonces la lista está vacía.

Una lista circular de longitud n se puede representar de la forma 
<a href="https://www.codecogs.com/eqnedit.php?latex=L=(a_{1},a_{2},...,a_{n},a_{1})" target="_blank">
<img src="https://latex.codecogs.com/gif.latex?L=(a_{1},a_{2},...,a_{n},a_{1})" title="L=(a_{1},a_{2},...,a_{n},a_{1})" /></a> 
donde repetimos <img src="https://latex.codecogs.com/gif.latex?a_{1}" title="a_{1}" /> después de <img src="https://latex.codecogs.com/gif.latex?a_{n}" title="a_{n}" /> para indicar que el elemento que sigue a <img src="https://latex.codecogs.com/gif.latex?a_{n}" title="a_{n}" /> es <img src="https://latex.codecogs.com/gif.latex?a_{1}" title="a_{1}" /> y el
anterior a éste es <img src="https://latex.codecogs.com/gif.latex?a_{n}" title="a_{n}" />.

Definimos una posición como el lugar que ocupa un elemento en la lista.
La constante POS_NULA denota una posición inexistente.
# Operaciones:
## ListaCir()
Postcondiciones: Crea y devuelve una lista circular vacía.

## void insertar(const T& x, posicion p)
Precondiciones: <img src="https://latex.codecogs.com/gif.latex?L=()" title="L=()" /> y p es irrelevante o bien,
<img src="https://latex.codecogs.com/gif.latex?L=(a_{1},a_{2},...,a_{n},a_{1})" title="L=(a_{1},a_{2},...,a_{n},a_{1})" /> y <img src="https://latex.codecogs.com/gif.latex?\dpi{110}&space;1\leq&space;p\leq&space;n" title="1\leq p\leq n" />

Postcondiciones: Si <img src="https://latex.codecogs.com/gif.latex?L=()" title="L=()" />, entonces <img src="https://latex.codecogs.com/gif.latex?L=(x,x)" title="L=(x,x)" /> (lista circular con un único elemento);
en caso contrario,
<img src="https://latex.codecogs.com/gif.latex?L=(a_{1},...,a_{p-1},x,a_{p},...,a_{n},a_{1})" title="L=(a_{1},...,a_{p-1},x,a_{p},...,a_{n},a_{1})" />

## void eliminar(posicion p)
Precondiciones: <img src="https://latex.codecogs.com/gif.latex?L=(a_{1},a_{2},...,a_{n},a_{1})" title="L=(a_{1},a_{2},...,a_{n},a_{1})" /> , <img src="https://latex.codecogs.com/gif.latex?\dpi{110}&space;1\leq&space;p\leq&space;n" title="1\leq p\leq n" />

Postcondiciones: <img src="https://latex.codecogs.com/gif.latex?L=(a_{1},...,a_{p-1},a_{p&plus;1},...,a_{n},a_{1})" title="L=(a_{1},...,a_{p-1},a_{p+1},...,a_{n},a_{1})" />

## const T& elemento(posicion p)
Precondiciones: <img src="https://latex.codecogs.com/gif.latex?L=(a_{1},a_{2},...,a_{n},a_{1})" title="L=(a_{1},a_{2},...,a_{n},a_{1})" /> , <img src="https://latex.codecogs.com/gif.latex?\dpi{110}&space;1\leq&space;p\leq&space;n" title="1\leq p\leq n" />

Postcondiciones: Devuelve <img src="https://latex.codecogs.com/gif.latex?a_{p}" title="a_{p}" />, el elemento que ocupa la posición p.

## posicion buscar(const T& x ) const
Postcondiciones: Devuelve la posición de una ocurrencia de x en la lista.

Si x nopertenece a la lista, devuelve POS_NULA.

## posicion inipos() const
Postcondiciones: Devuelve una posición indeterminada de la lista. Si la lista está vacía,devuelve POS_NULA.

Esta operación se utilizará para inicializar una variable de tipo posicion.

## posicion siguiente(posicion p) const
Precondiciones: <img src="https://latex.codecogs.com/gif.latex?L=(a_{1},a_{2},...,a_{n},a_{1})" title="L=(a_{1},a_{2},...,a_{n},a_{1})" /> , <img src="https://latex.codecogs.com/gif.latex?\dpi{110}&space;1\leq&space;p\leq&space;n" title="1\leq p\leq n" />

Postcondiciones: Devuelve la posición siguiente a p.

## posicion anterior(posicion p) const
Precondiciones: <img src="https://latex.codecogs.com/gif.latex?L=(a_{1},a_{2},...,a_{n},a_{1})" title="L=(a_{1},a_{2},...,a_{n},a_{1})" /> , <img src="https://latex.codecogs.com/gif.latex?\dpi{110}&space;1\leq&space;p\leq&space;n" title="1\leq p\leq n" />

Postcondiciones: Devuelve la posición anterior a p.
