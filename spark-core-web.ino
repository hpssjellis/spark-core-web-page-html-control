int temp = 0;

void setup() {
  pinMode(D7, OUTPUT);
  pinMode(A0, INPUT);
  Spark.function("myTurnOn", turnOn);
  Spark.function("myTurnOff", turnOff);
}

void loop() {
   // nothing here
}

int turnOn(String args) {
  digitalWrite(D7, HIGH);
  return 1;
}

int turnOff(String args) {
  digitalWrite(D7, LOW);
  return 1;
}



/*

//Hi Mike. I put the html code here so you can see it
// possibly running on 
// https://jer-http-spark-dec12-jerteach.c9.io/www/ajaxForm2.html
// or
// https://jer-http-spark-dec12-jerteach.c9.io/www/


<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8" />

<title>AJAX Post form demo</title>
<script type="text/javascript">
<!--
var loadingmessage = 'Processing...';
function setAjax(){
   var xmlHttp;
   try{
      xmlHttp=new XMLHttpRequest(); // Firefox, Opera 8.0+, Safari
      return xmlHttp;
   }
   catch (e){
      try{
         xmlHttp=new ActiveXObject("Msxml2.XMLHTTP"); // Internet Explorer
         return xmlHttp;
      }
      catch (e){
         try{
            xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
            return xmlHttp;
         }
         catch (e){
            alert("Your browser does not support AJAX!");
            return false;
         }
     }
   }
}
function myAjax(f, url, myDivToChange) {
   var poststr = getFormValues(f);
    postData(url, poststr, myDivToChange);
}
function postData(url, parameters, myDivToChange2){
   var xmlHttp = setAjax();
   xmlHttp.onreadystatechange =  function(){
      if(xmlHttp.readyState > 0 && xmlHttp.readyState < 4){
          document.getElementById(myDivToChange2).innerHTML=loadingmessage;
      }
      if (xmlHttp.readyState == 4) {
             // this is where the magic occcurs
         document.getElementById(myDivToChange2).innerHTML=xmlHttp.responseText+' data sent was '+parameters;
      }
   }
   xmlHttp.open("POST", url, true);
   xmlHttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
   xmlHttp.send(parameters);
}
function getFormValues(fobj){
   var str = "";
   var valueArr = null;
   var val = "";
   var cmd = "";
   for(var i = 0;i < fobj.elements.length;i++){
      switch(fobj.elements[i].type){
         case "text":
            str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
            break;
         case "textarea":
            str += fobj.elements[i].name +"=" + escape(fobj.elements[i].value) + "&";
            break;
         case "select-one":
             str += fobj.elements[i].name +"=" + fobj.elements[i].options[fobj.elements[i].selectedIndex].value + "&";
             break;
     }
   }
   str = str.substr(0,(str.length - 1));
   return str;
}
//--></script>






</head>

<body onload="document.all.myForm.myName.select()">




Type in the boxes to activate AJAX.<br>
<form name="myForm" method="POST" action = "https://api.spark.io/v1/devices/sparkCoreName/myTurnOn" >

Access Token: <input  name="access_token" type=text size=50 placeholder="76sdf78sd9f7sd6f87s6dfgsf76g"> 
Get this from the setting area when logged into <a href="http://spark.io">http://spark.io</a><br>

Device ID: <input id="myDeviceId" name="myCore" type=text size=50 placeholder="sparkCoreName" onchange="{
   document.myForm.action = 'https://api.spark.io/v1/devices/' + document.all.myDeviceId.value + '/' + document.all.myFunctionName.value
      // alert(document.myForm.action)
}"> 
Get this from the core area when logged in<br>
 
Function Name: <input id="myFunctionName" name="myFunction"  type=text size=50 placeholder="myTurnOn" onchange="{
    document.myForm.action = 'https://api.spark.io/v1/devices/' + document.all.myDeviceId.value + '/' + document.all.myFunctionName.value
   // alert(document.myForm.action)
 
}"> 
Get this from the firmware.ino code you flashed to your sparkcore <br>

<input type=button value=submit onClick="{myAjax(this.form, document.myForm.action, 'myDiv1')}">
<input type=button value=test onClick="{  alert(document.myForm.action)}">
</form>

<div id="myDiv1" style="color: blue;"></div>




*/
