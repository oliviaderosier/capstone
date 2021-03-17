<!DOCTYPE html>

<html>
<div style="background-image: url('golf.jpg')";>
<head>

<!-------------------------------------------LINE GRAPH CODE---------------------------------------------> 

    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);
/*-------------------------------------------GETTING VALUES FROM DATA BASE FOR GRAPH----------------------------------------*/

var m1 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
                
                 $q = "SELECT moisture FROM data where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

var m2 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
                $N = $N -1 ;
  
                 $q = "SELECT moisture FROM data where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

  var m3 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
                $N = $N -2 ;
  
                 $q = "SELECT moisture FROM data where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

var m4 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
                $N = $N -3 ;
  
                 $q = "SELECT moisture FROM data where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

var m5 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data2";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
  
                 $q = "SELECT moisture FROM data2 where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

var m6 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data2";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
                $N = $N-1;
  
                 $q = "SELECT moisture FROM data2 where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

var m7 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data2";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
                $N = $N-2;
  
                 $q = "SELECT moisture FROM data2 where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

var m8 = <?php
                $db = mysqli_connect("localhost", "root", "", "capstone");
                if ($db->connect_error)
                    {
                      die ("Connection failed: " . $db->connect_error);
  
                    }
                $q = "SELECT MAX(id) FROM data2";
                $results = $db->query($q);
                $row = mysqli_fetch_array($results);
                $N = $row[0];
                $N = $N-3;
  
                 $q = "SELECT moisture FROM data2 where id = $N";
                 $results = $db->query($q);
                 $row = $results->fetch_assoc();
                 $M = $row['moisture'];
                 echo $M;
  
                $db->close();
  ?>

      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Week Day', 'Hole 1', 'Hole 2'],
          ['Monday', m1, m5],
          ['Tuesday', m2, m6],
          ['Wednesday', m3, m7],
          ['Thursday', m4, m8]
        ]);

        var options = {
          title: 'Soil Moisture Level (Unitless)',
          curveType: 'function',
          legend: { position: 'bottom' }
        };

        var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));

        chart.draw(data, options);
      }
    </script>

<!-------------------------------------------BAR GRAPH CODE--------------------------------------------->

<script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
<script type="text/javascript">

  google.charts.load('current', {'packages':['bar']});
  google.charts.setOnLoadCallback(drawStuff);

/*-------------------------------------------GETTING VALUES FROM DATA BASE FOR GRAPH----------------------------------------*/

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

var hole2 = <?php

        $db = mysqli_connect("localhost", "root", "", "capstone");
        if ($db->connect_error)
            {
               die ("Connection failed: " . $db->connect_error);

            }
        $q = "SELECT * FROM data2 ORDER BY id DESC LIMIT 1";
        $results = $db->query($q);
        $row = $results->fetch_assoc();
        $hole2= $row["waterUsed"];

        echo $hole2; 

        $db->close();
?>

  function drawStuff() {
    var data = new google.visualization.arrayToDataTable([
      ['Hole Number', 'Amount of Water Used to Date (L)'],
      ["Hole 1", hole1],
      ["Hole 2", hole2],
      ["Hole 3", 12],
      ["Hole 4", 10],
      ["Hole 5", 13],
      ["Hole 6", 19],
      ["Hole 7", 21],
      ["Hole 8", 13],
      ["Hole 9", 9]
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

<!---------------------------------------------------REFRESH CODE--------------------------------------------->

<meta http-equiv="refresh" content="900">

</head>

<!-------------------------------------------------START OF HTML CODE-------------------------------------------------->

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
<p>&#x1F325 Feels Like:  <span id="feelsLike"></span>&#176C</p> 

<!-------------------------------------------PHP SQL DATABASE CONNECTION AND DATA ACCESS FOR SOIL TEMP--------------------------------------------->

<?php

  $db = mysqli_connect("localhost", "root", "", "capstone");
  if ($db->connect_error)
  {
      die ("Connection failed: " . $db->connect_error);

  }

  $q = "SELECT * FROM data ORDER BY id DESC LIMIT 1";
  $results = $db->query($q);

  $temp =$row['temp'];

  echo '<p> &#x1F3CC Soil Temperature: '.$temp.'&#176 C </p>';

  $db->close();
?>

<p>&#x1F326 Percent Chance of Rain: <span id="rain"></span>% <p>
<p>&#x263C Time of Sunrise: <span id="rise"></span> AM </p>
<p>&#x263E Time of Sunset: <span id="set"></span> PM </p>
</div>

<div id="parameterBlock" style = "position:relative; left:800px; top:-850px; width: 250px;">
<p>Soil Salt Index (Unitless) </p>

<?php

  $db = mysqli_connect("localhost", "root", "", "capstone");
  if ($db->connect_error)
  {
      die ("Connection failed: " . $db->connect_error);

  }

  $q = "SELECT * FROM data ORDER BY id DESC LIMIT 1";
  $results = $db->query($q);

  $salt1 =$row['salt'];

  echo '<p>&#x1F3CC	Hole 1: ' .$salt1. ' </p>';

  $db->close();
?>

<?php

  $db = mysqli_connect("localhost", "root", "", "capstone");
  if ($db->connect_error)
  {
      die ("Connection failed: " . $db->connect_error);

  }

  $q = "SELECT * FROM data2 ORDER BY id DESC LIMIT 1";
  $results = $db->query($q);

  $salt2 =$row['salt'];

  echo '<p>&#x1F3CC Hole 2: ' .$salt2. ' </p>';

  $db->close();
?>

</div>

<div id="parameterBlock" style = "position:relative; left:800px; top:-800px;">
<p>Battery Life of Communication Devices </p>

<!-------------------------------------------PHP SQL DATABASE CONNECTION AND DATA ACCESS FOR BATTERY LIFE--------------------------------------------->

<?php

  $db = mysqli_connect("localhost", "root", "", "capstone");
  if ($db->connect_error)
  {
      die ("Connection failed: " . $db->connect_error);

  }

  $q = "SELECT * FROM data ORDER BY id DESC LIMIT 1";
  $results = $db->query($q);

  $battery =$row['battery'];

  echo '<p>&#x1F50B Device 1: ' .$battery. '%</p>';

  $db->close();
?>

<?php

  $db = mysqli_connect("localhost", "root", "", "capstone");
  if ($db->connect_error)
  {
      die ("Connection failed: " . $db->connect_error);

  }

  $q2 = "SELECT * FROM data2 ORDER BY id DESC LIMIT 1";
  $results = $db->query($q2);

  $battery2 =$row['battery'];

  echo '<p>&#x1F50B Device 2: ' .$battery2. '%</p>';

  $db->close();
?>

<p>&#x1F50B Device 3: 95%</p>

</div>

</div>
</body>
</html>

<!-----------------------------------------END OF HTML CODE------------------------------------------->


<!-----------------------------------------JAVA WEATHER API------------------------------------------->

<script>
function myFunction() {
fetch('http://api.openweathermap.org/data/2.5/weather?q=Regina&appid=6676b2af2b110e60dcd8e8d742d5ff8e&units=metric')
.then(response => response.json())
.then(data=>{
  
    document.getElementById("feelsLike").innerHTML =  data['main']['feels_like'];
    document.getElementById("temp").innerHTML = data['main']['temp'];

//time conversion from epoch unix time to readable time
                var riseTime = data['sys']['sunrise'] * 1000;
                var riseDate = new Date(riseTime);
                riseDate.toDateString();
                var hours = riseDate.getHours();
                var minutes = riseDate.getMinutes();

                if(minutes < 10)
                {
                  var time = hours + ":0"+ minutes;
                }
                else{
                  var time = hours + ":"+ minutes;
                }
                

                var setTime = data['sys']['sunset'] * 1000;
                var setDate = new Date(setTime);
                setDate.toDateString();
                var hours1 = setDate.getHours() - 12;
                var minutes1 = setDate.getMinutes();

                if(minutes1 < 10)
                {
                  var time1 = hours1 + ":0"+ minutes1;
                }
                else{
                  var time1 = hours1 + ":"+ minutes1;
                }
                

    document.getElementById("rise").innerHTML = time;
    document.getElementById("set").innerHTML = time1;
    })
    }
  </script>

<!-------------------------------------------JAVA CHANCE OF RAIN API--------------------------------------------->

  <script>
  fetch('http://api.worldweatheronline.com/premium/v1/weather.ashx?key=d1e8c8e0551e4b798d3190230210202&q=Regina&num_of_days=1&format=json&tp=12&mca=no')
  .then(response => response.json())
  .then(data=>{

  document.getElementById("rain").innerHTML = data['data']['weather'][0]['hourly'][1]['chanceofrain'];
  })
  </script>
  