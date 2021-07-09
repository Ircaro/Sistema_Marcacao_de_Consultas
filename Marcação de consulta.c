#include <stdio.h> // Biblioteca padrão
#include <stdlib.h> // Biblioteca padrão
#include <stdbool.h> // Biblioteca booleano 
#include <locale.h> // Biblioteca para Língua Portuguesa 
#include <string.h> // Biblioteca para receber string
//Autores:  Adriele Figueredo  e  Írcaro Thiago

//Variáveis globais
int m, n, k; // Variáveis usadas no for
int dataConsulta, voltarMenu, selecaoHorarioMenu, horaMarcada, opcaoHora, marcacoes = 0, desmarcarData; //Variáveis usadas nos procedimentos 
char calendarioDiasSemana[7] = {'D', 'S', 'T', 'Q', 'Q', 'S', 'S'}; //Vetor de dias da semana 
char nomePaciente[60], nomeDentista[60]; //Variáveis usadas no main
int  calendarioDias[5][7] = {0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 0, 0, 0}; //Matriz dias do mês de junho
int descricaoHorarios[8] = {8, 9, 10, 11, 13, 14, 15, 16}; //Vetor dos horários 
bool fimDeSemana = false, selecaoMenu = true, selecaoMenuHorario = true, diaNaoDisponivel = true; //Variáveis booleanas
char topoHorarios[9] = {'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};//Vetor topo dos horários
int horarios[30][9] = { //Matriz dos dias e horários
1, 0, 1, 0, 1, 0, 1, 0, 1, 
2, 1, 0, 0, 0, 1, 0, 0, 1,
3, 0, 1, 1, 0, 1, 0, 1, 1,
4, 0, 1, 0, 1, 0, 0, 1, 0,
5, 0, 0, 0, 0, 0, 0, 0, 0,
6, 0, 0, 0, 0, 0, 0, 0, 0,
7, 1, 0, 1, 0, 1, 0, 0, 1,
8, 0, 1, 0, 1, 1, 0, 1, 1,
9, 1, 0, 0, 1, 0, 0, 1, 1,
10, 1, 0, 0, 0, 0, 0, 1, 0,
11, 1, 0, 0, 1, 0, 0, 0, 0,
12, 0, 0, 0, 0, 0, 0, 0, 0,
13, 0, 0, 0, 0, 0, 0, 0, 0,
14, 1, 0, 1, 0, 0, 0, 0, 1,
15, 1, 1, 0, 1, 1, 0, 1, 1,
16, 0, 0, 0, 0, 0, 0, 0, 1,
17, 0, 1, 0, 0, 0, 1, 0, 0,
18, 0, 0, 1, 0, 0, 1, 0, 1,
19, 0, 0, 0, 0, 0, 0, 0, 0,
20, 0, 0, 0, 0, 0, 0, 0, 0,
21, 1, 0, 0, 1, 0, 0, 0, 1,
22, 1, 1, 0, 0, 0, 1, 0, 0,
23, 0, 1, 0, 1, 0, 0, 0, 1,
24, 1, 0, 0, 0, 0, 0, 0, 1,
25, 0, 1, 0, 0, 0, 1, 0, 1,
26, 0, 0, 0, 0, 0, 0, 0, 0,
27, 0, 0, 0, 0, 0, 0, 0, 0,
28, 0, 0, 0, 1, 1, 0, 0, 0,
29, 1, 0, 0, 0, 1, 0, 0, 1,
30, 0, 1, 1, 1, 0, 1, 1, 0};
char topoVisualizacao[4] = {'a', 'b', 'c', 'd'};//Vetor de visualização de consultas marcadas 

void selecaoHorario(){//Procedimentos para selecionar o horário no Menu de horários em marcarConsulta()
	setlocale(LC_ALL, "Portuguese");
	system("cls");
	printf("Prezado(a) %s, sua consulta foi marcada com sucesso no dia %2.2d às %2.2dhrs com o(a) Dr.(a) %s.\n", nomePaciente, dataConsulta, horaMarcada, nomeDentista);
	selecaoMenuHorario = false;	
}

void marcarConsulta(){ //Procedimentos para marcação de consulta
	setlocale(LC_ALL, "Portuguese");
	selecaoMenuHorario = true;
	
	system("cls");
	printf("############# MARCAÇÃO DE CONSULTA ############## \n \n");
	
	printf("|               ### JUNHO/2021 ###               | \n"); //Matriz para a visualização da agenda do mês de junho
	printf("|");
	
		for(m=0; m<7; m++){ //Laço de repetição para mostar os elementos do Vetor 
			printf(" %2.c   |", calendarioDiasSemana[m]);
		}
	
	printf("\n");
	
	for(m=0; m<5; m++){ //Laço de repetição para mostar os elementos da Matriz
		printf("|");
		for(n=0; n<7; n++){
			if (calendarioDias[m][n] == 0) {
				printf("      |");
			} else {
				printf("  %2.2d  |",  calendarioDias[m][n]);
			}
		}
		printf("\n");
	}
	
	printf("\n");
	printf("Selecione uma data na qual deseja marcar a sua consulta: ");
	scanf("%d", &dataConsulta);
	fimDeSemana = false; 
	printf("\n");
	
	while(fimDeSemana == false){ //Verificar se a data escolhida é maior que 30 ou se é um final de semana 
		fimDeSemana = true;
			if(dataConsulta > 30){ //Verificar se a data escolhida é maior do que 30, nesse caso o fimDeSemana se torna falso repetindo a verificação 
				printf("Data inválida, por gentileza tente novamente: ");
				scanf("%d", &dataConsulta);
				printf("\n");
				fimDeSemana = false;
			} else {
				for (m = 0; m < 5; m++) { //Verificar se a data escolhida está nas colunas 0 e 6, domingo e sábado respectivamente, nesse caso o fimDeSemana se torna falso repetindo a verificação 
					if (dataConsulta == calendarioDias[m][0] || dataConsulta == calendarioDias[m][6]){ 
						fimDeSemana = false;
							if(fimDeSemana == false){
								printf("A data escolhida precisa ser em um dia útil, por gentileza tente novamente: ");
								scanf("%d", &dataConsulta);
								printf("\n");
							} 
						break;
					}
				}
			}
	}
	
	system("cls");
	
	printf("Você selecionou a data: %2.2d \n \n", dataConsulta);//Caso não entre em nenhuma condição acima mostrará a data selecionada
	printf("Selecione um horário (Caso não tenha um horário disponível, selecione a opção 9 - CANCELAR): \n \n");
	printf("|");
	for (m=0; m<9; m++) { //Mostrar um vetor do topo dos horários
		if (topoHorarios[m] == 'z') { //Substituindo as letras pelo conteúdo do printf
			printf("        |");
		}
		if (topoHorarios[m] == 'a') {
			printf("1 - 08h |");
		}
		if (topoHorarios[m] == 'b') {
			printf("2 - 09h |");
		}
		if (topoHorarios[m] == 'c') {
			printf("3 - 10h |");
		}
		if (topoHorarios[m] == 'd') {
			printf("4 - 11h |");
		}
		if (topoHorarios[m] == 'e') {
			printf("5 - 13h |");
		}
		if (topoHorarios[m] == 'f') {
			printf("6 - 14h |");
		}
		if (topoHorarios[m] == 'g') {
			printf("7 - 15h |");
		}
		if (topoHorarios[m] == 'h') {
			printf("8 - 16h |");
		}
	}
	
	printf("\n");
	
	printf("|");
	for (m=0; m<30; m++){ //Laço de repetição para mostrar a data selecionada 
		for(n=0; n<9; n++){
			if (dataConsulta == horarios[m][0]){
				printf("   %2.2d   |", horarios[m][0]);
				break;
			}	
		}
	}
	
	for (k=0; k<8; k++) { //Laço de repetição para mostrar os horários disponíveis
			if(horarios[dataConsulta-1][k+1] == 1 || horarios[dataConsulta-1][k+1] == 2) {
				printf("   X    |"); //Substituir o 1 ou 2 pelo conteudo do printf 
			} else if (horarios[dataConsulta-1][k+1] == 0){
				printf("        |"); //Substituir o 0 pelo conteudo do printf 
			}
	}
	
	printf("\n");
	
	while(selecaoMenuHorario == true){ //Mostrar as opções para o paciente selecionar 
		
		printf("\nSelecione uma opção de horário disponível: \n");
		printf("1 - 08h \n");
		printf("2 - 09h \n");
		printf("3 - 10h \n");
		printf("4 - 11h \n");
		printf("5 - 13h \n");
		printf("6 - 14h \n");
		printf("7 - 15h \n");
		printf("8 - 16h \n");
		printf("9 - CANCELAR \n");
		printf("O horário selecionado será: ");
		scanf("%d", &selecaoHorarioMenu);
		
		while (horarios[dataConsulta-1][selecaoHorarioMenu] == 1 || horarios[dataConsulta-1][selecaoHorarioMenu] == 2){//Verificar se a opção selecionada é válida 
			printf("\n");
			printf("Esse horário não está disponível, por gentileza verifique se há outro horário disponível e selecione novamente: ");
			scanf("%d", &selecaoHorarioMenu);
		}
		
		horaMarcada = descricaoHorarios[selecaoHorarioMenu - 1]; //Armazenar o horário selecionado na variável
		
		switch(selecaoHorarioMenu){ //Imprimir a mensagem de que a consulta foi marcada com sucesso
			
			case 1:
				selecaoHorario(); 
			break;
			
			case 2:
				selecaoHorario();					
			break;
				
			case 3:
				selecaoHorario();					
			break;
			
			case 4:
				selecaoHorario();					
			break;
			
			case 5:
				selecaoHorario();					
			break;
				
			case 6:
				selecaoHorario();					
			break;
			
			case 7:
				selecaoHorario();				
			break;
			
			case 8:
				selecaoHorario();					
			break;
			
			case 9:
				selecaoMenuHorario = false;					
			break;
			
			default:
				printf("Opção inválida! Tente novamente. \n");				
			break;
		}	
	}
	
	horarios[dataConsulta-1][selecaoHorarioMenu] = 2; //Armazenar o horário e a data selecionados pelo paciente na matriz horários 

//Menu final							
	printf("\nO que deseja fazer agora? \n");
	printf("1 - Voltar ao Menu \n");
	printf("2 - Finalizar o atendimento \n");
	scanf("%d", &voltarMenu); 
	
	while(voltarMenu != 1 && voltarMenu != 2){ //Verificar se a opção é válida 
		system("cls");
		printf("Você nao selecionou um número válido, por gentileza tente novamente \n \n");
		printf("1 - Voltar ao Menu \n");
		printf("2 - Finalizar o atendimento \n");
		scanf("%d", &voltarMenu);		
	}
		
	if(voltarMenu == 2 ){ //Finaliza atendimento
		selecaoMenu = false;
		system("cls");
		printf("Atendimento finalizado! Obrigado pela preferência.");
	}
}

void visualizarConsulta(){//Procedimentos para a visualização de consultas
	setlocale(LC_ALL, "Portuguese");
	selecaoMenuHorario = true;
	
	system("cls");
	printf("|                                        ### CONSULTAS MARCADAS ###                                      |\n");
	
	for (m=0; m<4; m++) { //Mostrar o topo das consultas marcadas 
		if(topoVisualizacao[m] == 'a') { //Substituindo as letras pelo conteúdo do printf
			printf("|                     Paciente                     |");
		}
		if(topoVisualizacao[m] == 'b') {
			printf("            Dentista            |");
		}
		if(topoVisualizacao[m] == 'c') {
			printf("   Dia   |");
		}
		if(topoVisualizacao[m] == 'd') {
			printf("   Hora   |");
		}
	}
	printf("\n \n");
	
	for (m=0; m<30; m++) { //Mostrar as consultas marcadas com os dados colhidos no main
		for (n=0; n<8; n++) {
			if(horarios[m][n+1] == 2) {
				printf("|   %-47.47s|", nomePaciente);
				printf("   %-26.26s   |", nomeDentista);
				printf("   %2.2d    |", m+1);
					if (n == 0 ) {
						printf("   08hrs  |"); //Substituindo os valores de n pelo conteúdo do printf
					}
					if (n == 1 ) {
						printf("   09hrs  |");
					}
					if (n == 2 ) {
						printf("   10hrs  |");
					}
					if (n == 3 ) {
						printf("   11hrs  |");
					}
					if (n == 4 ) {
						printf("   13hrs  |");
					}
					if (n == 5 ) {
						printf("   14hrs  |");
					}
					if (n == 6 ) {
						printf("   15hrs  |");
					}
					if (n == 7 ) {
						printf("   16hrs  |");
					}
				printf("\n");			
			}
		}
	}

//Menu final	
	printf("\nO que deseja fazer agora? \n");
	printf("1 - Voltar ao Menu \n");
	printf("2 - Finalizar o atendimento \n");
	scanf("%d", &voltarMenu);
	
	while(voltarMenu != 1 && voltarMenu != 2){
		system("cls");
		printf("Você nao selecionou um número válido, por gentileza tente novamente \n \n");
		printf("1 - Voltar ao Menu \n");
		printf("2 - Finalizar o atendimento \n");
		scanf("%d", &voltarMenu);		
	}
		
	if(voltarMenu == 2 ){
		selecaoMenu = false;
		system("cls");
		printf("Atendimento finalizado! Obrigado pela preferência.");
	}

}

void desmarcarConsulta(){ //Procedimentos para a desmarcação de consultas
	setlocale(LC_ALL, "Portuguese");
	selecaoMenuHorario = true;
	system("cls");
	marcacoes = 0;
	for (m=0; m<30; m++) { //Contar quantas consultas foram marcadas
		for (n=0; n<8; n++) {
			if (horarios[m][n+1] == 2) {
				marcacoes++;
			}
		}
	}
	
	if (marcacoes == 0) { //Verificar se não há consultas marcadas  
		printf("Prezado(a) %s, não há consultas marcadas em seu nome.", nomePaciente);
	} else {
		printf("|                                        ### CONSULTAS MARCADAS ###                                      |\n\n");
		marcacoes = 0;
		for (m=0; m<30; m++) { //Contar e imprimir as consultas marcadas 
			for (n=0; n<8; n++) {
				if (horarios[m][n+1] == 2){ 
					marcacoes++;
					printf("%d - %s - %2.2d/06 - ", marcacoes, nomeDentista, m+1);
					if (n == 0 ) {
							printf("08hrs\n"); //Substituindo os valores de n pelo conteúdo do printf
						}
						if (n == 1 ) {
							printf("09hrs\n");
						}
						if (n == 2 ) {
							printf("10hrs\n");
						}
						if (n == 3 ) {
							printf("11hrs\n");
						}
						if (n == 4 ) {
							printf("13hrs\n");
						}
						if (n == 5 ) {
							printf("14hrs\n");
						}
						if (n == 6 ) {
							printf("15hrs\n");
						}
						if (n == 7 ) {
							printf("16hrs\n");
						}
				}
			}
		}
		
		printf("\n\nQual consulta deseja desmarcar?\n");
		scanf("%d", &desmarcarData);
		
		while (desmarcarData > marcacoes) { //Verifica se a opção selecionada é válida 
			printf("Opção inválida. Por gentileza informe uma opção que esteja disponível para desmarcar sua consulta:\n");
			scanf("%d", &desmarcarData);
		}
		marcacoes=0;
		for (m=0; m<30; m++) { //Conta as consultas e substitui a opção selecionada pelo usuário disponibilizando o horário
			for (n=0; n<8; n++) {
				if (horarios[m][n+1] == 2){
					marcacoes++;
					if (desmarcarData == marcacoes) {
						horarios[m][n+1] = 0;
					}
				}
			}
		}
		printf("\nSua consulta foi desmarcarda com sucesso!!\n");
	}
	
//Menu final	
	printf("\nO que deseja fazer agora? \n");
	printf("1 - Voltar ao Menu \n");
	printf("2 - Finalizar o atendimento \n");
	scanf("%d", &voltarMenu);
	
	while(voltarMenu != 1 && voltarMenu != 2){
		system("cls");
		printf("Você nao selecionou um número válido, por gentileza tente novamente \n \n");
		printf("1 - Voltar ao Menu \n");
		printf("2 - Finalizar o atendimento \n");
		scanf("%d", &voltarMenu);		
	}
		
	if(voltarMenu == 2 ){
		selecaoMenu = false;
		system("cls");
		printf("Atendimento finalizado! Obrigado pela preferência.");
	}
}

main(void){//Função principal 
	char dataNascimento[10], cpf[11];//Variáveis para colher dados do paciente  
	int i, j; //Variáveis do for 
	int opcaoDentista, menuSelect, tamCPF;//Variáveis diversas 
	setlocale(LC_ALL, "Portuguese");//Acentuação
		

// Coleta de dados do paciente 

	printf("########## SISTEMA DE MARCAÇÕES ########## \n\n");

	printf("Informe seu nome completo (sem acentuação): \n");
	gets(nomePaciente);//Armazenar string com espaços

	printf("Informe o seu CPF (sem pontos ou traços): \n");
	scanf("%s", &cpf); //Variável cpf declarada como char
	
	while(strlen(cpf) != 11) { //Verificar o tamanho do cpf 
		printf("CPF inválido! Por gentileza, informe o seu CPF novamente (sem pontos ou traços): \n");
		scanf("%s", &cpf);
	}
		
	printf("Informe sua data de nascimento (no formato DD/MM/AAAA): \n");
	scanf("%s", &dataNascimento);  //Variável data declarada como char
	
	while(strlen(dataNascimento) != 10 && dataNascimento[3] != '/' && dataNascimento[6] != '/') { // Verificação do tamanho e do formato da data
		printf("Data inválida! Por gentileza, informe a sua data de nascimento novamente (no formato DD/MM/AAAA): \n");
		scanf("%s", &dataNascimento);
	}
	
	printf("\n");
	system("cls");
	
// Apresentação dos dados do paciente 

	printf("O nome armazenado foi: %s \n", nomePaciente);
	printf("O CPF armazenado foi: "); 
		for(i = 0; i<11; i++){ //Para acrescentar os pontos e espaços e mostrar o CPF inteiro 
			printf("%c", cpf[i]);
			if (i == 2){
				printf(".");
			} if (i == 5){
				printf(".");
			} if (i == 8){
				printf("-");
			}			
		}	
	
	printf("\n");
	printf("A data de nascimento armazenada foi: %s \n", dataNascimento);
	printf("\n \n");
	
// Escolha do profissional dentista

	printf("########## SELEÇÃO DE PROFISSIONAL ########## \n \n");
	printf("Por gentileza, selecione o número correspondente ao dentista que deseja atendimento: \n\n"); 
	printf("1 - ARTHUR FILGUEIRAS ASSUNÇÃO \n");
	printf("2 - DANIELLE VASCONCELOS MELLO \n\n");
	printf("A opção escolhida será: ");
	scanf("%d", &opcaoDentista);
	printf("\n");
	
	while(opcaoDentista != 1 && opcaoDentista != 2){ //Verificar se a opção digitada está correta 
		system("cls");
		printf("Você não selecionou um número válido, por gentileza tente novamente \n \n");
		printf("1 - ARTHUR FILGUEIRAS ASSUNÇÃO \n");
		printf("2 - DANIELLE VASCONCELOS MELLO \n");
		printf("A opção escolhida será: ");
		scanf("%d", &opcaoDentista);
		printf("\n");
	}
	
	system("cls");
		
	if (opcaoDentista == 1){
		strcpy(nomeDentista, "Arthur Filgueiras Assunção"); //Armazenar uma string em uma variável 
	} else if(opcaoDentista == 2){
		strcpy(nomeDentista, "Danielle Vasconcelos Mello"); //Armazenar uma string em uma variável
	}
	

// Apresentação do menu
	while (selecaoMenu == true) { //Verificar a opção selecionar menu está verdadeira para retornar ao menu, caso contrario finaliza o sistema
		
		system("cls");
		printf("O atendimento será com o(a) dentista: %s \n", nomeDentista);
		printf("\n");
		printf ("##########  MENU  ######### \n");
		printf ("1 - MARCAR CONSULTA \n");
		printf ("2 - VISUALIZAR CONSULTAS MARCADAS \n");
		printf ("3 - DESMARCAR CONSULTA \n");
		printf ("4 - FINALIZAR ATENDIMENTO \n");
		scanf("%d", &menuSelect);
		

			switch(menuSelect){ 
				case 1:
					marcarConsulta();
				break;
					
				case 2:
					visualizarConsulta();
				break;
				
				case 3:
					desmarcarConsulta();
				break;
				
				case 4:
					system("cls");
					printf("Atendimento finalizado! Obrigado pela preferência.");
					selecaoMenu = false;
				break;
				
				default:
					printf("Opção inválida, atendimento finalizado!");
					selecaoMenu = false;
				break;	
			}
	}
	
	return 0;
}
