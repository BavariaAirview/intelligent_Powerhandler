#define NUM_FILTER = 40

uint16_t temp_scaler = 100;
int temp_offset = 1;


//_________________________________________________________________ no change below this line nessasary

String M_Menu[10];
String O_Menu[5];
String v1_Menu[3];
String v2_Menu[3];

uint8_t LED1_r = 0;
uint8_t LED2_r = 0;
uint8_t LED3_r = 0;
uint8_t LED4_r = 0;
uint8_t LED1_g = 0;
uint8_t LED2_g = 0;
uint8_t LED3_g = 0;
uint8_t LED4_g = 0;
uint8_t LED1_b = 0;
uint8_t LED2_b = 0;
uint8_t LED3_b = 0;
uint8_t LED4_b = 0;

int encoderPinALast = LOW;
int rotation = LOW;
volatile unsigned int encoderPos = 0;

bool Relais1 = false;
bool Relais2 = false;
bool Relais3 = false;
bool Relais4 = false;
bool Relais5 = false;
bool Relais6 = false;
bool Relais7 = false;
bool Relais8 = false;

char courser_pos = 1;         // 1 = Hauptmenüpunkt, 2 = Option, 3 = Value1, 4 = Value2
char courser_pos_alt = 1;
int ueberhame1 = 0;
int ueberhame2 = 0;
char nOption = 0;
char nOption_alt = 0;
char nMainMenu = 0;
char nMainMenu_alt = 0;
int nValue1 = 0;
int nValue2 = 0;
bool numValue1 = False;
bool numValue2 = False;
String MainMenu = "";
String Option = "";
String Value1 = "";
String Value2 = "";

String Courser_pos = "menu";

float NTC = 0;
float temp = 0;
float NTC_lowpass[NUM_FILTER];

uint8_t i = 1;

bool Taster1 = false;
bool Taster2 = false;
bool Taster3 = false;
bool Taster4 = false;
bool Taster_enco = false;
