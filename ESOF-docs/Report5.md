<img src="https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcQ5v37xur40kL994HczH-li9mzyHP47jhvORpy-vNoHzatPjm11gSvwLVU" alt="FEUP">
####**Engenharia de Software 2015/2016**
#####MIEIC - 3ºAno

###Grupo:
- Gil Manuel Oliveira de Almeida Domingues, **gil.domingues@fe.up.pt**
- Pedro Martins Pontes, **pontes.pedro@fe.up.pt**
- Pedro Miguel Pereira de Melo, **up201305618@fe.up.pt**

###Evolução de *Software*
Evoluir *sofware* é uma necessidade, seja para contemplar novas funcionalidades, novos requisitos ou simplesmente para melhorar o seu desempenho ou fiabilidade.
Nesta fase final, procedeu-se à identificação e posterior implementação de uma nova funcionalidade para o *Tomahawk*.


####A *feature*
Como referido anteriormente, o *Tomahawk* tem uma [página](https://tomahawk.uservoice.com/) através da qual os utilizadores podem apresentar sugestões de funcionalidades. Após cuidada análise,  optou-se por evoluir uma funcionalidade que aparentava, por um lado, ser simples e, por outro, de alguma utilidade. 
Assim, a escolha recaiu sobre um [pedido](https://tomahawk.uservoice.com/forums/224204-feature-requests/suggestions/9735033-shut-down-the-player-when-you-press-the-close-butt) de um utilizador no sentido de disponibilizar uma opção que permitisse terminar a aplicação quando se fecha a sua janela, em vez de ficar a correr em *background*.


####Componentes que implementam a *feature*
Apesar de se  tratar uma funcionalidade de relativa simplicidade e de a única componente lógica envolvida ser a interface de utilizador, constatou-se que :


####Submissão de patch
Após a implementação da nova funcionalidade, foi feito um [*pull request*](), com vista à sua integração no projeto.


####Análise Crítica
Apesar de a funcionalidade selecionada aparentar ter um nível de complexidade relativamente reduzido, considera-se que essa dificuldade foi acentuada pela parca organização do código do projeto. A isso somou-se o facto de a página do projeto - com a documentação e instruções de *build* - se ter encontrado *offline* durante grande parte do tempo disponível para a conclusão desta tarefa.

Como foi dito [anteriormente](https://github.com/pmpontes/tomahawk/blob/master/ESOF-docs/Report4.md), a diminuta documentação do código é um fator que torna difícil a tarefa daqueles que pretendem colaborar com o projeto, pois torna necessário algum conhecimento da estrutura do projeto para que haja produtividade.

Tratando-se de um projeto *open-source* e estando disponível em diferentes plataformas, qualquer um pode, dentro das competências, contribuir para o desenvolvimento do *Tomahwak*.

