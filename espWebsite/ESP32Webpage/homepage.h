// To create literal strings stored in flash memory enclose your HTML code between 
// F(R"=====( HTML code here )=====");
// If you have 1 reading then you probably have 2 literal strings
// If you have 2 readings then you probably have 3 literal strings etc.

String homePagePart1 = F(R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Autonomous Vehicle</title>
  <style>
    * {
      box-sizing: border-box;
    }

    body {
      margin: 0;
      padding: 0;
      background-color: rgb(4, 75, 138);
      font-family: 'Gill Sans', 'Gill Sans MT', Calibri, 'Trebuchet MS', sans-serif;
      color: white;
      text-align: center;
    }

    h1 {
      font-size: 60px;
    }

    h2 {
      color: rgb(255, 145, 0);
      font-size: 25px;
      margin-bottom: 30px;
    }

    #Dashboard {
      display: flex;
      flex-wrap: wrap;
      justify-content: space-around;
      padding: 20px;
    }

    #Telemetry, #CarView, #Controls {
      flex: 1 1 30%; /* Grow to fill space, but do not shrink below 30% of the parent container */
      margin: 10px;
    }

    .controlSlider{
      rotate: 90deg;
      margin-top: 50px;
      margin-bottom: 70px;
    }

    .button{
        width: 20%;
    }
    .button img {
    width: 100%;
    height: auto;
    }

    #CarView {
      display: flex;
      flex-direction: column;
      align-items: center;
    }

    .collision_row {
      display: flex;
      justify-content: center;
      margin-bottom: 10px;
    }

    .collision_object {
      width: 80px;
      height: 30px;
      background-color: red;
      border-radius: 20px;
      margin: 10px;
    }

    .footer {
      display: flex;
      justify-content: space-around;
      padding: 20px;
      background-color: transparent;
    }

    .pageLink p{
      background-color: orange;
      border-radius: 20px;
      padding: 10px 20px;
      margin: 0;
    }

    @media (max-width: 700px) {
      h1 {
        font-size: 30px;
      }
      h2 {
        font-size: 15px;
      }

      #Dashboard {
        flex-direction: column;
      }
    }
  </style>
</head>
<body>

<!-- Title -->
<div class="flex-container" style="flex-direction: column;">
  <h1>Autonomous Vehicle</h1>
  <h2>Welcome to the Autonomous Vehicle Dashboard</h2>
</div> 

<!-- Main content -->
<div id="Dashboard">
  <div id="Telemetry">
    <table>
      <tr><th>Heading:</th><td>
)=====");
String homePagePart2 = F(R"=====(
</td></tr>
      <tr><th>Temperature:</th><td>
)=====");
String homePagePart3 = F(R"=====(
 Celsius</td></tr>
      <tr><th>Humidity:</th><td>
)=====");
String homePagePart4 = F(R"=====(
</td></tr>
      <tr><th>Mode:</th><td>
)=====");
String homePagePart5 = F(R"=====(
</td></tr>
    </table>
  </div>
  <div id="CarView">
    <div class="collision_row">
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
    <img src="https://freesvg.org/img/car_topview.png" alt="Vehicle" style="width: 80%;">
  </div>
  <div id="Controls">
    <h2>Set Heading</h2>
    <input type="range" min="1" max="360" value="90" class="slider" id="headingSlider" oninput="updateHeading(this.value);">
    <h2 id="headingValue">90</h2>
    <h2>Manual Control</h2>
    <input type="range" min="-255" max="255" value="0" class="controlSlider" id="speedSlider" oninput="updateSpeedLeft(this.value);">
    <input type="range" min="-255" max="255" value="0" class="controlSlider" id="speedSlider" oninput="updateSpeedRight(this.value);">
    <div class="flex-container">
        <button class="button" onclick="fetch('/sentKeyPressToWebServer?button=A')"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR6YPeSJ6scm5usZK5s6w4Yu6wKKkpyxQ5isDpwAQLuEQ&s" alt=""></button>
        <button class="button" onclick="fetch('/sentKeyPressToWebServer?button=B')"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR6YPeSJ6scm5usZK5s6w4Yu6wKKkpyxQ5isDpwAQLuEQ&s" alt=""></button>
        <button class="button" onclick="fetch('/sentKeyPressToWebServer?button=C')"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR6YPeSJ6scm5usZK5s6w4Yu6wKKkpyxQ5isDpwAQLuEQ&s" alt=""></button>
        <button class="button" onclick="fetch('/sentKeyPressToWebServer?button=D')"><img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcR6YPeSJ6scm5usZK5s6w4Yu6wKKkpyxQ5isDpwAQLuEQ&s" alt=""></button>

      </div>
  </div>
</div> 

<!-- Other page links -->
<div class="footer">
  <div class="pageLink"><p>About</p></div>
  <div class="pageLink"><p>Poster</p></div>
  <div class="pageLink"><p>Contact</p></div>
  <div class="pageLink"><p>Gallery</p></div>
</div> 

<script>
  function updateHeading(heading) {
    document.getElementById("headingValue").textContent = heading;
    fetch(`sentHeadingToWebServer?value=${heading}`);
  }

  function updateSpeedLeft(speedL) {
    document.getElementById("speedValueL").textContent = speedL;
    fetch(`sentSpeedLeftToWebServer?value=${speedL}`);
  }

  function updateSpeedRight(speedR) {
    document.getElementById("speedValueR").textContent = speedR;
    fetch(`sentSpeedRightToWebServer?value=${speedR}`);
  }
</script>


</body>
</html>
)=====");