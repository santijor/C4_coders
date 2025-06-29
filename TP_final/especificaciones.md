- Integrantes: Gustavo Calderon, Ivan Vargas, Nicolas Gregori, Santiago Jorquera
  
- Consignas implementadas:
1) Buscar estudiantes por nombre y por rango de edad.
2) Cada estudiante puede anotarse a una materia y rendirla.
3) Dar de alta, modificar, eliminar y listar estudiantes y materias.
   
- Puntos extra:
1) Busqueda por árbol binario.
2) Exportar estudiantes y sus caracteristicas con CSV.
3) Tests unitarios.

- Dentro de la carpeta estudiante se encuentra todo el trabajo. En la carpeta de test se encuentran los test unitarios. En la carpeta lista se encuentra el anterior TP que realizamos, el cual nos sirvió para realizar este trabajo, mientras que en la carpeta de util se encuentra el código del árbol binario. Por ultimo, en la carpeta de ckmake-build-debug es donde se guardan las distintas caracteristicas del estudiante y/o materia en formato csv.

/**Limitaciones del código y sus motivos:

1) Tildes y "ñ" en nombres de estudiantes: al momento de crear un Estudiante y asignarle un nombre, si incluye una tilde en él o una ñ ocurrirá un error (se escribiran caracteres en hexadecimal), por lo que creemos más conveniente que simplemente no se escriban nombres con tilde o ñ a la hora de usar el código.
