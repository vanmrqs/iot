#include <Keypad.h>

const byte LINHAS  = 4;
const byte COLUNAS = 4;

const byte NUMERO_TENTATIVAS = 3;
const byte TAMANHO_SENHA     = 4;

char teclado[LINHAS][COLUNAS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinosLinhas[LINHAS]   = {11, 10, 9, 8};
byte pinosColunas[COLUNAS] = {7, 6, 5, 4};

Keypad keypad = Keypad(makeKeymap(teclado), pinosLinhas, pinosColunas, LINHAS, COLUNAS);

char senha[TAMANHO_SENHA];
int i = 0;
int numeroTentativas = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
 char entrada = keypad.getKey();
  
 if ( entrada == '*' ) {
   resetaSenha(senha);
   i = 0;
   numeroTentativas = 0;
   Serial.println("Tentativas e senha resetada");
 } else if ( entrada ) {
   senha[i] = entrada;
   i++;
 }

 if ( ( numeroTentativas < NUMERO_TENTATIVAS ) && (i == TAMANHO_SENHA) ) {
   numeroTentativas++;
   Serial.println(verificaSenha(senha));
   resetaSenha(senha);
   i = 0;
 }
}

String verificaSenha(char senha[4]){
  if ( ! strncmp(senha, "1234", TAMANHO_SENHA) ) {
  	return "Senha correta";
  }
  
  return "Errou";
}

void resetaSenha(char senha[4]){
	for( i = 0; i < TAMANHO_SENHA; i++ ) {
    	senha[i] = NULL;
    }
}