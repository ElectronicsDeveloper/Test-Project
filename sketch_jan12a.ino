// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int PIR=8;

void setup() {
  pinMode(PIR,INPUT);
  Serial.begin(9600);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
}

void loop() {
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print("Security System ");
  lcd.setCursor(0, 1);
  lcd.print("   Activated    ");
  
    if(digitalRead(PIR)==HIGH)
    {
      // Print a message to the LCD.
      lcd.setCursor(0, 0);
      lcd.print("Theft Detected  ");
      lcd.setCursor(0, 1);
      lcd.print("Sending SMS.....");
  
      sendSMS();
      delay(5000);
    }
}

void sendSMS()
{
     Serial.println("AT+CMGD=1");    //Delete privious sent SMS
     delay(1000);
          
     Serial.println("AT+CMGF=1");   //Set SMS configuration
     delay(1000);
     
     Serial.print("AT+CMGW=");          //Write New SMS
     Serial.write(34);                  //Double quotes ASCII Code
     Serial.print("+9198--------");         //Enter Your Mobile number
     Serial.write(34);
     Serial.println();                  //Send Crrige return
     delay(1000);
     
     Serial.println("Alert: Theft Detected");
     delay(1000);

     Serial.write(26); //Cntrl+Z
     delay(1000);
     delay(1000);

     Serial.println("AT+CMSS=1");      //Send SMS from memory location 1
     delay(4000);
}
