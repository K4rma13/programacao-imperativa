# Ex 3.3
- Criar triangulo.c, horizontal.c, vertical.c
- Compilar os 3 separadamente com o comando: `gcc -c *nome do ficheiro*.c`
- Compilar os resultantes triangulo.o, horizontal.o e vertical.o da seguinte maneira:
  - `gcc -o t1 triangulo.o vertical.o`
  - `gcc -o t2 triangulo.o horizontal.o`
- Com isto 2 executaveis (t1 e t2) são criados, com a função "main" de ambos sendo a de triangulo.c, e a função "triangulo" de t1 e t2 respetivamente a função de vertical.c e horizontal.c
