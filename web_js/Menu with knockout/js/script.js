$(document).ready(onLoad);

function onLoad2(){
  $("#dataKeeper").click(function() {
			$(this).css("background-color","violet"),
			$(this).css("color","white")
		});
}

function onLoad() {
	var htmlTop = document.getElementById("htmlTop");
	var model = new ViewModel();
	ko.applyBindings(model, htmlTop);
	model.loadMenuPage(model.menu()[0]);
  /*list1 = {
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
  
  $('#menu').append('<ul id=main_menu></ul>');
  
  for(var i=0;i<mas.length;i++)
  {
	//alert(1);
	  $("#main_menu").append('<li id=title><a href='+mas[i].name+'.html>'+mas[i].name+'</a></li>');
	  $("#main_menu>li:last-child").append('<ul id=submenu></ul>');
	  for(var j=0;j<mas[i].submenu.length;j++) {
		$("#main_menu>li:last-child #submenu").append('<li><a href='+mas[i].name+'_'+mas[i].submenu[j]+'.html>'+mas[i].submenu[j]+'</a></li>');
	  }
   }
   
	onLoad2();
	
	$("#main_menu #title").mouseover(Show);
	$("#main_menu #title").mouseout(Hide);
	
	function Show(){
		$(this.lastChild).css("display","block");
	};

	function Hide() {
		$(this.lastChild).css("display","none");
	}*/
	
}