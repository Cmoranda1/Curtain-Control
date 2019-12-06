#include <DS3231.h>
DS3231 rtc(SDA, SCL);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  rtc.begin();
  rtc.setDOW(MONDAY);
  rtc.setTime(10, 4, 0);
  rtc.setDate(4, 9, 2018);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Time ");
  Serial.println(rtc.getTimeStr());
  if(strstr(rtc.getTimeStr(), "10:04:0") != NULL){
    Serial.println("Wakey Wakey");
  }

  Serial.print("Date: ");
  Serial.println(rtc.getDateStr());

  delay(5000);

}
