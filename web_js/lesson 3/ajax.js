function onLoad() {
	var menu = document.getElementById('menu');
	
	var elements = menu.getElementsByTagName('a');
	for(var i=0;i<elements.length;i++) {
		elements[i].onclick = function(event){
		 loadPage(event.target.href);
		 return false;
		};
	}
	
	document.getElementById("dataKeeper").onclick = function () {
				  //alert(document.getElementById("dataKeeper"));
				
				  document.getElementById("dataKeeper").style.backgroundColor = 'yellow';
				}
}

//функция для получения объекта XML HTTP запроса
function getXmlHttp(){
	  var xmlhttp;
	  try {
		xmlhttp = new ActiveXObject("Msxml2.XMLHTTP");
	  } catch (e) {
		try {
		  xmlhttp = new ActiveXObject("Microsoft.XMLHTTP");
		} catch (E) {
		  xmlhttp = false;
		}
	  }
	  if (!xmlhttp && typeof XMLHttpRequest!='undefined') {
		xmlhttp = new XMLHttpRequest();
	  }
	  return xmlhttp;
}

function loadPage(page) {
	var xmlhttp = getXmlHttp();
	xmlhttp.open('GET', page, true);
	xmlhttp.onreadystatechange = function() {
	  if (xmlhttp.readyState == 4) {
		 if(xmlhttp.status == 200) {
				document.getElementById("content").innerHTML = xmlhttp.responseText;
				
				document.getElementById("dataKeeper").onclick = function () {
				  //alert(document.getElementById("dataKeeper"));
				
				  document.getElementById("dataKeeper").style.backgroundColor = 'yellow';
				}
			}
	  }
	};
	xmlhttp.send(null);
}
