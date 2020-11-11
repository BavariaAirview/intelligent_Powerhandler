
#define debug 1

uint16_t temp_scaler = 110;
int temp_offset = 60;
float soll_temp = 15.5;
uint8_t delay_printer = 40;    // Minuten
uint8_t delay_PC = 1;          // Minuten
int8_t remind_timer = 30;      // Minuten



//_________________________________________________________________ no change below this line nessasary
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

//                R G B
uint8_t LED1[] = {0, 0, 0};   // 3D Drucker
uint8_t LED2[] = {0, 0, 0};   // Licht
uint8_t LED3[] = {0, 0, 0};   // Tools
uint8_t LED4[] = {0, 0, 0};   // PC
uint8_t LED5[] = {0, 0, 0};   // Reminder

bool Relais1 = false;   // Netzteil
bool Relais2 = false;   // Heizung
bool Relais3 = false;   //  = Relais2
bool Relais4 = false;   // 3D Drucker
bool Relais5 = false;   // Licht
bool Relais6 = false;   // Tools
bool Relais7 = false;   // PC
bool Relais8 = false;   // Netzwerk
bool aus = false;

int8_t courser_pos = 1;         // 1 = Hauptmenüpunkt, 2 = Value1, 3 = Value2
int8_t nMainMenu = 0;
int8_t nValue1 = 0;
uint16_t Minuten = 0;
bool boolValue = false;
bool set_boolValue = false;
int8_t nValue2 = 2;
float numValue2 = 0;
long waittime = 0;
long diplaytimer = 10000;
long menudelay = 0;
long printdelay = 0;
long beepdelay = 0;
long remind_counter = 0;
long remind_timer_alt = 0;
long cycletime = 0;
String error = "";
bool printprogress = false;

int channel = 0;
int resolution = 8;

uint16_t NTC = 0;
float temp = 0;
double NTC_OHM = 0;
double TKelvin = 0;

bool drucker = false;
bool licht = true;
bool tools = false;
bool PC = false;
bool Heizung = false;
bool Heizung_relais = false;
bool Menuauswahl = false;
bool DisplayON = true;
bool SystemON = true;
bool reminder = false;
uint8_t Taster1ana = 0;
uint8_t Printer_done_ana = 0;

bool Taster1 = false;         // 3D Drucker
bool Taster2 = false;         // Licht
bool Taster3 = false;         // Tools
bool Taster4 = false;         // PC
bool Taster_enco = false;
bool Printer_done = false;
bool alleTaster = false;
bool allesAndere = false;
bool timer_set = false;
bool printwait = false;
bool AllOff = false;

bool Taster1_alt = false;
bool Taster2_alt = false;
bool Taster3_alt = false;
bool Taster4_alt = false;
bool Taster_enco_alt = false;

String M_Menu = "";
String v1_Menu = "";
String v2_Menu = "";
