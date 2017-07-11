Las variables se actualizan solo en el proceso hijo ya que es el que ejecuta dicha actualización, y a parte cada proceso no
comparte las variables del otro. Por lo tanto que se actualicen en el hijo no significa que se actualicen en el padre.

Los mensajes que se escriben cuando está comentada la opción para desactivar el buffer de salida por pantalla,
se van guardando en el buffer de salida por lo tanto cuando llegamos al mensaje previo al fork lo guardamos
en el buffer de salida del hijo por ejemplo si es el primero en ejecutarse, y luego guardamos el mensaje
que quiere escribir el hijo por pantalla.
Ahora supongamos que se ejecuta es el padre y volvemos a guardar en el buffer el mensaje previo al fork y luego su
mensaje correspondiente.
Y ya escribimos en pantalla.

Si está descomentada quitamos el buffer de salida por pantalla y simplemente se escribe directamente en pantalla
lo que están ejecutando ambos procesos.
