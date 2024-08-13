# Padrões de Projetos

Análise de códigos com Padrões de Projeto de Software. Nesse documento veremos 3 exemplos de Padrões de Projeto (Design Patterns):

1. Singleton (Padrão Criacional)

2. Bridge (Padrão Estrutural)

3. Mediator (Padrão Comportamental)
<br/>

- Singleton:

É um padrão de projeto criacional que serve para garantir uma única instância de um objeto e ainda proporciar um lugar de acesso global para qualquer parte do código. É possível utilizar o singleton quando seu programa deve ter apenas uma instância da classe a disposição dos clientes. Ele limita a classe a apenas um meio de criação de objeto, anulando todos os outros. E também, quando for preciso retringir o acesso a uma varíavel global, ou seja, só a classe singleton pode substituir a instância criada pela mesma. A implemetação desse padrão é comumente feita por criar um construtor da classe com encapsulamento privado, impedindo que outros objetos usem do operador new, e ainda criar um método estático com encapsulamento público para realizar a instância da classe em um campo estático, retornado sempre a mesma instância em chamadas posteriores. 

[Veja um exemplo do Singleton em Python, retirada do site GeeksforGeeks] (https://github.com/virocha11/padroesProjetos/blob/939c3d08d92f4fd3002a07ec779bede4b949f7a6/singleton.py#L1-L15)

  Observe que o método `__new__` é responsável por criar e retornar uma instância da classe `Singleton` e também verifica a existência de um atributo `__instance` com o método `hasattr()` caso não tenha ele cria e armazena em `cls.__instance`. 
Se a classe Singleton é instanciada pela primeira vez, na linha 9, a verificação `hasattr(cls, '__instance')` retorna False, pois o atributo `__instance` ainda não existe. Quando a classe Singleton for instanciada novamente, a verificação `hasattr(cls, '__instance')` retorna True. Logo, a mesma instância é retornada, sem criar uma nova. O método `print(singleton is new_singleton)` está verificando se as variáveis `singleton` e  `new_singleton` referenciam a mesma instância. Como o padrão Singleton está sendo seguido corretamente, a saída será True.
A linha 14 define um atributo `singl_variable` na instância `singleton`. O `print(new_singleton.singl_variable)` vai imprimir "Singleton Variable", pois `new_singleton` referencia a mesma instância da classe.

- Abaixo encontra-se o diagrama da classe Singleton no padrão UML.

![Diagrama UML da classe Singleton](https://upload.wikimedia.org/wikipedia/commons/d/dc/Singleton_pattern_uml.png)

Fonte: commons.wikimedia.org

Nota: Cabe dizer, que embora o Singleton resolva dois problemas ele infringe o princípio de Responsabilidade Única, dos princípios SOLID.

<br/>

- Bridge:

É um padrão de projeto estrutural usado para evitar que um conjunto de classes, ou classe grande, tenha uma ligação permanente entre a abstração e a implementação, dividindo em duas hierarquias independentes entre si. Assim, diminuindo o acoplamento entre elas. Esse padrão é usado quando nos deparamos com problemas de escalabilidade, que consiste em expandir o software de modo eficiente. A solução abordada para o Bridge é de utilizar o relacionamento de composição entre a implementação e abstração, ao invés de herança, extraindo hierarquias de classes. Desse modo, será possível modificar as classes de maneira independente em relação a outra hierarquia. Porque, a classe de abstração não vai se encarregar de todos os trabalhos. O trabalho será delegado ao objeto de implementação.

[Veja um exemplo do padrão Bridge em C++, adpatado do site GeeksforGeeks.](https://github.com/virocha11/padroesProjetos/blob/d30ea64774d48fed801ad01d2c8a0ab85423e47e/bridge.cpp#L1-L82)

  Observe que o código possui duas classes abstratas: `Shape` (abstração) que define a interface para os tipos de formas Circle e Square. Ela possui um método virtual puro `draw()`, que será implementado pelas subclasses. E `Renderer`(implementação) que define a interface para as formas de renderização, VectorRenderer e RasterRenderer. Essa classe tem o método virtual puro `render()`, o qual será implementado pelas classes concretas.
As classes concretas `VectorRenderer` e `RasterRenderer` herdam da implementação Renderer e escrevem o método `render()`. Já as classes `Circle` e `Square` escrevem o código `draw()` da abstração Square. Ambas as classes estão dependendo de uma referência ou instância de Renderer, passada no método construtor da classe, que vai realizar o processo de renderização específico de cada forma. 
As instâncias de VectorRenderer e RasterRenderer são então criadas e passadas para as formas de Circle e Square na função `main()`. Assim, as formas `circle.draw()` e `square.draw()` desenham e chamam a renderização de vetor ou raster correspondente.

- Encontra-se abaixo o diagrama do Bridge no padrão UML.

![Diagrama UML do padrão Bridge](https://upload.wikimedia.org/wikipedia/commons/c/cf/Bridge_UML_class_diagram.svg)

Fonte: commons.wikimedia.org
<br/>

- Mediator:

É um padrão de projeto comportamental que serve para reduzir as dependências entre objetos, diminuindo o nível de acoplamento entre eles. Ele limita as colaborações dos objetos para se comunicarem apenas com um objeto mediador, o qual é responsável por enviar as mensagens para os demais. O Mediator é usado para casos em que há dificuldade de mudança nas classes, devido ao acoplamento com outras e também em casos que é preciso reutilizar o código mas ele dependente muito de outros componentes. Nesses casos, o padrão diz que os componentes devem colaborar indiretamente uns com os outros, focando a comunicação em única classe mediadora. Desse modo, os componentes estaram alheios aos outros, aumentando a facilidade de mudança e reutilização do código.

[Veja um exemplo do padrão Mediator em Java]()

  Observe que `Buyer` e `AuctionMediator` interajam de forma desacoplada. Se o comportamento do leilão precisar mudar, pode-se modificar o AuctionMediator sem impactar os Buyer diretamente. 
A interface `Mediator` está definindo os métodos, `addBuyer()` e `findHighestBidder()` que devem ser implementados por qualquer classe mediadora derivada dela. A classe derivada `AuctionMediator` implementa os métodos da interface Mediator e armazena uma lista de compradores (buyers). 
A classe abstrata `Buyer` estabelece os métodos `bid(int price)` e `cancelTheBid()` que devem ser implementados por qualquer comprador. Repare que cada comprador tem uma referência a interface `Mediator` para a interação entre elas, além de armazenar o nome e o valor do lance (price). A classe `AuctionBuyer` é uma implementação concreta de `Buyer`.
A função `main()` está criando uma instância do mediador "AuctionMediator" e também adicionando três compradores (b1, b2 e b3). Cada comprador faz um lance, e o mediador escolhe o lance mais alto. O mediador determina novamente quem tem o lance mais alto entre os compradores restantes após o cancelamento do lance b2.


- Veja abaixo o diagrama do Mediator no padrão UML. 
![Diagrama UML do Mediator](https://refactoring.guru/images/patterns/diagrams/mediator/structure-indexed-2x.png)

Fonte: refactoring.guru
<br/>
- Referências

Refactoring Guru
https://refactoring.guru/pt-br/design-patterns

https://refactoring.guru/pt-br/design-patterns/singleton

https://refactoring.guru/pt-br/design-patterns/bridge

https://refactoring.guru/pt-br/design-patterns/mediator

GeeksforGeeks 
https://www.geeksforgeeks.org/singleton-pattern-in-python-a-complete-guide/

https://www.geeksforgeeks.org/bridge-method-c-design-patterns/

https://www.geeksforgeeks.org/mediator-design-pattern-in-java/

Wikimedia Commons
https://commons.wikimedia.org/wiki/File:Singleton_pattern_uml.png

https://commons.wikimedia.org/wiki/File:Bridge_UML_class_diagram.svg

