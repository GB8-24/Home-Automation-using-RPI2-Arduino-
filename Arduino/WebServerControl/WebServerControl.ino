/*Web Server
 A simple web server that shows the value of the analog input pins.
 using an Arduino Wiznet Ethernet shield. 
  Circuit:
 * Ethernet shield attached to pins 10, 11, 12, 13
 * Analog inputs attached to pins A0 through A5 (optional)
 */
//Created by Gaurav Bose.
#include <SPI.h>
#include <Ethernet.h>

// Enter a MAC address and IP address for your controller below.
// The IP address will be dependent on your local network:
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0x2D };


byte gateway[] = { 192, 168, 0, 1 }; //               <------- PUT YOUR ROUTERS IP Address to which your shield is connected Here
byte subnet[] = { 255, 255, 255, 0 }; //                <------- It will be as it is in most of the cases
IPAddress ip(192,168,0,199);

// Initialize the Ethernet server library
// with the IP address and port you want to use 
// (port 80 is default for HTTP):
EthernetServer server(80);


#define RELAY_CH1  2
#define RELAY_CH2  3
#define RELAY_CH3  4
#define RELAY_CH4  5
#define RELAY_CH5  6
#define RELAY_CH6  7
#define RELAY_CH7  8
#define RELAY_CH8  9

String readString;

void setup() {
  
  
        pinMode(RELAY_CH1, OUTPUT); 
 	digitalWrite(RELAY_CH1, LOW);  // switch on LED1
 
        pinMode(RELAY_CH2, OUTPUT); 
 	digitalWrite(RELAY_CH2, LOW);  // switch on LED2
 
        pinMode(RELAY_CH3, OUTPUT); 
 	digitalWrite(RELAY_CH3, LOW);  // switch on LED3
 
        pinMode(RELAY_CH4, OUTPUT); 
 	digitalWrite(RELAY_CH4, LOW);  // switch on LED4
 
        pinMode(RELAY_CH5, OUTPUT); 
 	digitalWrite(RELAY_CH5, LOW);  // switch on LED5
 
        pinMode(RELAY_CH6, OUTPUT); 
 	digitalWrite(RELAY_CH6, LOW);  // switch on LED6
 
        pinMode(RELAY_CH7, OUTPUT); 
 	digitalWrite(RELAY_CH7, LOW);  // switch on LED7
 
        pinMode(RELAY_CH8, OUTPUT); 
 	digitalWrite(RELAY_CH8, LOW);  // switch on LED8
  
  
  
 // Open serial communications and wait for port to open:
  Serial.begin(9600);
   while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  // start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP()); 
  
}


void loop() {
  // listen for incoming clients
  EthernetClient client = server.available();
  
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
           
      if (client.available()) {
        
        char c = client.read();
        
        if (readString.length() < 100) {
          //store characters to string
          readString += c;			//Serial.print(c);
        }
        
        Serial.write(c);
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");  // the connection will be closed after completion of the response
	  client.println("Refresh: 5");  // refresh the page automatically every 5 sec
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          
          client.println("<HEAD>");
          client.println("<meta name='apple-mobile-web-app-capable' content='yes' />");
          client.println("<meta name='apple-mobile-web-app-status-bar-style' content='black-translucent' />");
          //client.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"http://www.digital2u.net/autohome.css\" />");
          //client.println("<meta http-equiv=\"refresh\" content=\"5;url=http://192.168.0.199/\"/>" );
          client.println("</HEAD>");
          
          client.println("<body bgcolor=\"#D0D0D0\">");
          //client.println("<hr/>");
          //client.println("<hr/>");
          
          //client.println("<h4><center><img border=\"2\" src=\"https://lh3.googleusercontent.com/-C6BoJrRUFko/UEUFeCwkvdI/AAAAAAAAAOc/E7gcYvPV6r4/s960/Logo.jpg\" /></center></h4>");
          //client.println("<hr/>");
          //client.println("<hr/>");
                   
          client.print("<center> <p> <h1>Welcome to Arduino Home Control V0.25  </h1></p> ");
          //client.println("<br />");
          //client.println("<br />");
          
          
          // Relay Status Display
          client.println("<center>");
          
              client.println("<table border=\"5\">");
              
                  client.println("<tr>"); 
                      if (digitalRead(RELAY_CH1))
                      { 
                           client.print("<td> <p style=\"font-family:arial;color:black;font-size:26px;\">Device 1.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p> </td>");
                      }
                      else
                      {
                           client.print("<td> <p style=\"font-family:arial;color:black;font-size:26px;\">Device 1.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                      
                                  
                      if (digitalRead(RELAY_CH2))
                      {   
                           client.print("<td> <p style=\"font-family:arial;color:black;font-size:26px;\">Device 2.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p></td>");
                      }
                      else
                      {  
                          client.print("<td> <p style=\"font-family:arial;color:black;font-size:26px;\">Device 2.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                     
                      
                      if (digitalRead(RELAY_CH3))
                      { 
                           client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 3.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p></td>");
                      }
                      else
                      {
                          client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 3.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                     
                     
                      if (digitalRead(RELAY_CH4))
                      { 
                         client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 4.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p></td>");
                      }
                      else
                      {
                          client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 4.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                     
                     
                      if (digitalRead(RELAY_CH5))
                      { 
                           client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 5.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p></td>");
                      }
                      else
                      {
                          client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 5.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                     
                             
                      if (digitalRead(RELAY_CH6))
                      {   
                           client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 6.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p></td>");
                      }
                      else
                      {  
                          client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 6.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                      
                          
                      if (digitalRead(RELAY_CH7))
                      { 
                           client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 7.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p></td>");
                      }
                      else
                      {
                          client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 7.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                     
                     
                      if (digitalRead(RELAY_CH8))
                      { 
                         client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 8.</p><p style=\"font-family:arial;color:green;font-size:35px;\">ON</p></td>");
                      }
                      else
                      {
                          client.print("<td><p style=\"font-family:arial;color:black;font-size:26px;\">Device 8.</p><p style=\"font-family:arial;color:red;font-size:35px;\">OFF</p></td>");
                      }
                                         
                 client.println("</tr>");                   
              client.println("</table>"); 
              
          client.println("</center>");
          client.println("<br />");

          
          
         /* Relay Control Code  */                
        
          client.println("<a href=\"/?relay1on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\"; color:red ;>Device 1 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay1off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 1 OFF </font> </button> </a> <br />"); 
          client.println("<br />");
          

          client.println("<a href=\"/?relay2on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 2 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay2off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 2 OFF </font> </button> </a> <br />"); 
          client.println("<br />");
          
          
          client.println("<a href=\"/?relay3on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 3 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay3off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 3 OFF </font> </button> </a> <br />"); 
          client.println("<br />");
          

          client.println("<a href=\"/?relay4on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 4 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay4off\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 4 OFF </font> </button> </a> <br />"); 
          client.println("<br />");
         
          
          client.println("<a href=\"/?relay5on\"\"> <button style=\"width:360px;height:120px\"> <font size=\"7\">Device 5 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay5off\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Device 5 OFF </font> </button> </a> <br />"); 
          client.println("<br />");        


          client.println("<a href=\"/?relay6on\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Device 6 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay6off\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Device 6 OFF </font> </button> </a> <br />"); 
          client.println("<br />");
         
          
          client.println("<a href=\"/?relay7on\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Device 7 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay7off\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Device 7 OFF </font> </button> </a> <br />");  
          client.println("<br />");
          

          client.println("<a href=\"/?relay8on\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Device 8 ON </font> </button> </a> ");
          client.println("<a href=\"/?relay8off\"\"><button style=\"width:360px;height:120px\"> <font size=\"7\">Device 8 OFF </font> </button> </a> <br />"); 
          client.println("<br />");
         
          
          // control arduino pin via ethernet Start //

        if(readString.indexOf("?relay1on") >0)//checks for on
        {
            digitalWrite(RELAY_CH1, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay1off") >0)//checks for off
          {
            digitalWrite(RELAY_CH1, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
         if(readString.indexOf("?relay2on") >0)//checks for on
        {
            digitalWrite(RELAY_CH2, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay2off") >0)//checks for off
          {
            digitalWrite(RELAY_CH2, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
          if(readString.indexOf("?relay3on") >0)//checks for on
        {
            digitalWrite(RELAY_CH3, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay3off") >0)//checks for off
          {
            digitalWrite(RELAY_CH3, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
        
        if(readString.indexOf("?relay4on") >0)//checks for on
        {
            digitalWrite(RELAY_CH4, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay4off") >0)//checks for off
          {
            digitalWrite(RELAY_CH4, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
        
         if(readString.indexOf("?relay5on") >0)//checks for on
        {
            digitalWrite(RELAY_CH5, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay5off") >0)//checks for off
          {
            digitalWrite(RELAY_CH5, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
         if(readString.indexOf("?relay6on") >0)//checks for on
        {
            digitalWrite(RELAY_CH6, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay6off") >0)//checks for off
          {
            digitalWrite(RELAY_CH6, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
          
          
          if(readString.indexOf("?relay7on") >0)//checks for on
        {
            digitalWrite(RELAY_CH7, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay7off") >0)//checks for off
          {
            digitalWrite(RELAY_CH7, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
        
        if(readString.indexOf("?relay8on") >0)//checks for on
        {
            digitalWrite(RELAY_CH8, HIGH);    // set pin 4 high
            //Serial.println("Led On");
			
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/on.png' />");
            //client.println("Light 1 Is On");
            client.println("<br />");
	}
        else{
          if(readString.indexOf("?relay8off") >0)//checks for off
          {
            digitalWrite(RELAY_CH8, LOW);    // set pin 4 low
            //Serial.println("Led Off");
            client.println("<link rel='apple-touch-icon' href='http://chriscosma.co.cc/off.png' />");

	    //client.println("Light 1 Is Off");
            client.println("<br />");
          }
        }
                    
        // INPUT
          
          
          // output the value of each analog input pin
          //for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
          //  int sensorReading = analogRead(analogChannel);
          //  client.print("analog input ");
          //  client.print(analogChannel);
          //  client.print(" is ");
          //  client.print(sensorReading);
          //  client.println("<br />");       
          //}
                   
          client.println("<hr> <p> By <a href=\"http://androidcontrol.blogspot.com\"></p><p style=\"font-family:arial;color:blue;font-size:20px;\">Android Control Blogspot</p></a>");
                  
           readString="";
           client.println("</body>");         
           client.println("</html>");
         
          break;
        }// if ( c == \n )
        
        
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
                
      }
    }
    
    // give the web browser time to receive the data   
    delay(1);
    //client.println("<meta http-equiv=\"refresh\" content=\"10;url=http://192.168.0.199/\"/>" );
    
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
    
  }//if(Client)
  
}//Loop

