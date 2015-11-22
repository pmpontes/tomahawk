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
  O código do *Tomahawk* encontra-se estruturado em vários pacotes distintos, encarregados da realização de tarefas distintas (como abordado no [Relatório 3](https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/Report3.md)).
  Esta hierarquia dos conteúdos permite testar modularmente os componentes da aplicação - dado que estes funcionam se forma independente uns dos outros - permitindo obter um maior controlo sobre o estado do componente a ser testado.

- **Observabilidade**:

  Do inglês *Observability*, este critério avalia o quão visíveis são os resultados de um teste.
  Após uma procura cuidada ao código da aplicação, verificamos que a equipa do *Tomahawk* não criou um único teste, embora tenham desenvolvido um mecanismo para a criação e manutenção destes.
  Foi-nos revelado por um dos membros da equipa de desenvolvedores, após esta ter sido inquirida sobre a situação descrita, que dentro do seu conhecimento não tinham sido criados quaisqueres testes.

- **Isolabilidade** e **Separação de responsabilidades**:

 Estes dois critérios encontram-se intimamente ligados.
 O primeiro provém do inglês *Isolateability* e avalia o grau em que um componente pode ser testado de forma isolada de todos os outros componentes, enquanto que o segundo, proveniente do inglês *Separation of concerns*, avalia o grau em que é possível testar de forma independente um componente, devido a este ter uma responsabilidade bem definida.
 Tal como dito acima, o código do *Tomahawk* encontra-se estruturado em pacotes que possuem tarefas destintas. Esta organização permite que o código seja mais legível, menos confuso e portanto mais fácil de testar de forma isoalda.

- **Inteligibilidade**:

  Do inglês *Understandability*, este critério avalia a facilidade com que é possível compreender a estrutura e o funcionamento de qualquer componente que esteja a ser testado, baseando-se quer na qualidade com que este se encontra documentado, quer pelo facto do seu código ser autoexplicativo.
  O código fonte do *Tomahawk* encontra-se muito pouco documentado. Apartando os cabeçalhos dos ficheiros - onde estão contidas apenas informação relativas aos autores e de matérias legais relativas ao uso da aplicação e do seu código - os poucos e esparsos comentários não são esclaredores o suficiente para permitirem uma boa compreensão do código, pelo menos de uma forma rápida e intuitiva. Raras são as estruturas, módulos e funções comentadas, existindo ficheiros de código que, possuindo mais de mil linhas de código, não contêm mais do que um dezena de comentários.   
  Pode assim afirmar-se que o código do *Tomahawk* é muito pouco inteligivel.

- **Heterogeneidade**:

  Do inglês *Heterogeneity*, este critério avalia a necessidade de serem realizados em paralelo diversos métodos e ferramentas de teste, devido ao uso de diferentes tecnologias.
  O *Tomahawk* é uma aplicação multiplataforma, pelo que teve de ser desenvolvido tendo em mente que diferentes plataformas funcionam de maneiras distintas. Surge então a necessidade de, para cada plataforma, serem criados bancos de testes adequados para o ambiente em que são vão executados.   
  Além disso, o *Tomahawk* depende não só de *APIs* externas, como por exemplo a *Playdar* mas também dos *plugins* criados e necessários ao funcionamento da aplicação, sendo necessários distintos testes para testar todos estes componentes.    
  Pode assim afirmar-se que o *Tomahawk* é heterogéneo.

Perante as observações feitas acima, conclui-se que o grau de testabilidade do *Tomahawk* poderá ser bastante aumentado, começando pela qualidade da documentação do seu código - o que, a par da estruturação que o projeto já apresenta, permitiria aumentar inteligibilidade do código, facilitando a tarefa de definição de testes.

####Testes em números
As estatísticas de teste são um meio que permite acompanhar o progresso e o sucesso de um projeto. Existem diversos tipos de teste – testes unitários, testes de sistema, testes de desempenho – e ainda outras métricas relevantes, como a cobertura.

Uma das estatísticas mais comummente usada é a cobertura, que determina a percentagem de linhas de código – ou outra unidade de programação – alcançada por um conjunto de testes. Os números de um teste de cobertura podem ser facilmente manipulados, visto que basta invocar alguns métodos nos casos de teste para que a percentagem de cobertura suba. Por esse motivo, a cobertura deve ser, sobretudo, uma métrica usada como ferramenta de revisão de código, na medida em que identifica qual o código que não foi sujeito a testes – e pode usar-se essa informação para repensar o conjunto de testes em si, a estratégia de teste ou o próprio design do sistema. (adaptado de http://avandeursen.com/2013/11/19/test-coverage-not-for-managers/)

O *Tomahawk* não está sujeito a uma quantidade considerável de testes, sendo que os únicos existentes, pelo menos na perspetiva do contribuidor, são três conjuntos de testes unitários: um usado para verificar a consistência da base de dados, outro usado para testar a resistência a erros da busca de músicas e finalmente um para testar a resistência a erros e o correto funcionamento da conversão de um url para música. Tendo em conta o tamanho do projeto, pode-se concluir que os testes existentes acabam por não ter uma cobertura considerável, como um dos maiores contribuidores admitiu, tendo dito também que precisavam desesperadamente de mais testes.

Estes testes – que se encontram no repositório – estão, de acordo com um dos responsáveis pelo projeto, desatualizados. Tal pode apenas ser visto como um sinal que, uma vez desenvolvido o *core* da aplicação, a definição de testes deixou de ser uma prioridade.
De um ponto de vista académico, teria sido interessante apresentar números concretos e analisar a qualidade dos testes a que o código do projeto é sujeito. Todavia, não foi possível obter outros testes usados no projeto, apesar dos inúmeros pedidos dirigidos aos colaboradores do projeto – no sentido de disponibilizarem a *suite* de testes utilizada atualmente no *Tomahawk* ou, em alternativa, o resultado da sua execução. 

####Análise Crítica
De modo geral, parece algo notória a falta de preocupação por parte da equipa do *Tomahawk* com a componente de verificação e validação de software, sendo que tal poderá ficar a dever-se à natureza *open source* do projeto.

Se, por um lado, o projeto se encontra relativamente bem estruturado – existindo um delineamento das funcionalidades que cada componente implementa –, por outro, encontra-se muito pouco documentado, pelo que a tarefa de definir testes é algo complexa e exige algum conhecimento da API – o que, além de dificultar a compreensão do componente a ser testado, torna o projeto menos apelativo a potenciais novos colaboradores.

Dado o número diminuto de testes, pode concluir-se que este projeto necessita de um maior investimento na criação de testes, sendo este um problema que os contribuidores admitem que é uma falha a ser colmatada.
<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/irclog_testing.png?raw=true" alt="IRC chat log.">

Teria sido interessante apresentar e analisar dados concretos relativos aos testes a que o código do projeto é sujeito. Todavia, não foi possível obter esses testes ou os seus resultados. Os únicos testes disponíveis estão desatualizados, facto que comprova que a necessidade de definição de testes.

Mais ainda, a Dashboard – a plataforma usada para gerir *bugs* e anomalias encontrou-se *offline* durante todo o período de elaboração do presente relatório, pelo que o exercício de selecionar um *bug* para corrigir – por forma a ilustrar o processo de verificação do projeto – não pôde ser realizado.

No final, não foi possível, com base nas informações disponíveis, determinar se os processos de verificação e validação aplicados ao projeto *Tomahawk* são adequados.
