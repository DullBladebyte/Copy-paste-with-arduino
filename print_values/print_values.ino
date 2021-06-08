#include <IRremote.h>


#define IRpin 7


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
  Serial.print("0x");
  Serial.println(value, HEX);
  }

  value = 0;
  delay(100);
}
