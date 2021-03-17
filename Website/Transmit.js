
    const axios = require('axios');

    (async _ => {
        try {

            //rain API
            let resp = await axios.get('http://api.worldweatheronline.com/premium/v1/weather.ashx?key=d1e8c8e0551e4b798d3190230210202&q=Regina&num_of_days=1&format=json&tp=12&mca=no')
            console.log(resp.data['data']['weather'][0]['hourly'][1]['chanceofrain']); 

            var rain = resp.data['data']['weather'][0]['hourly'][1]['chanceofrain'];
            
            //set time API
            let resp2 = await axios.get('http://api.openweathermap.org/data/2.5/weather?q=Regina&appid=6676b2af2b110e60dcd8e8d742d5ff8e&units=metric')
            console.log(resp2.data['sys']['sunset'] * 1000);

            //time conversion
                var setTime = resp2.data['sys']['sunset'] * 1000;
                var setDate = new Date(setTime);
                setDate.toDateString();
                var hours1 = setDate.getHours();
                var minutes1 = setDate.getMinutes();

                if(minutes1 < 10)
                {
                  var time1 = hours1 + ":0"+ minutes1;
                }
                else{
                  var time1 = hours1 + ":"+ minutes1;
                }
            console.log(time1);

            let currentDate = new Date();
            let hours = currentDate.getHours() 
            let minutes = currentDate.getMinutes();
            console.log(hours + ':' + minutes);

            var sunset;

            if (hours< hours1)
            {
             sunset = 0;
            }

            else if (hours = hours1)
            {
                if(minutes < minutes1)
                {
                 sunset = 0;
                }
                
                if(minutes > minutes1)
                {
                sunset = 1;
                }
            }
        
            let userpassword = "olivia.derosier@gmail.com:CAPSTONE!";
            let encodedAuth = Buffer.from(userpassword).toString('base64');
            
            //encoding data
            let data = rain + "X" + sunset;
            
            console.log(data);
            
            let encodedData = Buffer.from(data).toString('base64');

            console.log(encodedData);
    
            const body = `
                <sci_request version="1.0">
                    <send_message>
                        <targets>
                            <device id="00000000-00000000-00409DFF-FF63DD73"/>
                        </targets>
                        <rci_request version="1.1">
                            <do_command target="xbgw">
                                <send_serial addr="00:13:A2:00:41:68:0B:D5" encoding="base64">
                                    ${encodedData}
                                </send_serial>
                            </do_command>
                        </rci_request>
                    </send_message>
                </sci_request>
            `;
    
            const headers = {
                "Authorization": `Basic ${encodedAuth}`,
                "Content-Type": "text/xml"
            }
    
            let response = await axios.post("https://remotemanager.digi.com/ws/sci", body, { headers });
    
            console.log(response.data);
        } catch (err) {
            console.log(err)
        }
    
    })();
    