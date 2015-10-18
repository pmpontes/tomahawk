<img src="https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcQ5v37xur40kL994HczH-li9mzyHP47jhvORpy-vNoHzatPjm11gSvwLVU" alt="FEUP">
####**Engenharia de Software 2015/2016**
#####MIEIC - 3ºAno

###Grupo:
- Gil Manuel Oliveira de Almeida Domingues, **gil.domingues@fe.up.pt** 
- Pedro Martins Pontes, **pontes.pedro@fe.up.pt**
- Pedro Miguel Pereira de Melo, **up201305618@fe.up.pt**

##Tomahawk - Engenharia de requisitos e casos de utilização

###Levantamento de Requisitos
Em qualquer setor de atividade, a comunicação entre cliente e prestadores de serviços é fundamental para garantir que o produto final corresponde às expectativas do cliente. No contexto da engenharia de *software*, o levantamento e a análise de requisitos são, pois, etapas incontornáveis na concretização dessa comunicação, permitindo que todos os envolvidos saibam com exatidão o que é esperado do produto a ser desenvolvido, sendo estes os princípios da engenharia de requisitos.

Desde logo, o *Tomahawk* pressupõe, enquanto conceito, facilidade de utilização – através da simplicidade da gestão dos conteúdos áudio de vários serviços distintos – a acessibilidade a partir de diversas plataformas e a integração de uma componente social.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/use_cases.png?raw=true" alt="Diagrama de casos de utilização.">
 
Dado o caráter *open-source* do *Tomahawk*, o papel de *stakeholders* cabe aos utilizadores, que, reportando *bugs* e propondo novas funcionalidades, contribuem para o crescimento e evolução do projeto.

Existem dois ambientes que permitem a interação entre a equipa do *Tomahawk* e os seus utilizadores: o *Feedback Loop* e a Dashboard – pontes entre os *developers* e o público, através das quais se podem tirar dúvidas, submeter *bugs* para posterior análise e correção e ainda deixar ideias para novas funcionalidades. 
Para aceder à *Dashboard* é necessário efetuar o registo em https://bugs.tomahawk-player.org/secure/Signup!default.jspa.

###Contribuir para o projeto

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/issues.png?raw=true" alt="Issues da Dashboard.">
 
Na *Dashboard* do projeto podemos encontrar uma lista de *issues* – que podem dizer respeito a um *bug* – normal ou *epic* –, uma melhoria ou uma nova funcionalidade.

####Bugs
É pedido ao utilizador, sempre que pretenda reportar um *bug*, uma pequena descrição do problema – por modo a facilitar a sua resolução – devendo avaliar a sua gravidade e atribuir-lhe uma prioridade:

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/bug_types.png?raw=true" alt="Bugs e prioridades.">
 
####Novas funcionalidades
Ideais e sugestões para novas funcionalidades podem ser partilhadas através do *Feedback Loop* ou discutidas na *Dashboard* entre utilizadores e *developers*. Antes de fazer qualquer pedido, é conveniente verificar se essa funcionalidade não foi já solicitada.

###Análise de Requisitos
Como visto, a atenção que as questões levantadas merecem por parte dos responsáveis pelo projeto *Tomahawk* – tempo e recursos – depende da prioridade que lhes foi atribuída, mas também do julgamento que fazem da questão.

Para que uma ideia seja posta em prática ou um *bug* corrigido é necessário que pelo um dos desenvolvedores se debruce sobre a questão, ou que a outra pessoa tome a iniciativa de o fazer, devendo, para isso, recorrer à *Agile Board*.

A comunicação entre os desenvolvedores e os responsáveis pelo projeto é feita através da *Dashboard*, e da *Agile Board*, auxiliando a tomada de decisões.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/dashboard.PNG?raw=true" alt="Dashboard.">

###Validação de requisitos
O processo de validação de requisitos é crucial na Engenharia de Requisitos, consistindo numa avaliação dos requisitos definidos para o projeto, por forma a verificar se os mesmos se enquadram na filosofia do mesmo. Esta avaliação visa diminuir o risco de serem encontradas incoerências nos requisitos em fases avançadas do desenvolvimento do projeto, o que por sua vez pode levar a um maior gasto de tempo e a um maior consumo de recursos. 

Tipicamente, no contexto empresarial, a execução da validação de requisitos recai sobre o cliente. No entanto, no caso do *Tomahawk*, a equipa responsável pelo projeto é que decide quais as novas funcionalidades a serem integradas; o que pode ser explicado recorrendo uma vez mais ao caráter *open-source* do projeto.

Para facilitar a adição destas novas funcionalidades, foi colocada pela equipa de *developers* uma bateria de testes na pasta do projeto, com o intuito de poderem testar o código à medida que este é desenvolvido.

Após terminadas, todas as contribuições são submetidas para um dos *masters* para que possam ser novamente testadas, embora de uma forma mais intensiva. Caso os resultados obtidos nesta segunda fase de testes sejam favoráveis, é feito *merge* no *branch master* e as contribuições são incorporadas no projeto.

###Conclusões
O processo de recolha, análise e negociação de requisitos no desenvolvimento do Tomahawk apresenta uma dinâmica distinta da estudada para este processo.

A equipa do *Tomahawk* utiliza um processo de desenvolvimento "progressivo", onde o reconhecimento prévio de todos os requisitos do projeto é impossivel, dado que a criação de funcionalidades e a deteção de erros conduzem a uma constante e ciclica definição de novos requisitos, que devem por sua vez ser analisados, validados ou rejeitados, levando novamente à criação de novas funcionalidades.

Ao contrário do que acontece tipicamente no mundo empresarial, a equipa responsável pelo desenvolvimento do *Tomahawk* é que decide se um dado requisito proposto por um utilizador, que pode também assumir um papel de colaborador, é relevante; tendo criado um conjunto de critérios necessários à validação de novos requisitos. Um destes critérios, por exemplo, é a aprovação incondicional em testes automatizados sobre o código submetido em *pull requests*. 

Assim, e apesar das diferenças mencionadas face ao modelo teórico, pode afirmar-se que o desenvolvimento do projeto *Tomahawk* segue metodologias bem definidas para a gestão dos seus requisitos.
