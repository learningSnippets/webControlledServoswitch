const char web_page[] PROGMEM = R"=====(

<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <style>
        .title{
            text-align: center;
        }
        .buttons-div{
            text-align: center;
        }
        .button{
            width: 120px;
            height: 60px;
            margin: 0 30px;
            font-size: 30px;
            border-radius: 20px;
        }
        .onbtn{
            background-color: yellowgreen;
        }
        .offbtn{
            background-color: red;
        }
        .button:active{
            background-color: black;
            color: white;
        }
    </style>
  </head>
  
  <body>
    <h1 class="title">Learning Snippets - web controlled servo</h1>
    <div class="buttons-div">
        <button class="button onbtn" onclick="sendData2(3)">ON</button>
        <button class="button offbtn" onclick="sendData2(4)">OFF</button>
    </div>
    
    <script>
        function sendData2(StatusSer1) { 
        var xhttp = new XMLHttpRequest();
        xhttp.open("GET", "setSER1?;SERstate1=" + StatusSer1, true);   
        xhttp.send();
        }
    </script>
     
  </body>

</html>
)=====";
