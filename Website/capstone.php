<!DOCTYPE html>
<html>
<div style="background-image: url('golf.jpg')";>
<head>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);

var m1 = <?php

              $db = mysqli_connect("localhost", "root", "", "capstone");
              if ($db->connect_error)
                  {
                    die ("Connection failed: " . $db->connect_error);

                  }
              $q = "SELECT * FROM data";
              $results = $db->query($q);
              $row = $results->fetch_assoc();
              $m1= $row["moisture"];

              echo $m1; 

              $db->close();
?>

var s1 = <?php

              $db = mysqli_connect("localhost", "root", "", "capstone");
              if ($db->connect_error)
                  {
                    die ("Connection failed: " . $db->connect_error);

                  }
              $q = "SELECT * FROM data";
              $results = $db->query($q);
              $row = $results->fetch_assoc();
              $s1= $row["salt"];

              echo $s1; 

              $db->close();
?>


      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Year', 'Moisture Level', 'Salinity Level'],
          ['Monday',  m1, s1],
          ['Tuesday',  200,      460],
          ['Wednesday',  660,       1120],
          ['Thursday',  1030,      540]
        ]);

        var options = {
          title: 'Soil Moisture and Salinity Levels in PPM',
          curveType: 'function',
          legend: { position: 'bottom' }
        };

        var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));

        chart.draw(data, options);
      }
    </script>

<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">

  google.charts.load('current', {'packages':['bar']});
  google.charts.setOnLoadCallback(drawStuff);

var hole1 = <?php

        $db = mysqli_connect("localhost", "root", "", "capstone");
        if ($db->connect_error)
            {
               die ("Connection failed: " . $db->connect_error);

            }
        $q = "SELECT * FROM data ORDER BY id DESC LIMIT 1";
        $results = $db->query($q);
        $row = $results->fetch_assoc();
        $hole1= $row["waterUsed"];

        echo $hole1; 

        $db->close();
?>

  function drawStuff() {
    var data = new google.visualization.arrayToDataTable([
      ['Hole Number', 'Amount of Water Used to Date (L)'],
      ["Hole 1", hole1],
      ["Hole 2", 31],
      ["Hole 3", 12],
      ["Hole 4", 10],
      ["Hole 5", 13],
      ["Hole 6", 19],
      ["Hole 7", 21],
      ["Hole 8", 13],
      ["Hole 9", 43]
    ]);
   
    var options = {
      title: 'Amount of Water Used to Date',
      width: 700,
      legend: { position: 'none' },
      chart: { title: 'Amount of Water Used to Date',
               subtitle: 'In Liters'}, 
      bars: 'horizontal', // Required for Material Bar Charts.
      axes: {
        x: {
          0: { side: 'top', label: 'Liters'} // Top x-axis.
        }
      },
      bar: { groupWidth: "90%" }
    };

    

    var chart = new google.charts.Bar(document.getElementById('bargraph'));
    chart.draw(data, options);
  };

  
</script>

<link rel="stylesheet" href="style.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">

</head>

<body onload = "myFunction()">
<div id="bulk">
<div id="header">
<h1 class="title">Automated Irrigation System Dashboard</h1>
<h2 class="subtitle">University of Regina Capstone Project 2020</h2>
</div>

<div id="curve_chart" class="chart"></div>
<div id="bargraph"></div>

<div id="logo">
<img src="UofRLogo.png" alt="U of R logo" width="100" height="100">
</div>

<div id="parameterBlock">
<p>&#x1F321 Ambient Temperature:  <span id="temp"></span>&#176C</p>
<p>&#x1F325 Feels Like:  <span id="feelsLike"></span>&#176C, <span id="desc"></span>. </p>
<p> &#x1F3CC Soil Temperature: 30 &#176 C </p>
<p>&#x1F326 Percent Chance of Rain: 10% <p>
<p>&#x263C Time of Sunrise: <span id="rise"></span> AM </p>
<p>&#x263E Time of Sunset: <span id="set"></span> PM </p>

</div>
</div>
</div>
</div>

</body>
</html>

<script>
function myFunction() {
fetch('http://api.openweathermap.org/data/2.5/weather?q=Regina&appid=6676b2af2b110e60dcd8e8d742d5ff8e&units=metric')
.then(response => response.json())
.then(data=>{
  
    document.getElementById("desc").innerHTML = data['weather'][0]['description'];
    document.getElementById("feelsLike").innerHTML =  data['main']['feels_like'];
    document.getElementById("temp").innerHTML = data['main']['temp'];

    var riseTime = data['sys']['sunrise'] * 1000;
    var riseDate = new Date(riseTime);
    riseDate.toDateString();
    var hours = riseDate.getHours();
    var minutes = riseDate.getMinutes();
    var time = hours + ":"+ minutes;

    var setTime = data['sys']['sunset'] * 1000;
    var setDate = new Date(setTime);
    setDate.toDateString();
    var hours1 = setDate.getHours() - 12;
    var minutes1 = setDate.getMinutes();
    var time1 = hours1 + ":"+ minutes1;

    document.getElementById("rise").innerHTML = time;
    document.getElementById("set").innerHTML = time1;
    })
    }
  </script>

  <?php

  $db = mysqli_connect("localhost", "root", "", "capstone");
  if ($db->connect_error)
  {
      die ("Connection failed: " . $db->connect_error);

  }

  $q = "SELECT * FROM data";
  $results = $db->query($q);

  if($results->num_rows > 0){
    while($row = $results->fetch_assoc()){
      echo "time: ".$row['dataDate']. "- moisture: ".$row['moisture']."- salt index: ".$row['salt']."- temperature: ".$row['temp']."- water used: ".$row['waterUsed']. "- battery life: ".$row['battery']."<br>";
  }
  }

  else {
  echo "0 results";
  }

  $db->close();
  ?>