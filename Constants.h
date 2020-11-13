//   Constantwerte
#define debug 1

#define arbeit 1
// #define keller 1
#define NUM_LEDS 5
#define LED_MAX 200
#define LED_LOW 25

#define COLOR_ORDER GRB
#define CHIPSET     WS2811
#define BRIGHTNESS  200
#define FRAMES_PER_SECOND 10
#define tasterdelay 200
#define remindbeep 100
#define freq 2000
#define Beeptime 80

#define Relais1_pin 26
#define Relais2_pin 25
#define Relais3_pin 33
#define Relais4_pin 32
#define Relais5_pin 35
#define Relais6_pin 34
#define Relais7_pin 39
#define Relais8_pin 38
#define Buzzer_pin 27

#define LED_PIN 15
#define NTC_pin 10
#define Printer_Bed_pin 14
#define Taster1_pin 2
#define Taster2_pin 0
#define Taster3_pin 4
#define Taster4_pin 16
#define Taster_enco_pin 17
#define encoder0PinA 5
#define encoder0PinB 18

// WEBServer
#ifdef arbeit 
char ssid[] = "GEDA-Entwicklung";     //  your network SSID (name)
char pass[] = "2aGQrMjn2DyC2DmYf47tfihP3R7kQRwF";  // your network password
#endif

#ifdef keller 
char ssid[] = "Kellerkind";     //  your network SSID (name)
char pass[] = "Syn2tony";  // your network password
#endif

#define wificonnecttime 5000
#define routerbootdelay 2000
