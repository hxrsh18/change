int led[]={3,4,5,6,7};
void setup() {
  Serial.begin(9600);
  for(int i=0;i<5;i++){
    pinMode(led[i],OUTPUT);
  }
}
void loop() {
  int i,j;
  Serial.println("Enter a number (0-31");
  while(Serial.available()==0){}
    int k=Serial.parseInt();
  if (k==(0-31)){
    a:
      for(int i=0;i<5;i++){
        digitalWrite(led[i],LOW);
      }
      int n=k;
      if (n>=32 || n<0){
        Serial.println("Enter a number between 0 and 31");
        goto a;
      }
      for(int i=4;i>-1;i--){
      byte st=bitRead(n,i);
      Serial.print(st);
      if(st==1) digitalWrite(led[i],HIGH);
    }
    Serial.println();
    delay(1500);
  }
}
