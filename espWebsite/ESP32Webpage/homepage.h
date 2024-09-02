// To create literal strings stored in flash memory enclose your HTML code between
// F(R"=====( HTML code here )=====");
// If you have 1 reading then you probably have 2 literal strings
// If you have 2 readings then you probably have 3 literal strings etc.

String homePagePart1 = F(R"=====(
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta http-equiv="refresh" content="3">
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

.slidecontainer {
  width: 80%;
  justify-content: center;
}

.slider {
  -webkit-appearance: none;
  width: 100%;
  height: 25px;
  border-radius: 20px;
  background: #d3d3d3;
  outline: none;
  opacity: 0.7;
  -webkit-transition: .2s;
  transition: opacity .2s;
}

.slider:hover {
  opacity: 1;
}

.slider::-webkit-slider-thumb {
  -webkit-appearance: none;
  appearance: none;
  width: 25px;
  height: 25px;
  background: orange;
  cursor: pointer;
}

.slider::-moz-range-thumb {
  width: 25px;
  height: 25px;
  background: orange;
  cursor: pointer;
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

@media screen and (max-width: 1000px) {
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
        <th>Heading:</th><th>
)=====");
String homePagePart2 = F(R"=====(
</th>
      </tr>
      <tr>
        <th>Tempreture:</th><th>
)=====");
String homePagePart3 = F(R"=====(
  Celsius</th>
      </tr>
      <tr>
        <th>Humidity:</th><th>
)=====");
String homePagePart4 = F(R"=====(
%</th>
      </tr>
      <tr>
        <th>Mode:</th><th>
)=====");
String homePagePart5 = F(R"=====(
</th>
      </tr>
    </table>
  </div>
  <div id="CarView">
    <div class="flex-container">
    <div class="collision_object" style="background-color:
)=====");
String homePagePart6 = F(R"=====(
     ;"></div>
    <div class="collision_object" style="background-color:
)=====");
String homePagePart7 = F(R"=====(
;"></div>
    <div class="collision_object" style="background-color:
)=====");
String homePagePart8 = F(R"=====(
;"></div>
  </div>
    <img src="https://freesvg.org/img/car_topview.png" alt="Vehicle">
  </div>
  <div class = "flex-container" id="Controls">
    <div class="slidecontainer">
      <h2 style="padding-bottom: 5px;">Set Heading</h2>
      <input type="range" min="1" max="360" value="90" class="slider" id="myRange" oninput="fetch('sentHeadingToWebServer?button=T')">
      <h2><span id="demo"></span></h2>
      <div class="flex-container">
        <button class="button" onclick="fetch('/sentKeyPressToWebServer?button=0')">Bluetooth</button>
        <button class="button" onclick="fetch('/sentKeyPressToWebServer?button=1')">Autonomous</button>
        <button class="button" onclick="fetch('/sentKeyPressToWebServer?button=2')">Heading</button>
      </div>
    </div>
  </div>
</div> 

<script>
  var slider = document.getElementById("myRange");
  var output = document.getElementById("demo");
  output.innerHTML = slider.value;
  
  slider.oninput = function() {
    var heading = slider.value;
    output.innerHTML = this.value;
    fetch(`sentHeadingToWebServer?heading=${heading}`);
  }
  </script>


</body>
</html>
)=====");
