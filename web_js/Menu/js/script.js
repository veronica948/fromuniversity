function onLoad() {
  list1 = {
	  name: "Main",
	  submenu: []
  };
  list2 = {
	  name: "list2",
	  submenu: ["l1","l2","l3"]
  };
  list3 = {
	  name: "list3",
	  submenu: ["l1","l2"]
  };
  list4 = {
	  name: "list4",
	  submenu: ["l1","l2"]
  }; 
  var mas=[list1,list2,list3,list4];
  
  var dive=document.getElementById('menu');
  var newUl=document.createElement('ul');
  newUl.id='main_menu';
  dive.appendChild(newUl);
  for(var i=0;i<mas.length;i++)
  {
	  var newLi=document.createElement('li');
	  newUl.appendChild(newLi);
	  newLi.id='title';
	  var new_a = document.createElement('a');
	  newLi.appendChild(new_a);
	  new_a.innerHTML=mas[i].name;
	  new_a.setAttribute('href',mas[i].name+'.html');
	  newLi.addEventListener( 'mouseover', show, false);
	  newLi.addEventListener( 'mouseout', hide, false);
	  var newUl_2=document.createElement('ul');
		  newUl_2.id='submenu';
		  newLi.appendChild(newUl_2);
	  for(var j=0;j<mas[i].submenu.length;j++) {
		  var newLi_2=document.createElement('li');
		  newUl_2.appendChild(newLi_2);
		  var new_a_2 = document.createElement('a');
		  newLi_2.appendChild(new_a_2);
		  new_a_2.innerHTML=mas[i].submenu[j];
		  new_a_2.setAttribute('href',mas[i].name+'_'+mas[i].submenu[j]+'.html');
	  }
  }
  function show() {
	  this.lastChild.style.display="block";
  }
  function hide() {
	  this.lastChild.style.display="none";
  }
    
  var elements = menu.getElementsByTagName('a');
	for(var i=0;i<elements.length;i++) {
		elements[i].onclick = function(event){
		 loadPage(event.target.href);
		 return false;
		};
	}
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
					
				  document.getElementById("dataKeeper").style.backgroundColor = 'violet';
				  document.getElementById("dataKeeper").style.color = 'white';
				}
			}
	  }
	};
	xmlhttp.send(null);
}
}