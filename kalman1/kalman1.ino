#include<Wire.h> 

#define Addr 0x53// ADXL345 I2C address is 0x53(83)
double xAccl=0;
double yAccl=0;
double zAccl=0;

//kalman filter global tanımlar
double X_k_KalmanTahminEski = 0; //Prior Estimate
double Pk_HataKovaryansiEski = 1; //Error

//kalman fonksiyonu
double kalman_init(double Zk) 
{
  //tanımlamalar
double Zk_OlcumDegeri =Zk;
double Xk_HesaplananDeger;
double R_HataMiktari = 0.1;
//hesaplama kısmı
Xk_HesaplananDeger =KalmanFiltresiHesapla(Zk_OlcumDegeri,R_HataMiktari);
 return  Xk_HesaplananDeger;
}

 double KalmanFiltresiHesapla(double Zk_OlculenDeger, double R_HataMiktari)
{
//Güncelleme--Eski değerleri yeni değerler içine atıyor.

double X_k_KalmanTahminYeni =X_k_KalmanTahminEski;

double Pk_HataKovaryansiYeni =Pk_HataKovaryansiEski;

//Ölçümleri Düzeltme--
double Kk_KalmanKazanci = Pk_HataKovaryansiYeni /(Pk_HataKovaryansiYeni + R_HataMiktari);

double Xk_KalmanHesaplanan = X_k_KalmanTahminYeni+ (Kk_KalmanKazanci * (Zk_OlculenDeger -X_k_KalmanTahminYeni));

Pk_HataKovaryansiYeni = (1 - Kk_KalmanKazanci) *Pk_HataKovaryansiEski;

//Eski Değerleri Atama--bu değişkenler Global tanımlandı. bu procedure her geldiğinde bunları kaybetmemelidir.


Pk_HataKovaryansiEski =Pk_HataKovaryansiYeni;

X_k_KalmanTahminEski = Xk_KalmanHesaplanan;
//bulunan sonuç bir sonraki adım için eski tahmin olacak.
return Xk_KalmanHesaplanan;
}

void setup()
{  
Wire.begin();  // Initialise I2C communication as MASTER 
Serial.begin(9600);   // Initialise serial communication, set baud rate = 9600  
Wire.beginTransmission(Addr);  // Start I2C Transmission 
Wire.write(0x2C);  // Select bandwidth rate register  
Wire.write(0x0A);  // Normal mode, Output data rate = 100 Hz 
Wire.endTransmission();    // Stop I2C transmission  
Wire.beginTransmission(Addr);  // Start I2C Transmission  
Wire.write(0x2D);  // Select power control register 
Wire.write(0x08);  // Auto-sleep disable
Wire.endTransmission();// Stop I2C transmission    
Wire.beginTransmission(Addr); // Start I2C Transmission 
Wire.write(0x31); // Select data format register 
Wire.write(0x08); // Self test disabled, 4-wire interface, Full resolution, Range = +/-2g   
Wire.endTransmission(); // Stop I2C transmission   
delay(300);
}

void loop()
{  
unsigned int data[6];  
for(int i = 0; i < 6; i++)  
{    
Wire.beginTransmission(Addr); // Start I2C Transmission     
Wire.write((50 + i)); // Select data register    
Wire.endTransmission();// Stop I2C transmission         
Wire.requestFrom(Addr, 1); // Request 1 byte of data        

if(Wire.available() == 1) // Read 6 bytes of data    
// xAccl lsb, xAccl msb, yAccl lsb, yAccl msb, zAccl lsb, zAccl msb    
{      
data[i] = Wire.read();    
}  

}  
// Convert the data to 10-bits    
 xAccl = (((data[1] & 0x03) * 256) + data[0]);  
if(xAccl > 511)  
{    
xAccl -= 1024;  
}  
double xnew=KalmanFiltresiHesapla(xAccl,0.1);
 yAccl = (((data[3] & 0x03) * 256) + data[2]);  
if(yAccl > 511)  
{    
yAccl -= 1024;  
}  
double ynew=KalmanFiltresiHesapla(yAccl,0.1);
 zAccl = (((data[5] & 0x03) * 256) + data[4]);  
if(zAccl > 511)  
{    
zAccl -= 1024;  
}    
double znew=KalmanFiltresiHesapla(zAccl,0.1);
// Output data to serial monitor  

Serial.print("X-Axis : ");  

Serial.print(xnew);  

Serial.print("Y-Axis : ");  

Serial.print(ynew);  

Serial.print("Z-Axis : ");  

Serial.println(znew);  

delay(300);

}
