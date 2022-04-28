const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head><meta charset="UTF-8">

<title>ĐỒ ÁN 2</title>

<style>
h1 {text-align:  center;}
p  {text-align:  center;}
div {text-align: center;}
</style>

</head>

<body>
<h1> Đồ Án 2 </h1>&nbsp;
<h2><u>Giảng viên hướng dẫn:</u> TS.Nguyễn Văn Hòa </h2>&nbsp;
<h2> <u>PHẦN I</u>: Giới thiệu tổng quát </h2>
<h2> Danh sách nhóm sinh viên thực hiện: </h2>
<h3> 1. Nguyễn Sơn Hoàng </h3>
<h3> 2. Nguyễn Chiến Thắng</h3>

<h2> <u>PHẦN II</u>: Thông Số Nhiệt Độ, Độ ẩm và Nồng độ chất trong không khí tại nơi đo </h2>

<div>
<h3>1.Nhiệt Độ :
<span id="nhietdos">0</span>°C<br>
<h3>2.Độ ẩm : 
<span id = "doams">0</span>%<br>
<h3>3.Nồng độ các hạt trong không khí :
<span  id = "nongdos" >0</span> ppm;<br>
</div>

<script>

setInterval(function() {
  getnhietdo();
  getdoam();
  getnongdo();
}, 1000); //2000mSeconds update rate

function getnhietdo() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("nhietdos").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "docnhietdo", true);
  xhttp.send();
}

function getdoam() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("doams").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "docdoam", true);
  xhttp.send();
}

function getnongdo() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("nongdos").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "docnongdo", true);
  xhttp.send();
}

</script>

<h2> <u>PHẦN III</u>: Điều Khiển Cơ Cấu Chấp Hành <h2>

<div>
<h3> Điều khiển xe di chuyển </h3>

<p><button 
id ="tien" style=background-color:#BCEE68;width:90px;height:80px;border-radius:10px;
onclick = "statusforward()"><b>Forward</b></button></p>

<button 
id ="trai" style=background-color:#BCEE68;width:90px;height:80px;border-radius:10px;
onclick = "statusleft()"><b>Left</b></button>

<button 
id ="dung" style=background-color:#FF6A6A;width:90px;height:80px;border-radius:10px;
onclick = "statusstop()"><b>Stop</b></button>

<button 
id ="phai" style=background-color:#BCEE68;width:90px;height:80px;border-radius:10px;
onclick = "statusright()"><b>Right</b></button>

<p><button 
id ="lui" style=background-color:#BCEE68;width:90px;height:80px;border-radius:10px;
onclick = "statusback()"><b>Back</b></button></p>

<h3> Bật/Tắt Đèn Led </h3>
<button 
id = "led" style=background-color:#BCEE68;width:140px;height:40px 
onclick = "statusled()"><b>Press here</b></button>

</div>
<script>

// Control Motor Go Ahead
// *************************************************************************************************************************************************************************
function goforward() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("tien").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "forward", true);
  xhttp.send();
}

function gostop1() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("tien").innerHTML = "Stop Ahead";
    }
  };
  xhttp.open("GET", "stop", true);
  xhttp.send();
}
var j = 0;
function statusforward(){
  j = j+1;
  if(j%2 ==1){
    goforward();
  }
  if(j%2 == 0){
    gostop1();
  }
}

// Control Motor Go Back
// *************************************************************************************************************************************************************************
function goback() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lui").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "back", true);
  xhttp.send();
}

function gostop2() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("lui").innerHTML = "Stop Back";
    }
  };
  xhttp.open("GET", "stop", true);
  xhttp.send();
}
var k = 0;
function statusback(){
  k = k+1;
  if(k%2 ==1){
    goback();
  }
  if(k%2 == 0){
    gostop2();
  }
}

// Control Motor Go Left
// *************************************************************************************************************************************************************************

function goleft() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("trai").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "left", true);
  xhttp.send();
}

function gostop3() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("trai").innerHTML = "Stop Left";
    }
  };
  xhttp.open("GET", "stop", true);
  xhttp.send();
}
var h = 0;
function statusleft(){
  h = h+1;
  if(h%2 ==1){
    goleft();
  }
  if(h%2 == 0){
    gostop3();
  }
}

// Control Motor Go Right
// *************************************************************************************************************************************************************************

function goright() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("phai").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "right", true);
  xhttp.send();
}

function gostop4() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("phai").innerHTML = "Stop Right";
    }
  };
  xhttp.open("GET", "stop", true);
  xhttp.send();
}
var s = 0;
function statusright(){
  s = s+1;
  if(s%2 ==1){
    goright();
  }
  if(s%2 == 0){
    gostop4();
  }
}

// Control Motor Go Stop
// *************************************************************************************************************************************************************************

function gostop() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("dung").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "stop", true);
  xhttp.send();
}

function gostop5() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("dung").innerHTML = "Stop Motor";
    }
  };
  xhttp.open("GET", "stop", true);
  xhttp.send();
}
var x = 0;
function statusstop(){
  x = x+1;
  if(x%2 ==1){
    gostop();
  }
  if(x%2 == 0){
    gostop5();
  }
}

// Control LED ON/OFF
// *************************************************************************************************************************************************************************
function ledon() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("led").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "ledon", true);
  xhttp.send();
}

function ledoff() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("led").innerHTML = this.responseText;
    }
  };
  xhttp.open("GET", "ledoff", true);
  xhttp.send();
}
var i = 0;
 function statusled(){
  i = i+1;
  if(i%2 ==1){
    ledon();
  }
  if(i%2 == 0){
    ledoff();
  }
}

</script>
</body>
</html>


)=====";
