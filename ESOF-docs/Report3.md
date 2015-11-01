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

###Vista Lógica
A vista lógica mostra uma abstração de um sistema como um conjunto de classes ou pacotes, bem como as relações entre eles.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/logical.png?raw=true" alt="Logical view.">

O diagrama acima traduz uma interpretação da vista lógica do projeto *Tomahawk*, composta por quatro pacotes:
- O pacote *tomahawk* corresponde às funções essenciais da aplicação – no que respeita à reprodução de conteúdos multimédia.
- O pacote *infoplugins* inclui os vários ‘*resolvers*’ – *plugins* que acedem a serviços *online* de *streaming*, usando as suas *API*’s.
- O pacote *accounts* compreende toda a gestão da componente social da aplicação – nomeadamente, a interação entre os utilizadores, além da gestão de contas de outros serviços *online* de *streaming*.
- O pacote *user interface* corresponde à *GUI* dos vários ambientes – *Linux, Mac* e *Windows*.


###Vista de Implementação
A vista de implementação mostra a decomposição do sistema em componentes e as dependências entre eles.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/implementation.png?raw=true" alt="Implementation view.">

O diagrama acima corresponde a uma interpretação da implementação do projeto *Tomahawk*, tendo sido dividido em seis componentes:
- O componente *tomahawk* corresponde ao núcleo da aplicação, que vai necessitar dos restantes componentes para o seu correto funcionamento;
- O componente *accounts* gere as contas de serviços externos e não só, que o utilizador pode associar à sua aplicação.
- O componente *libtomahawk-playdarapi* permite o uso do serviço *Playdar*, que a partir de metadados de uma musica, procura forma de a reproduzir.
- O componente *infoplugins* inclui os vários ‘*resolvers*’ – *plugins* que acedem a serviços *online* de *streaming*, usando as suas *API*’s.
- O componente *viewpages* gere a informação que é apresentada na interface do *Tomahawk*.
- O componente *libtomahawk* é responsável pela gestão e reprodução de música, gerindo também as playlists do utilizador.


###Vista de Processo
Apresenta-se, de seguida, o diagrama de atividade relativo ao *Tomahawk*, no qual se visa representar o comportamento da aplicação aquando da sua execução. No entanto, dada a grande complexidade da aplicação, o diagrama de atividade elaborado foca-se apenas nos aspectos do funcionamento do *Tomahawk* de maior importância.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/activity_diagram.png?raw=true" alt="Process view.">

Este diagrama representa o funcionamento da aplicação desde o instante em que o utilizador insere os dados sobre a música que deseja encontrar até ao momento em que esta é ou não encontrada nas bases de dados e consequentemente reproduzida. Após esta inserção de dados, ocorre uma coversão destes valores para metadados, para que posteriormente possam ser pesquisados nas bases de dados, o que é feito recorrendo à *API* *Playdar*. Estas bases de dados, escolhidas pelo utilizador, são inquiridas de uma forma sequencial, sendo escolhida para fazer o *stream* da música aquela em que se verificar a primeira correspondência. Caso nenhuma das bases de dados inquiridas possua o ficheiro é mostrada ao utilizador uma mensagem de aviso e o ciclo recomeça, podendo ser pesquisada uma música diferente. Caso contrário, o utilizador pode ainda acrescentar a música a uma das suas *playlists*, para não ter de repetir todo o processo caso a deseje ouvir novamente.

###Vista de Deployment
O seguinte diagrama mostra a vista de *deployment* referente ao projeto.

<img src="https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/resources/deployment.png?raw=true" alt="Deployment view.">

Este diagrama representa os diferentes nós de *hardware* no sistema do projeto *Tomahawk*. O nó *User's Device* corresponde ao *hardware* do utilizador, isto é, o seu computador ou smartphone com a aplicação *Tomahawk*. O nó *1st or 3rd Party Server* representa os servidores ao qual o *Tomahawk* tem acesso através dos *'resolvers'* - os *plugins* instalados pelo utilizador na aplicação principal. Estes servidores podem conter dois artefactos: metadados e ficheiros de áudio, que juntos possiblitam ao utilizador uma reprodução por *streaming* de músicas que o utilizador não tenha no seu dispositivo. Apesar de os servidores em questão serem maioritariamente de outros serviços, existe o serviço dedicado do *Tomahawk*, o *Hatchet*, que adiciona ao *Tomahawk* a já mencionada componente social.


###Conclusões
Conclusão
Importa, primeiramente, salvaguardar que os diagramas apresentados são resultado de uma possível interpretação do projeto.

A vista lógica traduz-se num diagrama de pacotes, mostrando os pacotes divididos de acordo com as funcionalidades que implementam: o núcleo essencial da aplicação, os ‘resolvers’, a componente social e a interface gráfica.

No que respeita à vista de implementação, expressa por um diagrama de componentes, dividiram-se alguns dos pacotes identificados em componentes distintos.

Com a vista de processo ilustra-se o funcionamento da aplicação desde o instante em que o utilizador insere os dados sobre a música que deseja encontrar até ao momento em que esta é ou não encontrada nas bases de dados – e, consequentemente, reproduzida.

O diagrama de componentes - correspondente à vista de *deployment* - representa os diferentes nós de *hardware* no sistema do projeto *Tomahawk*: *User's Device* - o *hardware* do utilizador -, e *1st or 3rd Party Server* - os servidores ao qual o *Tomahawk* tem acesso através dos *'resolvers'*.

Finalmente, considera-se que o projeto apresenta uma estruturação satisfatória, apesar de a tarefa de extração da informação necessária à construção dos diagramas apresentados não ter sido simples.
