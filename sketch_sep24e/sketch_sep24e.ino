#include "BluetoothSerial.h" 

BluetoothSerial ESP_BT; 

void setup() {
  Serial.begin(115200);   
  ESP_BT.begin("blututesp"); 
  
}
//String input = Serial.readString();


void loop() {
  kirim();
  if (ESP_BT.available()) {
    String receivedData = ESP_BT.readString(); 
    Serial.print("Received: ");
    Serial.println(receivedData);
    
    
    ESP_BT.println("Message received: " + receivedData);
  }
  
  // Jika ada data dari Serial Monitor, kirim ke client Bluetooth
  if (Serial.available()) {
    String dataToSend = Serial.readString();
    nama(dataToSend);
    //ESP_BT.println(dataToSend); 
  }

  delay(2000); 
}
void nama(String jeneng){
  int jmlh=jeneng.length();
  for(int i=0;i<=jmlh;i++){
    ESP_BT.println(jeneng[i]);
    delay(2000);
  }
}

int kirim(){
  String pesan = "selamat datang";
  int jmlh=pesan.length();
  for(int i=0;i<=jmlh;i++){
    Serial.println (pesan[i]);
    delay(2000);
  }
  return 0;
}
