#define rele 5
#define presenceSensor 4
#define buzzer 3

int presenceSensorState;  //Instacia estado do sensor

//Dados buzzer
int melodia[] = {660,660,660,510,660,770,380};
int duracaonotas[] = {100,100,100,100,100,100,100};

void setup() 
{  
  Serial.begin(9600);                   //Inicia o serial
  Serial.println("Começo do programa"); 
  pinMode(rele, OUTPUT);                //Define a porta rele como saida
  pinMode(presenceSensor, INPUT);       //Define a porta "sensor" como entrada
  
  digitalWrite(rele, HIGH);              //High = desligado(estado 1), Low = ligado(estado 0) | começa desligado
}

void loop() 
{  
  acionamentoRele();                   //Loop do Rele
}

void acionamentoRele()
{
  
   presenceSensorState = digitalRead(presenceSensor);
   Serial.print("Estado do sensor: ");
   Serial.println(presenceSensorState);
  
   if (presenceSensorState == LOW)
   {
     digitalWrite(rele,HIGH);                         //Desacionamento rele 
   }
   else                                               //Se houver alteração de estado
   {
    Serial.println("Alguém acionou a luz!!!");        
    digitalWrite(rele,LOW);                           //Acionamento Rele
    Mario();                                          
    delay(5000);                                      //Permanecer por 5 segundos
   }
}

void Mario()                                          //Função do buzzer
{
  for (int nota = 0; nota < 7; nota++) {

        int duracaonota = duracaonotas[nota];
        tone(buzzer, melodia[nota],duracaonota);
        //pausa
        int pausanota[] ={150,300,300,100,300,550,575};
        delay(pausanota[nota]);
        }

        noTone(buzzer);
}
