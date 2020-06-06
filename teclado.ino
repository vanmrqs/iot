#include <Keypad.h>

const byte linhas  = 4;
const byte colunas = 4;

char teclado[linhas][colunas] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinosLinhas[linhas]   = {11, 10, 9, 8};
byte pinosColunas[colunas] = {7, 6, 5, 4};

Keypad keypad = Keypad(makeKeymap(teclado), pinosLinhas, pinosColunas, linhas, colunas);

char senha[4];
int i = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
 char entrada = keypad.getKey();
  
  if ( entrada == '*' ) {
   	resetaSenha(senha);
    i = 0;
  } else if ( entrada ) {
  	senha[i] = entrada;
    i++;
  }
  
  if ( i == 4 ) {
  	Serial.println(verificaSenha(senha));
    resetaSenha(senha);
    i = 0;
  }
}

String verificaSenha(char senha[4]){
  if ( ! strncmp(senha, "1234", 4) ) {
  	return "Senha correta";
  }
  
  return "Errou";
}

void resetaSenha(char senha[4]){
	for( i = 0; i < 4; i++ ) {
    	senha[i] = NULL;
    }
}