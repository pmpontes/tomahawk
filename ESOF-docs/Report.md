<img src="https://encrypted-tbn2.gstatic.com/images?q=tbn:ANd9GcQ5v37xur40kL994HczH-li9mzyHP47jhvORpy-vNoHzatPjm11gSvwLVU" alt="FEUP">
####**Engenharia de Software 2015/2016**
#####MIEIC - 3ºAno

###Grupo:
- Gil Manuel Oliveira de Almeida Domingues, **up201304646@fe.up.pt** 
- Pedro Martins Pontes, **up201305367@fe.up.pt**
- Pedro Miguel Pereira de Melo, **up201305618@fe.up.pt**

<img src="https://avatars0.githubusercontent.com/u/440844?v=3&s=200" align="left" width="50">
##  O projeto *Tomahawk*

###Conceito

O *Tomahawk* é um reprodutor de mídia gratuito, *open-source* e *multi-plataforma*, que agrega todos os aspetos dos reprodutores de mídia "tradicionais" mas que visa responder também às necessidades da cultura *on demand* contemporânea. Deste modo, é capaz de procurar/reproduzir ficheiros de mídia a partir de bibliotecas locais ao utilizador bem como de vários servidores *online*, entre os quais o *Spotify* ou o *Youtube*. 
O *Tomahawk* permite que os utilizadores armazenem os seus ficheiros de media em *clouds*, disponibilizanda ainda uma interface que permite a comunicação entre os vários utilizadores da aplicação. 

###Funcionamento

O *Tomahawk*, à semelhança de muitos outros reprodutores de mídia, permite a leitura, partilha e gestão de diferentes tipos de ficheiros de mídia. Contudo, o *Tomahawk* diferencia-se por funcionar com base em *metadados*, ou seja, sempre que se pretende reproduzir um ficheiro de mídia, a aplicação processa em primeira instância algumas informações relativas ao ficheiro, tais como o seu nome, o nome do seu artista ou do possível álbum a que pertença. Só após o processamento destes dados é que a pesquisa ao ficheiro, entre os conteúdos disponíveis, é realizada sendo seleccionada a opção mais adequada. O mesmo acontece aquando da partilha de ficheiros entre utilizadores, onde ocorre uma transferência de *metadados* em vez de ficheiros.

A componente social da aplicação é implementada simulando um cliente de *streaming P2P*, permitindo aos utilizadores reproduzir ficheiros de mídia a partir dos computadores de amigos. Assim, a *playlist* de um utilizador pode conter ficheiros armazenados no seu próprio computador, no computador de um amigo, nos servidores do *YouTube* e até do *Spotify*.

O *Tomahawk* consegue reproduzir músicas guardadas em bibliotecas locais, à semelhança do iTunes e Spotify. A novidade é a instalação de "*revolvers*" – *plugins* que encontram músicas para reproduzir a partir de vários serviços de *streaming*, usando APIs disponibilizadas por estes serviços.

###Processo de Desenvolvimento
Desenvolver um sistema de *software* é, na sua essência, traduzir num produto de *software* uma ideia, um conceito, uma necessidade. Existem vários processos de desenvolvimento de *software* distintos, mas fases como especificação, *design*, implementação e validação são transversais a todos eles e todos eles têm como objetivo último a eficiência. O que os distingue são fatores como a forma como essas etapas se sequenciam, o tipo e frequência de entregas e a capacidade de lidar com mudanças, incertezas e riscos.

Não tendo obtido dos colaboradores uma resposta, em tempo útil, acerca de qual o processo de desenvolvimento adotado, cingimo-nos a uma análise do historial de *commits* do projeto, que sugere um modelo de desenvolvimento e entrega incrementais. O que tem o seu sentido: depois de desenvolvido o *core* da aplicação, vão sendo criados vários *branches*, ora com o propósito de corrigir um bug ora para introduzir uma nova funcionalidade. 

No caso, esta abordagem de desenvolvimento incremental da aplicação tem como principal vantagem permitir receber um maior *feedback* por parte dos utilizadores e progredir com base nessa informação. Baseando-se nessa interação, os *developers* podem dar prioridade à resolução dos *bugs* mais mencionados – sem ter de perder tempo a procurá-los –, e à implementação das funcionalidades mais requisitadas – evitando o risco de desenvolver funcionalidades que não correspondem ao que os utilizadores procuram.

Por outro lado, esta aproximação pode conduzir a uma degradação da estrutura do projeto, tornando a adição de novas funcionalidades cada vez mais complicada, se não se investir algum tempo em *refactoring*. Adicionalmente, a política de branching utilizada pode conduzir à introdução de código duplicado a cada funcionalidade adicionada, reforçando a necessidade de *refactoring*.

Dito isto, e dada a natureza do projeto, consideramos o processo de desenvolvimento incremental bastante adequado porque, não existindo um processo de desenvolvimento perfeito, esta abordagem facilita o trabalho colaborativo sem com isso comprometer a evolução da aplicação.


###Atividades
######21-09-2015:
- Seleção do projeto;

######28-09-2015:
- Configuração do Github;
- Primeiro contacto com o projeto Tomahawk, após fork; 
- Pedido de esclarecimento sobre os processos de desenvolvimento aos colaboradores do projeto;





