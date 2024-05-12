//#include <SimulatorProgram.h>
//#include <LiquidCrystalSim.h>
#include <LiquidCrystal.h>

int button1_7 = 7;
int button2_8 = 8;
int button3_9 = 9;
int button4_10 = 10;
int button5_15 = 15;
int button6_16 = 16;
int button7_17 = 17;
int button8_18 = 18;

bool is_running = false;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
String startText = "Mygtuku busena: ";
String scrollingText = "Mygtuku busena: ";

void setup(){
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.print("Spauskite");
  lcd.setCursor(0,1);
  lcd.print("BUTTON 1 (D7)");
}

void loop(){
  
  int start_buttonState = digitalRead(button1_7);
  int button1_7 = 7;
  int button2_8 = 8;
  int button3_9 = 9;
  int button4_10 = 10;
int button5_15 = 15;
int button6_16 = 16;
int button7_17 = 17;
int button8_18 = 18;

  if(!is_running && start_buttonState == HIGH) {
     is_running = true;
     scrollingText = startText;
  }
  if(!is_running && start_buttonState == LOW){
    lcd.setCursor(0,0);
    lcd.print("Spauskite");
    lcd.setCursor(0,1);
    lcd.print("BUTTON 1 (D7)");
  }
  if(button1_7 == HIGH)
    scrollingText = scrollingText + "B1-1 ";
  else scrollingText = scrollingText + "B1-0 ";

  if(button2_8 == HIGH)
    scrollingText = scrollingText + "B2-1 ";
  else scrollingText = scrollingText + "B2-0 ";

  if(button3_9 == HIGH)
    scrollingText = scrollingText + "B3-1 ";
  else scrollingText = scrollingText + "B3-0 ";

  if(button4_10 == HIGH)
    scrollingText = scrollingText + "B4-1 ";
  else scrollingText = scrollingText + "B4-0 ";

  if(button5_15 == HIGH)
    scrollingText = scrollingText + "B5-1 ";
  else scrollingText = scrollingText + "B5-0 ";

  if(button6_16 == HIGH)
    scrollingText = scrollingText + "B6-1 ";
  else scrollingText = scrollingText + "B6-0 ";

  if(button7_17 == HIGH)
    scrollingText = scrollingText + "B7-1 ";
  else scrollingText = scrollingText + "B7-0 ";

  if(button8_18 == HIGH)
    scrollingText = scrollingText + "B8-1 ";
  else scrollingText = scrollingText + "B8-0 ";

  if(is_running){
    for (int i = 0; i < scrollingText.length() + 16; i++) {
      lcd.clear();
      lcd.setCursor(max(0, 16 - i), 0);

      String textToShow = scrollingText.substring(max(0, i - 16), min(i, scrollingText.length()));
      lcd.print(textToShow);
      delay(100);
      is_running = false;
      }
  }
}

// for (int i = 0; i <= scrollingText.length() + 16; i++) {
//       lcd.clear();
//       lcd.setCursor(max(0, 16 - i), 0);

//       // Display the substring from the end of the text to i characters
//       String textToShow = scrollingText.substring(max(0, i - 16), min(i, scrollingText.length()));
//       lcd.print(textToShow);

//       delay(200);



// int previous;
// bool is_running = false;
// int current_ofset;
// bool reset = true;

// String inString; //Šito reikia nes nėra SimulatorProgram.h

// void setup() {
//   Serial.begin(9600);
//   inString.reserve(10);

//   lcd.begin(16, 2);
//   lcd.print("Timer");
//   lcd.setCursor(3, 1);
//   lcd.print("PRESS START");
//   previous = millis() / 1000;
//   lcd.noBlink();
//   // put your setup code here, to run once:

// }

// void loop() {
//   int start_buttonState = digitalRead(start_buttonPin);
//   int stop_buttonState = digitalRead(stop_buttonPin);
//   int reset_buttonState = digitalRead(reset_buttonPin);
//   if(!is_running && start_buttonState == HIGH) {
//     is_running = true;
//     if(reset){
//       current_ofset = millis() / 1000;
//       reset = false;
//     }
//   }
//   if(is_running && stop_buttonState == HIGH){
//     is_running = false;
//   }
//   if(reset_buttonState == HIGH){
//     current_ofset = millis()/1000;
//     lcd.setCursor(4, 1);
//     lcd.print("00:00:00");
//     reset = true;
//   }
//   if(is_running) {
//     if(previous != millis() /1000){
//       int counter = previous - current_ofset;
//       int sec = counter % 60;
//       sec < 0 ? sec : 0;
//       int minn = (counter%3600-sec)/60;
//       int hour = (counter - counter%3600)/3600;
//       char result[8];
//       result[0] = 48 + (hour-hour%10)/10;
//       result[1] = 48 + hour%10;
//       result[2] = ':';
//       result[3] = 48 + (minn-minn%10)/10;
//       result[4] = 48 + minn%10;
//       result[5] = ':';
//       result[6] = 48 + (sec-sec%10)/10;
//       result[7] = 48 + sec%10;

//       lcd.setCursor(4, 1);
//       previous = millis()/1000;
//       lcd.print(result);
//     }
//   }
// }
