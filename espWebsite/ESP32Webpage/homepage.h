// To create literal strings stored in flash memory enclose your HTML code between 
// F(R"=====( HTML code here )=====");
// If you have 1 reading then you probably have 2 literal strings
// If you have 2 readings then you probably have 3 literal strings etc.

String homePagePart1 = F(R"=====(
<!DOCTYPE html>
<html lang="en" > <!-- Needed for Screenreaders !-->
<head>
<!-- UTF-8 character set covers most characters in the world -->
  <meta charset="utf-8">
  <!-- Make page respond to screen size !-->
  <meta name="viewport" content="width=device-width, initial-scale=1, viewport-fit=cover">
 
<!--Include a Title. Used by Search Engines -->
<title> Temperature Reading WebServer </title>
<style>
   
   <!--choose good contrast between background and foreground colours -->
   body {       
	background-color: DodgerBlue;
	}
	.flex-Container{
        display: flex;
        flex-direction: column;
        background-color: DodgerBlue;
        align-items: center;
      }
    h1{
    font: bold;
    font-size: 40px;
    font-family: Arial;
    color: navy;
	text-align: center;
  }
  p{
    font-size: 25px;
    font-family: Arial;
    color: navy;
	text-align: center;
   }  
  th, td {
    font-size: 25px;
    padding: 8px;
    text-align: left;
    border-bottom: 1px solid #ddd;
}
</style>
</head>
	<body>
		<div class="flex-Container">
		<h1> Temperature Example Website </h1>
      
		<p>Welcome to my website displaying the temperature in ATU</p>
    
		<table>
        <tr>
          <th>Sensor</th>
          <th>Value</th>
          <th>Unit</th>
        </tr>
        <tr>
          <td>Temperature</td>
          <td>
           )=====");
String homePagePart2 = F(R"=====(</td>
         <td>Degree Cel</td>
        </tr>
      </table>
     </div>
	</body>
</html>)=====");

String homePagePart3 = F(R"=====(
 <html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Autonomous Vehicle</title>
</head>
<body>

  <style>
*{
    background-color: rgb(4, 75, 138);
    font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
    text-align: center;
    margin: 5px
}

p{
  background-color: transparent;
  font-size: 20px;
}
th{
  text-align: left;
  font-size: 20px;
}

.flex-container {
  display: flex;
  flex-direction: row;
  justify-content: space-around;
}

h1{
  height: 15%;
  width: 100%;
  color: rgb(255, 255, 255);
  font-size: 60px;
}

h2{
  width: 100%;
  color: rgb(255, 145, 0);
  font-size: 25px;
  padding-bottom: 60px;
}

#Dashboard{
  display: flex;
  flex-direction: row;
  justify-content: space-around;
}

#Telemetry{
 width: 20%;
}

#CarView{
  display: flex;
  flex-direction: column;
  justify-content: center;
  width: 20%;
}

#Controls{
  width: 20%;
}

.collision_object{
  width: 20%;
  padding: 2%;
  min-height: 10px;
  text-align: center;
  border-radius: 20px;
}

.footer {
  display: flex;
  flex-direction: row;
  justify-content: left;
  margin-top: 20px;
  margin-left: 7%;
}

.pageLink{
  background-color: orange;
  border-radius: 20px;
}

@media screen and (max-width: 700px) {
  #Dashboard {   
    flex-direction: column;
  }
  h1{
    font-size: 30px;
  }
  h2{
    font-size: 15px;
  }
  th{
  font-size: 10px;
}
p{
  font-size: 10px;
}

}

  </style>


<!-- Title -->
<div class = "flex-container" style="flex-direction: column;">
<h1>Autonomous Vehicle</h1>
<h2>Welcome to the Autonomous Vehicle Dashboard</h2>
</div> 

<!-- Main content -->
<div id = "Dashboard">
  <div id="Telemetry" style="text-align: left;">
    <table>
      <tr>
        <th>Heading:</th><th>50</th>
      </tr>
      <tr>
        <th>Tempreture:</th><th>22 Celsius</th>
      </tr>
      <tr>
        <th>Humidity:</th><th>10%</th>
      </tr>
      <tr>
        <th>Mode:</th><th>Autonomous</th>
      </tr>
    </table>
  </div>
  <div id="CarView">
    <div class="flex-container">
    <div class="collision_object" style="background-color: red;"></div>
    <div class="collision_object" style="background-color: red;"></div>
    <div class="collision_object" style="background-color: red;"></div>
  </div>
    <img src="https://freesvg.org/img/car_topview.png" alt="Vehicle">
  </div>
  <div class = "flex-container" id="Controls">

  </div>
</div> 

<!-- Other page links -->
<div class = "footer">
  <div class="pageLink"><p>About</p></div>
  <div class="pageLink"><p>Poster</p></div>
  <div class="pageLink"><p>Contact</p></div>
  <div class="pageLink"><p>Gallery</p></div>
</div> 




</body>
</html>
)=====");
