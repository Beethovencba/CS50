OBJETIVO: Implementar um app web de compra e venda de ativos. Ao termino do projeto o usuário deve poder se registrar/logar, pesquisar, comprar e vender ações, bem como poder visualizar o histórico de transações além claro de sua carteira de ações.  

    CONTEXTO: o C$ 50 Finance, um aplicativo da web por meio do qual é possível gerenciar carteiras de ações. Essa ferramenta não apenas permitirá que você verifique os preços reais das ações e os valores das carteiras, mas também permitirá que você compre (ok, “compre”) e venda (ok, “venda”) ações consultando o IEX sobre os preços das ações.

    Na verdade, o IEX permite que você baixe cotações de ações por meio de sua API (interface de programação de aplicativo) usando URLs como ***https://cloud.iexapis.com/stable/stock/nflx/quote?token=API_KEY***. Observe como o símbolo da Netflix (NFLX) está embutido neste URL; é assim que a IEX sabe quais dados retornar. Esse link não retornará realmente nenhum dado porque o IEX requer que você use uma chave de API (mais sobre isso daqui a pouco), mas se o fizesse, você veria uma resposta no formato JSON (JavaScript Object Notation).



COFIGURAÇÃO:

Antes de começar esta atribuição, precisaremos nos registrar para obter uma chave de API para poder consultar os dados do IEX. Para fazer isso, siga estas etapas:

- Visite [iexcloud.io/cloud-login#/register/](https://iexcloud.io/cloud-login#/register/).
- Selecione o tipo de conta “Individual”, digite seu endereço de e-mail e uma senha e clique em "Create account”.
- Depois de registrado, role para baixo até “Get started for free” e clique em “Select Start” para escolher o plano gratuito.
- Depois de confirmar sua conta por e-mail de confirmação, visite [https://iexcloud.io/console/tokens](https://iexcloud.io/cloud-login?r=https%3A%2F%2Fiexcloud.io%2Fconsole%2Ftokens#/).
- Copie a chave que aparece na coluna Token (deve começar com  ).
    
    **pk_**
    
- Em uma janela de terminal no **[CS50 IDE](https://ide.cs50.io/)**, execute:

    export API_KEY=value

onde **value** é aquele valor (colado), sem nenhum espaço imediatamente antes ou depois de **=**. Você também deve colar esse valor em um documento de texto em algum lugar, caso precise dele novamente mais tarde.

- Instale os módulos flask e flask_session:

   $ pip install Flask

   $ pip install flask-session
    


- Defina a variável de ambiente FLASK_APP:

   $ export FLASK_APP=application.py


- Instale o módulo cs50:

   $ pip install cs50


EXECUÇÃO:

Inicie o servidor da web integrado do Flask (em finance/ ):

    $ flask run

Visite o URL gerado pelo **flask** para ver o código de distribuição em ação. Porém, você não poderá fazer o login ou registrar-se ainda!

Por meio do navegador de arquivos do CC50, clique duas vezes **finance.db**, a fim de abri-lo com phpLiteAdmin. Observe como **finance.db** vem com uma tabela chamada **users**. Dê uma olhada em sua estrutura (ou seja, schema). Observe como, por padrão, os novos usuários receberão $10.000 em dinheiro. Mas não há (ainda!) Nenhum usuário (ou seja, linhas) nele para navegar.