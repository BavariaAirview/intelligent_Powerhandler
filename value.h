#define NUM_FILTER 40
#define NUM_LEDS 4
#define LED_MAX 200
#define LED_LOW 40

#define debug 1

uint16_t temp_scaler = 100;
int temp_offset = 1;
float soll_temp = 18.5;
uint8_t delay_printer = 10;    // Minuten
uint8_t delay_PC = 1;          // Minuten


//_________________________________________________________________ no change below this line nessasary

#define COLOR_ORDER RGB
#define CHIPSET     WS2811
#define BRIGHTNESS  200
#define FRAMES_PER_SECOND 10

#define Relais1_pin 2
#define Relais2_pin 3
#define Relais3_pin 4
#define Relais4_pin 5
#define Relais5_pin 6
#define Relais6_pin 7
#define Relais7_pin 8
#define Relais8_pin 9

#define LED_PIN 10
#define NTC_pin A0
#define Printer_Bed_pin A7
#define Taster1_pin A6
#define Taster2_pin A3
#define Taster3_pin A2
#define Taster4_pin A1
#define Taster_enco_pin 13
#define encoder0PinA 11
#define encoder0PinB 12

//                R G B
uint8_t LED1[] = {0,0,0};     // 3D Drucker
uint8_t LED2[] = {0,0,0};     // Licht
uint8_t LED3[] = {0,0,0};     // Tools
uint8_t LED4[] = {0,0,0};     // PC

bool Relais1 = false;   // Netzteil
bool Relais2 = false;   // Heizung
bool Relais3 = false;   //  = Relais2
bool Relais4 = false;   // 3D Drucker
bool Relais5 = false;   // Licht
bool Relais6 = false;   // Tools
bool Relais7 = false;   // PC
bool Relais8 = false;   // Netzwerk

uint8_t courser_pos = 1;         // 1 = Hauptmenüpunkt, 2 = Value1, 3 = Value2
uint8_t nMainMenu = 0;
uint8_t nValue1 = 0;
bool boolValue = false;
bool set_boolValue = false;
uint8_t nValue2 = 0;
float numValue2 = 0;
char MainMenu = "";
char Value1 = "";
char Value2 = "";
long waittime = 0;
long diplaytimer = 10000;
long menudelay = 0;
long printdelay = 1000;
String error = "";
bool printprogress = false;

float NTC = 0;
float temp = 0;
float NTC_lowpass[NUM_FILTER];

uint8_t i = 1;

bool drucker = false;
bool licht = true;
bool tools = false;
bool PC = false;
bool Heizung = true;
bool Menuauswahl = false;
bool DisplayON = true;
bool SystemON = true;

bool Taster1 = false;         // 3D Drucker
bool Taster2 = false;         // Licht
bool Taster3 = false;         // Tools
bool Taster4 = false;         // PC
bool Taster_enco = false;
bool Printer_done = false;
bool alleTaster = false;
bool allesAndere = false;

bool Taster1_alt = false;
bool Taster2_alt = false;
bool Taster3_alt = false;
bool Taster4_alt = false;
bool Taster_enco_alt = false;

const char *M_Menu[] = {"3Dprint", "Licht", "Tools", "PC", "Heater", "System"};
const char *v1_Menu[] = {"ON", "OFF"};
const char *v2_Menu[] = {"temp", "delay"};
