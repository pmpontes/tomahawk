<img src="https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcQ5v37xur40kL994HczH-li9mzyHP47jhvORpy-vNoHzatPjm11gSvwLVU" alt="FEUP">
####**Engenharia de Software 2015/2016**
#####MIEIC - 3ºAno

###Grupo:
- Gil Manuel Oliveira de Almeida Domingues, **gil.domingues@fe.up.pt**
- Pedro Martins Pontes, **pontes.pedro@fe.up.pt**
- Pedro Miguel Pereira de Melo, **up201305618@fe.up.pt**

###Verificação e Validação de *Software*
Num contexto de desenvolvimento de *software*, é frequente questionarmos se se está a desenvolver o produto certo e se isso está a ser feito corretamente. Responder a estas questões implica aplicar processos de verificação e validação, por forma a garantir que o produto se adequa ao seu propósito – isto é, se, por um lado, faz aquilo que é necessário, e, por outro, se o faz bem.

Importa, pois, analisar os processos de verificação e validação aplicados no desenvolvimento do projeto *Tomahawk*.

####Grau de testabilidade
Quão testável é um programa? A testabilidade de um programa é condicionada por fatores como a controlabilidade dos seus componentes, a observabilidade dos resultados de um teste, o quão isoláveis e delimitáveis são os seus componentes e respetivas responsabilidades, o quão heterogéneo e fácil de entender é o sistema.

Seguidamente, discute-se o quão testável é o projeto - por meio de exemplos e outras referências, sempre que tal se considere pertinente.

- Controlabilidade

Este critério define-se como o grau a que é possível controlar o estado dos componentes a serem testados. 


- Observabilidade

A observabilidade determina o quão observáveis são os resultados de um teste. 


- «Isolabilidade»

Não sendo parte da Língua Portuguesa, o termo «isolabilidade» respeita ao grau de testabilidade de um componente, isoladamene.


- Separação de responsabilidades

Este critério está intimamente ligado ao anterior, e implica a delimitação de responsabilidades entre os vários componentes a ser testados.


- Inteligibilidade

Medida do quão simples de compreender é o componente a testar – seja pela qualidade da sua documentação ou pelo facto de ser autoexplicativo.


- Heterogeneidade

Critério que relaciona o uso de diferentes tecnologias com a necessidade de métodos de teste diversificados.



Perante as considerações acima, é possível concluir que (…)
(Discuss how 'testable' is the program. Discuss how to improve the testability of software components.)

####Testes em números
(identificar diversos tipos de teste)

Antes de apresentar números, é pertinente interrogar (…)

Number of tests (# tests unitários; # tests de sistema, # tests de desempenho, % coverage)

Um teste de cobertura determina a percentagem de linhas de código – ou outra unidade de programação – alcançada por um conjunto de testes. Mas o que significa este número? O que se pode concluir dele?

Os números de um teste de cobertura podem ser facilmente manipulados, visto que basta invocar alguns métodos nos casos de teste para que a percentagem de cobertura suba, sem necessidade de confirmar os resultados desses métodos.

Com efeito, pode tirar-se mais informação de uma percentagem de cobertura baixa – que  pode significar que o conjunto de testes definidos não são adequados – do que uma cobertura de 100%. Com efeito, um teste de cobertura pode dizer-nos que um conjunto de testes é inadequado, mas nunca o contrário.

Análise de cobertura é, sobretudo, uma ferramenta de revisão de código, na medida em que identifica qual o código que não foi sujeito a testes – e pode usar-se essa informação para repensar o conjunto de testes em si, a estratégia de teste ou o próprio design do sistema.

A ideia por trás de um teste de cobertura por mutação é a geração de mutações no código a ser testado, como negação de condições boleanas ou operações com inteiros – sendo que um conjunto de testes é bom quando as alterações introduzidas despoletarem a falha de um elevado número teste.
http://avandeursen.com/2013/11/19/test-coverage-not-for-managers/

####Processo de identificação e correção de um *Bug*
Escolher um bug fácil ou já corrigido

####Análise Crítica
Concluindo, constata-se que o Tomahawk é um projeto (analisar testabilidade).

Teria sido interessante apresentar e analisar dados concretos relativos aos testes a que o código do projeto é sujeito. Todavia, não foi possível obter esses testes ou os seus resultados. Os únicos testes disponíveis – através do repositório – estão desatualizados, facto que pode indicar que, uma vez desenvolvido o *core* da aplicação, a definição de testes deixou de ser uma prioridade.

Mais ainda, a Dashboard – a plataforma usada para gerir *bugs* e anomalias encontrou-se *offline* durante todo o período de elaboração do presente relatório, pelo que o exercício de selecionar um *bug* para corrigir – por forma a ilustrar o processo de verificação do projeto – não pôde ser realizado.
