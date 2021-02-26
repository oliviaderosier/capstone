package capstone;

import java.util.*;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Scanner;
import java.util.Base64.Encoder;

/*
* This is a stub class with a main method to run a Remote Manager web service.
*/

public class WebServiceRequest {
 
/** Run the web service request**/
 public static void main(String[] args) { 
    try {
         // Create url to Remote Manager server for a given web service request
         URL url = new URL("https://remotemanager.digi.com/ws/sci");
         HttpURLConnection conn = (HttpURLConnection)url.openConnection();
         conn.setDoOutput(true);
         conn.setRequestMethod("POST"); 

         String userpassword = "olivia.derosier@gmail.com:CAPSTONE!";
         String encodedAuthorization = Base64.getEncoder().encodeToString(userpassword.getBytes());

         conn.setRequestProperty("Authorization", "Basic "+ encodedAuthorization);
         
         // Send data to server
         
         conn.setRequestProperty("Content-Type", "text/xml");
         OutputStreamWriter out = new OutputStreamWriter(conn.getOutputStream());

         String data = "SGVsbG8sIFdvcmxkIQ==\r\n"; // Hello, World!

         out.write("<sci_request version=\"1.0\">\r\n");
         out.write("<send_message>\r\n");
         out.write("<targets>\r\n");
         out.write("<device id=\"00000000-00000000-00409DFF-FF63DD73\"/>\r\n");
         out.write("</targets> \r\n");
         out.write("<rci_request version=\"1.1\">\r\n");
         out.write("<do_command target=\"xbgw\">\r\n");
         out.write("<send_serial addr=\"00:13:A2:00:41:68:0B:D5\" encoding=\"base64\">"); 
         out.write(data);
         out.write("</send_serial>\r\n");
         out.write("</do_command>\r\n");
         out.write("</rci_request>\r\n");
         out.write("</send_message>\r\n");
         out.write("</sci_request>\r\n");

         // out.write("<sci_request version=\"1.0\">\r\n");
         // out.write("<send_message>\r\n");
         // out.write("<targets>\r\n");
         // out.write("<device id=\"00000000-00000000-00409DFF-FF63DD73\"/>\r\n");
         // out.write("</targets> \r\n");
         // out.write("<rci_request version=\"1.1\">\r\n");
         // out.write("<do_command target=\"xbgw\"/>\r\n");
         // out.write("<send_serial addr=\"00:13:A2:00:41:68:0B:D5\" encoding=\"base64\">"");
         // out.write("SGVsbG8sIFdvcmxkIQ==\r\n");
         // out.write("</send_serial>\r\n");
         // out.write("</do_command>\r\n");
         // out.write("</rci_request>\r\n");
         // out.write("</send_message>\r\n");
         // out.write("</sci_request>\r\n");
      
         out.close();

         // Get input stream from response and convert to String
         conn.disconnect();
         conn.setDoInput(true);
         InputStream is = conn.getInputStream();
         Scanner isScanner = new Scanner(is);
         StringBuffer buf = new StringBuffer();
         while(isScanner.hasNextLine()) { 
            buf.append(isScanner.nextLine() +"\n");
         }

         // Output response to standard out
         String responseContent = buf.toString();
         System.out.println(responseContent);
    
      } catch (IOException e) { 
        // Print any exceptions that occur
        e.printStackTrace();
    }
    
 }
}