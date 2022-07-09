#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<conio.h>

int main()
{
	setlocale(LC_ALL,"Portuguese");
	char email[70], erro_email[70],posicao_init=' ';
	int flag=0, flag_count=0, indice=0,qtd=0, indice_erro=0,qtd_arroba=0,posic_arroba,qtd_ponto,pos_arroba;
	int space=0,pos_arroba_erro;
	printf("Digite seu e-mail -> ");
		gets(email);
	
	while(email[indice] == ' ')
	{
		indice++;
	}
	posicao_init = indice;//para verificar se o 1º caract é aceito	

		while(email[indice] != '\0')//conta e verifica posições
		{
			qtd++;
			switch(email[indice])
				{
					case '!':;case '#':;case '$':;case '%':;case '&':;case '*':;case '(':;case ')':;case '_':;case '+':;case '-':;case '=':;case '§':;case '{':;case '}':;case '[':;case ']':;case 'º':;case 'ª':;case '´':;case '`':;case '^':;case '~':;case '<':;case '>':;case ',':;case ';':;case ':':;case '?':;case '/':;case '°':
					erro_email[flag_count++] = email[indice];
					flag++;
					
					;break;
				}
				if(email[indice] ==' ')
				{
					flag++;
					space++;
					erro_email[flag_count++] = email[indice];
				}
				if(email[indice] =='@')
				{
					qtd_arroba++;
					posic_arroba = indice;
				}
			indice++;
		}
		if(email[posicao_init] >='A' && email[posicao_init] <= 'Z' )
		{
			erro_email[flag_count++] = email[posicao_init];//esse flag_count possui a ultima posicao
		}
		
		pos_arroba = posic_arroba;
		if(qtd_arroba != 1)
		{
			erro_email[flag_count++]= '@';
			flag++;
		}
		else
		{
			if(email[pos_arroba+1] >='a' && email[pos_arroba+1] <='z')
			{
				while(email[posic_arroba++] != '\0')
				{
					if(email[posic_arroba] =='.')
					qtd_ponto++;
				}
			}
			else
			{
				pos_arroba_erro =flag_count;
				erro_email[flag_count++]= email[pos_arroba+1];
				flag++;
			}	
		}
		if(qtd_ponto !=1 )
		{
			
		}
		if(flag != 0)
		{
			while(erro_email[indice_erro] != '\0')
			{
				//printf("\nNº %d -> C -> %c\n", indice_erro+1,erro_email[indice_erro]);
				switch(erro_email[indice_erro])
				{
					case ' ':printf("Erro Nº %d, não deve haver espaços -> %c\n",indice_erro+1,erro_email[indice_erro]);break;
					case '@':printf("Erro Nº %d, deve ter 1 @  -> %c\n",indice_erro+1,erro_email[indice_erro]);break;
					default:
						if(erro_email[indice_erro] >= 'A' && erro_email[indice_erro] <= 'Z')
						{
							printf("Erro Nº %d, deve iniciar com letra minuscula -> %c\n",indice_erro+1,erro_email[indice_erro]);
						}else if(indice_erro == pos_arroba_erro)
						{
							printf("Erro Nº %d, após o @ deve ser um caractere -> %c\n",indice_erro+1,erro_email[indice_erro]);
						}else
							printf("Erro Nº %d, caractere invalido -> %c\n",indice_erro+1,erro_email[indice_erro]);
					;
				}
				indice_erro++;
			}
		}
	if(flag == 0)
		printf("Email válido!");
	else
		printf("Email invalido!");
}
