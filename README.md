# Sistema de Marcação de Consultas

_O sistema tem como finalidade marcar consultas em um consultório de atendimento odontológico. Teremos dois especialistas: o Dr. Arthur Filgueiras Assunção e a Dra. Danielle Vasconcelos Mello. O usuário irá informar seus dados e poderá visualizar o calendário com os dias e horários disponíveis para o atendimento de cada dentista e efetuar a marcação, além disso, será capaz de visualizar as suas consultas que já foram marcadas. Caso não possa comparecer poderá desmarcar o atendimento._

### Requisitos do Sistema 

1. Colher dados de identificação do usuário tais como: nome completo, CPF e data de nascimento.

![sistema 1](https://user-images.githubusercontent.com/70827699/125008509-05343f80-e039-11eb-9043-4655a6c0e743.png)

2. Selecionar um dos dentistas já cadastrados: Arthur Filgueiras Assunção ou Danielle Vasconcelos Mello.

![sistema 2](https://user-images.githubusercontent.com/70827699/125008597-2d23a300-e039-11eb-945a-9bbf1e8b15bc.png)

3. Mostrar menu com as seguintes informações:

MENU

1 - Marcar consulta

2 - Visualizar consultas marcadas

3 - Desmarcar consulta

4 - Finalizar o atendimento

![sistema 3](https://user-images.githubusercontent.com/70827699/125008656-56443380-e039-11eb-8631-1660964fa522.png)

4. Ao selecionar a opção 1, deverá ser mostrado na tela um calendário e selecionar uma data:
#### Junho/2020 ####                
 D | S | T | Q | Q | S | S 
:---: | :---: | :---: | :--: | :---: | :---: | :---:
 | | |1|2|3|4|5
 6|7|8|9|10|11|12
 13|14|15|16|17|18|19
 21|22|23|24|25|26|27
 28|29|30
  
![sistema 4](https://user-images.githubusercontent.com/70827699/125009094-3bbe8a00-e03a-11eb-81bf-c76eeb811663.png)

5. Após selecionar uma data, será necessário selecionar um horário disponível (ao exemplo abaixo, foi selecionado o dia 15):

 DIA | 1-08:00 | 2-09:00 | 3-10:00 | 4-11:00 | 5-13:00 | 6-14:00 | 7-15:00 | 8-16:00 
:---: | :---: | :---: | :--: | :---: | :---: | :---: | :---: | :---:
15| X | X | | X | X | | X | X

![sistema 5](https://user-images.githubusercontent.com/70827699/125010205-72959f80-e03c-11eb-9b35-52e1ac89e204.png)

6. Após selecionar o horário deverá apresentar a seguinte mensagem:
_“Prezado paciente nomePaciente sua consulta foi marcada com sucesso, no diaMarcado às horarioMarcado com o Dr(a) nomeDentista.”. 
O sistema deverá perguntar ao usuário se deseja “Voltar ao menu"  ou “Finalizar o atendimento”._

![sistema 6](https://user-images.githubusercontent.com/70827699/125010370-c1dbd000-e03c-11eb-99e4-b1afd7af148d.png)

7. Ao selecionar a opção 2, deverá aparecer na tela as consultas marcadas:
#### Consultas Marcadas ####                
 Paciente | Dentista | Dia | Horario 
:---: | :---: | :---: | :--: 
 Ircaro Thiago Souza Seixas | Arthur Filgueiras Assuncao | 15 | 10hrs
 
![sistema 7](https://user-images.githubusercontent.com/70827699/125010650-4fb7bb00-e03d-11eb-97c7-8fc0b12dbcf0.png)

O sistema deverá perguntar ao usuário se deseja “Voltar ao menu” ou “Finalizar o atendimento”.

8. Ao selecionar a opção 3, deverá escolher a consulta que deseja desmarcar.
 
	1 - Arthur Filgueiras Assunção - 15/06 - 11hrs
	
	2 - Arthur Filgueiras Assunção - 17/06 - 16hrs

![sistema 8](https://user-images.githubusercontent.com/70827699/125010728-7e359600-e03d-11eb-80ec-eeca06e4d211.png)

Após selecionar a opção no qual deseja desmarcar a consulta, irá aparecer a mensagem de que a consulta foi desmarcada, deixando o horário disponível novamente. O sistema deverá perguntar ao usuário se ele deseja “Voltar ao menu” ou “Finalizar o atendimento”.

![sistema 9](https://user-images.githubusercontent.com/70827699/125010833-ad4c0780-e03d-11eb-86cc-c7a2161c0b50.png)

9. Ao selecionar a opção 4 o sistema deverá ser encerrado.

![sistema 10](https://user-images.githubusercontent.com/70827699/125010901-d1a7e400-e03d-11eb-9e53-41c322069661.png)


  
  
  
