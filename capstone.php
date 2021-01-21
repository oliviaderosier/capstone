<!DOCTYPE html>
<html>
<div style="background-image: url('golf.jpg')";>
<head>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);

      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Year', 'Moisture Level', 'Salinity Level'],
          ['Monday',  1000,      400],
          ['Tuesday',  1170,      460],
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

  function drawStuff() {
    var data = new google.visualization.arrayToDataTable([
      ['Hole Number', 'Amount of Water Used to Date (L)'],
      ["Hole 1", 44],
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

<body>

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
<div class="panel-body">&#x1F321 Ambient Temperature: 25 &#176 C </div>
<div class="panel-body">&#x1F3CC Soil Temperature: 30 &#176 C </div>
<div class="panel-body">&#x1F326 Percent Chance of Rain: 10% </div>
<div class="panel-body">&#x23F1 Time of Sunset: 10:03 PM </div>
</div>
</div>
</div>


</body>
</html>
