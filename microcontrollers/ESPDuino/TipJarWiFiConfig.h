//This Program makes Esp8266 as a webserver. It scans the wirless networks and connectes to the one selected by the user
//Westborough IOT
//Pugazendhi Shanmugam on June 22 2016

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

const char* ssid = "WBIOT";
const char* password = "WBIOT";

ESP8266WebServer server(80);

//Check if header is present and correct
bool is_authentified(){
  Serial.println("Enter is_authentified");
  if (server.hasHeader("Cookie")){   
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
    if (cookie.indexOf("ESPSESSIONID=1") != -1) {
      Serial.println("Authentification Successful");
      return true;
    }
  }
  Serial.println("Authentification Failed");
  return false;	
}

//login page, also called for disconnect
void handleLogin(){
  String msg;
  if (server.hasHeader("Cookie")){   
    Serial.print("Found cookie: ");
    String cookie = server.header("Cookie");
    Serial.println(cookie);
  }
  if (server.hasArg("DISCONNECT")){
    Serial.println("Disconnection");
    String header = "HTTP/1.1 301 OK\r\nSet-Cookie: ESPSESSIONID=0\r\nLocation: /login\r\nCache-Control: no-cache\r\n\r\n";
    server.sendContent(header);
    return;
  }
  if (server.hasArg("USERNAME") && server.hasArg("PASSWORD")){
    if (server.arg("USERNAME") == "admin" &&  server.arg("PASSWORD") == "admin" ){
      String header = "HTTP/1.1 301 OK\r\nSet-Cookie: ESPSESSIONID=1\r\nLocation: /\r\nCache-Control: no-cache\r\n\r\n";
      server.sendContent(header);
      Serial.println("Log in Successful");
      return;
    }
  msg = "Wrong username/password! try again.";
  Serial.println("Log in Failed");
  }
  String content = "<html><body><H2>hello, you successfully connected to Tip Jar!</H2><br><form action='/login' method='POST'>connect to Tip using your user id and password<br>";
  content += "User:<input type='text' name='USERNAME' placeholder='user name'><br>";
  content += "Password:<input type='password' name='PASSWORD' placeholder='password'><br>";
  content += "<input type='submit' name='SUBMIT' value='Submit'></form>" + msg + "<br>";
  content += "You also can go <a href='/inline'>here</a></body></html>";
  server.send(200, "text/html", content);
}

void WiFiStation(){

  String content = "";
  String strSSID = "";
  String strPass = "";

   if (server.hasArg("SSIDVal") && server.hasArg("PASSWORD")){
    
      strSSID = server.arg("SSIDVal");
      Serial.println("connecting toSSIDVal ******"+strSSID);
      strPass = server.arg("PASSWORD");
      Serial.println("connecting Pass ******"+strPass);
      char chSSID[strSSID.length()];
      char chPass[strPass.length()]; 
      strSSID.toCharArray(chSSID,strSSID.length()+1);
      strPass.toCharArray(chPass,strPass.length()+1);
      String header = "HTTP/1.1 301 OK\r\nSet-Cookie: ESPSESSIONID=1\r\nLocation: /\r\nCache-Control: no-cache\r\n\r\n";
      server.sendContent(header);
      WiFi.disconnect(true);
      Serial.println();
      Serial.print("connecting to ");
      Serial.println(strSSID);
      WiFi.begin(chSSID,chPass);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address: ");
      String strIP= "";
      Serial.println(WiFi.localIP());
      content = "<html><body><H1>You have successfully connected to "+server.arg("SSIDVal")+"</H1><br>";
    //  content = "<body><H1>IP Address "+strIP(WiFi.localIP())+"</H1><br></html>"
  } else {
  content = "<html><body><H1>Unable to make a WiFi connection </H1><br>";
  }
  server.send(200, "text/html", content);
}
//root page can be accessed only if authentification is ok
void handleRoot(){
  Serial.println("Enter handleRoot");
  String header;
  if (!is_authentified()){
    String header = "HTTP/1.1 301 OK\r\nLocation: /login\r\nCache-Control: no-cache\r\n\r\n";
    server.sendContent(header);
    return;
  }
  String content = "<html><body><H2>Welcome to TipJar Configuration</H2><br>";
  if (server.hasHeader("User-Agent")){
    content += "the user agent used is : " + server.header("User-Agent") + "<br><br>";
  }
  content += "<a href=\"/WiFiCon?CONNECT=YES\">Click here to  configure WiFi for TipJar</a></body></html>";
  server.send(200, "text/html", content);
}

void handleWiFi(){
  Serial.println("Enter WiFiCon");
  String header;
  if (!is_authentified()){
    String header = "HTTP/1.1 301 OK\r\nLocation: /login\r\nCache-Control: no-cache\r\n\r\n";
    server.sendContent(header);
    return;
  }
  // WiFi.scanNetworks will return the number of networks found
  String content = "<html><body><H2>Select the WiFI and Provide WiFi Password</H2><br><form action='/WiFiStation' method='POST'><br>";
  int n=0;
  for (int i = 0; i < 3; ++i)
  {
  n = WiFi.scanNetworks();
  delay(5000);
  }
  Serial.println("scan done");
  if (n == 0)
    content += "<H1>No WiFi Networks Available</H1>";
  else
  {
    Serial.print(n);
    Serial.println(" networks found");
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      
      content += "<input type=\"radio\" name=\"SSIDVal\" value=\""+WiFi.SSID(i)+"\">"+WiFi.SSID(i)+"</input></p>";
      
      delay(10);
    }
  }
   content += "Password:<input type='password' name='PASSWORD' placeholder='password'><br>";
   content += "<input type='submit' name='SUBMIT' value='Submit'></form><br>";
   content += "</body></html>";
   server.send(200, "text/html", content);
}
//no need authentification
void handleNotFound(){
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
}

void setup(void){
  Serial.begin(115200);
  WiFi.disconnect();
  WiFi.mode(WIFI_AP_STA);
WiFi.softAP(ssid, password);
  Serial.println("");

 
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  server.on("/", handleRoot);
  server.on("/login", handleLogin);
  server.on("/inline", [](){
    server.send(200, "text/plain", "this works without need of authentification");
  });
   server.on("/WiFiCon", handleWiFi);
   server.on("/WiFiStation", WiFiStation);

  server.onNotFound(handleNotFound);
  //here the list of headers to be recorded
  const char * headerkeys[] = {"User-Agent","Cookie"} ;
  size_t headerkeyssize = sizeof(headerkeys)/sizeof(char*);
  //ask server to track these headers
  server.collectHeaders(headerkeys, headerkeyssize );
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
