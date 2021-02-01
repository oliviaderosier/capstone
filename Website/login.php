<!DOCTYPE HTML>

<html>
<head>
<link rel="stylesheet" href="style.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
<style>
footer {
  text-align: center;
  padding: 3px;
  background-color:grey;
  color: white;
  position: relative;
 bottom:-200px;
}

body{
background-image: url('golf.jpg');
}
</style>
</head>
<body>

<div id="bulk">
<div id="header">
<h1 class="title">Automated Irrigation System Dashboard</h1>
<h2 class="subtitle">University of Regina Capstone Project 2020</h2>
</div>

<div id="logo2">
<img src="UofRLogo.png" alt="U of R logo" width="100" height="100">
</div>

<div class="form-group">
<form action="login.php" method="post">
    <label for="usr">Name:</label>
    <input type="text" class="form-control" id="usr" name = "username">
  </div>
  <div class="form-group">
    <label for="pwd">Password:</label>
    <input type="password" class="form-control" id="pwd" name= "password">
</div> <div id="butt">
<input type ="submit">
</div>
<input type = "hidden" name="submitted" value = "1">
</form>

<footer>
   <p> Olivia DeRosier, Austin Waldon, Colton Moore</p>
</footer>

</div>

<?php
$validate = true;

if (isset($_POST["submitted"]) && $_POST["submitted"])
{
    $username = trim($_POST["username"]);
    $password = trim($_POST["password"]);
    
    $db = new mysqli("localhost", "root", "", "capstone");
    if ($db->connect_error)
    {
        die ("Connection failed: " . $db->connect_error);

    }
 
    $q = "SELECT * FROM login WHERE username = '$username'and password='$password';";
  
    $r = $db->query($q);
    $row = $r->fetch_assoc();

    if($username = $row["username"] && $password = $row["password"])
    {
        $validate = true;
        echo "true";
    }
    else
    {
       $validate =false;
       session_start();
       $_SESSION["username"] = $row["username"];
       header("Location: wrongpassword.php");
       $db->close();
       exit();
    }
   
    if($validate == true)
    {
        session_start();
        $_SESSION["username"] = $row["username"];
        header("Location: capstone.php");
        $db->close();
        exit();
    }
    else 
    {
        $error = "The username/password combination was incorrect. Login failed.";
        $db->close();
    }
}
?>
</body>
</html>
