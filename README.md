# Padrões de Projetos

Análise de códigos com Padrões de Projeto de Software. Nesse documento veremos 3 exemplos de Padrões de Projeto (Design Patterns):

1. Singleton (Padrão Criacional)

2. Bridge (Padrão Estrutural)

3. (Padrão Comportamental)
<br/>

- Singleton:

É um padrão de projeto criacional que serve para garantir uma única instância de um objeto e ainda proporciar um lugar de acesso global para qualquer parte do código. É possível utilizar o singleton quando seu programa deve ter apenas uma instância da classe a disposição dos clientes. Ele limita a classe a apenas um meio de criação de objeto, anulando todos os outros. E também, quando for preciso retringir o acesso a uma varíavel global, ou seja, só a classe singleton pode substituir a instância criada pela mesma. A implemetação desse padrão é comumente feita por criar um construtor da classe com encapsulamento privado, impedindo que outros objetos usem do operador new, e ainda criar um método estático com encapsulamento público para realizar a instância da classe em um campo estático, retornado sempre a mesma instância em chamadas posteriores. 

[Veja um exemplo de uma classe Singleton em Python, retirada do site GeeksforGeeks.] (https://github.com/virocha11/padroesProjetos/blob/939c3d08d92f4fd3002a07ec779bede4b949f7a6/singleton.py#L1-L15)

  Observe que o método `__new__` é responsável por criar e retornar uma instância da classe `Singleton` e também verifica a existência de um atributo `__instance` com o método `hasattr()` caso não tenha ele cria e armazena em `cls.__instance`. 
Se a classe Singleton é instanciada pela primeira vez, na linha 9, a verificação `hasattr(cls, '__instance')` retorna False, pois o atributo `__instance` ainda não existe. Quando a classe Singleton for instanciada novamente, a verificação `hasattr(cls, '__instance')` retorna True. Logo, a mesma instância é retornada, sem criar uma nova. O método `print(singleton is new_singleton)` está verificando se as variáveis `singleton` e  `new_singleton` referenciam a mesma instância. Como o padrão Singleton está sendo seguido corretamente, a saída será True.
A linha 14 define um atributo `singl_variable` na instância `singleton`. O `print(new_singleton.singl_variable)` vai imprimir "Singleton Variable",pois `new_singleton` referencia a mesma instância da classe.

- Abaixo encontra-se o diagrama da classe Singleton no padrão UML.

![Diagrama UML da classe Singleton](https://upload.wikimedia.org/wikipedia/commons/d/dc/Singleton_pattern_uml.png)

Fonte: Wikimedia.org

Nota: Cabe dizer, que embora o Singleton resolva dois problemas ele infringe o princípio de Responsabilidade Única, dos princípios SOLID.

<br/>

- Bridge