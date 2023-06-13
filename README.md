# Consumo de Água (MyConsumption.io)

- Para rodar o site é necessário: clonar o repositório no seu computador local;
- Instalar os pacotes npm no seu computador, utilizando o comando `npm i` numa linha de comandos (referenciado no diretório do projeto);
- Rodar o comando `nodemon index.js` para inicializar o site;
- Entrar no endereço `http://localhost:3000/` e acessar o site.


Além disso, é importante ressaltar que NÃO existem dados para a pripriedade 3 (Edificio Pedro).

Existem dados somente para os Edificios Mateus que foram populaods arbitrariamente (dados somente nos dias 15/06 e 16/06), e João (dados somente nos dias 06/06 à 12/06).


# Cronograma

1. Desenvolvimento do Hardware (25/02/2023 - 15/03/2023):
   - Pesquisar e adquirir os componentes eletrônicos necessários.
   - Realizar a montagem e conexão dos componentes no protoboard.
   - Programar o NodeMCU-ESP8266 para realizar a medição do consumo de água e enviar os dados para o broker TagoIO.
   - Realizar testes de comunicação entre o hardware e o broker para garantir a transmissão correta dos dados.

2. Desenvolvimento do Firmware (15/03/2023 - 05/04/2023):
   - Desenvolver o código do firmware para o NodeMCU-ESP8266.
   - Implementar as requisições POST para enviar os dados coletados para o broker TagoIO.
   - Realizar testes unitários para verificar se as requisições estão sendo feitas corretamente e se os dados são armazenados corretamente no broker.

3. Desenvolvimento do Software (05/04/2023 - 25/04/2023):
   - Criar o servidor utilizando Node.js e Express.js.
   - Desenvolver as rotas e os controladores necessários para interagir com o broker TagoIO.
   - Implementar a lógica de consulta e tratamento dos dados do consumo de água.
   - Realizar testes unitários para verificar se os dados são corretamente consultados e tratados no servidor.

4. Desenvolvimento do Front-End (25/04/2023 - 10/05/2023):
   - Criar as páginas do site utilizando HTML, CSS e JavaScript.
   - Implementar a interface de seleção de propriedades, período de dias e tipo de agrupamento.
   - Integrar as chamadas de API para buscar os dados do consumo de água do servidor.
   - Realizar testes de interface para verificar se os dados são corretamente exibidos no site.

5. Testes Integrados (10/05/2023 - 25/05/2023):
   - Realizar testes de integração entre o hardware, firmware, software e front-end.
   - Simular diferentes cenários de consumo de água e verificar se os dados são coletados, transmitidos, armazenados e exibidos corretamente.
   - Registrar e corrigir quaisquer erros ou falhas encontrados durante os testes.


# Testes

1. Hardware (15/03/2023):
   - Os componentes eletrônicos estão corretamente conectados no protoboard.
   - O sensor de fluxo/vazão de água está medindo o consumo com precisão.
   - Os dados coletados estão sendo enviados corretamente para o broker TagoIO.
   - A comunicação entre o hardware e o broker está funcionando adequadamente.

2. Firmware (05/04/2023):
   - As requisições POST para enviar os dados coletados estão sendo feitas com sucesso.
   - Os dados coletados são armazenados corretamente no broker TagoIO.
   - As requisições de consulta dos dados no broker estão retornando os resultados esperados.
   - Os dados são tratados corretamente no servidor e estão prontos para serem inseridos no banco de dados.

3. Software(25/04/2023):
   - O servidor desenvolvido em Node.js e Express.js está funcionando corretamente.
   - As rotas e controladores estão interagindo corretamente com o broker TagoIO.
   - As consultas dos dados do consumo de água estão retornando os resultados corretos.
   - Os dados são corretamente tratados no servidor antes de serem disponibilizados para o front-end.

4. Front-End (10/05/2023):
   - As páginas do site são exibidas corretamente e possuem um layout adequado.
   - A interface de seleção de propriedades, período de dias e tipo de agrupamento está funcionando corretamente.
   - As chamadas de API para buscar os dados do consumo de água estão retornando os resultados esperados.
   - Os dados de consumo de água são exibidos corretamente no site, de acordo com as seleções do usuário.

5. Testes Integrados(25/05/2023):
   - O fluxo de dados entre o hardware, firmware, software e front-end está ocorrendo sem problemas.
   - Os diferentes cenários de consumo de água são simulados com sucesso e os dados são coletados, transmitidos, armazenados e exibidos corretamente.
