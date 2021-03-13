
    const axios = require('axios');

    (async _ => {
        try {
            let userpassword = "olivia.derosier@gmail.com:CAPSTONE!";
            let encodedAuth = Buffer.from(userpassword).toString('base64');

            let data = "SGVsbG8sIFdvcmxkIQ==";
    
            const body = `
                <sci_request version="1.0">
                    <send_message>
                        <targets>
                            <device id="00000000-00000000-00409DFF-FF63DD73"/>
                        </targets>
                        <rci_request version="1.1">
                            <do_command target="xbgw">
                                <send_serial addr="00:13:A2:00:41:68:0B:CA" encoding="base64">
                                    ${data}
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
    