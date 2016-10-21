# Trabalho Prático 2 - Computação Gráfica 2016

## Labirinth Scape
Projeto desenvolvido para a disciplina de Computação Gráfica no CEFET-MG, com o objetivo de simular um labirinto em 3D utilizando os conhecimentos de **OpenGL** e **C++**.

![alt Demo](https://raw.githubusercontent.com/caiubi/LabirinthScape/master/ImageResources/Demo.png)

### Observações:
O programa está em fase de desenvolvimento, e o conteúdo descrito abaixo é uma idealização das funcionalidades ainda a serem desenvolvidas.

### Instalação e execução

Labirinth Scape requer as seguintes bibliotecas para ser compilado e executado:
* GLFW **v3.2.1** (baixe [aqui](http://www.glfw.org/download.html))
* SOIL **v1.16** (baixe [aqui](http://www.lonesock.net/soil.html))

Para instalar e configurar essas bibliotecas automaticamente (Linux apenas), utilize os seguintes comandos:

Linux:
```sh
$ cd <diretorio-raiz-labirinthscape>
$ make setup
```

Para compilar e executar o programa:

MacOS e Linux:
```sh
$ cd <diretorio-raiz-labirinthscape>
$ make
```

Para limpar os executaveis e arquivos objetos existentes:
```sh
$ cd <diretorio-raiz-labirinthscape>
$ make clean
```

### Comandos:
* Utilize as teclas **cima** e **baixo** para mover o personagem para frente e trás.
* Utilize as setas **esquerda** e **direita** para mover a direção do personagem.
* A partir de qualquer tela as teclas r ou esq podem ser pressionadas para reiniciar ou finalizar o jogo respectivamente.

#### Em breve:
* Como instalar as dependências em MacOS

