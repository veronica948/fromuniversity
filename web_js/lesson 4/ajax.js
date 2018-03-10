$( document ).ready(onLoad);

function onLoad() {
	//var menu = document.getElementById('menu');
	
	//var elements = menu.getElementsByTagName('a');
	/*var elements = $("#menu a");
	for(var i=0;i<elements.length;i++) {
		elements[i].onclick = function(event){
		 loadPage(event.target.href);
		 return false;
		};
	}*/
	
	$("#menu a").bind("click",function() {
				 loadPage($(this).attr("href"));
				 return false;
			});
	
	
/*	document.getElementById("dataKeeper").onclick = function () {
				  //alert(document.getElementById("dataKeeper"));
				
				  document.getElementById("dataKeeper").style.backgroundColor = 'yellow';
				}
	*/
	
	$("#dataKeeper").click(function() {
			$(this).css("background-color","yellow");
		});
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
	/*var xmlhttp = getXmlHttp();
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
	xmlhttp.send(null);*/
	
	// Using the core $.ajax() method
$.ajax({
    // the URL for the request
    url: page,
 
    // the data to send (will be converted to a query string)
    //data: {
//        id: 123
//    },
 
    // whether this is a POST or GET request
    type: "GET",
 
    // the type of data we expect back
    //dataType : "json",
 
    // code to run if the request succeeds;
    // the response is passed to the function
    success: function( html ) {
        $("#content").html( html );
		onLoad();
    },
 
    // code to run if the request fails; the raw request and
    // status codes are passed to the function
    error: function( xhr, status ) {
        console.log( "Sorry, there was a problem!" );
    },
 
    // code to run regardless of success or failure
    complete: function( xhr, status ) {
        console.log( "The request is complete!" );
    }
});
}
