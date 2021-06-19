# archivo.sal == archivo donde YO predefino qué es lo que debe devolver el programa
# archivo.out == archivo donde se guarda lo que realmente devuelve el programa

# make
# ./tad > jonathan.out
# diff  jonathan.out  jonathan.sal 


# cambiar nombre de tad01.cpp -> tad.cpp (mediante una copia)
# compilar tad.cpp
# ejecutar ./tad > tad.out
# comparar tad<i>.out tad<i>.sal (diff)

# listar todos los archivos *.cpp de la carpeta src (con un bucle)
    # por cada archivo, [cambiarle el nombre] de tad<i>.cpp a tad.cpp (para compilarlo con el make)
    # limpiar la compilación anterior (make clean) -> borrar archivos *.o y archivos ejecutable (tad)
    # compilamos el nuevo tad.cpp
    # ejecutamos y guardamos la salida en un archivo.loquesea.
        # al ejecutar: valgrind -q --tool=memcheck --leak-check=full ./tad
    # comparamos archivo.loquesea VS archivo.salidaesperada (diff archivo.salidaesperada archivo.loquesea)



# carlos names
# tad01.cpp     (código fuente) -> tad.cpp
# tad01.cpp.sal (salida esperada)
# tad01.cpp.out (salida obtenida)


# bash -> .sh

# Iterar sobre todo los archivos *.cpp de las subcarpetas de src/
for file in  src/vector/*.cpp
do
    # Me devuelve el nombre del archivo
    echo "Evaluando $file"
    # Copiar el archivo en $file a src/tad.cpp
    cp $file src/tad.cpp
    # Compilar
    make
    # Ejecutar
    # valgrind -q --tool=memcheck --leak-check=full ./tad > tad.sal
    valgrind -q --tool=memcheck --leak-check=full ./tad > $file.out
    #./tad > tad.sal
    # Comparar 
    # diff -b --brief "tad.sal" "$file.sal" 
    diff -b --brief $file.out $file.sal 
    # ...
    if [ "$?" == "0" ]; then
		echo "OK"
	else
		echo "ERROR"
	fi
    make clean
    #rm ./$file.out


done