<h1>Estrutura de Dados III - Trabalho 3</h1>

<div align="justify" >
<p>Foi implementado um programa por meio do qual o usuário possa obter
dados de um arquivo binário de entrada, gerar um grafo não direcionado ponderado a
partir deste e realizar investigações interessantes dentro do contexto de topologia de
rede da Internet.</p>

<p>O programa oferece as seguintes funcionalidades:</p>
<li>11) Permite a recuperação dos dados, de todos os registros, armazenados em um
arquivo de dados no formato binário e a geração de um grafo contendo esses dados na
forma de um conjunto de vértices V e um conjunto de arestas A. A representação do grafo é na forma de listas de adjacências. As listas
de adjacências consistem tradicionalmente em um vetor de |V| elementos que são
capazes de apontar, cada um, para uma lista linear, de forma que o i-ésimo elemento
do vetor aponta para a lista linear de arestas que são adjacentes ao vértice i.</br>Cada elemento do vetor representa um idConecta. Os vértices do vetor
devem ser ordenados de forma crescente de acordo com o valor de idConecta. Se dois
ou mais PoPs têm o mesmo valor de idConecta, eles são considerados o mesmo PoPs.
Além do idConecta, cada elemento do vetor armazena também os seguintes
campos correspondentes: (i) nomePoPs; (ii) nomePais; (iii) siglaPais.</br>Cada elemento da lista linear representa uma aresta entre dois PoPs. Ou seja,
cada elemento da lista linear representa uma aresta entre idConecta e
idPoPsConectado. A aresta armazena a velocidade em Gbps. Velocidades
indicadas em Mbps são transformadas em Gbps. Considere que 1 Mbps =
0.0009765625 Gbps e que 1 Gbps = 1024 Mbps. Os elementos de cada lista linear
são ordenados de forma crescente de acordo com idPoPsConectado.
</br></br>
<li>12) Essa funcionalidade determina quantos ciclos simples existem no grafo. Um ciclo simples é um ciclo em que nenhum
vértice se repete, com exceção do primeiro e do último (ou seja, o primeiro vértice,
chamado de vértice de origem, é o mesmo que o último vértice, chamado de vértice de
destino).
</br></br>
<li>13) Essa funcionalidade determina qual o fluxo máximo entre dois PoPs. Essa funcionalidade pode
ser executada n vezes seguidas. 
</br></br>
<li>14) Essa funcionalidade determina o comprimento do caminho mínimo
entre dois PoPs, sendo que existe a necessidade de se passar por um terceiro PoPs. Essa funcionalidade pode 
ser executada n vezes seguidas. Nesta funcionalidade, entenda que caminho mínimo se refere à menor soma de velocidades disponíveis. 
</br></br>
<p>Para compilar os códigos, use o comando <code>make all</code>.</p>
<p>Para executar o programa, use o comando <code>make run</code>.</p>
<p>Para testar o programa, pode-se usar o arquivo <strong>topologiaRedeT3.csv</strong>.</p>
