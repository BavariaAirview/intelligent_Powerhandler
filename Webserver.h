// Webserver

// Callback: receiving any WebSocket message
void onWebSocketEvent(uint8_t client_num,
                      WStype_t type,
                      uint8_t * payload,
                      size_t length) {

  // Figure out the type of WebSocket event
  switch(type) {

    // Client has disconnected
    case WStype_DISCONNECTED:
      break;

    // New client has connected
    case WStype_CONNECTED:
      {
        IPAddress ip = webSocket.remoteIP(client_num);
      }
      break;

    // Handle text messages from client
    case WStype_TEXT:

      // Print out raw message
      Serial.printf("[%u] Received text: %s\n", client_num, payload);

      // WEB Steuerung
      if ( strcmp((char *)payload, "SysOFF") == 0 ) {
        stSystemON = false;
        
      } else if ( strcmp((char *)payload, "Licht") == 0 ) {
        licht = !licht;
      
      } else if ( strcmp((char *)payload, "Heiz") == 0 ) {
        Heizung = !Heizung;

      } else if ( strcmp((char *)payload, "PC") == 0 ) {
        PC = !PC;

      } else if ( strcmp((char *)payload, "Tools") == 0 ) {
        tools = !tools;

      } else if ( strcmp((char *)payload, "3DP") == 0 ) {
        drucker = !drucker;

      } else if ( strcmp((char *)payload, "getState") == 0 ) {

        stSystem = stSysOFF << 0;
        stSystem = licht << 1;
        stSystem = tools << 2;
        stSystem = PC << 3;
        stSystem = drucker << 4;
        stSystem = Heizung << 5;

        sprintf(msg_buf, "%d", stSystem);
        webSocket.sendTXT(client_num, msg_buf);

      // Message not recognized
      } 
      break;

    // For everything else: do nothing
    case WStype_BIN:
    case WStype_ERROR:
    case WStype_FRAGMENT_TEXT_START:
    case WStype_FRAGMENT_BIN_START:
    case WStype_FRAGMENT:
    case WStype_FRAGMENT_FIN:
    default:
      break;
  }
}

// Callback: send homepage
void onIndexRequest(AsyncWebServerRequest *request) {
  IPAddress remote_ip = request->client()->remoteIP();
  
  request->send(SPIFFS, "/index.html", "text/html");
}

// Callback: send style sheet
void onCSSRequest(AsyncWebServerRequest *request) {
  IPAddress remote_ip = request->client()->remoteIP();
  
  request->send(SPIFFS, "/style.css", "text/css");
}

// Callback: send 404 if requested file does not exist
void onPageNotFound(AsyncWebServerRequest *request) {
  IPAddress remote_ip = request->client()->remoteIP();
  
  request->send(404, "text/plain", "Not found");
}

void Wificonnect() {
  // Connect to WPA/WPA2 network:
  status = WiFi.begin(ssid, pass);
  delay(500);
  missconnectcounter++;
  myip = WiFi.localIP();
}
void StartServer() {
  // On HTTP request for root, provide index.html file
  server.on("/", HTTP_GET, onIndexRequest);

  // On HTTP request for style sheet, provide style.css
  server.on("/style.css", HTTP_GET, onCSSRequest);

  // Handle requests for pages that do not exist
  server.onNotFound(onPageNotFound);

  // Start web server
  server.begin();

  // Start WebSocket server and assign callback
  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);

  ServerisOn = true;
}
