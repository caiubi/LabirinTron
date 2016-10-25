# Trabalho Prático 2 - Computação Gráfica 2016

## LabirinTron
Projeto desenvolvido para a disciplina de Computação Gráfica no CEFET-MG, com o objetivo de simular um labirinto em 3D utilizando os conhecimentos de **OpenGL** e **C++**. O tema escolhido para ilustrar o projeto foi baseado no filme Tron Legacy.

![alt Demo](https://raw.githubusercontent.com/caiubi/LabirinTron/master/Print1.png)

### Instalação e execução

Labirinth Scape requer as seguintes bibliotecas para ser compilado e executado:
* GLFW **v3.2.1** (baixe [aqui](http://www.glfw.org/download.html))
* SOIL **v1.16** (baixe [aqui](http://www.lonesock.net/soil.html))

Para instalar e configurar essas bibliotecas automaticamente (Linux apenas), utilize os seguintes comandos:

Linux:
```sh
$ cd <diretorio-raiz-labirintron>
$ make setup
```

Para compilar e executar o programa:

MacOS e Linux:
```sh
$ cd <diretorio-raiz-labirintron>
$ make
```

Para limpar os executaveis e arquivos objetos existentes:
```sh
$ cd <diretorio-raiz-labirintron>
$ make clean
```

### Comandos:
* Utilize as teclas **cima** e **baixo** para mover o personagem para frente e trás.
* Utilize as setas **esquerda** e **direita** para mover a direção do personagem.
* Utilize a tecla **M** para habilitar um modo de trapaça do programa, dessa forma, é possível visualizar um Minimapa com a representação do labirinto visto de cima.
![alt Demo](https://raw.githubusercontent.com/caiubi/LabirinTron/master/Print2.png)
* Para alternar entre os modos de visualização em primeira e terceira pessoa, pressione a tecla **3**.
* A partir de qualquer tela a tecla **esq** pode ser pressionada para finalizar o programa.

![alt Demo](https://raw.githubusercontent.com/caiubi/LabirinTron/master/Print3.png)

#### Em breve:
* Como instalar as dependências em MacOS
