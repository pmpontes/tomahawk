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

 O grau de testabilidade é uma propriedade extrínseca de todos os programas, e é tanto maior quanto, dentro de um dado contexto de teste, o programa puder ser testado; sendo mais fácil encontrar uma falha nos programas que apresentam um elevado grau de testabilidade do que nos programas com um reduzido grau de testabilidade.
 
 A testabilidade de um programa não pode ser "medida" diretamente, estando esta "medição" condicionada por diversos fatores como a controlabilidade dos seus componentes, a observabilidade dos resultados de um teste, o quão isoláveis e delimitáveis são os seus componentes e respetivas responsabilidades, o quão heterogéneo é o sistema ou o quão legível é esse mesmo sistema.

Segue-se a seguir uma descrição do quão testável é o *Tomahawk*.

- **Controlabilidade**:

  Do inglês *Controllability*, este critério avalia o grau em que é possível controlar o estado dos componentes a serem testados. 
  O código do *Tomahawk* encontra-se estruturado em vários pacotes distintos, encarregados da realização de tarefas distintas (como abordado no [Relatório 3](https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/Report3.md)). Para além disso, os ficheiros contidos nestes pacotes encontram-se por sua vez agrupados em pacotes mais pequenos, encarregados de dividar as complexas tarefas em tarefas cada vez mais simples. 
  Esta hierarquia dos conteúdos permite testar modularmente os componentes da aplicação - dado que estes funcionam se forma independente uns dos outros - permitindo obter um maior controlo sobre o estado do componente a ser testado.

- **Observabilidade**:

  Do inglês *Observability*, este critério avalia o quão visíveis são os resultados de um teste.
  Após uma procura cuidada ao código da aplicação, verificamos que a equipa do *Tomahawk* não criou um único teste, embora tenham desenvolvido um mecanismo para a criação e manutenção destes. 
  Foi-nos revelado por um dos membros da equipa de desenvolvedores, após esta ter sido inquirida sobre a situação descrita, que dentro do seu conhecimento não tinham sido criados quaisqueres testes.

- **Isolabilidade** e **Separação de responsabilidades**:
 
 Estes dois critérios encontram-se intimamente ligados.
 O nome do primeiro provém do inglês *Isolateability* e avalia o grau em que um componente pode ser testado de forma isolada de todos os outros componentes, enquanto que o segundo, proveniente do inglês *Separation of concerns*, avalia o grau em que é possível testar de forma independente um componente, devido a este ter uma responsabilidade bem definida.
 Tal como dito acima, o código do *Tomahawk* encontra-se estruturado em pacotes que possuem tarefas destintas. Esta organização permite que o código seja mais legível, menos confuso e portanto mais fácil de testar de forma isoalda.
  
- **Inteligibilidade**:

  Do inglês *Understandability*, este critério avalia a facilidade com que é possível compreender a estrutura e o funcionamento de qualquer componente que esteja a ser testado, baseando-se quer na qualidade com que este se encontra documentado, quer pelo facto do código a ele relativo ser autoexplicativo.
  O código fonte do *Tomahawk* encontra-se muito pouco documentado! Apartando os cabeçalhos dos ficheiros - onde estão contidas apenas informação relativas aos autores e de matérias legais relativas ao uso da aplicação e do seu código - os poucos e esparsos comentários não são esclaredores o suficiente para permitirem uma boa compreensão do mesmo código, pelo menos de uma forma rápida e intuitiva. Raras são as estruturas, módulos e funções comentadas, existindo ficheiros de código que, possuindo mais de mil linhas de código, não contêm mais do que um dezena de comentários.   
  Pode assim afirmar-se que o código do *Tomahawk* não é inteligivel.    

- **Heterogeneidade**:

  Do inglês *Heterogeneity*, este critério avalia a necessidade de serem realizados em paralelo diversos métodos e ferramentas de teste, devido ao uso de diferentes tecnologias.
  O *Tomahawk* é uma aplicação multiplataforma, pelo que teve de ser desenvolvido tendo em mente que diferentes plataformas funcionam de maneiras distintas. Surge então a necessidade de, para cada plataforma, serem criados bancos de testes adequados para o ambiente em que são vão executados.   
  Além disso, o *Tomahawk* depende não só de *APIs* externas, como por exemplo a *Playdar* mas também dos *plugins* criados e necessários ao funcionamento da aplicação, sendo necessários distintos testes para testar todos estes distintos componentes.    
  Pode assim afirmar-se que o *Tomahawk* é heterogéneo.
  
Perante as observações feitas acima, conclui-se que o grau de testabilidade do *Tomahawk* poderá ser aumentado favoravelmente se fossem verdadeiramente criados testes unitários e se o código fosse acompanhado de uma boa documentação, o que - em parceria com a estruturação que o projeto já apresenta - permitiria aumentar não só a observabilidade do código, a  sua inteligibilidade; contribuindo assim para que este possa ser mais facilmente testável.

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
