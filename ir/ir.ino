#include <IRremote.h>


#define IRpin 7


#define CTRLC //replace here for ctrl c
#define CTRLV //replace here for ctrl v

IRrecv IR(IRpin);
decode_results results;

static unsigned long value;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
}

void loop() {
  if (IR.decode(&results))
  {     
   
   if (results.value == 0XFFFFFFFF)
       results.value = value;

   value = results.value;
   IR.resume();
   
  }

  if (value){
    
    switch(value){
      case CTRLC:
        Serial.println("copy");
        break;
      case CTRLV:
        Serial.println("paste");
        break;
    }
   value = 0;

  delay(10);
}
}
