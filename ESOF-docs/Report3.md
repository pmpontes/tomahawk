<img src="https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcQ5v37xur40kL994HczH-li9mzyHP47jhvORpy-vNoHzatPjm11gSvwLVU" alt="FEUP">
####**Engenharia de Software 2015/2016**
#####MIEIC - 3ºAno

###Grupo:
- Gil Manuel Oliveira de Almeida Domingues, **gil.domingues@fe.up.pt** 
- Pedro Martins Pontes, **pontes.pedro@fe.up.pt**
- Pedro Miguel Pereira de Melo, **up201305618@fe.up.pt**

##Aquitetura de *Software*
Como qualquer outro sistema complexo, o software deve ser construído numa base sólida. Não considerar certos cenários, não acautelar problemas comuns ou não ter em conta as consequências a longo prazo de decisões importantes pode pôr um projeto em risco. Atualmente, existem plataformas que simplificam a tarefa de construir aplicações, mas não eliminam a necessidade de desenhar a aplicação cuidadosamente, com base em cenários e requisitos específicos. 

Arquiteturas mal concebidas podem conduzir a instabilidade, incapacidade de suportar requisitos – presentes ou futuros –, e dificuldade em aplicar ou gerir o ambiente de produção. É aqui que entra a arquitetura de software – organização fundamental de um sistema, formado pelos seus componentes, as relações entre eles e os princípios que moldam o seu design e evolução. Arquitetura de software envolve, ainda, funcionalidade, usabilidade, resiliência, performance, reutilização, restrições económicas e tecnológicas, compromissos e preocupações estéticas (*Shaw et Garlan*, 1996).

##Vista Lógica
A vista lógica mostra uma abstração de um sistema como um conjunto de classes ou pacotes, bem como as relações entre eles. 

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/logical.png?raw=true" alt="Logical view.">

O diagrama acima traduz uma interpretação da vista lógica do projeto *Tomahawk*, composta por quatro pacotes:
- O pacote *tomahawk* corresponde às funções essenciais da aplicação – no que respeita à reprodução de conteúdos multimédia.
- O pacote *infoplugins* inclui os vários ‘*resolvers*’ – *plugins* que acedem a serviços *online* de *streaming*, usando as suas *API*’s.
- O pacote *accounts* compreende toda a gestão da componente social da aplicação – nomeadamente, a interação entre os utilizadores.
- O pacote *user interface* corresponde à *GUI* dos vários ambientes – *Linux, Mac* e *Windows*.


##Vista de Implementação
A vista de implementação mostra a decomposição do sistema em componentes e as dependências entre eles. 

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/implementation.png?raw=true" alt="Implementation view.">

Diagrama de componentes com a vista de implementação referente ao projeto. 
(considerações sobre a vista)

##Vista de Processo
Apresenta-se, de seguida, o diagrama de atividade relativo ao *Tomahawk*, no qual se visa representar o comportamento da aplicação aquando da sua execução. No entanto, dada a grande complexidade da aplicação, o diagrama de atividade elaborado foca-se apenas nos aspectos do funcionamento do *Tomahawk* de maior realce.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/activity_diagram.png?raw=true" alt="Process view.">

Este diagrama representa o funcionamento da aplicação desde o instante em que o utilizador insere os dados sobre a música que deseja encontrar até ao momento em que esta é ou não encontrada nas bases de dados e consequentemente reproduzida. Após esta inserção de dados, ocorre uma coversão destes valores para metadados, para que posteriormente possam ser pesquisados nas bases de dados, o que é feito recorrendo à API *Playar*. Estas bases de dados, escolhidas pelo utilizador, são inquiridas de uma forma sequencial, sendo escolhida para fazer o *stream* da música aquela em que se verificar a primeira correspondência. Caso nenhuma das bases de dados inquiridas possua o ficheiro é mostrada ao utilizador uma mensagem de aviso e o ciclo recomeça, podendo ser pesquisada uma música diferente. Caso contrário, o utilizador pode ainda acrescentar a música a uma das suas *playlists*, para não ter de repetir todo o processo caso a deseje ouvir novamente. 

##Vista de Deployment
O seguinte diagrama mostra a vista de *deployment* referente ao projeto.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/deployment.png?raw=true" alt="Deployment view.">

(considerações sobre a vista)
